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

#ifndef __FXSCROLLBAR_H__
#define __FXSCROLLBAR_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>
#include <fxuidefs.h>

namespace FX
{
    class FXScrollBar
    {
        public:
            FXScrollBar();
            FXScrollBar(const char* scrollbar_caption, FX::FXRect progressbar_r, FX::FXDisplay* display, ui_direction direction);
            ~FXScrollBar();
        public:
            void SetLimits(unsigned int _begin, unsigned int _end);
            //void GetLimits(unsigned int _begin, unsigned int _end) const;
            void SetOrientation(ui_direction direction);
        private:
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
            const char* caption;
            //unsigned int progress;
            unsigned int begin;
            unsigned int end;
            ui_direction _direction;
    };
}

#endif
