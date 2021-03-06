#include "WPSC.hpp"

namespace DataSpec
{
namespace DNAParticle
{

template <class IDType>
void WPSM<IDType>::read(athena::io::YAMLDocReader& r)
{
    for (const auto& elem : r.getCurNode()->m_mapChildren)
    {
        if (elem.first.size() < 4)
        {
            LogModule.report(logvisor::Warning, "short FourCC in element '%s'", elem.first.c_str());
            continue;
        }

        r.enterSubRecord(elem.first.c_str());

        switch (*reinterpret_cast<const uint32_t*>(elem.first.data()))
        {
        case SBIG('IORN'):
            x0_IORN.read(r);
        break;
        case SBIG('IVEC'):
            x4_IVEC.read(r);
        break;
        case SBIG('PSOV'):
            x8_PSOV.read(r);
        break;
        case SBIG('PSVM'):
            xc_PSVM.read(r);
        break;
        case SBIG('VMD2'):
            x10_VMD2.read(r);
        break;
        case SBIG('PSLT'):
            x14_PSLT.read(r);
        break;
        case SBIG('PSCL'):
            x18_PSCL.read(r);
        break;
        case SBIG('PCOL'):
            x1c_PCOL.read(r);
        break;
        case SBIG('POFS'):
            x20_POFS.read(r);
        break;
        case SBIG('OFST'):
            x24_OFST.read(r);
        break;
        case SBIG('APSO'):
            x28_APSO.read(r);
        break;
        case SBIG('HOMG'):
            x29_HOMG.read(r);
        break;
        case SBIG('AP11'):
            x2a_AP11.read(r);
        break;
        case SBIG('AP21'):
            x2b_AP21.read(r);
        break;
        case SBIG('AS11'):
            x2c_AS11.read(r);
        break;
        case SBIG('AS12'):
            x2d_AS12.read(r);
        break;
        case SBIG('AS13'):
            x2e_AS13.read(r);
        break;
        case SBIG('TRAT'):
            x30_TRAT.read(r);
        break;
        case SBIG('APSM'):
            x34_APSM.read(r);
        break;
        case SBIG('APS2'):
            x44_APS2.read(r);
        break;
        case SBIG('ASW1'):
            x54_ASW1.read(r);
        break;
        case SBIG('ASW2'):
            x64_ASW2.read(r);
        break;
        case SBIG('ASW3'):
            x74_ASW3.read(r);
        break;
        case SBIG('OHEF'):
            x84_OHEF.read(r);
        break;
        case SBIG('COLR'):
            x94_COLR.read(r);
        break;
        case SBIG('EWTR'):
            xa4_EWTR.read(r);
        break;
        case SBIG('LWTR'):
            xa5_LWTR.read(r);
        break;
        case SBIG('SWTR'):
            xa6_SWTR.read(r);
        break;
        case SBIG('PJFX'):
            xa8_PJFX = r.readUint32(nullptr);
        break;
        case SBIG('RNGE'):
            xac_RNGE.read(r);
        break;
        case SBIG('FOFF'):
            xb0_FOFF.read(r);
        break;
        case SBIG('FC60'):
            xunk_FC60.read(r);
        break;
        case SBIG('SPS1'):
            xunk_SPS2.read(r);
        break;
        case SBIG('SPS2'):
            xunk_SPS2.read(r);
        break;
        }

        r.leaveSubRecord();
    }
}

template <class IDType>
void WPSM<IDType>::write(athena::io::YAMLDocWriter& w) const
{
    if (x0_IORN)
    {
        w.enterSubRecord("IORN");
        x0_IORN.write(w);
        w.leaveSubRecord();
    }
    if (x4_IVEC)
    {
        w.enterSubRecord("IVEC");
        x4_IVEC.write(w);
        w.leaveSubRecord();
    }
    if (x8_PSOV)
    {
        w.enterSubRecord("PSOV");
        x8_PSOV.write(w);
        w.leaveSubRecord();
    }
    if (xc_PSVM)
    {
        w.enterSubRecord("PSVM");
        xc_PSVM.write(w);
        w.leaveSubRecord();
    }
    if (x10_VMD2)
    {
        w.enterSubRecord("VMD2");
        x10_VMD2.write(w);
        w.leaveSubRecord();
    }
    if (x14_PSLT)
    {
        w.enterSubRecord("PSLT");
        x14_PSLT.write(w);
        w.leaveSubRecord();
    }
    if (x18_PSCL)
    {
        w.enterSubRecord("PSCL");
        x18_PSCL.write(w);
        w.leaveSubRecord();
    }
    if (x1c_PCOL)
    {
        w.enterSubRecord("PCOL");
        x1c_PCOL.write(w);
        w.leaveSubRecord();
    }
    if (x20_POFS)
    {
        w.enterSubRecord("POFS");
        x20_POFS.write(w);
        w.leaveSubRecord();
    }
    if (x24_OFST)
    {
        w.enterSubRecord("OFST");
        x24_OFST.write(w);
        w.leaveSubRecord();
    }
    if (x28_APSO)
    {
        w.enterSubRecord("APSO");
        x28_APSO.write(w);
        w.leaveSubRecord();
    }
    if (x29_HOMG)
    {
        w.enterSubRecord("HOMG");
        x29_HOMG.write(w);
        w.leaveSubRecord();
    }
    if (x2a_AP11)
    {
        w.enterSubRecord("AP11");
        x2a_AP11.write(w);
        w.leaveSubRecord();
    }
    if (x2b_AP21)
    {
        w.enterSubRecord("AP21");
        x2b_AP21.write(w);
        w.leaveSubRecord();
    }
    if (x2c_AS11)
    {
        w.enterSubRecord("AS11");
        x2c_AS11.write(w);
        w.leaveSubRecord();
    }
    if (x2d_AS12)
    {
        w.enterSubRecord("AS12");
        x2d_AS12.write(w);
        w.leaveSubRecord();
    }
    if (x2e_AS13)
    {
        w.enterSubRecord("AS13");
        x2e_AS13.write(w);
        w.leaveSubRecord();
    }
    if (x30_TRAT)
    {
        w.enterSubRecord("TRAT");
        x30_TRAT.write(w);
        w.leaveSubRecord();
    }
    if (x34_APSM)
    {
        w.enterSubRecord("APSM");
        x34_APSM.write(w);
        w.leaveSubRecord();
    }
    if (x44_APS2)
    {
        w.enterSubRecord("APS2");
        x44_APS2.write(w);
        w.leaveSubRecord();
    }
    if (x54_ASW1)
    {
        w.enterSubRecord("ASW1");
        x54_ASW1.write(w);
        w.leaveSubRecord();
    }
    if (x64_ASW2)
    {
        w.enterSubRecord("ASW2");
        x64_ASW2.write(w);
        w.leaveSubRecord();
    }
    if (x74_ASW3)
    {
        w.enterSubRecord("ASW3");
        x74_ASW3.write(w);
        w.leaveSubRecord();
    }
    if (x84_OHEF)
    {
        w.enterSubRecord("OHEF");
        x84_OHEF.write(w);
        w.leaveSubRecord();
    }
    if (x94_COLR)
    {
        w.enterSubRecord("COLR");
        x94_COLR.write(w);
        w.leaveSubRecord();
    }
    if (!xa4_EWTR)
    {
        w.enterSubRecord("EWTR");
        xa4_EWTR.write(w);
        w.leaveSubRecord();
    }
    if (!xa5_LWTR)
    {
        w.enterSubRecord("LWTR");
        xa5_LWTR.write(w);
        w.leaveSubRecord();
    }
    if (!xa6_SWTR)
    {
        w.enterSubRecord("SWTR");
        xa6_SWTR.write(w);
        w.leaveSubRecord();
    }
    if (xa8_PJFX != ~0)
        w.writeUint32("PJFX", xa8_PJFX);
    if (xac_RNGE)
    {
        w.enterSubRecord("RNGE");
        xac_RNGE.write(w);
        w.leaveSubRecord();
    }
    if (xb0_FOFF)
    {
        w.enterSubRecord("FOFF");
        xb0_FOFF.write(w);
        w.leaveSubRecord();
    }
    if (xunk_FC60)
    {
        w.enterSubRecord("FC60");
        xunk_FC60.write(w);
        w.leaveSubRecord();
    }
    if (xunk_SPS1)
    {
        w.enterSubRecord("SPS1");
        xunk_SPS1.write(w);
        w.leaveSubRecord();
    }
    if (xunk_SPS1)
    {
        w.enterSubRecord("SPS2");
        xunk_SPS2.write(w);
        w.leaveSubRecord();
    }
}

template <class IDType>
size_t WPSM<IDType>::binarySize(size_t __isz) const
{
    __isz += 4;
    if (x0_IORN)
        __isz = x0_IORN.binarySize(__isz + 4);
    if (x4_IVEC)
        __isz = x4_IVEC.binarySize(__isz + 4);
    if (x8_PSOV)
        __isz = x8_PSOV.binarySize(__isz + 4);
    if (xc_PSVM)
        __isz = xc_PSVM.binarySize(__isz + 4);
    if (x10_VMD2)
        __isz = x10_VMD2.binarySize(__isz + 4);
    if (x14_PSLT)
        __isz = x14_PSLT.binarySize(__isz + 4);
    if (x18_PSCL)
        __isz = x18_PSCL.binarySize(__isz + 4);
    if (x1c_PCOL)
        __isz = x1c_PCOL.binarySize(__isz + 4);
    if (x20_POFS)
        __isz = x20_POFS.binarySize(__isz + 4);
    if (x24_OFST)
        __isz = x24_OFST.binarySize(__isz + 4);
    if (x28_APSO)
        __isz = x28_APSO.binarySize(__isz + 4);
    if (x29_HOMG)
        __isz = x29_HOMG.binarySize(__isz + 4);
    if (x2a_AP11)
        __isz = x2a_AP11.binarySize(__isz + 4);
    if (x2b_AP21)
        __isz = x2b_AP21.binarySize(__isz + 4);
    if (x2c_AS11)
        __isz = x2c_AS11.binarySize(__isz + 4);
    if (x2d_AS12)
        __isz = x2d_AS12.binarySize(__isz + 4);
    if (x2e_AS13)
        __isz = x2e_AS13.binarySize(__isz + 4);
    if (x30_TRAT)
        __isz = x30_TRAT.binarySize(__isz + 4);
    if (x34_APSM)
        __isz = x34_APSM.binarySize(__isz + 4);
    if (x44_APS2)
        __isz = x44_APS2.binarySize(__isz + 4);
    if (x54_ASW1)
        __isz = x54_ASW1.binarySize(__isz + 4);
    if (x64_ASW2)
        __isz = x64_ASW2.binarySize(__isz + 4);
    if (x74_ASW3)
        __isz = x74_ASW3.binarySize(__isz + 4);
    if (x84_OHEF)
        __isz = x84_OHEF.binarySize(__isz + 4);
    if (x94_COLR)
        __isz = x94_COLR.binarySize(__isz + 4);
    if (!xa4_EWTR)
        __isz = xa4_EWTR.binarySize(__isz + 4);
    if (!xa5_LWTR)
        __isz = xa5_LWTR.binarySize(__isz + 4);
    if (!xa6_SWTR)
        __isz = xa6_SWTR.binarySize(__isz + 4);
    if (xa8_PJFX != ~0)
        __isz += 12;
    if (xac_RNGE)
        __isz = xac_RNGE.binarySize(__isz + 4);
    if (xb0_FOFF)
        __isz = xb0_FOFF.binarySize(__isz + 4);
    if (xunk_FC60)
        __isz = xunk_FC60.binarySize(__isz + 4);
    if (xunk_SPS1)
        __isz = xunk_SPS1.binarySize(__isz + 4);
    if (xunk_SPS2)
        __isz = xunk_SPS2.binarySize(__isz + 4);
    return __isz;
}

template <class IDType>
void WPSM<IDType>::read(athena::io::IStreamReader& r)
{
    uint32_t clsId;
    r.readBytesToBuf(&clsId, 4);
    if (clsId != SBIG('WPSM'))
    {
        LogModule.report(logvisor::Warning, "non WPSM provided to WPSM parser");
        return;
    }
    r.readBytesToBuf(&clsId, 4);
    while (clsId != SBIG('_END'))
    {
        switch(clsId)
        {
        case SBIG('IORN'):
            x0_IORN.read(r);
        break;
        case SBIG('IVEC'):
            x4_IVEC.read(r);
        break;
        case SBIG('PSOV'):
            x8_PSOV.read(r);
        break;
        case SBIG('PSVM'):
            xc_PSVM.read(r);
        break;
        case SBIG('VMD2'):
            x10_VMD2.read(r);
        break;
        case SBIG('PSLT'):
            x14_PSLT.read(r);
        break;
        case SBIG('PSCL'):
            x18_PSCL.read(r);
        break;
        case SBIG('PCOL'):
            x1c_PCOL.read(r);
        break;
        case SBIG('POFS'):
            x20_POFS.read(r);
        break;
        case SBIG('OFST'):
            x24_OFST.read(r);
        break;
        case SBIG('APSO'):
            r.readUint32();
            x28_APSO = r.readBool();
        break;
        case SBIG('HOMG'):
            x29_HOMG.read(r);
        break;
        case SBIG('AP11'):
            x2a_AP11.read(r);
        break;
        case SBIG('AP21'):
            x2b_AP21.read(r);
        break;
        case SBIG('AS11'):
            x2c_AS11.read(r);
        break;
        case SBIG('AS12'):
            x2d_AS12.read(r);
        break;
        case SBIG('AS13'):
            x2e_AS13.read(r);
        break;
        case SBIG('TRAT'):
            x30_TRAT.read(r);
        break;
        case SBIG('APSM'):
            x34_APSM.read(r);
        break;
        case SBIG('APS2'):
            x44_APS2.read(r);
        break;
        case SBIG('ASW1'):
            x54_ASW1.read(r);
        break;
        case SBIG('ASW2'):
            x64_ASW2.read(r);
        break;
        case SBIG('ASW3'):
            x74_ASW3.read(r);
        break;
        case SBIG('OHEF'):
            x84_OHEF.read(r);
        break;
        case SBIG('COLR'):
            x94_COLR.read(r);
        break;
        case SBIG('EWTR'):
            r.readUint32();
            xa4_EWTR = r.readBool();
        break;
        case SBIG('LWTR'):
            r.readUint32();
            xa5_LWTR = r.readBool();
        break;
        case SBIG('SWTR'):
            r.readUint32();
            xa6_SWTR = r.readBool();
        break;
        case SBIG('PJFX'):
        {
            uint32_t fcc;
            r.readBytesToBuf(&fcc, 4);
            if (fcc != SBIG('NONE'))
                xa8_PJFX = r.readUint32Big();
        }
        break;
        case SBIG('RNGE'):
            xac_RNGE.read(r);
        break;
        case SBIG('FOFF'):
            xb0_FOFF.read(r);
        break;
        case SBIG('FC60'):
            xunk_FC60.read(r);
        break;
        case SBIG('SPS1'):
            xunk_SPS1.read(r);
        break;
        case SBIG('SPS2'):
            xunk_SPS2.read(r);
        break;
        default:
            LogModule.report(logvisor::Fatal, "Unknown WPSM class %.4s @%" PRIi64, &clsId, r.position());
        break;
        }
        r.readBytesToBuf(&clsId, 4);
    }
}

template <class IDType>
void WPSM<IDType>::write(athena::io::IStreamWriter &w) const
{
    if (x0_IORN)
    {
        w.writeBytes("IORN", 4);
        x0_IORN.write(w);
    }
    if (x4_IVEC)
    {
        w.writeBytes("IVEC", 4);
        x4_IVEC.write(w);
    }
    if (x8_PSOV)
    {
        w.writeBytes("PSOV", 4);
        x8_PSOV.write(w);
    }
    if (xc_PSVM)
    {
        w.writeBytes("PSVM", 4);
        xc_PSVM.write(w);
    }
    if (x10_VMD2)
    {
        w.writeBytes("VMD2", 4);
        x10_VMD2.write(w);
    }
    if (x14_PSLT)
    {
        w.writeBytes("PSLT", 4);
        x14_PSLT.write(w);
    }
    if (x18_PSCL)
    {
        w.writeBytes("PSCL", 4);
        x18_PSCL.write(w);
    }
    if (x1c_PCOL)
    {
        w.writeBytes("PCOL", 4);
        x1c_PCOL.write(w);
    }
    if (x20_POFS)
    {
        w.writeBytes("POFS", 4);
        x20_POFS.write(w);
    }
    if (x24_OFST)
    {
        w.writeBytes("OFST", 4);
        x24_OFST.write(w);
    }
    if (x28_APSO)
    {
        w.writeBytes("APSO", 4);
        x28_APSO.write(w);
    }
    if (x29_HOMG)
    {
        w.writeBytes("HOMG", 4);
        x29_HOMG.write(w);
    }
    if (x2a_AP11)
    {
        w.writeBytes("AP11", 4);
        x2a_AP11.write(w);
    }
    if (x2b_AP21)
    {
        w.writeBytes("AP21", 4);
        x2b_AP21.write(w);
    }
    if (x2c_AS11)
    {
        w.writeBytes("AS11", 4);
        x2c_AS11.write(w);
    }
    if (x2d_AS12)
    {
        w.writeBytes("AS12", 4);
        x2d_AS12.write(w);
    }
    if (x2e_AS13)
    {
        w.writeBytes("AS13", 4);
        x2e_AS13.write(w);
    }
    if (x30_TRAT)
    {
        w.writeBytes("TRAT", 4);
        x30_TRAT.write(w);
    }
    if (x34_APSM)
    {
        w.writeBytes("APSM", 4);
        x34_APSM.write(w);
    }
    if (x44_APS2)
    {
        w.writeBytes("APS2", 4);
        x44_APS2.write(w);
    }
    if (x54_ASW1)
    {
        w.writeBytes("ASW1", 4);
        x54_ASW1.write(w);
    }
    if (x64_ASW2)
    {
        w.writeBytes("ASW2", 4);
        x64_ASW2.write(w);
    }
    if (x74_ASW3)
    {
        w.writeBytes("ASW3", 4);
        x74_ASW3.write(w);
    }
    if (x84_OHEF)
    {
        w.writeBytes("OHEF", 4);
        x84_OHEF.write(w);
    }
    if (x94_COLR)
    {
        w.writeBytes("COLR", 4);
        x94_COLR.write(w);
    }
    if (!xa4_EWTR)
    {
        w.writeBytes("EWTR", 4);
        xa4_EWTR.write(w);
    }
    if (!xa5_LWTR)
    {
        w.writeBytes("LWTR", 4);
        xa5_LWTR.write(w);
    }
    if (!xa6_SWTR)
    {
        w.writeBytes("SWTR", 4);
        xa6_SWTR.write(w);
    }
    if (xa8_PJFX != ~0)
    {
        w.writeBytes("PJFXCNST", 8);
        w.writeUint32(xa8_PJFX);
    }
    if (xac_RNGE)
    {
        w.writeBytes("RNGE", 4);
        xac_RNGE.write(w);
    }
    if (xb0_FOFF)
    {
        w.writeBytes("FOFF", 4);
        xb0_FOFF.write(w);
    }
    if (xunk_FC60)
    {
        w.writeBytes("FC60", 4);
        xunk_FC60.write(w);
    }
    if (xunk_SPS1)
    {
        w.writeBytes("SPS1", 4);
        xunk_SPS1.write(w);
    }
    if (xunk_SPS2)
    {
        w.writeBytes("SPS2", 4);
        xunk_SPS2.write(w);
    }

    w.writeBytes("_END", 4);
}

template <class IDType>
void WPSM<IDType>::gatherDependencies(std::vector<hecl::ProjectPath>& pathsOut) const
{
    g_curSpec->flattenDependencies(x34_APSM.id, pathsOut);
    g_curSpec->flattenDependencies(x44_APS2.id, pathsOut);
    g_curSpec->flattenDependencies(x54_ASW1.id, pathsOut);
    g_curSpec->flattenDependencies(x64_ASW2.id, pathsOut);
    g_curSpec->flattenDependencies(x74_ASW3.id, pathsOut);
    g_curSpec->flattenDependencies(x84_OHEF.id, pathsOut);
    g_curSpec->flattenDependencies(x94_COLR.id, pathsOut);
}

template struct WPSM<UniqueID32>;
template struct WPSM<UniqueID64>;

template <class IDType>
bool ExtractWPSM(PAKEntryReadStream& rs, const hecl::ProjectPath& outPath)
{
    athena::io::FileWriter writer(outPath.getAbsolutePath());
    if (writer.isOpen())
    {
        WPSM<IDType> wpsm;
        wpsm.read(rs);
        wpsm.toYAMLStream(writer);
        return true;
    }
    return false;
}
template bool ExtractWPSM<UniqueID32>(PAKEntryReadStream& rs, const hecl::ProjectPath& outPath);
template bool ExtractWPSM<UniqueID64>(PAKEntryReadStream& rs, const hecl::ProjectPath& outPath);

template <class IDType>
bool WriteWPSM(const WPSM<IDType>& wpsm, const hecl::ProjectPath& outPath)
{
    athena::io::FileWriter w(outPath.getAbsolutePath(), true, false);
    if (w.hasError())
        return false;
    wpsm.write(w);
    int64_t rem = w.position() % 32;
    if (rem)
        for (int64_t i=0 ; i<32-rem ; ++i)
            w.writeBytes((atInt8*)"\xff", 1);
    return true;
}
template bool WriteWPSM<UniqueID32>(const WPSM<UniqueID32>& wpsm, const hecl::ProjectPath& outPath);
template bool WriteWPSM<UniqueID64>(const WPSM<UniqueID64>& wpsm, const hecl::ProjectPath& outPath);

}
}
