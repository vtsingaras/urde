#ifndef __URDE_IFACTORY_HPP__
#define __URDE_IFACTORY_HPP__

#include <memory>
#include <functional>
#include "RetroTypes.hpp"

namespace urde
{
class CVParamTransfer;
class IObj;
class CObjectReference;

using CFactoryFnReturn = std::unique_ptr<IObj>;
using FFactoryFunc = std::function<CFactoryFnReturn(const urde::SObjectTag& tag,
                                                    urde::CInputStream& in,
                                                    const urde::CVParamTransfer& vparms,
                                                    CObjectReference* selfRef)>;
using FMemFactoryFunc = std::function<CFactoryFnReturn(const urde::SObjectTag& tag,
                                                       std::unique_ptr<u8[]>&& in, u32 len,
                                                       const urde::CVParamTransfer& vparms,
                                                       CObjectReference* selfRef)>;

class IFactory
{
public:
    virtual ~IFactory() = default;
    virtual CFactoryFnReturn Build(const SObjectTag&, const CVParamTransfer&, CObjectReference*)=0;
    virtual void BuildAsync(const SObjectTag&, const CVParamTransfer&, IObj**, CObjectReference*)=0;
    virtual void CancelBuild(const SObjectTag&)=0;
    virtual bool CanBuild(const SObjectTag&)=0;
    virtual const SObjectTag* GetResourceIdByName(const char*) const=0;
    virtual FourCC GetResourceTypeById(ResId id) const=0;
    virtual void EnumerateResources(const std::function<bool(const SObjectTag&)>& lambda) const=0;
    virtual void EnumerateNamedResources(const std::function<bool(const std::string&, const SObjectTag&)>& lambda) const=0;

    /* Non-factory versions, replaces CResLoader */
    virtual u32 ResourceSize(const urde::SObjectTag& tag)=0;
    //virtual bool LoadResourceAsync(const urde::SObjectTag& tag, std::unique_ptr<u8[]>& target)=0;
    //virtual bool LoadResourcePartAsync(const urde::SObjectTag& tag, u32 size, u32 off, std::unique_ptr<u8[]>& target)=0;
    virtual std::unique_ptr<u8[]> LoadResourceSync(const urde::SObjectTag& tag)=0;
    virtual std::unique_ptr<u8[]> LoadResourcePartSync(const urde::SObjectTag& tag, u32 size, u32 off)=0;
};

}

#endif // __URDE_IFACTORY_HPP__
