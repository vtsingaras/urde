#ifndef __URDE_CRIPPLE_HPP__
#define __URDE_CRIPPLE_HPP__

#include "RetroTypes.hpp"
#include "zeus/CVector3f.hpp"

namespace urde
{
class CRipple
{
private:
    TUniqueId x0_;
    float x4_ = 0.f;
    zeus::CVector3f x8_;
    float x14_ = 2.f;
    float x18_ = 12.f;
    float x1c_ = 3.f;
    float x20_ = 0.25f;
    float x24_ = 0.00098039221f;
public:
    CRipple(TUniqueId, const zeus::CVector3f&, float);

    void SetTime(float);
    float GetTime() const;
    float GetTimeFalloff() const;
    TUniqueId GetUniqueId() const;
    float GetFequency() const;
    float GetAmplitude() const;
    float GetOODistanceFalloff() const;
    float GetDistanceFalloff() const;
    zeus::CVector3f GetCenter() const;
    float GetOOTimeFalloff() const;
};
}
#endif // __URDE_CRIPPLE_HPP__
