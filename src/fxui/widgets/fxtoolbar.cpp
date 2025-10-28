#include <fxtoolbar.h>

FX::FXToolBar::FXToolBar()
{
}

FX::FXToolBar::FXToolBar(FX::FXRect menubar_r, FX::FXDisplay* display, ui_direction direction)
    :
    d(display),
    rect(menubar_r)
    {
        if (direction == FX_HORIZONTAL)
        {
            FX::FXColor menubar_color = { 0,0,0,255 };
            FX::FXColor textColor = { 0,0,0,255 };
            // 800 - width 25 - height
            //FX::FXDisplay::FillRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, {255,255,255,255});
            //d->FillRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, {200,200,200,255});
            d->FillRect(rect.x, rect.y, rect.width, rect.height, { 200,200,200,255 });
            d->DrawRect(rect.x, rect.y, rect.width, rect.height, menubar_color);
        }
        if (direction == FX_VERTICAL)
        {
        }
    }

void
FX::FXToolBar::AddItemSeparator()
{
    FX::FXColor textColor = {255,255,255,255};
    d->DrawLine(rect.width+5, rect.height, rect.width+5, rect.height+10, textColor);
    d->DrawLine(rect.width+5, rect.height, rect.width+5, rect.height+10, textColor);
}

FX::FXToolBar::~FXToolBar()
{
}

int
FX::FXToolBar::GetHeight() const
{
	return rect.y;
}

int
FX::FXToolBar::GetWidth() const
{
	return rect.width;
}
