#ifndef __URDE_CHEALTHINFO_HPP__
#define __URDE_CHEALTHINFO_HPP__

#include "RetroTypes.hpp"

namespace urde
{

class CHealthInfo
{
    float x0_health;
    float x4_knockbackResistance;
public:
    CHealthInfo(float hp)
        : x0_health(hp),
          x4_knockbackResistance(0.f)
    {
    }

    CHealthInfo(float hp, float resist)
        : x0_health(hp),
          x4_knockbackResistance(resist)
    {}

    CHealthInfo(CInputStream& in);
    void SetHP(float hp) { x0_health = hp; }
    float GetHP() const {return x0_health;}
    float GetKnockbackResistance() const {return x4_knockbackResistance;}
};

}

#endif // __URDE_CHEALTHINFO_HPP__
