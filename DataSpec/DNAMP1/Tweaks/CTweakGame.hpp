#ifndef _DNAMP1_CTWEAKGAME_HPP_
#define _DNAMP1_CTWEAKGAME_HPP_

#include "../../DNACommon/Tweaks/ITweakGame.hpp"

namespace DataSpec
{
namespace DNAMP1
{

struct CTweakGame : ITweakGame
{
    DECL_YAML
    String<-1> x4_worldPrefix;
    String<-1> x14_ruinsArea; // ????
    Value<float> x24_fov;
    Value<bool> x28_unknown1;
    Value<bool> x29_unknown2;
    Value<bool> x2a_unknown3;
    Value<bool> x2b_unknown4;
    Value<float> x2c_cunknown5;
    Value<float> x30_unknown6;
    Value<float> x34_unknown7;
    Value<float> x38_unknown8;
    Value<float> x3c_unknown9;
    Value<float> x40_unknown10;
    Value<float> x44_unknown11;
    Value<float> x48_unknown12;
    Value<float> x4c_unknown13;
    Value<float> x50_unknown14;
    Value<float> x54_unknown15;
    Value<float> x58_unknown16;
    Value<float> x5c_unknown17;
    Value<float> x60_unknown18;
    Value<float> x64_hardmodeDamageMult;
    Value<float> x68_hardmodeWeaponMult;

    virtual const std::string& GetWorldPrefix() const { return x4_worldPrefix; }
    virtual float GetFirstPersonFOV() const { return x24_fov; }
    CTweakGame(athena::io::IStreamReader& in) { this->read(in); x2b_unknown4 = false; }
};
}
}

#endif
