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

#ifndef __FXMENUBAR_H__
#define __FXMENUBAR_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>
#include <fxwidget.h>

#include <cstdint>
#include <vector>

namespace
{
    class MenuItems
    {
        uint32_t menu_item_i;
        const char* menu_item_name;
    };

    std::vector<MenuItems> menus;
}

namespace FX
{
    class FXMenuBar/* : public FX::FXWidget*/
    {
        public:
            FXMenuBar();
            FXMenuBar(FX::FXRect menubar_r, FX::FXDisplay* display);
            ~FXMenuBar();
        public:
            void AddMenu(const char* menu);
            void AddMenuItem(const char* item);
            bool IsNativeMenuBar() const { return isNative; }
            void MakeNativeMenuBar();
            int GetHeight() const;
			int GetWidth() const;
        private:
            uint32_t menu_counter;
            uint32_t word_gap;
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
            bool isNative;
    };
}

#endif
