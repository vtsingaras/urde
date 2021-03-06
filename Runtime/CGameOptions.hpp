#ifndef __URDE_CGAMEOPTIONS_HPP__
#define __URDE_CGAMEOPTIONS_HPP__

#include "RetroTypes.hpp"

namespace urde
{

/** Options tracked persistently between game sessions */
class CPersistentOptions
{
    bool x0_[98] = {};
    bool x68_[64] = {};
    std::vector<std::pair<ResId, TEditorId>> xac_cinematicStates; /* (MLVL, Cinematic) */
    u32 xb0_ = 0;
    u32 xb4_ = 0;
    u32 xb8_ = 0;
    u32 xbc_ = 0;
    u32 xc0_ = 0;
    u32 xc4_ = 0;
    u32 xc8_ = 0;
    u32 xcc_ = 0;

    union
    {
        struct
        {
            bool xd0_24_;
            bool xd0_25_;
            bool xd0_26_;
            bool xd0_27_;
            bool xd0_28_;
            bool xd0_29_;
        };
        u16 _dummy = 0;
    };

public:
    CPersistentOptions() = default;
    CPersistentOptions(CBitStreamReader& stream);

    void SetCinematicState(ResId mlvlId, TEditorId cineId, bool state);
};

/** Options tracked per game session */
class CGameOptions
{
public:
    enum class ESoundMode
    {
        Mono,
        Stereo,
        Surround
    };

private:
    bool x0_[64] = {};
    ESoundMode x44_soundMode = ESoundMode::Stereo;
    u32 x48_ = 4;
    u32 x4c_ = 0;
    u32 x50_ = 0;
    u32 x54_ = 0;
    u32 x58_ = 0x7f;
    u32 x5c_ = 0x7f;
    u32 x60_ = 0xff;
    u32 x64_ = 0xff;

    union
    {
        struct
        {
            bool x68_24_;
            bool x68_25_;
            bool x68_26_;
            bool x68_27_;
            bool x68_28_;
        };
        u16 _dummy = 0;
    };

    u32 x70_ = 0;
    u32 x74_ = 0;
    u32 x78_ = 0;

public:
    CGameOptions();
    CGameOptions(CBitStreamReader& stream);
    void InitSoundMode();
    void PutTo(CBitStreamWriter& writer) const;
};

class CHintOptions
{
public:
    enum class EHintState
    {
        Zero,
        One,
        Two
    };
    struct SHintState
    {
        EHintState x0_state = EHintState::Zero;
        float x4_time = 0.f;
        bool x8_flag = false;

        SHintState() = default;
        SHintState(EHintState state, float time, bool flag)
        : x0_state(state), x4_time(time), x8_flag(flag) {}
    };
private:
    std::vector<SHintState> x0_hintStates;
    u32 x10_nextHintIdx = -1;
public:
    CHintOptions() = default;
    CHintOptions(CBitStreamReader& stream);
    void PutTo(CBitStreamWriter& writer) const;
};

}

#endif // __URDE_CGAMEOPTIONS_HPP__
