#ifndef __URDE_CSORTEDLISTS_HPP__
#define __URDE_CSORTEDLISTS_HPP__

#include "RetroTypes.hpp"
#include "zeus/CAABox.hpp"

namespace urde
{

struct SSortedList
{
    TUniqueId x0_ids[1024];
    void Reset() {std::fill(std::begin(x0_ids), std::end(x0_ids), -1);}
    SSortedList() {Reset();}
};

class CSortedListManager
{
    struct SNode
    {
        u32 x0_ = 0;
        zeus::CAABox x4_box = zeus::CAABox::skNullBox;
        u32 x1c_;
        u32 x20_;
        u32 x24_;
        u32 x28_ = -1;
        bool x2a_ = false;
    };
    SNode x0_nodes[1024];
    SSortedList xb000_sortedLists[6];
public:
    CSortedListManager();
    void Reset();
};

}

#endif // __URDE_CSORTEDLISTS_HPP__
