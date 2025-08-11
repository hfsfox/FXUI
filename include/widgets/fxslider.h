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

#ifndef __FXSLIDER_H__
#define __FXSLIDER_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

namespace FX
{
    class FXSlider
    {
        public:
            FXSlider();
            FXSlider(const char* progressbar_caption, FX::FXRect progressbar_r, FX::FXDisplay* display);
            ~FXSlider();
        public:
            void SetLimits(unsigned int _begin, unsigned int _end);
        private:
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
            const char* caption;
            //unsigned int progress;
            unsigned int begin;
            unsigned int end;
    };
}

#endif
