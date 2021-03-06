#ifndef __URDE_CMEMORYCARDSYS_HPP__
#define __URDE_CMEMORYCARDSYS_HPP__

#include "CToken.hpp"
#include "World/CWorld.hpp"
#include "CGameHintInfo.hpp"
#include "CSaveWorld.hpp"
#include <vector>

namespace urde
{
class CDummyWorld;
class CStringTable;

class CSaveWorldMemory
{
    friend class CMemoryCardSys;
    ResId x0_strgId = -1;
    ResId x4_savwId = -1;
    u32 x8_areaCount;
    std::vector<ResId> xc_areaIds;
    std::vector<CWorldLayers::Area> x1c_defaultLayerStates;
    TLockedToken<CStringTable> x2c_worldName; /* used to be optional */
    TLockedToken<CSaveWorld> x3c_saveWorld; /* used to be optional */

public:
    ResId GetSaveWorldAssetId() const { return x4_savwId; }
    u32 GetAreaCount() const { return x8_areaCount; }

    const TLockedToken<CStringTable>& GetWorldName() const { return x2c_worldName; }
    const TLockedToken<CSaveWorld>& GetSaveWorld() const { return x3c_saveWorld; }
};

class CSaveWorldIntermediate
{
    friend class CMemoryCardSys;
    ResId x0_mlvlId;
    ResId x4_strgId;
    ResId x8_savwId;
    std::vector<ResId> xc_areaIds;
    std::vector<CWorldLayers::Area> x1c_defaultLayerStates;
    std::unique_ptr<CDummyWorld> x2c_dummyWorld;
    TLockedToken<CSaveWorld> x34_saveWorld; /* Used to be auto_ptr */

public:
    CSaveWorldIntermediate(ResId mlvl, ResId savw);

    bool InitializePump();
};

class CMemoryCardSys
{
    TLockedToken<CGameHintInfo> x0_hints;
    std::vector<std::pair<ResId, CSaveWorldMemory>> xc_memoryWorlds; /* MLVL as key */
    std::experimental::optional<std::vector<CSaveWorldIntermediate>> x1c_worldInter; /* used to be auto_ptr of vector */
    std::unordered_map<ResId, CSaveWorld::EScanCategory> x20_scanStates;
public:
    const std::vector<CGameHintInfo::CGameHint>& GetHints() const { return x0_hints->GetHints(); }
    const std::vector<std::pair<ResId, CSaveWorldMemory>>& GetMemoryWorlds() const { return xc_memoryWorlds; }
    CMemoryCardSys();
    bool InitializePump();
};

}

#endif // __URDE_CMEMORYCARDSYS_HPP__
