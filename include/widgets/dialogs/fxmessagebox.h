#ifndef __FXMESSAGEBOX_H__
#define __FXMESSAGEBOX_H__

#include <fxdisplay.h>
#include <fxwindow.h>
#include <fxbutton.h>
#include <fxrect.h>
#include <fxpoint.h>

namespace FX
{
    class FXMessageBox: public FX::FXWindow
    {
        public:
            FXMessageBox(FX::FXDisplay* display, const FX::FXRect& rect, const char* title, const char* text)
            :
            FXWindow(display, rect, title)
            {
                FX::FXColor text_color = {0,0,0,255};

                while (FX::FXWindow::ProcessEvents() && !FX::FXWindow::ShouldClose())
                {
                    display->SetViewColor({250,250,250,255});
                    //const char* t = "some text";
                    display->DrawText(text, rect.x+100+strlen(text), rect.y+100, text_color);
                }
            }
        public:
            bool Create()
            {
                return FX::FXWindow::Create();
            }
            void Show()
            {
                FX::FXWindow::Show();
            }
        private:
    };
}

#endif
