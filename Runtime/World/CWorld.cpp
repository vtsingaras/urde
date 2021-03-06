#include "CWorld.hpp"
#include "CGameArea.hpp"
#include "GameGlobalObjects.hpp"
#include "CSimplePool.hpp"
#include "CStateManager.hpp"
#include "CInGameTweakManagerBase.hpp"
#include "Audio/CAudioGroupSet.hpp"
#include "Editor/ProjectResourceFactoryBase.hpp"

namespace urde
{

CWorld::CSoundGroupData::CSoundGroupData(int grpId, ResId agsc)
: x0_groupId(grpId), x4_agscId(agsc)
{
    x1c_groupData = g_SimplePool->GetObj(SObjectTag{FOURCC('AGSC'), agsc});
}

CDummyWorld::CDummyWorld(ResId mlvlId, bool loadMap)
: x4_loadMap(loadMap), xc_mlvlId(mlvlId)
{
    SObjectTag tag{FOURCC('MLVL'), mlvlId};
    static_cast<ProjectResourceFactoryBase*>(g_ResFactory)->LoadResourceAsync(tag, x34_loadBuf);
}

ResId CDummyWorld::IGetWorldAssetId() const
{
    return xc_mlvlId;
}

ResId CDummyWorld::IGetStringTableAssetId() const
{
    return x10_strgId;
}

ResId CDummyWorld::IGetSaveWorldAssetId() const
{
    return x14_savwId;
}

const CMapWorld* CDummyWorld::IGetMapWorld() const
{
    return x2c_mapWorld.GetObj();
}

CMapWorld* CDummyWorld::IMapWorld()
{
    return x2c_mapWorld.GetObj();
}

const IGameArea* CDummyWorld::IGetAreaAlways(TAreaId id) const
{
    return &x18_areas.at(id);
}

TAreaId CDummyWorld::IGetCurrentAreaId() const
{
    return x3c_curAreaId;
}

TAreaId CDummyWorld::IGetAreaId(ResId id) const
{
    int ret = 0;
    if (id == -1)
        return kInvalidAreaId;
    for (const CDummyGameArea& area : x18_areas)
    {
        if (area.xc_mrea == id)
            return ret;
        ++ret;
    }
    return kInvalidAreaId;
}

CWorld::CRelay::CRelay(CInputStream& in)
{
    x0_relay = in.readUint32Big();
    x4_target = in.readUint32Big();
    x8_msg = in.readUint16Big();
    xa_active = in.readBool();
}

std::vector<CWorld::CRelay> CWorld::CRelay::ReadMemoryRelays(athena::io::MemoryReader& r)
{
    std::vector<CWorld::CRelay> ret;
    u32 count = r.readUint32Big();
    ret.reserve(count);
    for (u32 i=0 ; i<count ; ++i)
        ret.emplace_back(r);
    return ret;
}

CWorldLayers CWorldLayers::ReadWorldLayers(athena::io::MemoryReader& r)
{
    CWorldLayers ret;

    u32 areaCount = r.readUint32Big();
    ret.m_areas.reserve(areaCount);
    for (u32 i=0 ; i<areaCount ; ++i)
    {
        ret.m_areas.emplace_back();
        ret.m_areas.back().m_layerCount = r.readUint32Big();
        ret.m_areas.back().m_layerBits = r.readUint64Big();
    }

    u32 nameCount = r.readUint32Big();
    ret.m_names.reserve(areaCount);
    for (u32 i=0 ; i<nameCount ; ++i)
        ret.m_names.push_back(r.readString());

    areaCount = r.readUint32Big();
    for (u32 i=0 ; i<areaCount ; ++i)
        ret.m_areas[i].m_startNameIdx = r.readUint32Big();

    return ret;
}

bool CDummyWorld::ICheckWorldComplete()
{
    switch (x8_phase)
    {
    case Phase::Loading:
    {
        if (!x34_loadBuf)
            return false;
        athena::io::MemoryReader r(x34_loadBuf.get(), UINT32_MAX, false);
        r.readUint32Big();
        int version = r.readUint32Big();
        x10_strgId = r.readUint32Big();

        if (version >= 15)
            x14_savwId = r.readUint32Big();
        if (version >= 12)
            r.readUint32Big();
        if (version >= 17)
            CWorld::CRelay::ReadMemoryRelays(r);

        u32 areaCount = r.readUint32Big();
        r.readUint32Big();

        x18_areas.reserve(areaCount);
        for (u32 i=0 ; i<areaCount ; ++i)
            x18_areas.emplace_back(r, i, version);

        x28_mapWorldId = r.readUint32Big();
        if (x4_loadMap)
            x2c_mapWorld = g_SimplePool->GetObj(SObjectTag{FOURCC('MAPW'), x28_mapWorldId});

        r.readByte();
        r.readUint32Big();

        if (version > 10)
        {
            u32 audioGroupCount = r.readUint32Big();
            for (u32 i=0 ; i<audioGroupCount ; ++i)
            {
                r.readUint32Big();
                r.readUint32Big();
            }
        }

        if (version > 12)
            r.readString();

        CWorldLayers::ReadWorldLayers(r);

        if (x4_loadMap)
            x8_phase = Phase::LoadingMap;
        else
        {
            x8_phase = Phase::Done;
            return false;
        }
    }
    case Phase::LoadingMap:
    {
        if (!x2c_mapWorld.IsLoaded() || !x2c_mapWorld.GetObj())
            return false;

        x2c_mapWorld->SetWhichMapAreasLoaded(*this, 0, 9999);
        x8_phase = Phase::LoadingMapAreas;
    }
    case Phase::LoadingMapAreas:
    {
        if (x2c_mapWorld->IsMapAreasStreaming())
            return false;

        x8_phase = Phase::Done;
    }
    case Phase::Done:
        return true;
    default:
        return false;
    }

    return false;
}

std::string CDummyWorld::IGetDefaultAudioTrack() const
{
    return {};
}

int CDummyWorld::IGetAreaCount() const
{
    return x18_areas.size();
}

CWorld::CWorld(IObjectStore& objStore, IFactory& resFactory, ResId mlvlId)
: x60_objectStore(objStore), x64_resFactory(resFactory)
{
    SObjectTag tag{FOURCC('MLVL'), mlvlId};
    static_cast<ProjectResourceFactoryBase&>(resFactory).LoadResourceAsync(tag, x40_loadBuf);
}

ResId CWorld::IGetWorldAssetId() const
{
    return x8_mlvlId;
}

ResId CWorld::IGetStringTableAssetId() const
{
    return xc_strgId;
}

ResId CWorld::IGetSaveWorldAssetId() const
{
    return x10_savwId;
}

const CMapWorld* CWorld::IGetMapWorld() const
{
    return const_cast<CWorld*>(this)->GetMapWorld();
}

CMapWorld* CWorld::IMapWorld()
{
    return const_cast<CMapWorld*>(GetMapWorld());
}

const CGameArea* CWorld::GetAreaAlways(TAreaId id) const
{
    return x18_areas.at(id).get();
}

CGameArea* CWorld::GetArea(TAreaId id)
{
    return const_cast<CGameArea*>(GetAreaAlways(id));
}

const IGameArea* CWorld::IGetAreaAlways(TAreaId id) const
{
    return GetAreaAlways(id);
}

TAreaId CWorld::IGetCurrentAreaId() const
{
    return x68_curAreaId;
}

TAreaId CWorld::IGetAreaId(ResId id) const
{
    int ret = 0;
    if (id == -1)
        return kInvalidAreaId;
    for (const std::unique_ptr<CGameArea>& area : x18_areas)
    {
        if (area->x84_mrea == id)
            return ret;
        ++ret;
    }
    return kInvalidAreaId;
}

void CWorld::MoveToChain(CGameArea* area, EChain chain)
{
    if (area->x138_curChain == chain)
        return;

    if (area->x138_curChain != EChain::Invalid)
        if (x4c_chainHeads[int(chain)] == area)
            x4c_chainHeads[int(chain)] = area->x130_next;

    area->SetChain(x4c_chainHeads[int(chain)], chain);
    x4c_chainHeads[int(chain)] = area;
}

void CWorld::LoadSoundGroup(int groupId, ResId agscId, CSoundGroupData& data)
{
}

void CWorld::LoadSoundGroups()
{
}

bool CWorld::CheckWorldComplete(CStateManager* mgr, TAreaId id, ResId mreaId)
{
    if (mreaId != -1)
    {
        x68_curAreaId = 0;
        TAreaId aid = 0;
        for (const std::unique_ptr<CGameArea>& area : x18_areas)
        {
            if (area->x84_mrea == mreaId)
            {
                x68_curAreaId = aid;
                break;
            }
            ++aid;
        }
    }
    else
        x68_curAreaId = id;

    switch (x4_phase)
    {
    case Phase::Loading:
    {
        if (!x40_loadBuf)
            return false;
        athena::io::MemoryReader r(x40_loadBuf.get(), UINT32_MAX, false);
        r.readUint32Big();
        int version = r.readUint32Big();
        xc_strgId = r.readUint32Big();

        if (version >= 15)
            x10_savwId = r.readUint32Big();
        if (version >= 12)
        {
            ResId skyboxId = r.readUint32Big();
            if (skyboxId != -1 && mgr)
                x94_skybox = g_SimplePool->GetObj(SObjectTag{FOURCC('CMDL'), skyboxId});
        }
        if (version >= 17)
            x2c_relays = CWorld::CRelay::ReadMemoryRelays(r);

        u32 areaCount = r.readUint32Big();
        r.readUint32Big();

        x18_areas.reserve(areaCount);
        for (u32 i=0 ; i<areaCount ; ++i)
            x18_areas.push_back(std::make_unique<CGameArea>(r, i, version));

        if (x48_chainCount < 5)
        {
            for (int i=x48_chainCount ; i<5 ; ++i)
                x4c_chainHeads[i] = nullptr;
            x48_chainCount = 5;
        }

        for (std::unique_ptr<CGameArea>& area : x18_areas)
            MoveToChain(area.get(), EChain::One);

        x24_mapwId = r.readUint32Big();
        x28_mapWorld = g_SimplePool->GetObj(SObjectTag{FOURCC('MAPW'), x24_mapwId});

        if (mgr)
        {
            std::vector<TEditorId> ids;
            mgr->LoadScriptObjects(kInvalidAreaId, r, ids);
            mgr->InitScriptObjects(ids);
        }

        if (version > 10)
        {
            u32 audioGroupCount = r.readUint32Big();
            x74_soundGroupData.reserve(audioGroupCount);
            for (u32 i=0 ; i<audioGroupCount ; ++i)
            {
                int grpId = r.readUint32Big();
                ResId agscId = r.readUint32Big();
                x74_soundGroupData.emplace_back(grpId, agscId);
            }
        }

        if (version > 12)
        {
            x84_defAudioTrack = r.readString();
            std::string trackKey = hecl::Format("WorldDefault: %8.8x", u32(x8_mlvlId));
            if (g_TweakManager->HasTweakValue(trackKey))
                x84_defAudioTrack = g_TweakManager->GetTweakValue(trackKey)->x30_str;
        }

        CWorldLayers::ReadWorldLayers(r);

        x4_phase = Phase::LoadingMap;
    }
    case Phase::LoadingMap:
    {
        if (!x28_mapWorld.IsLoaded() || !x28_mapWorld.GetObj())
            return false;

        if (x68_curAreaId == kInvalidAreaId)
            x28_mapWorld->SetWhichMapAreasLoaded(*this, 0, 9999);
        else
            x28_mapWorld->SetWhichMapAreasLoaded(*this, x68_curAreaId, 3);

        x4_phase = Phase::LoadingMapAreas;
    }
    case Phase::LoadingMapAreas:
    {
        if (x28_mapWorld->IsMapAreasStreaming())
            return false;

        x4_phase = Phase::LoadingSkyBox;
    }
    case Phase::LoadingSkyBox:
    {
        x70_26_ = true;
        x70_27_ = false;

        if (!x94_skybox.IsLoaded())
            return false;

        CModel* skybox = x94_skybox.GetObj();
        if (!skybox)
            return false;

        skybox->GetInstance().Touch(0);
        if (!skybox->IsLoaded(0))
            return false;

        xa4_skyboxB = x94_skybox;

        for (CSoundGroupData& group : x74_soundGroupData)
            group.x1c_groupData.Lock();

        x4_phase = Phase::LoadingSoundGroups;
    }
    case Phase::LoadingSoundGroups:
    {
        bool allLoaded = true;
        for (CSoundGroupData& group : x74_soundGroupData)
        {
            bool loaded = group.x1c_groupData.IsLoaded();
            allLoaded &= loaded;
            if (loaded)
            {
                CAudioGroupSet* groupData = group.x1c_groupData.GetObj();
                if (groupData)
                    LoadSoundGroup(group.x0_groupId, group.x4_agscId, group);
            }
        }
        if (!allLoaded)
            return false;

        LoadSoundGroups();
        x4_phase = Phase::Done;
    }
    case Phase::Done:
        return true;
    default:
        return false;
    }

    return false;
}

bool CWorld::ScheduleAreaToLoad(CGameArea* area, CStateManager& mgr)
{
    if (!area->xf0_24_postConstructed)
    {
        MoveToChain(area, EChain::Two);
        return true;
    }
    else
    {
        if (area->x138_curChain != EChain::Three)
        {
            if (area->x138_curChain != EChain::Four)
            {
                x70_24_ = true;
            }
            MoveToChain(area, EChain::Three);
        }
        return false;
    }
}

void CWorld::TravelToArea(TAreaId aid, CStateManager& mgr, bool skipLoadOther)
{
    if (aid < 0 || aid >= x18_areas.size())
        return;
    x70_24_ = false;
    x68_curAreaId = aid;

    CGameArea* chain0 = x4c_chainHeads[0];
    while (chain0)
    {
        if (chain0->Invalidate(mgr))
        {
            MoveToChain(chain0, EChain::One);
            break;
        }
        chain0 = chain0->x130_next;
    }

    CGameArea* chain3 = x4c_chainHeads[3];
    while (chain3)
    {
        MoveToChain(chain3, EChain::Four);
        chain3 = chain3->x130_next;
    }

    CGameArea* chain2 = x4c_chainHeads[2];
    while (chain2)
    {
        MoveToChain(chain2, EChain::Zero);
        chain2 = chain2->x130_next;
    }

    CGameArea* area = x18_areas[aid].get();
    if (area->x138_curChain != EChain::Four)
        x70_24_ = true;
    area->Validate(mgr);
    MoveToChain(area, EChain::Three);
    area->SetOcclusionState(CGameArea::EOcclusionState::Occluded);

    CGameArea* otherLoadArea = nullptr;
    if (!skipLoadOther)
    {
        bool otherLoading = false;
        for (CGameArea::Dock& dock : area->xcc_docks)
        {
            u32 dockRefCount = dock.GetDockRefs().size();
            for (u32 i=0 ; i<dockRefCount ; ++i)
            {
                if (!dock.ShouldLoadOtherArea(i))
                    continue;
                TAreaId connArea = dock.GetConnectedAreaId(i);
                CGameArea* cArea = x18_areas[connArea].get();
                if (!cArea->xf0_25_active)
                    continue;
                if (!otherLoading)
                {
                    otherLoading = ScheduleAreaToLoad(cArea, mgr);
                    if (!otherLoading)
                        continue;
                    otherLoadArea = cArea;
                }
                else
                    ScheduleAreaToLoad(cArea, mgr);
            }

        }
    }

    CGameArea* chain4 = x4c_chainHeads[4];
    while (chain4)
    {
        MoveToChain(chain4, EChain::Zero);
        chain4 = chain4->x130_next;
    }

    size_t toStreamCount = 0;
    chain0 = x4c_chainHeads[0];
    while (chain0)
    {
        chain0->RemoveStaticGeometry();
        chain0 = chain0->x130_next;
        ++toStreamCount;
    }

    if (!toStreamCount && otherLoadArea && !x70_25_)
        otherLoadArea->StartStreamIn(mgr);

    GetMapWorld()->SetWhichMapAreasLoaded(*this, aid, 3);
}

bool CWorld::ICheckWorldComplete()
{
    return CheckWorldComplete(nullptr, kInvalidAreaId, -1);
}

std::string CWorld::IGetDefaultAudioTrack() const
{
    return x84_defAudioTrack;
}

int CWorld::IGetAreaCount() const
{
    return x18_areas.size();
}

bool CWorld::DoesAreaExist(TAreaId area) const
{
    return (area >= 0 && area < x18_areas.size());
}

}
