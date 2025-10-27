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
#include <fxuidefs.h>

namespace FX
{
    class FXToolBar
    {
        public:
            FXToolBar(/*ui_direction direction = FX_HORIZONTAL */ );
            FXToolBar(FX::FXRect menubar_r, FX::FXDisplay* display, ui_direction direction = FX_HORIZONTAL);
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
            FX::FXDisplay* d;
            FX::FXRect rect;
    };
}

#endif
