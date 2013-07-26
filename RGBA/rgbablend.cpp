#include "rgbablend.h"

namespace anl
{
    CRGBABlend::CRGBABlend() : m_low(), m_high(), m_control(0.0){}

    CRGBABlend::CRGBABlend(double control, SRGBA low, SRGBA high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(double control, SRGBA low, std::shared_ptr<CRGBAModuleBase> high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(double control, std::shared_ptr<CRGBAModuleBase> low, SRGBA high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(double control, std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(std::shared_ptr<CImplicitModuleBase> control, SRGBA low, SRGBA high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(std::shared_ptr<CImplicitModuleBase> control, SRGBA low, std::shared_ptr<CRGBAModuleBase> high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CRGBAModuleBase> low, SRGBA high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}
    CRGBABlend::CRGBABlend(std::shared_ptr<CImplicitModuleBase> control, std::shared_ptr<CRGBAModuleBase> low, std::shared_ptr<CRGBAModuleBase> high) : CRGBAModuleBase(), m_low(low), m_high(high), m_control(control){}

    CRGBABlend::~CRGBABlend(){}

    void CRGBABlend::setLowSource(std::shared_ptr<CRGBAModuleBase> m)
    {
        m_low.set(m);
    }

    void CRGBABlend::setHighSource(std::shared_ptr<CRGBAModuleBase> m)
    {
        m_high.set(m);
    }

    void CRGBABlend::setLowSource(SRGBA c)
    {
        m_low.set(c);
    }

    void CRGBABlend::setHighSource(SRGBA c)
    {
        m_high.set(c);
    }

    void CRGBABlend::setControlSource(std::shared_ptr<CImplicitModuleBase> m)
    {
        m_control.set(m);
    }

    void CRGBABlend::setControlSource(double v)
    {
        m_control.set(v);
    }

    SRGBA CRGBABlend::get(double x, double y)
    {
        SRGBA low=m_low.get(x,y);
        SRGBA high=m_high.get(x,y);
        double control=m_control.get(x,y);

        return SRGBA(
            (float)(low[0]+control*(high[0]-low[0])),
            (float)(low[1]+control*(high[1]-low[1])),
            (float)(low[2]+control*(high[2]-low[2])),
            (float)(low[3]+control*(high[3]-low[3])));
    }

    SRGBA CRGBABlend::get(double x, double y, double z)
    {
        SRGBA low=m_low.get(x,y,z);
        SRGBA high=m_high.get(x,y,z);
        double control=m_control.get(x,y,z);

        return SRGBA(
            (float)(low[0]+control*(high[0]-low[0])),
            (float)(low[1]+control*(high[1]-low[1])),
            (float)(low[2]+control*(high[2]-low[2])),
            (float)(low[3]+control*(high[3]-low[3])));
    }

    SRGBA CRGBABlend::get(double x, double y, double z, double w)
    {
        SRGBA low=m_low.get(x,y,z,w);
        SRGBA high=m_high.get(x,y,z,w);
        double control=m_control.get(x,y,z,w);

        return SRGBA(
            (float)(low[0]+control*(high[0]-low[0])),
            (float)(low[1]+control*(high[1]-low[1])),
            (float)(low[2]+control*(high[2]-low[2])),
            (float)(low[3]+control*(high[3]-low[3])));
    }
    SRGBA CRGBABlend::get(double x, double y, double z, double w, double u, double v)
    {
        SRGBA low=m_low.get(x,y,z,w,u,v);
        SRGBA high=m_high.get(x,y,z,w,u,v);
        double control=m_control.get(x,y,z,w,u,v);

        return SRGBA(
            (float)(low[0]+control*(high[0]-low[0])),
            (float)(low[1]+control*(high[1]-low[1])),
            (float)(low[2]+control*(high[2]-low[2])),
            (float)(low[3]+control*(high[3]-low[3])));
    }
};