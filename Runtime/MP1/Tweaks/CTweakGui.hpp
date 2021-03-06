#ifndef __URDE_MP1_CTWEAKGUI_HPP__
#define __URDE_MP1_CTWEAKGUI_HPP__

#include "GuiSys/ITweakGui.hpp"
#include "zeus/CVector3f.hpp"
#include "zeus/CColor.hpp"

namespace urde
{
class CTweakGui : public ITweakGui
{
    bool x4_;
    float x8_;
    float xc_;
    float x10_;
    float x14_;
    float x18_;
    float x1c_;
    float x20_;
    float x24_;
    float x28_;
    u32 x2c_ = 0;
    float x30_;
    float x34_;
    float x38_;
    float x3c_;
    bool x40_;
    float x44_;
    float x48_;
    float x4c_;
    float x50_;
    float x54_;
    float x58_;
    float x5c_;
    float x60_;
    zeus::CVector3f x64_;
    zeus::CVector3f x70_;
    float x7c_;
    float x80_;
    float x84_;
    float x88_;
    float x8c_;
    float x90_;
    float x94_;
    float x98_;
    float x9c_;
    float xa0_;
    float xa4_;
    u32 xa8_;
    u32 xac_;
    u32 xb0_;
    float xb4_;
    float xb8_;
    float xbc_;
    float xc0_;
    float xc4_;
    float xc8_;
    float xcc_;
    float xd0_;
    u32 xd4_;
    float xd8_;
    float xdc_;
    float xe0_;
    float xe4_;
    float xe8_;
    float xec_;
    float xf0_;
    float xf4_;
    u32 xf8_;
    u32 xfc_;
    u32 x100_;
    u32 x104_;
    u32 x108_;
    u32 x10c_;
    float x110_;
    float x114_;
    float x118_;
    float x11c_;
    float x120_;
    float x124_;
    float x128_;
    float x12c_;
    bool x130_;
    float x134_;
    float x138_;
    float x13c_;
    float x140_;
    float x144_;
    float x148_;
    float x14c_;
    std::string x150_;
    std::string x160_;
    std::string x170_;
    std::string x180_;
    std::string x190_;
    float x1a0_;
    float x1a4_;
    float x1a8_;
    float x1ac_;
    float x1b0_;
    float x1b4_;
    float x1b8_;
    float x1bc_;
    float x1c0_;
    float x1c4_;
    float x1c8_;
    bool x1cc_;
    bool x1cd_;
    float x1d0_;
    float x1d4_;
    float x1d8_;
    float x1dc_;
    float x1e0_;
    float x1e4_;
    float x1e8_;
    float x1ec_;
    float x1f0_;
    float x1f4_;
    float x1f8_;
    float x1fc_;
    zeus::CColor x200_;
    float x204_ = 0.0014f;
    float x208_ = 0.0000525f;
    float x20c_;
    float x210_;
    float x214_;
    float x218_;
    float x21c_;
    float x220_;
    float x224_;
    float x228_;
    float x22c_;
    float x230_;
    float x234_;
    float x238_;
    float x23c_;
    float x240_;
    float x244_;
    float x248_;
    float x24c_;
    float x250_;
    float x254_;
    float x258_;
    float x25c_;
    float x260_;
    float x264_;
    float x268_;
    float x26c_;
    float x270_;
    bool x274_;
    bool x275_ = true;
    float x278_;
    u32 x27c_;
    float x280_;
    float x284_;
    zeus::CColor x288_;
    float x28c_;
    zeus::CColor x290_;
    zeus::CColor x294_;
    zeus::CColor x298_;
    zeus::CColor x29c_;
    zeus::CColor x2a0_;
    zeus::CColor x2a4_;
    zeus::CColor x2a8_;
    zeus::CColor x2ac_;
    zeus::CColor x2b0_;
    zeus::CColor x2b4_;
    float x2b8_;
    float x2bc_;
    float x2c0_;
    std::vector<float> x2c4_scanSpeeds;
    std::string x2d0_;
    std::string x2e0_;
    std::string x2f0_;
    zeus::CColor x300_;
    zeus::CColor x304_;
    float x308_;
    float x30c_;
    float x310_;
    std::string x314_;
    std::string x324_;
    std::string x334_;
    zeus::CColor x344_;
    zeus::CColor x348_;
    zeus::CColor x34c_;
    zeus::CColor x350_;
    zeus::CColor x354_;
    zeus::CColor x358_;
    float x35c_;
    float x360_;
    float x364_;
public:
    CTweakGui(CInputStream&);

    float GetScanSpeed(s32) const;
};
}
#endif // __URDE_MP1_CTWEAKGUI_HPP__
