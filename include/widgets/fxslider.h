#ifndef __FXSLIDER_H__
#define __FXSLIDER_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

//#include <cstring>

namespace FX
{
    class FXSlider
    {
        public:
            FXSlider();
            FXSlider(const char* progressbar_caption, FX::FXRect progressbar_r, FX::FXDisplay* display)
            :
            d(display),
            rect(progressbar_r),
            caption(progressbar_caption),
            //progress(0),
            begin(0),
            end(100)
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
            ~FXSlider()
            {
            }
        public:
            /*void SetProgress(unsigned int _progress)
            {
                progress = _progress;
            };*/
            void SetLimits(unsigned int _begin, unsigned int _end)
            {
                begin = _begin;
                end = _end;
            };
        private:
            FX::FXRect rect;
            FX::FXDisplay* d;
            bool selected;
            const char* caption;
            //unsigned int progress;
            unsigned int begin;
            unsigned int end;
    };
}

#endif
