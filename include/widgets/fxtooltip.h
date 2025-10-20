//-----------------------------------------------------------------------------
// FXUI SDK
// FXUI: Graphical User Interface Framework:
//
// Version 0.1       Date :
//
//-----------------------------------------------------------------------------
// MIT
// © 2025, , All Rights Reserved
//-----------------------------------------------------------------------------

#ifndef __FXTOOLTIP_H__
#define __FXTOOLTIP_H__

#include <fxwidget.h>
#include <fxrect.h>

namespace FX
{
    class FXToolTip: public FX::FXWidget
    {
        public:
            FXToolTip(const char* tooltip_text, FX::FXWidget widget_for_tooltip);
            ~FXToolTip();
        public:
            void SetRect(FX::FXRect rect);
    };
}

#endif
