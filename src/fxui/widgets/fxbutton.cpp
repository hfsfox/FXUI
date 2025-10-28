#include "fxwidget.h"
#include <fxbutton.h>
#include <cstring>

FX::FXButton::FXButton()
:
FX::FXWidget(rect)
{
}

FX::FXButton::FXButton(const char* button_caption, FX::FXRect button_r, FX::FXDisplay* display)
    :
    d(display),
    rect(button_r),
    caption(button_caption),
    FX::FXWidget(button_r)
    {
        FX::FXColor button_bg_color = {200,200,200,255};
        FX::FXColor textColor = {0,0,0,255};
        selected = false;
        if(!selected)
        {
            d->FillRect(rect.x, rect.y, rect.width, rect.height, {245,245,245,255});
            d->DrawRect(rect.x, rect.y, rect.width, rect.height, button_bg_color);
            d->DrawText(caption, rect.x+5+strlen(caption), rect.y+15, textColor);
        }
    }
FX::FXButton::~FXButton()
{
}

void
FX::FXButton::OnClick()
{
};

int
FX::FXButton::GetHeight() const
{
	return rect.y;
}

int
FX::FXButton::GetWidth() const
{
	return rect.width;
}

