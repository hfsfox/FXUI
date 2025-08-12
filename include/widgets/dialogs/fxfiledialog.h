//-----------------------------------------------------------------------------
// FXUI SDK
// FXUI: Graphical User Interface Framework:
//
// Version 0.1       Date :
//
//-----------------------------------------------------------------------------
// MIT
// © 2025, , All Rights Reserved
//-----------------------------------------------------------------------------

#ifndef __FXFILEDIALOG_H__
#define __FXFILEDIALOG_H__

#include <fxdisplay.h>
#include <fxwindow.h>
#include <fxbutton.h>
#include <fxrect.h>
#include <fxpoint.h>

#include <cstring>

namespace FX
{
    class FXFileDialog : public FX::FXWindow
    {
        public:
            FXFileDialog(FX::FXDisplay* display, const FX::FXRect& rect, const char* title, const char* _text)
            :
            FXWindow(display, rect, title),
            text(_text)
            {
                FX::FXColor text_color = {0,0,0,255};

                while (FX::FXWindow::ProcessEvents() && !FX::FXWindow::ShouldClose())
                {
                    display->SetViewColor({250,250,250,255});
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
            //FX::FXWindow w;
            //FXDisplay* d;
            const char* text;
            //FX::FXRect rect;
            //FX::FXColor text_color;
    };
}

#endif
