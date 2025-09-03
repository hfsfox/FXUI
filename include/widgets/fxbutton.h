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

#ifndef __FXBUTTON_H__
#define __FXBUTTON_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>
#include <fxwidget.h>

namespace FX
{
    class FXButton: public FX::FXWidget
    {
        public:
            FXButton();
            FXButton(const char* button_caption, FX::FXRect button_r, FX::FXDisplay* display);
            ~FXButton();
        public:
            void OnClick();
        private:
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
            const char* caption;
    };
}

#endif
