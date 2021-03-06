#ifndef _DNAMP1_SWITCH_HPP_
#define _DNAMP1_SWITCH_HPP_

#include "../../DNACommon/DNACommon.hpp"
#include "IScriptObject.hpp"
#include "Parameters.hpp"

namespace DataSpec
{
namespace DNAMP1
{
struct Switch : IScriptObject
{
    DECL_YAML
    String<-1> name;
    Value<bool> unknown1;
    Value<bool> unknown2;
    Value<bool> unknown3;
};
}
}

#endif
