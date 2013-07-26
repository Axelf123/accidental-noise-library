#ifndef RGBABUFFERBLUR_H
#define RGBABUFFERBLUR_H
#include "rgbabufferbase.h"

namespace anl
{
    class CRGBABufferBlur : public CRGBABufferBase
    {
    public:
        CRGBABufferBlur();
        CRGBABufferBlur(std::shared_ptr<CRGBABufferBase> src, double blursize, bool seamless);
        ~CRGBABufferBlur();

        void setSource(std::shared_ptr<CRGBABufferBase> src);
        void setBlurSize(double blursize);
        void setSeamless(bool seamless);

        void get(CArray2Drgba &out);
    private:
        std::shared_ptr<CRGBABufferBase> m_source;
        double m_blursize;
        bool m_seamless;
    };
};

#endif
