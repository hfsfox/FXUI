
#ifndef __FXWINDOW_H__
#define __FXWINDOW_H__

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxpoint.h>

namespace FX
{
    typedef struct FXRect FXRect;
}

// Window class
namespace FX
{
    class FXWindow
    {
        public:
            FXWindow(FX::FXDisplay* display, const FX::FXRect& rect, const char* title);
            ~FXWindow();
        public:
            bool Create();
            void Show();
            void Hide();
            bool ProcessEvents();
            void SetTitle(const char* title);
            void MoveTo(FX::FXPoint where);
            void ResizeTo(FX::FXRect& newSize);
        public:
            bool ShouldClose() { return shouldClose; }
            FX::FXDisplay* GetDisplay() const { return display; }
            const FX::FXRect& GetRect() const { return rect; }
        private:
            FX::FXDisplay* display;
            FX::FXRect rect;
            const char* title;
            bool shouldClose;
        private:
    };
}

#endif
