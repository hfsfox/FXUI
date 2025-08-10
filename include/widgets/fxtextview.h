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

#ifndef __FXTEXCONTROL_H__
#define __FXTEXCONTROL_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

namespace FX
{
    class FXTextView
    {
        public:
            FXTextView();
            FXTextView(const char* init_text, FX::FXRect text_control_r, FX::FXDisplay* display)
            :
            d(display),
            rect(text_control_r),
            text(init_text)
            {
                d->FillRect(rect.x, rect.y, rect.width, rect.height, {255,255,255,255});
            }
            ~FXTextView()
            {
            }
        private:
            const char* text;
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
    };
}

#endif
