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
            FXCheckBox(const char* check_box_caption, FX::FXRect check_box_r, FX::FXDisplay* display);
            ~FXCheckBox();
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
