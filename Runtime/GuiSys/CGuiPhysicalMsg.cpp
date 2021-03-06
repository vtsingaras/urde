#include "CGuiPhysicalMsg.hpp"

namespace urde
{

CGuiPhysicalMsg::CGuiPhysicalMsg(const PhysicalMap& map)
{
    SetMessage(map, true);
}

bool CGuiPhysicalMsg::Exists(const CGuiPhysicalMsg& other) const
{
    return ((~x8_repeatStates | other.x8_repeatStates) & x0_curStates) == other.x0_curStates;
}

void CGuiPhysicalMsg::SetMessage(const PhysicalMap& map, bool pressed)
{
    for (const std::pair<EPhysicalControllerID, CPhysicalID>& item : map)
    {
        u64 physicalBit = 1 << u64(item.second.x0_key);
        if (pressed)
            x0_curStates |= physicalBit;
        else
            x0_curStates &= ~physicalBit;

        if (item.second.x4_repeat)
            x8_repeatStates |= physicalBit;
        else
            x8_repeatStates &= ~physicalBit;
    }
}

void CGuiPhysicalMsg::AddControllerID(PhysicalMap& map, EPhysicalControllerID key, bool repeat)
{
    map.emplace(std::make_pair(key, CPhysicalID{key, repeat}));
}

CGuiPhysicalMsg::EControllerState
CGuiPhysicalMsg::FindControllerID(const PhysicalMap& map, EPhysicalControllerID key)
{
    auto search = map.find(key);
    if (search == map.cend())
        return EControllerState::NotPressed;
    return search->second.x4_repeat ? EControllerState::PressRepeat : EControllerState::Press;
}

}
