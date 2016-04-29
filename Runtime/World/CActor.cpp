#include "CActor.hpp"
#include "CActorParameters.hpp"
#include "CStateManager.hpp"
#include "Collision/CMaterialList.hpp"
#include "Graphics/CGraphics.hpp"
#include "Audio/CSfxManager.hpp"

namespace urde
{

static CMaterialList MakeActorMaterialList(const CMaterialList& materialList, const CActorParameters& params)
{
    CMaterialList ret = materialList;
    if (params.GetVisorParameters().x0_28_b3)
        ret.Add(EMaterialTypes::Fourteen);
    if (params.GetVisorParameters().x0_29_b4)
        ret.Add(EMaterialTypes::Fifteen);
    return ret;
}

CActor::CActor(TUniqueId uid, bool active, const std::string& name, const CEntityInfo& info,
               const zeus::CTransform&, CModelData&& mData, const CMaterialList& list,
               const CActorParameters& params, TUniqueId)
    : CEntity(uid, info, active, name),
      x68_material(MakeActorMaterialList(list, params)),
      x70_(CMaterialFilter::MakeIncludeExclude({EMaterialTypes::Nineteen}, {EMaterialTypes::Zero}))
{
    if (mData.x1c_normalModel)
        x64_modelData = std::make_unique<CModelData>(std::move(mData));
}

void CActor::AcceptScriptMsg(EScriptObjectMessage msg, TUniqueId uid, CStateManager& mgr)
{
    switch(msg)
    {
    case EScriptObjectMessage::Activate:
    {
        if (!x30_24_active)
            xbc_time = CGraphics::GetSecondsMod900();
    }
        break;
    case EScriptObjectMessage::Decrement:
        RemoveEmitter();
        break;
    case EScriptObjectMessage::UNKM13: // 33
    {
        /* TODO: What's x98_?
        if (x98_)
            AddMaterial(EMaterialTypes::ThirtyNine, mgr);
        else
            RemoveMaterial(EMaterialTypes::ThirtyNine, mgr);
        */
        /*
        if (HasModelData() && x64_modelData->AnimationData())
        {
            TAreaId aid = GetCurrentAreaId();
            x64_modelData->AnimationData()->sub_8002AE6C(mgr, aid, x64_modelData->x0_particleScale);
        }
        */
    }
        break;
    case EScriptObjectMessage::UNKM14: // 34
    {
        RemoveEmitter();
        /* TODO: Not sure about this
        if (HasModelData() && x64_modelData->AnimationData() && x64_modelData->x28_)
            x64_modelData->AnimationData().GetParticleDB().GetActiveParticleLightIds(mgr);
        */
    }
        break;
    case EScriptObjectMessage::UNKM15: // 35
    {
        for (const SConnection& conn : x20_conns)
        {
            if (conn.x0_state != EScriptObjectState::DFST)
                continue;

            const CActor* act = dynamic_cast<const CActor*>(mgr.GetObjectById(mgr.GetIdForScript(conn.x8_objId)));
            if (act && xc6_ == kInvalidUniqueId)
                xc6_ = act->GetUniqueId();
        }
    }
        break;
    case EScriptObjectMessage::UNKM17: // 37
        //SetInFluid(true, uid);
        break;
    case EScriptObjectMessage::UNKM19: // 39
        //SetInFluid(false, kInvalidUniqueId);
        break;
    default:break;
    }
    CEntity::AcceptScriptMsg(msg, uid, mgr);
}

void CActor::RemoveEmitter()
{
    if (x8c_sfxHandle)
    {
        CSfxManager::RemoveEmitter(*x8c_sfxHandle.get());
        x88_sfxId = -1;
        x8c_sfxHandle.reset();
    }
}

void CActor::RemoveMaterial(EMaterialTypes t1, EMaterialTypes t2, EMaterialTypes t3, EMaterialTypes t4, CStateManager& mgr)
{
    x68_material.Remove(t1);
    RemoveMaterial(t2, t3, t4, mgr);
}

void CActor::RemoveMaterial(EMaterialTypes t1, EMaterialTypes t2, EMaterialTypes t3, CStateManager & mgr)
{
    x68_material.Remove(t1);
    RemoveMaterial(t2, t3, mgr);
}

void CActor::RemoveMaterial(EMaterialTypes t1, EMaterialTypes t2, CStateManager& mgr)
{
    x68_material.Remove(t1);
}

void CActor::RemoveMaterial(EMaterialTypes t, CStateManager& mgr)
{
    x68_material.Remove(t);
    mgr.UpdateObjectInLists(*this);
}

void CActor::AddMaterial(EMaterialTypes t1, EMaterialTypes t2, EMaterialTypes t3, EMaterialTypes t4, EMaterialTypes t5, CStateManager& mgr)
{
    x68_material.Add(t1);
    AddMaterial(t2, t3, t4, t5, mgr);
}

void CActor::AddMaterial(EMaterialTypes t1, EMaterialTypes t2, EMaterialTypes t3, EMaterialTypes t4, CStateManager& mgr)
{
    x68_material.Add(t1);
    AddMaterial(t2, t3, t4, mgr);
}

void CActor::AddMaterial(EMaterialTypes t1, EMaterialTypes t2, EMaterialTypes t3, CStateManager& mgr)
{
    x68_material.Add(t1);
    AddMaterial(t2, t3, mgr);
}

void CActor::AddMaterial(EMaterialTypes t1, EMaterialTypes t2, CStateManager& mgr)
{
    x68_material.Add(t1);
    AddMaterial(t2, mgr);
}

void CActor::AddMaterial(EMaterialTypes type, CStateManager& mgr)
{
    x68_material.Add(type);
    mgr.UpdateObjectInLists(*this);
}

bool CActor::HasModelData() const
{
    return x64_modelData.operator bool();
}

}