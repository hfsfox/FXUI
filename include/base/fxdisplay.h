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

#ifndef __FXDISPLAY_H__
#define __FXDISPLAY_H__

#include <fxplatformdefs.h>
#include <fxplatformuidefs.h>
#include <fxuicolor.h>
#include <fxpoint.h>
#include <fxrect.h>
//#if defined (PLATFORM_UNIX_COMPATIBLE)
// Platform detection

#if defined (BACKEND_X11)
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
#elif defined (BACKEND_WAYLAND)
    #include <wayland-client.h>
#elif defined (BACKEND_BEAPI)
    #include <interface/View.h>
#elif defined (BACKEND_WINAPI)
    #include <windows.h>
#elif defined (BACKEND_COCOA)
    //#include <Cocoa/Cocoa.h>
    #include <Carbon/Carbon.h>
    #include <objc/message.h>
    #include <objc/runtime.h>
#endif

namespace FX
{
    typedef struct FXColor FXColor;
    class FXFont;
}

namespace FX
{
    typedef struct MonitorInfo
        {
            const char* name;       // The name of monitor
            bool        primary;    // The monitor is primary
            FX::FXRect  rect;       // The position and size of monitor
        } MonitorInfo;
}

namespace FX
{
    class FXDisplay
    {
        friend class FWindow;

        public:
            FXDisplay();
            FXDisplay(FX::FXRect& size);
            ~FXDisplay();
        public:
            bool Init();
            void Cleanup();
        public:
            void* GetNativeContext() const;
        public:
            void Clear();
            //void ClearDisplay();
        public:
            void DrawText(const char* text, int x, int y, FX::FXColor color);
            void DrawText(const char* text, FX::FXPoint where, FX::FXColor color);
            void DrawCircle(int center_x, int center_y, int radius, FX::FXColor color);
            void DrawCircle(FX::FXPoint where, int radius, FX::FXColor color);
            void DrawPoint(int center_x, int center_y, FX::FXColor color);
            void DrawPoint(FX::FXPoint where, FX::FXColor color);
            void DrawLine(int center_x_begin, int center_y_begin,int center_x_end, int center_y_end, FX::FXColor color);
            void DrawLine(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color);
            void DrawRect(int x_begin, int y_begin, int width, int height, FX::FXColor color);
            void DrawRect(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color);
            void DrawTriangle(int x_a_begin, int y_a_begin,int x_b_begin, int y_b_begin,int x_c_begin, int y_c_begin);
            void DrawTriangle(FX::FXPoint where_a_begin, FX::FXPoint where_b_begin, FX::FXPoint where_c_begin);
        public:
            void FillRect(int x_begin, int y_begin, int width, int height, FX::FXColor color);
            void FillRect(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color);
            void FillCircle(int center_x, int center_y, int radius, FX::FXColor color);
            void FillCircle(FX::FXPoint where, int radius, FX::FXColor color);
            void FillTriangle(int x_a_begin, int y_a_begin,int x_b_begin, int y_b_begin,int x_c_begin, int y_c_begin);
            void FillTriangle(FX::FXPoint where_a_begin, FX::FXPoint where_b_begin, FX::FXPoint where_c_begin);
        public:
            void SetFont(FX::FXFont);
            void SetViewColor(FX::FXColor color);
            FX::FXColor GetViewColor() const;

            FX::FXRect GetDisplaySize() const;

            void Present();

        public:
        #if defined (BACKEND_X11)
            ::Display* display;
            ::Window window;
            ::GC gc;
            ::Visual *visual;
            ::Colormap colormap;
            int screen;
        #elif defined (BACKEND_WAYLAND)
            struct wl_display* display;
        #elif defined (BACKEND_BEAPI)
            BView* view;
        #elif defined (BACKEND_COCOA)
            //NSView* view;
            id app;
        #elif defined (BACKEND_WINAPI)
            HDC hdc;
            HWND hwnd;
        #endif
    };
}

#endif
