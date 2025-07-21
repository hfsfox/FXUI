#ifndef __FXTOOLBAR_H__
#define __FXTOOLBAR_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

//#include <cstdint>
//#include <vector>

/*
namespace
{
    class MenuItems
    {
        uint32_t menu_item_i;
        const char* menu_item_name;
    };

    std::vector<MenuItems> menus;
}
*/

namespace FX
{
    class FXToolBar
    {
        public:
            FXToolBar();
            FXToolBar(FX::FXRect menubar_r, FX::FXDisplay* display)
            :
            d(display),
            rect(menubar_r)
            //word_gap(30)
            {
                FX::FXColor menubar_color = {0,0,0,255};
                FX::FXColor textColor = {0,0,0,255};
                // 800 - width 25 - height
                //FX::FXDisplay::FillRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, {255,255,255,255});
                d->FillRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, {200,200,200,255});
                d->DrawRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, menubar_color);
                //
                /*
                display->DrawText("File", menubar_r.x+5, menubar_r.y+15, textColor);
                display->DrawText("Edit", menubar_r.x+word_gap+5, menubar_r.y+15, textColor);
                display->DrawText("View", menubar_r.x+(word_gap*2)+5, menubar_r.y+15, textColor);
                display->DrawText("Help", menubar_r.x+(word_gap*3)+5, menubar_r.y+15, textColor);
                */
            }
            void AddItemSeparator()
            {
                //display->
                FX::FXColor textColor = {0,0,0,255};
                d->DrawLine(rect.width+5, rect.height, rect.width+5, rect.height+10, textColor);
            }
            /*
            void AddMenu(const char* menu)
            {
            }
            void AddMenuItem(const char* item)
            {
            }
            */
            ~FXToolBar()
            {
            }
        private:
            //uint32_t menu_counter;
            //uint32_t word_gap;
            FX::FXDisplay* d;
            FX::FXRect rect;
    };
}

#endif
