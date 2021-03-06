#ifndef __CSCRIPTSPAWNPOINT_HPP__
#define __CSCRIPTSPAWNPOINT_HPP__

#include "CEntity.hpp"
#include "zeus/CTransform.hpp"
#include "CPlayerState.hpp"

namespace urde
{

class CScriptSpawnPoint : public CEntity
{
    zeus::CTransform x34_xf;
    std::vector<u32> x64_itemCounts;
    union
    {
        struct
        {
            bool x10c_24_firstSpawn : 1;
            bool x10c_25_ : 1;
        };
        u8 _dummy = 0;
    };
public:
    CScriptSpawnPoint(TUniqueId, const std::string& name, const CEntityInfo& info,
                      const zeus::CTransform& xf, const std::vector<u32>& itemCounts,
                      bool, bool, bool);

    bool FirstSpawn() const { return x10c_24_firstSpawn; }
    const zeus::CTransform& GetTransform() const { return x34_xf; }
    u32 GetPowerup(CPlayerState::EItemType item) const;
};

}

#endif // __CSCRIPTSPAWNPOINT_HPP__
