#ifndef __DNACOMMON_ITWEAKSLIDESHOW_HPP__
#define __DNACOMMON_ITWEAKSLIDESHOW_HPP__

#include "../DNACommon.hpp"

namespace DataSpec
{

struct ITweakSlideShow : BigYAML
{
    virtual const std::string& GetFont() const=0;
    virtual const zeus::CColor& GetFontColor() const=0;
    virtual const zeus::CColor& GetOutlineColor() const=0;
    virtual float GetX54() const=0;
};

}

#endif // __DNACOMMON_ITWEAKSLIDESHOW_HPP__
