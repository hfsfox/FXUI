#include <fxprogressbar.h>

#include <cstring>

FX::FXProgressBar::FXProgressBar()
{
}
FX::FXProgressBar::FXProgressBar(const char* progressbar_caption, FX::FXRect progressbar_r, FX::FXDisplay* display)
    :
    d(display),
    rect(progressbar_r),
    caption(progressbar_caption)
    //progress(0),
    //begin(0),
    //end(100)
    {
                FX::FXColor bg_color = {200,200,200,255};
                FX::FXColor textColor = {0,0,0,255};
                FX::FXColor progressbar_color = {134, 206, 250, 255};

                //selected = false;
                //if(!selected)
                //{
                    d->FillRect(rect.x, rect.y, rect.width, rect.height, {255,255,255,255});
                    d->DrawRect(rect.x, rect.y, rect.width, rect.height, bg_color);

                    // Progress Bar Length = ( (Current Value - Minimum Value) / (Maximum Value - Minimum Value) ) * Total Available Length
                    //d->FillRect(rect.x, rect.y, progress, rect.height, progressbar_color);
                    d->FillRect(rect.x, rect.y, (int)((progress-0)/(0-100/*end-begin*/)) * rect.width, rect.height, progressbar_color);

                    if(strlen(caption) != 0)
                    {
                        d->DrawText(caption, rect.x+5+strlen(caption), rect.y+15, textColor);
                    }
                //}
    }
FX::FXProgressBar::~FXProgressBar()
{
}
void
FX::FXProgressBar::SetProgress(unsigned int _progress)
{
    progress = _progress;
};

void
FX::FXProgressBar::SetLimits(unsigned int _begin, unsigned int _end)
{
    begin = _begin;
    end = _end;
};
