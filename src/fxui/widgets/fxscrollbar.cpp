#include <fxuidefs.h>
#include <fxscrollbar.h>

FX::FXScrollBar::FXScrollBar()
{
}
FX::FXScrollBar::FXScrollBar(const char* scrollbar_caption, FX::FXRect progressbar_r, FX::FXDisplay* display, ui_direction direction)
    :
    d(display),
    rect(progressbar_r),
    caption(scrollbar_caption),
    //progress(0),
    begin(0),
    end(100),
    _direction(direction)
    {
                FX::FXColor bg_color = {200,200,200,255};
                FX::FXColor textColor = {0,0,0,255};
                FX::FXColor progressbar_color = {134, 206, 250, 255};
                FX::FXColor background_color = {180,180,180,255};
                FX::FXColor arrow_color = {190,190,190,255};
                FX::FXColor thumb_color = {200,200,200,255};

                int scale_len = 40;

                //selected = false;
                //if(!selected)
                //{
            if(_direction == FX_HORIZONTAL){
                    int slider_height = 15;
                    // draw background
                    d->FillRect(rect.x, rect.y, rect.width, slider_height, background_color);
                    //draw side arrows
                    d->FillRect(rect.x, rect.y, slider_height, slider_height, arrow_color);
                    d->FillRect(rect.x+rect.width-slider_height, rect.y+rect.height-slider_height, slider_height, slider_height, arrow_color);
                    //draw thumb frame
                    d->FillRect(rect.x+slider_height+42/*rect.width-slider_height*/, rect.y+rect.height-slider_height, 40/*len*/, slider_height, thumb_color);
                    // draw frame
                    d->DrawRect(rect.x, rect.y, rect.width, rect.height, bg_color);
            }
            if (_direction == FX_VERTICAL)
            {
            }
    }
FX::FXScrollBar::~FXScrollBar()
{
}

void
FX::FXScrollBar::SetLimits(unsigned int _begin, unsigned int _end)
{
    begin = _begin;
    end = _end;
};

void
FX::FXScrollBar::SetOrientation(ui_direction direction)
{
    direction = _direction;
};
