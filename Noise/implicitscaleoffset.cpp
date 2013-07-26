#include "implicitscaleoffset.h"

namespace anl
{
    CImplicitScaleOffset::CImplicitScaleOffset() : CImplicitModuleBase(), m_source(0.0), m_scale(1.0), m_offset(0.0){}
    CImplicitScaleOffset::CImplicitScaleOffset(double source, double scale, double offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(double source, double scale, std::shared_ptr<CImplicitModuleBase> offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(double source, std::shared_ptr<CImplicitModuleBase> scale, double offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(double source, std::shared_ptr<CImplicitModuleBase> scale, std::shared_ptr<CImplicitModuleBase> offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(std::shared_ptr<CImplicitModuleBase> source, double scale, double offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(std::shared_ptr<CImplicitModuleBase> source, double scale, std::shared_ptr<CImplicitModuleBase> offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(std::shared_ptr<CImplicitModuleBase> source, std::shared_ptr<CImplicitModuleBase> scale, double offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::CImplicitScaleOffset(std::shared_ptr<CImplicitModuleBase> source, std::shared_ptr<CImplicitModuleBase> scale, std::shared_ptr<CImplicitModuleBase> offset) : CImplicitModuleBase(), m_source(source), m_scale(scale), m_offset(offset){}
    CImplicitScaleOffset::~CImplicitScaleOffset(){}

    void CImplicitScaleOffset::setSource(std::shared_ptr<CImplicitModuleBase> b){m_source.set(b);}
    void CImplicitScaleOffset::setSource(double v){m_source.set(v);}

    void CImplicitScaleOffset::setScale(double scale)
    {
        m_scale.set(scale);
    }
    void CImplicitScaleOffset::setOffset(double offset)
    {
        m_offset.set(offset);
    }
    void CImplicitScaleOffset::setScale(std::shared_ptr<CImplicitModuleBase> scale)
    {
        m_scale.set(scale);
    }
    void CImplicitScaleOffset::setOffset(std::shared_ptr<CImplicitModuleBase> offset)
    {
        m_offset.set(offset);
    }

    double CImplicitScaleOffset::get(double x, double y)
    {

        return m_source.get(x,y)*m_scale.get(x,y)+m_offset.get(x,y);
    }

    double CImplicitScaleOffset::get(double x, double y, double z)
    {


        return m_source.get(x,y,z)*m_scale.get(x,y,z)+m_offset.get(x,y,z);
    }

    double CImplicitScaleOffset::get(double x, double y, double z, double w)
    {


        return m_source.get(x,y,z,w)*m_scale.get(x,y,z,w)+m_offset.get(x,y,z,w);
    }

    double CImplicitScaleOffset::get(double x, double y, double z, double w, double u, double v)
    {


        return m_source.get(x,y,z,w,u,v)*m_scale.get(x,y,z,w,u,v)+m_offset.get(x,y,z,w,u,v);
    }
};
