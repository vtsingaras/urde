#ifndef _DNAMP1_NEWCAMERASHAKER_HPP_
#define _DNAMP1_NEWCAMERASHAKER_HPP_

#include "../../DNACommon/DNACommon.hpp"
#include "IScriptObject.hpp"
#include "Parameters.hpp"

namespace DataSpec
{
namespace DNAMP1
{
struct NewCameraShaker : IScriptObject
{
    DECL_YAML
    String<-1> name;
    Value<atVec3f> location;
    Value<bool> unknown1;
    PlayerParameters playerParams;
    Value<float> unknown3;
    Value<float> unknown4;
    struct CameraShakerParameters : BigYAML
    {
        DECL_YAML
        PlayerParameters playerParams;
        struct ShakerInfo : BigYAML
        {
            DECL_YAML
            PlayerParameters playerParams;
            Value<float> unknown1;
            Value<float> unknown2;
            Value<float> unknown3;
            Value<float> unknown4;
        };
        ShakerInfo shakers[2];
    } cameraShakerParameters1, cameraShakerParameters2, cameraShakerParameters3;
};
}
}

#endif
