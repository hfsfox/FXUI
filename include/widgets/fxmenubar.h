#ifndef __FXMENUBAR_H__
#define __FXMENUBAR_H__

//#include <SupportDefs.h>
#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

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
    class FXMenuBar
    {
        public:
            FXMenuBar();
            FXMenuBar(FX::FXRect menubar_r, FX::FXDisplay* display)
            :
            d(display),
            rect(menubar_r),
            word_gap(30)
            {
                FX::FXColor menubar_color = {200,200,200,255};
                FX::FXColor textColor = {0,0,0,255};
                // 800 - width 25 - height
                //FX::FXDisplay::FillRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, {255,255,255,255});
                //display->DrawRect(rect.x, rect.y, rect.width, rect.height, menubar_color);
                //d->DrawRect(rect.x, rect.y, rect.width, rect.height, menubar_color);
                selected = false;
                if(!selected)
                {
                    d->FillRect(rect.x, rect.y, rect.width, rect.height, {255,255,255,255});
                    d->DrawRect(rect.x, rect.y, rect.width, rect.height, menubar_color);
                    //
                    d->DrawText("File", rect.x+5, rect.y+15, textColor);
                    d->DrawText("Edit", rect.x+word_gap+5, rect.y+15, textColor);
                    d->DrawText("View", rect.x+(word_gap*2)+5, rect.y+15, textColor);
                    d->DrawText("Help", rect.x+(word_gap*3)+5, rect.y+15, textColor);
                }
            }
            void AddMenu(const char* menu)
            {
            }
            void AddMenuItem(const char* item)
            {
            }
            ~FXMenuBar()
            {
            }
        private:
            uint32_t menu_counter;
            uint32_t word_gap;
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
    };
}

#endif
