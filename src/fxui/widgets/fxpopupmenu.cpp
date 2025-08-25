#include <fxuidefs.h>
#include <fxpopupmenu.h>
#include <cstring>

FX::FXPopUpMenu::FXPopUpMenu()
{
}
FX::FXPopUpMenu::FXPopUpMenu(const char* popup_menu_caption, FX::FXRect progressbar_r, FX::FXDisplay* display)
    :
    d(display),
    rect(progressbar_r),
    caption(popup_menu_caption)
    {
                FX::FXColor bg_color = {200,200,200,255};
                FX::FXColor textColor = {0,0,0,255};
                FX::FXColor progressbar_color = {134, 206, 250, 255};
                FX::FXColor background_color = {180,180,180,255};
                FX::FXColor arrow_color = {190,190,190,255};
                FX::FXColor thumb_color = {200,200,200,255};

                int scale_len = 40;
                    int slider_height = 20;
                    // draw background
                    d->FillRect(rect.x, rect.y, rect.width, slider_height, background_color);
                    //draw caption
                    d->DrawText(caption, rect.x+5+strlen(caption), rect.y+15, textColor);
                    //draw side arrows
                    //d->FillRect(rect.x, rect.y, slider_height, slider_height, arrow_color);
                    d->FillRect(rect.x+rect.width-slider_height, rect.y+rect.height-slider_height, slider_height, slider_height, arrow_color);
                    //draw thumb frame
                    //d->FillRect(rect.x+slider_height+42, rect.y+rect.height-slider_height, 40/*len*/, slider_height, thumb_color);
                    // draw frame
                    //d->DrawRect(rect.x, rect.y, rect.width, rect.height, bg_color);

                    //d->DrawText(caption, rect.x+5+strlen(caption), rect.y+15, textColor);
    }
FX::FXPopUpMenu::~FXPopUpMenu()
{
}

