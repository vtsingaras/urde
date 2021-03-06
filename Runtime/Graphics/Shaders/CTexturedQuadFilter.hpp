#ifndef __URDE_CTEXTUREDQUADFILTER_HPP__
#define __URDE_CTEXTUREDQUADFILTER_HPP__

#include "TMultiBlendShader.hpp"
#include "zeus/CMatrix4f.hpp"
#include "zeus/CColor.hpp"
#include "zeus/CRectangle.hpp"
#include "Camera/CCameraFilter.hpp"
#include "CToken.hpp"

namespace urde
{

class CTexturedQuadFilter
{
    friend struct CTexturedQuadFilterGLDataBindingFactory;
    friend struct CTexturedQuadFilterVulkanDataBindingFactory;
    friend struct CTexturedQuadFilterMetalDataBindingFactory;
    friend struct CTexturedQuadFilterD3DDataBindingFactory;

protected:
    struct Vert
    {
        zeus::CVector2f m_pos;
        zeus::CVector2f m_uv;
    };

    struct Uniform
    {
        zeus::CMatrix4f m_matrix;
        zeus::CColor m_color;
        float m_uvScale;
    };
    TLockedToken<CTexture> m_tex;
    boo::ITexture* m_booTex;
    boo::GraphicsDataToken m_token;
    boo::IGraphicsBufferD* m_vbo;
    boo::IGraphicsBufferD* m_uniBuf;
    boo::IShaderDataBinding* m_dataBind = nullptr;
    Uniform m_uniform;

    CTexturedQuadFilter(boo::ITexture* tex);
public:
    static const zeus::CRectangle DefaultRect;
    CTexturedQuadFilter(CCameraFilterPass::EFilterType type, TLockedToken<CTexture> tex);
    CTexturedQuadFilter(CCameraFilterPass::EFilterType type, boo::ITexture* tex);
    void draw(const zeus::CColor& color, float uvScale, const zeus::CRectangle& rect=DefaultRect);
    void drawCropped(const zeus::CColor& color, float uvScale);
    const TLockedToken<CTexture>& GetTex() const { return m_tex; }

    using _CLS = CTexturedQuadFilter;
#include "TMultiBlendShaderDecl.hpp"
};

class CTexturedQuadFilterAlpha : public CTexturedQuadFilter
{
    friend struct CTexturedQuadFilterAlphaGLDataBindingFactory;
    friend struct CTexturedQuadFilterAlphaVulkanDataBindingFactory;
    friend struct CTexturedQuadFilterAlphaMetalDataBindingFactory;
    friend struct CTexturedQuadFilterAlphaD3DDataBindingFactory;

public:
    CTexturedQuadFilterAlpha(CCameraFilterPass::EFilterType type, TLockedToken<CTexture> tex);
    CTexturedQuadFilterAlpha(CCameraFilterPass::EFilterType type, boo::ITexture* tex);
    using _CLS = CTexturedQuadFilterAlpha;
#include "TMultiBlendShaderDecl.hpp"
};

}

#endif // __URDE_CTEXTUREDQUADFILTER_HPP__
