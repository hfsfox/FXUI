#ifndef __FXTEXTFIELD_H__
#define __FXTEXTFIELD_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

#include <fxtextview.h>

namespace FX
{
    class FXTextField: public FXTextView
    {
        public:
            FXTextField();
            FXTextField(const char* init_text, FX::FXRect check_box_r, FX::FXDisplay* display)
            :
            FX::FXTextView(init_text, check_box_r, display)
            /*d(display),
            rect(check_box_r),
            text(init_text)
            {
            }*/
            {
                d->FillRect(rect.x, rect.y, rect.width, rect.height, {255,255,255,255});
            }
        private:
            const char* text;
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
    };
}

#endif
