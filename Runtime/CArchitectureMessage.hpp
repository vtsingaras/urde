#ifndef __URDE_CARCHITECTUREMESSAGE_HPP__
#define __URDE_CARCHITECTUREMESSAGE_HPP__

#include "GCNTypes.hpp"
#include "Input/CFinalInput.hpp"
#include "rstl.hpp"

namespace urde
{
class CIOWin;

enum class EArchMsgTarget
{
    IOWinManager = 0,
    Game = 1,
    /* URDE targets, we start at 255 */
    ArchitectureSupport = 255,
};

enum class EArchMsgType
{
    RemoveIOWin = 0,
    CreateIOWin = 1,
    ChangeIOWinPriority = 2,
    RemoveAllIOWins = 3,
    TimerTick = 4,
    UserInput = 5,
    SetGameState = 6,
    ControllerStatus = 7,
    QuitGameplay = 8,
    UpdateBegin = 10,
    FrameBegin = 11,
    /* URDE messages, we start at 255 */
    ApplicationExit = 255,
};

struct IArchMsgParm
{
    virtual ~IArchMsgParm() {}
};

struct CArchMsgParmInt32 : IArchMsgParm
{
    u32 x4_parm;
    CArchMsgParmInt32(u32 parm) : x4_parm(parm) {}
    virtual ~CArchMsgParmInt32() {}
};

struct CArchMsgParmVoidPtr : IArchMsgParm
{
    void* x4_parm1;
    CArchMsgParmVoidPtr(void* parm1)
    : x4_parm1(parm1) {}
    virtual ~CArchMsgParmVoidPtr() {}
};

struct CArchMsgParmInt32Int32VoidPtr : IArchMsgParm
{
    u32 x4_parm1;
    u32 x8_parm2;
    void* xc_parm3;
    CArchMsgParmInt32Int32VoidPtr(u32 parm1, u32 parm2, void* parm3)
    : x4_parm1(parm1), x8_parm2(parm2), xc_parm3(parm3) {}
    virtual ~CArchMsgParmInt32Int32VoidPtr() {}
};

struct CArchMsgParmNull : IArchMsgParm
{
    virtual ~CArchMsgParmNull() {}
};

struct CArchMsgParmReal32 : IArchMsgParm
{
    float x4_parm;
    CArchMsgParmReal32(float parm) : x4_parm(parm) {}
    virtual ~CArchMsgParmReal32() {}
};

struct CArchMsgParmUserInput : IArchMsgParm
{
    CFinalInput x4_parm;
    CArchMsgParmUserInput(const CFinalInput& parm) : x4_parm(parm) {}
    virtual ~CArchMsgParmUserInput() {}
};

struct CArchMsgParmControllerStatus : IArchMsgParm
{
    u16 x4_parm1;
    bool x6_parm2;
    CArchMsgParmControllerStatus(u16 a, bool b)
    : x4_parm1(a), x6_parm2(b) {}

    virtual ~CArchMsgParmControllerStatus() {}
};

class CArchitectureMessage
{
    EArchMsgTarget x0_target;
    EArchMsgType x4_type;
    std::shared_ptr<IArchMsgParm> x8_parm;
public:
    CArchitectureMessage(EArchMsgTarget target, EArchMsgType type, IArchMsgParm* parm)
    : x0_target(target), x4_type(type), x8_parm(parm) {}

    EArchMsgTarget GetTarget() const {return x0_target;}
    EArchMsgType GetType() const {return x4_type;}
    template <class T>
    const T* GetParm() const {return dynamic_cast<T*>(x8_parm.get());}
};

class MakeMsg
{
public:
    static CArchitectureMessage CreateQuitGameplay(EArchMsgTarget target)
    {
        return CArchitectureMessage(target, EArchMsgType::QuitGameplay, new CArchMsgParmNull());
    }
    static CArchitectureMessage CreateControllerStatus(EArchMsgTarget target, u16 a, bool b)
    {
        return CArchitectureMessage(target, EArchMsgType::ControllerStatus, new CArchMsgParmControllerStatus(a, b));
    }
    static const CArchMsgParmInt32& GetParmNewGameflowState(const CArchitectureMessage& msg)
    {
        return *msg.GetParm<CArchMsgParmInt32>();
    }
    static const CArchMsgParmUserInput& GetParmUserInput(const CArchitectureMessage& msg)
    {
        return *msg.GetParm<CArchMsgParmUserInput>();
    }
    static CArchitectureMessage CreateUserInput(EArchMsgTarget target, const CFinalInput& input)
    {
        return CArchitectureMessage(target, EArchMsgType::UserInput, new CArchMsgParmUserInput(input));
    }
    static const CArchMsgParmReal32& GetParmTimerTick(const CArchitectureMessage& msg)
    {
        return *msg.GetParm<CArchMsgParmReal32>();
    }
    static CArchitectureMessage CreateTimerTick(EArchMsgTarget target, float val)
    {
        return CArchitectureMessage(target, EArchMsgType::TimerTick, new CArchMsgParmReal32(val));
    }
    static const CArchMsgParmInt32Int32VoidPtr& GetParmChangeIOWinPriority(const CArchitectureMessage& msg)
    {
        return *msg.GetParm<CArchMsgParmInt32Int32VoidPtr>();
    }
    static const CArchMsgParmInt32Int32VoidPtr& GetParmCreateIOWin(const CArchitectureMessage& msg)
    {
        return *msg.GetParm<CArchMsgParmInt32Int32VoidPtr>();
    }
    static CArchitectureMessage CreateCreateIOWin(EArchMsgTarget target, int pmin, int pmax, CIOWin* iowin)
    {
        return CArchitectureMessage(target, EArchMsgType::CreateIOWin, new CArchMsgParmInt32Int32VoidPtr(pmin, pmax, iowin));
    }
    static const CArchMsgParmVoidPtr& GetParmDeleteIOWin(const CArchitectureMessage& msg)
    {
        return *msg.GetParm<CArchMsgParmVoidPtr>();
    }
    static CArchitectureMessage CreateFrameBegin(EArchMsgTarget target, int a)
    {
        return CArchitectureMessage(target, EArchMsgType::FrameBegin, new CArchMsgParmInt32(a));
    }
    /* URDE Messages */
    static CArchitectureMessage CreateApplicationExit(EArchMsgTarget target)
    {
        return CArchitectureMessage(target, EArchMsgType::ApplicationExit, new CArchMsgParmNull());
    }
};

}

#endif // __URDE_CARCHITECTUREMESSAGE_HPP__
