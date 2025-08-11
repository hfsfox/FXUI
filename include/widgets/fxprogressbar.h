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

#ifndef __FXPROGRESSBAR_H__
#define __FXPROGRESSBAR_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

namespace FX
{
    class FXProgressBar
    {
        public:
            FXProgressBar();
            FXProgressBar(const char* progressbar_caption, FX::FXRect progressbar_r, FX::FXDisplay* display);
            ~FXProgressBar();
        public:
            void SetProgress(unsigned int _progress);
            void SetLimits(unsigned int _begin, unsigned int _end);
        private:
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
            const char* caption;
            unsigned int progress;
            unsigned int begin;
            unsigned int end;
    };
}

#endif
