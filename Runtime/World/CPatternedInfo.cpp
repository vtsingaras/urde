#include "CPatternedInfo.hpp"
#include "Audio/CSfxManager.hpp"

namespace urde
{

CPatternedInfo::CPatternedInfo(CInputStream& in, u32 pcount)
: x0_mass(in.readFloatBig()),
  x4_speed(in.readFloatBig()),
  x8_turnSpeed(in.readFloatBig()),
  xc_detectionRange(in.readFloatBig()),
  x10_detectionHeightRange(in.readFloatBig()),
  x14_dectectionAngle(in.readFloatBig()),
  x18_minAttackRange(in.readFloatBig()),
  x1c_maxAttackRange(in.readFloatBig()),
  x20_averageAttackTime(in.readFloatBig()),
  x24_attackTimeVariation(in.readFloatBig()),
  x28_leashRadius(in.readFloatBig()),
  x2c_playerLeashRadius(in.readFloatBig()),
  x30_playerLeashTime(in.readFloatBig()),
  x34_damageInfo(in),
  x50_damageWaitTime(in.readFloatBig()),
  x54_healthInfo(in),
  x5c_damageVulnerability(in),
  xc4_halfExtent(in.readFloatBig()),
  xc8_height(in.readFloatBig()),
  xcc_bodyOrigin(zeus::CVector3f::ReadBig(in)),
  xd8_stepUpHeight(in.readFloatBig()),
  xdc_(in.readFloatBig()),
  xe0_(in.readFloatBig()),
  xe4_(in.readFloatBig()),
  xe8_deathSfx(CSfxManager::TranslateSFXID(in.readUint32Big())),
  xec_animParams(in),
  xf8_active(in.readBool()),
  xfc_stateMachineId(in.readUint32Big()),
  x100_(in.readFloatBig()),
  x104_(in.readFloatBig()),
  x108_(in.readFloatBig()),
  x10c_particle1Frames(in.readUint32Big()),
  x110_particle1Scale(zeus::CVector3f::ReadBig(in)),
  x11c_particle1(in.readUint32Big()),
  x120_particle2Frames(in.readUint32Big())
{
    if (pcount >= 36)
        x124_particle2Scale.readBig(in);
    if (pcount >= 37)
        x130_particle2 = in.readUint32Big();
    if (pcount >= 38)
        x134_iceShatterSfx = CSfxManager::TranslateSFXID(in.readUint32Big());
}

std::pair<bool, u32> CPatternedInfo::HasCorrectParameterCount(CInputStream& in)
{
    u32 pcount = in.readUint32Big();
    if (pcount < 35 || pcount > 38)
        return {false, pcount};
    return {true, pcount};
}

}
