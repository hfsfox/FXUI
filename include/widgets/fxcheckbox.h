#ifndef __FXCHECKBOX_H__
#define __FXCHECKBOX_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

//#include <cstring>

namespace FX
{
    class FXCheckBox
    {
        public:
            FXCheckBox();
            FXCheckBox(const char* check_box_caption, FX::FXRect check_box_r, FX::FXDisplay* display)
            :
            d(display),
            rect(check_box_r),
            caption(check_box_caption)
            {
                FX::FXColor bg_color = {200,200,200,255};
                FX::FXColor textColor = {0,0,0,255};
                FX::FXColor select_color = {134, 206, 250, 255};

                int len = 15;
                int in_len = 10;

                //selected = false;
                if(!selected)
                {
                    //d->DrawCircle(rect.x, rect.y, 8, {0,0,0,255});
                    //d->FillCircle(rect.x, rect.y, 8, {255,255,255,255});
                    //d->FillCircle(rect.x, rect.y, 5, select_color);
                    d->FillRect(rect.x, rect.y, in_len, in_len, select_color);
                    //d->DrawRect(rect.x, rect.y, len, len, bg_color);
                }
                else
                {
                    //d->DrawCircle(rect.x, rect.y, 8, {0,0,0,255});
                    //d->FillCircle(rect.x, rect.y, 8, {255,255,255,255});
                    d->FillRect(rect.x, rect.y, len, len, {255,255,255,255});
                    d->DrawRect(rect.x, rect.y, len, len, bg_color);
                }
            }
            ~FXCheckBox()
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
