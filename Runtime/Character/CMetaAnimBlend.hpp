#ifndef __URDE_CMETAANIMBLEND_HPP__
#define __URDE_CMETAANIMBLEND_HPP__

#include "IMetaAnim.hpp"
#include "IOStreams.hpp"

namespace urde
{

class CMetaAnimBlend : public IMetaAnim
{
    std::shared_ptr<IMetaAnim> x4_animA;
    std::shared_ptr<IMetaAnim> x8_animB;
    float xc_blend;
    bool x10_;
public:
    CMetaAnimBlend(CInputStream& in);
    EMetaAnimType GetType() const {return EMetaAnimType::Blend;}

    void GetUniquePrimitives(std::set<CPrimitive>& primsOut) const;
    std::shared_ptr<CAnimTreeNode> VGetAnimationTree(const CAnimSysContext& animSys,
                                                     const CMetaAnimTreeBuildOrders& orders) const;
};

}

#endif // __URDE_CMETAANIMBLEND_HPP__
