#include <fxmenubar.h>

FX::FXMenuBar::FXMenuBar()
{
}
FX::FXMenuBar::FXMenuBar(FX::FXRect menubar_r, FX::FXDisplay* display)
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
            //for(uint i = 0; i < rect.height; i++)
            //{
            #ifdef BACKEND_BEAPI
                d->FillRect(rect.x, rect.y, rect.width, rect.height, {210,210,210,255});
            #else
            d->FillRect(rect.x, rect.y, rect.width, rect.height, {255,255,255,255});
            #endif
            //d->FillRect(rect.x, rect.y, rect.width, rect.height, {(165/255)-i,(165/255)-i,(165/255)-i,255});
            //}
            //d->DrawRect(rect.x, rect.y, rect.width, rect.height, menubar_color);
            #ifdef BACKEND_BEAPI
                d->DrawLine(rect.x, rect.height, rect.width, rect.height, {160,160,160,255});
            #else
                d->DrawRect(rect.x, rect.y, rect.width, rect.height, menubar_color);
            #endif
            //
            d->DrawText("File", rect.x+5, rect.y+15, textColor);
            d->DrawText("Edit", rect.x+word_gap+5, rect.y+15, textColor);
            d->DrawText("View", rect.x+(word_gap*2)+5, rect.y+15, textColor);
            d->DrawText("Help", rect.x+(word_gap*3)+5, rect.y+15, textColor);
        }
    }

void
FX::FXMenuBar::AddMenu(const char* menu)
{
}

void
FX::FXMenuBar::AddMenuItem(const char* item)
{
}

FX::FXMenuBar::~FXMenuBar()
{
}

void
FX::FXMenuBar::MakeNativeMenuBar()
{
}

int
FX::FXMenuBar::GetHeight() const
{
	return rect.y;
}

int
FX::FXMenuBar::GetWidth() const
{
	return rect.width;
}
