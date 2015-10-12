#ifndef _DNAMP1_CHOZOGHOST_HPP_
#define _DNAMP1_CHOZOGHOST_HPP_

#include "../../DNACommon/DNACommon.hpp"
#include "IScriptObject.hpp"
#include "Parameters.hpp"

namespace Retro
{
namespace DNAMP1
{
struct ChozoGhost : IScriptObject
{
    DECL_YAML
    String<-1> name;
    Value<atVec3f> location;
    Value<atVec3f> orientation;
    Value<atVec3f> scale;
    PatternedInfo patternedInfo;
    ActorParameters actorParameters;
    Value<float> unknown1;
    Value<float> unknown2;
    Value<float> unknown3;
    Value<float> unknown4;
    UniqueID32 wpsc1;
    DamageInfo damageInfo1;
    UniqueID32 wpsc2;
    DamageInfo damageInfo2;
    BehaveChance BehaveChance1;
    BehaveChance BehaveChance2;
    BehaveChance BehaveChance3;
    Value<atUint32> sound1;
    Value<float> unknown5;
    Value<atUint32> sound2;
    Value<atUint32> sound3;
    Value<atUint32> unknown6;
    Value<float> unknown7;
    Value<atUint32> unknown8;
    Value<float> unknown9;
    UniqueID32 particle;
    Value<atUint32> soundId4;
    Value<float>    unknown10;
    Value<float>    unknown11;
    Value<atUint32> unknown12;
    Value<atUint32> unknown13;
};
}
}

#endif