/**----------------------------------------------------------------------------
* FXUI SDK
* FXUI: Graphical User Interface Framework:
*
* Version 0.1       Date :
*
*------------------------------------------------------------------------------
* MIT
* © 2025, , All Rights Reserved
*------------------------------------------------------------------------------
**/

#ifndef     __FXCOLOR_H__
#define     __FXCOLOR_H__

#include <gui/support/fxguitypes.h>
//#include <base/common/fxplatformexport.h>

/**
 * Structure for represent RGB color with three components
**/

//#define dll_export   __declspec( dllexport )

//#define dll_export FXUI_EXPORT

namespace FX
{
    struct FX_GUI_API_EXPORT FXColor
    {
        unsigned red,green,blue,alpha;
        inline FXColor&
        SetTo(unsigned r, unsigned g, unsigned b, unsigned a)
        {
            this->red = r;
            this->green = g;
            this->blue = b;
            this->alpha = a;
            return *this;
        }

        inline FXColor&
        operator () (unsigned red, unsigned green, unsigned blue, unsigned alpha)
        {
            this->red   = red;
            this->green = green;
            this->blue  = blue;
            this->alpha = alpha;
            return *this;
        }

        inline FXColor&
        operator=(const FXColor& other)
        {
            return SetTo(other.red, other.green, other.blue, other.alpha);
        }

        inline FXColor&
        operator ~ ()
        {
            //FXColor c;
            this->red   = ~red;
            this->green = ~green;
            this->blue  = ~blue;
            this->alpha = ~alpha;
            return *this;
        }

        inline bool
        operator != (const FXColor &other) const
        {
            return (red != other.red || green != other.green || blue  != other.blue);
        }

        inline bool
        operator == (const FXColor &other) const
        {
            return (red == other.red && green == other.green && blue  == other.blue);
        }
    };
}

#endif
