#include <fxradiobutton.h>

FX::FXRadioButton::FXRadioButton()
{
}
FX::FXRadioButton::FXRadioButton(const char* radio_button_caption, FX::FXRect radio_button_r, FX::FXDisplay* display)
    :
    d(display),
    rect(radio_button_r),
    caption(radio_button_caption)
    {
                FX::FXColor bg_color = {200,200,200,255};
                FX::FXColor textColor = {0,0,0,255};
                FX::FXColor select_color = {134, 206, 250, 255};

                if(!selected)
                {
                    d->DrawCircle(rect.x, rect.y, 8, {0,0,0,255});
                    d->FillCircle(rect.x, rect.y, 8, {255,255,255,255});
                    d->FillCircle(rect.x, rect.y, 5, select_color);
                }
                else
                {
                    d->DrawCircle(rect.x, rect.y, 8, {0,0,0,255});
                    d->FillCircle(rect.x, rect.y, 8, {255,255,255,255});
                }
    }
FX::FXRadioButton::~FXRadioButton()
{
}

void
FX::FXRadioButton::Selected(bool _selected)
{
    selected = _selected;
}
