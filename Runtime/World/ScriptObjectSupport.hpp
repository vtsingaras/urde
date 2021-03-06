#ifndef __SCRIPT_OBJECT_SUPPORT_HPP__
#define __SCRIPT_OBJECT_SUPPORT_HPP__

namespace urde
{

enum class EScriptObjectType
{
    Actor = 0x00,
    Waypoint = 0x02,
    Door = 0x03,
    Trigger = 0x04,
    Timer = 0x05,
    Counter = 0x06,
    Effect = 0x07,
    Platform = 0x08,
    Sound = 0x09,
    Generator = 0x0A,
    Dock = 0x0B,
    Camera = 0x0C,
    CameraWaypoint = 0x0D,
    NewIntroBoss = 0x0E,
    SpawnPoint = 0x0F,
    CameraHint = 0x10,
    Pickup = 0x11,
    MemoryRelay = 0x13,
    RandomRelay = 0x14,
    Relay = 0x15,
    Beetle = 0x16,
    HUDMemo = 0x17,
    CameraFilterKeyframe = 0x18,
    CameraBlurKeyframe = 0x19,
    DamageableTrigger = 0x1A,
    Debris = 0x1B,
    CameraShaker = 0x1C,
    ActorKeyframe = 0x1D,
    Water = 0x20,
    Warwasp = 0x21,
    SpacePirate = 0x24,
    FlyingPirate = 0x25,
    ElitePirate = 0x26,
    MetroidBeta = 0x27,
    ChozoGhost = 0x28,
    CoverPoint = 0x2A,
    SpiderBallWaypoint = 0x2C,
    BloodFlower = 0x2D,
    FlickerBat = 0x2E,
    PathCamera = 0x2F,
    GrapplePoint = 0x30,
    PuddleSpore = 0x31,
    DebugCameraWaypoint = 0x32,
    SpiderBallAttractionSurface = 0x33,
    PuddleToadGamma = 0x34,
    DistanceFog = 0x35,
    FireFlea = 0x36,
    MetareeAlpha = 0x37,
    DockAreaChange = 0x38,
    ActorRotate = 0x39,
    SpecialFunction = 0x3A,
    SpankWeed = 0x3B,
    Parasite = 0x3D,
    PlayerHint = 0x3E,
    Ripper = 0x3F,
    PickupGenerator = 0x40,
    AIKeyframe = 0x41,
    PointOfInterest = 0x42,
    Drone = 0x43,
    MetroidAlpha = 0x44,
    DebrisExtended = 0x45,
    Steam = 0x46,
    Ripple = 0x47,
    BallTrigger = 0x48,
    TargetingPoint = 0x49,
    EMPulse = 0x4A,
    IceSheegoth = 0x4B,
    PlayerActor = 0x4C,
    Flaahgra = 0x4D,
    AreaAttributes = 0x4E,
    FishCloud = 0x4F,
    FishCloudModifier = 0x50,
    VisorFlare = 0x51,
    WorldTeleporter = 0x52,
    VisorGoo = 0x53,
    JellyZap = 0x54,
    ControllerAction = 0x55,
    Switch = 0x56,
    PlayerStateChange = 0x57,
    Thardus = 0x58,
    WallCrawlerSwarm = 0x5A,
    AIJumpPoint = 0x5B,
    FlaahgraTentacle = 0x5C,
    RoomAcoustics = 0x5D,
    ColorModulate = 0x5E,
    ThardusRockProjectile = 0x5F,
    Midi = 0x60,
    StreamedAudio = 0x61,
    WorldTeleporterToo = 0x62,
    Repulsor = 0x63,
    GunTurret = 0x64,
    FogVolume = 0x65,
    Babygoth = 0x66,
    Eyeball = 0x67,
    RadialDamage = 0x68,
    CameraPitchVolume = 0x69,
    EnvFxDensityController = 0x6A,
    Magdolite = 0x6B,
    TeamAIMgr = 0x6C,
    SnakeWeedSwarm = 0x6D,
    ActorContraption = 0x6E,
    Oculus = 0x6F,
    Geemer = 0x70,
    SpindleCamera = 0x71,
    AtomicAlpha = 0x72,
    CameraHintTrigger = 0x73,
    RumbleEffect = 0x74,
    AmbientAI = 0x75,
    AtomicBeta = 0x77,
    IceZoomer = 0x78,
    Puffer = 0x79,
    Tryclops = 0x7A,
    Ridley = 0x7B,
    Seedling = 0x7C,
    ThermalHeatFader = 0x7D,
    Burrower = 0x7F,
    ScriptBeam = 0x81,
    WorldLightFader = 0x82,
    MetroidPrimeStage2 = 0x83,
    MetroidPrimeStage1 = 0x84,
    MazeNode = 0x85,
    OmegaPirate = 0x86,
    PhazonPool = 0x87,
    PhazonHealingNodule = 0x88,
    NewCameraShaker = 0x89,
    ShadowProjector = 0x8A,
    EnergyBall = 0x8B,
    ScriptObjectTypeMAX
};

enum class EScriptObjectState
{
    Any = -1,
    Active,
    Arrived,
    Closed,
    Entered,
    Exited,
    Inactive,
    Inside,
    MaxReached,
    Open,
    Zero,
    Attack,
    UNKS1,
    Retreat,
    Patrol,
    Dead,
    CameraPath,
    CameraTarget,
    UNKS2,
    Play,
    UNKS3,
    DeathRattle,
    UNKS4,
    Damage,
    UNKS6,
    UNKS5,
    Modify,
    ScanStart,
    ScanProcessing,
    ScanDone,
    UNKS9,
    DFST,
    ReflectedDamage,
    InheritBounds
};

enum class EScriptObjectMessage
{
    None              = -1,
    UNKM1             = 0,
    Activate          = 1,
    UNKM2             = 2,
    Close             = 3,
    Deactivate        = 4,
    Decrement         = 5,
    Follow            = 6,
    Increment         = 7,
    Next              = 8,
    Open              = 9,
    Reset             = 10,
    ResetAndStart     = 11,
    SetToMax          = 12,
    SetToZero         = 13,
    Start             = 14,
    Stop              = 15,
    StopAndReset      = 16,
    ToggleActive      = 17,
    UNKM3             = 18,
    Action            = 19,
    Play              = 20,
    Alert             = 21,
    InternalMessage00 = 22,
    InternalMessage01 = 23,
    InternalMessage02 = 24,
    InternalMessage03 = 25,
    InternalMessage04 = 26,
    InternalMessage05 = 27,
    InternalMessage06 = 28,
    InternalMessage07 = 29,
    InternalMessage08 = 30,
    InternalMessage09 = 31,
    InternalMessage10 = 32,
    InternalMessage11 = 33,
    InternalMessage12 = 34,
    InternalMessage13 = 35,
    InternalMessage14 = 36,
    InternalMessage15 = 37,
    InternalMessage16 = 38,
    InternalMessage17 = 39,
    InternalMessage18 = 40,
};

}

#endif // __SCRIPT_OBJECT_SUPPORT_HPP__
