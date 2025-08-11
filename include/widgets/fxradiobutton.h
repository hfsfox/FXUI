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

#ifndef __FXRADIOBUTTON_H__
#define __FXRADIOBUTTON_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

namespace FX
{
    class FXRadioButton
    {
        public:
            FXRadioButton();
            FXRadioButton(const char* radio_button_caption, FX::FXRect radio_button_r, FX::FXDisplay* display);
            ~FXRadioButton();
        public:
            void Selected(bool _selected);
        private:
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
            const char* caption;
    };
}

#endif
