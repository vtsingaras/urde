#include "ANCS.hpp"

namespace DataSpec
{
namespace DNAMP2
{

void ANCS::CharacterSet::CharacterInfo::read(athena::io::IStreamReader& reader)
{
    idx = reader.readUint32Big();
    atUint16 sectionCount = reader.readUint16Big();
    name = reader.readString();
    cmdl.read(reader);
    cskr.read(reader);
    cinf.read(reader);

    atUint32 animationCount = reader.readUint32Big();
    reader.enumerate(animations, animationCount);

    pasDatabase.read(reader);

    atUint32 partCount = reader.readUint32Big();
    reader.enumerate(partResData.part, partCount);

    atUint32 swhcCount = reader.readUint32Big();
    reader.enumerate(partResData.swhc, swhcCount);

    atUint32 unkCount = reader.readUint32Big();
    reader.enumerate(partResData.unk, unkCount);

    atUint32 elscCount = reader.readUint32Big();
    reader.enumerate(partResData.elsc, elscCount);

    atUint32 spscCount = reader.readUint32Big();
    reader.enumerate(partResData.spsc, spscCount);

    atUint32 unkCount2 = reader.readUint32Big();
    if (unkCount2)
        abort();
    reader.enumerate(partResData.unk2, unkCount2);

    unk1 = reader.readUint32Big();

    animAABBs.clear();
    if (sectionCount > 1)
    {
        atUint32 aabbCount = reader.readUint32Big();
        reader.enumerate(animAABBs, aabbCount);
    }

    effects.clear();
    if (sectionCount > 2)
    {
        atUint32 effectCount = reader.readUint32Big();
        reader.enumerate(effects, effectCount);
    }

    if (sectionCount > 3)
    {
        cmdlOverlay.read(reader);
        cskrOverlay.read(reader);
    }

    animIdxs.clear();
    if (sectionCount > 4)
    {
        atUint32 aidxCount = reader.readUint32Big();
        reader.enumerateBig(animIdxs, aidxCount);
    }

    extents.clear();
    if (sectionCount > 9)
    {
        unk4 = reader.readUint32Big();
        unk5 = reader.readUByte();
        atUint32 extentsCount = reader.readUint32Big();
        reader.enumerate(extents, extentsCount);
    }
}

void ANCS::CharacterSet::CharacterInfo::write(athena::io::IStreamWriter& writer) const
{
    writer.writeUint32Big(idx);

    atUint16 sectionCount;
    if (unk4 || unk5 || extents.size())
        sectionCount = 10;
    else if (partResData.elsc.size())
        sectionCount = 6;
    else if (animIdxs.size())
        sectionCount = 5;
    else if (cmdlOverlay)
        sectionCount = 4;
    else if (effects.size())
        sectionCount = 3;
    else if (animAABBs.size())
        sectionCount = 2;
    else
        sectionCount = 1;
    writer.writeUint16Big(sectionCount);

    writer.writeString(name);
    cmdl.write(writer);
    cskr.write(writer);
    cinf.write(writer);

    writer.writeUint32Big(animations.size());
    writer.enumerate(animations);

    pasDatabase.write(writer);

    writer.writeUint32Big(partResData.part.size());
    writer.enumerate(partResData.part);

    writer.writeUint32Big(partResData.swhc.size());
    writer.enumerate(partResData.swhc);

    writer.writeUint32Big(partResData.unk.size());
    writer.enumerate(partResData.unk);

    writer.writeUint32Big(partResData.elsc.size());
    writer.enumerate(partResData.elsc);

    writer.writeUint32Big(partResData.spsc.size());
    writer.enumerate(partResData.spsc);

    writer.writeUint32Big(partResData.unk2.size());
    writer.enumerate(partResData.unk2);

    writer.writeUint32Big(unk1);

    if (sectionCount > 1)
    {
        writer.writeUint32Big(animAABBs.size());
        writer.enumerate(animAABBs);
    }

    if (sectionCount > 2)
    {
        writer.writeUint32Big(effects.size());
        writer.enumerate(effects);
    }

    if (sectionCount > 3)
    {
        cmdlOverlay.write(writer);
        cskrOverlay.write(writer);
    }

    if (sectionCount > 4)
    {
        writer.writeUint32Big(animIdxs.size());
        for (atUint32 idx : animIdxs)
            writer.writeUint32Big(idx);
    }

    if (sectionCount > 9)
    {
        writer.writeUint32Big(unk4);
        writer.writeUByte(unk5);
        writer.writeUint32Big(extents.size());
        writer.enumerate(extents);
    }
}

size_t ANCS::CharacterSet::CharacterInfo::binarySize(size_t __isz) const
{
    atUint16 sectionCount;
    if (unk4 || unk5 || extents.size())
        sectionCount = 10;
    else if (partResData.elsc.size())
        sectionCount = 6;
    else if (animIdxs.size())
        sectionCount = 5;
    else if (cmdlOverlay)
        sectionCount = 4;
    else if (effects.size())
        sectionCount = 3;
    else if (animAABBs.size())
        sectionCount = 2;
    else
        sectionCount = 1;

    __isz += 6;

    __isz += name.size() + 1;
    __isz += 12;

    __isz += 4;
    __isz = __EnumerateSize(__isz, animations);

    __isz = pasDatabase.binarySize(__isz);

    __isz += 4;
    __isz = __EnumerateSize(__isz, partResData.part);

    __isz += 4;
    __isz = __EnumerateSize(__isz, partResData.swhc);

    __isz += 4;
    __isz = __EnumerateSize(__isz, partResData.unk);

    __isz += 4;
    __isz = __EnumerateSize(__isz, partResData.elsc);

    __isz += 4;
    __isz = __EnumerateSize(__isz, partResData.spsc);

    __isz += 4;
    __isz = __EnumerateSize(__isz, partResData.unk2);

    __isz += 4;

    if (sectionCount > 1)
    {
        __isz += 4;
        __isz = __EnumerateSize(__isz, animAABBs);
    }

    if (sectionCount > 2)
    {
        __isz += 4;
        __isz = __EnumerateSize(__isz, effects);
    }

    if (sectionCount > 3)
        __isz += 8;

    if (sectionCount > 4)
        __isz += 4 + animIdxs.size() * 4;

    if (sectionCount > 9)
    {
        __isz += 9;
        __isz = __EnumerateSize(__isz, extents);
    }

    return __isz;
}

void ANCS::CharacterSet::CharacterInfo::read(athena::io::YAMLDocReader& reader)
{
    idx = reader.readUint32("idx");
    atUint16 sectionCount = reader.readUint16("sectionCount");
    name = reader.readString("name");

    reader.enumerate("animations", animations);

    reader.enumerate("pasDatabase", pasDatabase);

    reader.enumerate("part", partResData.part);

    reader.enumerate("swhc", partResData.swhc);

    reader.enumerate("unk", partResData.unk);

    reader.enumerate("elsc", partResData.elsc);

    reader.enumerate("spsc", partResData.spsc);

    reader.enumerate("unk2", partResData.unk2);

    unk1 = reader.readUint32("unk1");

    animAABBs.clear();
    if (sectionCount > 1)
    {
        reader.enumerate("part", animAABBs);
    }

    effects.clear();
    if (sectionCount > 2)
    {
        reader.enumerate("effects", effects);
    }

    if (sectionCount > 3)
    {
        reader.enumerate("cmdlOverlay", cmdlOverlay);
    }

    animIdxs.clear();
    if (sectionCount > 4)
    {
        reader.enumerate("animIdxs", animIdxs);
    }

    extents.clear();
    if (sectionCount > 9)
    {
        unk4 = reader.readUint32("unk4");
        unk5 = reader.readUByte("unk5");
        reader.enumerate("extents", extents);
    }
}

void ANCS::CharacterSet::CharacterInfo::write(athena::io::YAMLDocWriter& writer) const
{
    writer.writeUint32("idx", idx);

    atUint16 sectionCount;
    if (unk4 || unk5 || extents.size())
        sectionCount = 10;
    else if (partResData.elsc.size())
        sectionCount = 6;
    else if (animIdxs.size())
        sectionCount = 5;
    else if (cmdlOverlay)
        sectionCount = 4;
    else if (effects.size())
        sectionCount = 3;
    else if (animAABBs.size())
        sectionCount = 2;
    else
        sectionCount = 1;
    writer.writeUint16("sectionCount", sectionCount);

    writer.writeString("name", name);
    writer.enumerate("cmdl", cmdl);

    writer.enumerate("animations", animations);

    writer.enumerate("pasDatabase", pasDatabase);

    writer.enumerate("part", partResData.part);

    writer.enumerate("swhc", partResData.swhc);

    writer.enumerate("unk", partResData.unk);

    writer.enumerate("elsc", partResData.elsc);

    writer.enumerate("spsc", partResData.spsc);

    writer.enumerate("unk2", partResData.unk2);

    writer.writeUint32("unk1", unk1);

    if (sectionCount > 1)
    {
        writer.enumerate("animAABBs", animAABBs);
    }

    if (sectionCount > 2)
    {
        writer.enumerate("effects", effects);
    }

    if (sectionCount > 3)
    {
        writer.enumerate("cmdlOverlay", cmdlOverlay);
    }

    if (sectionCount > 4)
    {
        writer.enumerate("animIdxs", animIdxs);
    }

    if (sectionCount > 9)
    {
        writer.writeUint32("unk4", unk4);
        writer.writeUByte("unk5", unk5);
        writer.enumerate("extents", extents);
    }
}

const char* ANCS::CharacterSet::CharacterInfo::DNAType()
{
    return "urde::DNAMP2::ANCS::CharacterSet::CharacterInfo";
}

void ANCS::AnimationSet::read(athena::io::IStreamReader& reader)
{
    atUint16 sectionCount = reader.readUint16Big();

    atUint32 animationCount = reader.readUint32Big();
    reader.enumerate(animations, animationCount);

    atUint32 transitionCount = reader.readUint32Big();
    reader.enumerate(transitions, transitionCount);
    defaultTransition.read(reader);

    additiveAnims.clear();
    if (sectionCount > 1)
    {
        atUint32 additiveAnimCount = reader.readUint32Big();
        reader.enumerate(additiveAnims, additiveAnimCount);
        floatA = reader.readFloatBig();
        floatB = reader.readFloatBig();
    }

    halfTransitions.clear();
    if (sectionCount > 2)
    {
        atUint32 halfTransitionCount = reader.readUint32Big();
        reader.enumerate(halfTransitions, halfTransitionCount);
    }

    evnts.clear();
    if (sectionCount > 3)
    {
        atUint32 evntsCount = reader.readUint32Big();
        reader.enumerate(evnts, evntsCount);
    }
}

void ANCS::AnimationSet::write(athena::io::IStreamWriter& writer) const
{
    atUint16 sectionCount;
    if (evnts.size())
        sectionCount = 4;
    else if (halfTransitions.size())
        sectionCount = 3;
    else if (additiveAnims.size())
        sectionCount = 2;
    else
        sectionCount = 1;

    writer.writeUint16Big(sectionCount);

    writer.writeUint32Big(animations.size());
    writer.enumerate(animations);

    writer.writeUint32Big(transitions.size());
    writer.enumerate(transitions);
    defaultTransition.write(writer);

    if (sectionCount > 1)
    {
        writer.writeUint32Big(additiveAnims.size());
        writer.enumerate(additiveAnims);
        writer.writeFloatBig(floatA);
        writer.writeFloatBig(floatB);
    }

    if (sectionCount > 2)
    {
        writer.writeUint32Big(halfTransitions.size());
        writer.enumerate(halfTransitions);
    }

    if (sectionCount > 3)
    {
        writer.writeUint32Big(evnts.size());
        writer.enumerate(evnts);
    }
}

size_t ANCS::AnimationSet::binarySize(size_t __isz) const
{
    atUint16 sectionCount;
    if (evnts.size())
        sectionCount = 4;
    else if (halfTransitions.size())
        sectionCount = 3;
    else if (additiveAnims.size())
        sectionCount = 2;
    else
        sectionCount = 1;

    __isz += 6;
    __isz = __EnumerateSize(__isz, animations);

    __isz += 4;
    __isz = __EnumerateSize(__isz, transitions);
    __isz = defaultTransition.binarySize(__isz);

    if (sectionCount > 1)
    {
        __isz += 4;
        __isz = __EnumerateSize(__isz, additiveAnims);
        __isz += 8;
    }

    if (sectionCount > 2)
    {
        __isz += 4;
        __isz = __EnumerateSize(__isz, halfTransitions);
    }

    if (sectionCount > 3)
    {
        __isz += 4;
        __isz = __EnumerateSize(__isz, evnts);
    }

    return __isz;
}

void ANCS::AnimationSet::read(athena::io::YAMLDocReader& reader)
{
    atUint16 sectionCount = reader.readUint16("sectionCount");

    reader.enumerate("animations", animations);

    reader.enumerate("transitions", transitions);
    reader.enumerate("defaultTransition", defaultTransition);

    additiveAnims.clear();
    if (sectionCount > 1)
    {
        reader.enumerate("additiveAnims", additiveAnims);
        floatA = reader.readFloat("floatA");
        floatB = reader.readFloat("floatB");
    }

    halfTransitions.clear();
    if (sectionCount > 2)
    {
        reader.enumerate("halfTransitions", halfTransitions);
    }

    evnts.clear();
    if (sectionCount > 3)
    {
        reader.enumerate("evnts", evnts);
    }
}

void ANCS::AnimationSet::write(athena::io::YAMLDocWriter& writer) const
{
    atUint16 sectionCount;
    if (evnts.size())
        sectionCount = 4;
    else if (halfTransitions.size())
        sectionCount = 3;
    else if (additiveAnims.size())
        sectionCount = 2;
    else
        sectionCount = 1;

    writer.writeUint16("sectionCount", sectionCount);

    writer.enumerate("animations", animations);

    writer.enumerate("transitions", transitions);
    writer.enumerate("defaultTransition", defaultTransition);

    if (sectionCount > 1)
    {
        writer.enumerate("additiveAnims", additiveAnims);
        writer.writeFloat("floatA", floatA);
        writer.writeFloat("floatB", floatB);
    }

    if (sectionCount > 2)
    {
        writer.enumerate("halfTransitions", halfTransitions);
    }

    if (sectionCount > 3)
    {
        writer.enumerate("evnts", evnts);
    }
}

const char* ANCS::AnimationSet::DNAType()
{
    return "urde::DNAMP2::ANCS::AnimationSet";
}

void ANCS::AnimationSet::EVNT::read(athena::io::IStreamReader& reader)
{
    version = reader.readUint32Big();

    atUint32 loopCount = reader.readUint32Big();
    reader.enumerate(loopEvents, loopCount);

    uevtEvents.clear();
    if (version == 2)
    {
        atUint32 uevtCount = reader.readUint32Big();
        reader.enumerate(uevtEvents, uevtCount);
    }

    atUint32 effectCount = reader.readUint32Big();
    reader.enumerate(effectEvents, effectCount);

    atUint32 sfxCount = reader.readUint32Big();
    reader.enumerate(sfxEvents, sfxCount);
}

void ANCS::AnimationSet::EVNT::write(athena::io::IStreamWriter& writer) const
{
    writer.writeUint32Big(version);

    writer.writeUint32Big(loopEvents.size());
    writer.enumerate(loopEvents);

    if (version == 2)
    {
        writer.writeUint32Big(uevtEvents.size());
        writer.enumerate(uevtEvents);
    }

    writer.writeUint32Big(effectEvents.size());
    writer.enumerate(effectEvents);

    writer.writeUint32Big(sfxEvents.size());
    writer.enumerate(sfxEvents);
}

size_t ANCS::AnimationSet::EVNT::binarySize(size_t __isz) const
{
    __isz += 4;

    __isz += 4;
    __isz = __EnumerateSize(__isz, loopEvents);

    if (version == 2)
    {
        __isz += 4;
        __isz = __EnumerateSize(__isz, uevtEvents);
    }

    __isz += 4;
    __isz = __EnumerateSize(__isz, effectEvents);

    __isz += 4;
    __isz = __EnumerateSize(__isz, sfxEvents);

    return __isz;
}

void ANCS::AnimationSet::EVNT::read(athena::io::YAMLDocReader& reader)
{
    version = reader.readUint32("version");

    reader.enumerate("loopEvents", loopEvents);

    uevtEvents.clear();
    if (version == 2)
    {
        reader.enumerate("uevtEvents", uevtEvents);
    }

    reader.enumerate("effectEvents", effectEvents);

    reader.enumerate("sfxEvents", sfxEvents);
}

void ANCS::AnimationSet::EVNT::write(athena::io::YAMLDocWriter& writer) const
{
    writer.writeUint32("version", version);

    writer.enumerate("loopEvents", loopEvents);

    if (version == 2)
    {
        writer.enumerate("uevtEvents", uevtEvents);
    }

    writer.enumerate("effectEvents", effectEvents);

    writer.enumerate("sfxEvents", sfxEvents);
}

const char* ANCS::AnimationSet::EVNT::DNAType()
{
    return "urde::DNAMP2::ANCS::AnimationSet::EVNT";
}

}
}
