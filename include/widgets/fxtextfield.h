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
            FXTextField(const char* init_text, FX::FXRect check_box_r, FX::FXDisplay* display);
        private:
            const char* text;
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
    };
}

#endif
