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

#ifndef __FXMESSAGEBOX_H__
#define __FXMESSAGEBOX_H__

#include <fxdisplay.h>
#include <fxwindow.h>
#include <fxbutton.h>
#include <fxrect.h>
#include <fxpoint.h>

#include <cstring>

namespace FX
{
    class FXMessageBox : public FX::FXWindow
    {
        public:
            FXMessageBox(FX::FXDisplay* display, const FX::FXRect& rect, const char* title, const char* _text)
            :
            FXWindow(display, rect, title),
            //w(display, rect, "Cross-Platform FXWindow Demo"),
            //text_color({0,0,0,255}),
            text(_text)
            {
                FX::FXColor text_color = {0,0,0,255};

                //w(&display, rect, "Cross-Platform FXWindow Demo");

                while (FX::FXWindow::ProcessEvents() && !FX::FXWindow::ShouldClose())
                {
                    display->SetViewColor({250,250,250,255});
                    //const char* t = "some text";
                    display->DrawText(text, rect.x+100+strlen(text), rect.y+100, text_color);
                }
                //while (w.ProcessEvents() && !w.ShouldClose())
                //{
                    //display->SetViewColor({250,250,250,255});
                    //const char* t = "some text";
                    //display->DrawText(text, rect.x+100+strlen(text), rect.y+100, text_color);
                //}

                //w.Show();
                /*while (w.ProcessEvents() && !w.ShouldClose())
                {
                    d->SetViewColor({250,250,250,255});
                    //const char* t = "some text";
                    d->DrawText(text, rect.x+100+strlen(text), rect.y+100, text_color);
                }*/
            }
        public:
            bool Create()
            {
                return FX::FXWindow::Create();
                //return w.Create();
                //return true;
            }
            void Show()
            {
                FX::FXWindow::Show();
                //w.Show();
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
