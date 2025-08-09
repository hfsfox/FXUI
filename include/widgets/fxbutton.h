#ifndef __FXBUTTON_H__
#define __FXBUTTON_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

#include <cstring>

namespace FX
{
    class FXButton
    {
        public:
            FXButton();
            FXButton(const char* button_caption, FX::FXRect button_r, FX::FXDisplay* display)
            :
            d(display),
            rect(button_r),
            caption(button_caption)
            {
                FX::FXColor button_bg_color = {200,200,200,255};
                FX::FXColor textColor = {0,0,0,255};
                selected = false;
                if(!selected)
                {
                    d->FillRect(rect.x, rect.y, rect.width, rect.height, {255,255,255,255});
                    d->DrawRect(rect.x, rect.y, rect.width, rect.height, button_bg_color);

                    d->DrawText(caption, rect.x+5+strlen(caption), rect.y+15, textColor);
                }
            }
            ~FXButton()
            {
            }
        public:
            void OnClick()
            {
            };
        private:
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
            const char* caption;
    };
}

#endif
