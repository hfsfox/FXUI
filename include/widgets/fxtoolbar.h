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

#ifndef __FXTOOLBAR_H__
#define __FXTOOLBAR_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

namespace FX
{
    class FXToolBar
    {
        public:
            FXToolBar();
            FXToolBar(FX::FXRect menubar_r, FX::FXDisplay* display);
            /*
            void AddMenu(const char* menu)
            {
            }
            void AddMenuItem(const char* item)
            {
            }
            */
            ~FXToolBar();
            void AddItemSeparator();
        private:
            //uint32_t menu_counter;
            //uint32_t word_gap;
            FX::FXDisplay* d;
            FX::FXRect rect;
    };
}

#endif
