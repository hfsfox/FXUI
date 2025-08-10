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

//#include <cstring>

namespace FX
{
    class FXRadioButton
    {
        public:
            FXRadioButton();
            FXRadioButton(const char* radio_button_caption, FX::FXRect radio_button_r, FX::FXDisplay* display)
            :
            d(display),
            rect(radio_button_r),
            caption(radio_button_caption)
            {
                FX::FXColor bg_color = {200,200,200,255};
                FX::FXColor textColor = {0,0,0,255};
                FX::FXColor select_color = {134, 206, 250, 255};

                //selected = false;
                if(!selected)
                {
                    d->DrawCircle(rect.x, rect.y, 8, {0,0,0,255});
                    d->FillCircle(rect.x, rect.y, 8, {255,255,255,255});
                    d->FillCircle(rect.x, rect.y, 5, select_color);
                }
                else
                {
                    d->DrawCircle(rect.x, rect.y, 8, {0,0,0,255});
                    d->FillCircle(rect.x, rect.y, 8, {255,255,255,255});
                }
            }
            ~FXRadioButton()
            {
            }
        public:
            void Selected(bool _selected)
            {
                selected = _selected;
            }
        private:
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
            const char* caption;
    };
}

#endif
