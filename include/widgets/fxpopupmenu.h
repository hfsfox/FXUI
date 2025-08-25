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

#ifndef __FXPOPUPMENU_H__
#define __FXPOPUPMENU_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>
#include <fxuidefs.h>

namespace FX
{
    class FXPopUpMenu
    {
        public:
            FXPopUpMenu();
            FXPopUpMenu(const char* popup_menu_caption, FX::FXRect progressbar_r, FX::FXDisplay* display);
            ~FXPopUpMenu();
        public:

        private:
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
            const char* caption;
            //unsigned int progress;
            //unsigned int begin;
            //unsigned int end;
    };
}

#endif
