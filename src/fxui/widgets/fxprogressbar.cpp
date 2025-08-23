#include <cstdio>
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

                //float progress_c = (float)progress / 100;
                //int filled_width = static_cast<int>(rect.width * progress);

                //uint one_len = (rect.width / 100);
                int total = 0;

                //selected = false;
                //if(!selected)
                //{
                    d->FillRect(rect.x, rect.y, rect.width, rect.height, {255,255,255,255});
                    //d->DrawRect(rect.x, rect.y, rect.width, rect.height, bg_color);

                    // Progress Bar Length = ( (Current Value - Minimum Value) / (Maximum Value - Minimum Value) ) * Total Available Length
                    //for(int i = 0; i < 64 ; i++)
                    //{
                        //for (int i = 0; i < progress; ++i) {
                        //total += one_len;
                        //}

                        //printf("progress %d", progress);
                        progress =27;

                        d->FillRect(rect.x, rect.y, (rect.width*progress/100)/*(one_len*progress)*/, rect.height+1, progressbar_color);
                    //}
                    //d->FillRect(rect.x, rect.y, (int)((progress-0)/(0-100/*end-begin*/)) * rect.width, rect.height, progressbar_color);

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
