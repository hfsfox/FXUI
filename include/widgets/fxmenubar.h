#ifndef __FXMENUBAR_H__
#define __FXMENUBAR_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

namespace FX
{
    class FXMenuBar
    {
        public:
            FXMenuBar();
            FXMenuBar(FX::FXRect menubar_r, FX::FXDisplay* display)
            {
                FX::FXColor menubar_color = {0,0,0,255};
                FX::FXColor textColor = {0,0,0,255};
                // 800 - width 25 - height
                //FX::FXDisplay::FillRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, {255,255,255,255});
                display->FillRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, {255,255,255,255});
                display->DrawRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, menubar_color);
                //
                display->DrawText("File", menubar_r.x+5, menubar_r.y+15, textColor);
                display->DrawText("Edit", menubar_r.x+35, menubar_r.y+15, textColor);
                display->DrawText("View", menubar_r.x+65, menubar_r.y+15, textColor);
                display->DrawText("Help", menubar_r.x+95, menubar_r.y+15, textColor);
            }
            ~FXMenuBar()
            {
            }
        private:
    };
}

#endif
