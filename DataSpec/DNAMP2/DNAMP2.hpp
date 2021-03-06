#ifndef __DNAMP2_HPP__
#define __DNAMP2_HPP__

#include "../DNACommon/DNACommon.hpp"
#include "../DNAMP1/PAK.hpp"

namespace DataSpec
{
namespace DNAMP2
{

extern logvisor::Module Log;

/* MP2-specific, one-shot PAK traversal/extraction class */
class PAKBridge
{
    hecl::Database::Project& m_project;
    const nod::Node& m_node;
    DNAMP1::PAK m_pak;
public:
    bool m_doExtract;
    using Level = DataSpec::Level<UniqueID32>;
    std::unordered_map<UniqueID32, Level> m_levelDeps;
    hecl::SystemString m_levelString;

    PAKBridge(hecl::Database::Project& project,
              const nod::Node& node,
              bool doExtract=true);
    void build();
    static ResExtractor<PAKBridge> LookupExtractor(const DNAMP1::PAK& pak, const DNAMP1::PAK::Entry& entry);
    const std::string& getName() const {return m_node.getName();}
    const hecl::SystemString& getLevelString() const {return m_levelString;}

    using PAKType = DNAMP1::PAK;
    const PAKType& getPAK() const {return m_pak;}
    const nod::Node& getNode() const {return m_node;}

    void addCMDLRigPairs(PAKRouter<PAKBridge>& pakRouter,
            std::unordered_map<UniqueID32, std::pair<UniqueID32, UniqueID32>>& addTo,
            std::unordered_map<UniqueID32, std::pair<UniqueID32, std::string>>& cskrCinfToAncs) const;

    void addMAPATransforms(PAKRouter<PAKBridge>& pakRouter,
            std::unordered_map<UniqueID32, zeus::CMatrix4f>& addTo,
            std::unordered_map<UniqueID32, hecl::ProjectPath>& pathOverrides) const;
};

}
}

#endif // __DNAMP2_HPP__
