#ifndef _DNAMP1_SCRIPTOBJECT_HPP_
#define _DNAMP1_SCRIPTOBJECT_HPP_

#include "../../DNACommon/DNACommon.hpp"
#include "IScriptObject.hpp"
#include "Parameters.hpp"

namespace DataSpec
{
namespace DNAMP1
{
struct Trigger : IScriptObject
{
    DECL_YAML
    String<-1> name;
    Value<atVec3f> location;
    Value<atVec3f> volume;
    DamageInfo damageInfo;
    Value<atVec3f> force;
    Value<atUint32> unknown;
    Value<bool> active;
    Value<bool> unknown2;
    Value<bool> unknown3;
};
}
}

#endif
