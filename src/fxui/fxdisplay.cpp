#include "fxwindow.h"
#include <X11/Xft/Xft.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrender.h>
#include <fxpoint.h>
#include <fxdisplay.h>
#include <fxfont.h>

#if defined (BACKEND_X11)
    #include "platform/unix/x11/X11APIWindow.h"
#elif defined (BACKEND_BEAPI)
    //#include <interface/View.h>
    //#include <support/String.h>
    //#include <interface/Font.h>
    //#include <interface/Bitmap.h>
    //#include <translation/TranslationUtils.h>
    //#include <storage/Resources.h>
    //#include <GraphicsDefs.h>
    //#include <InterfaceDefs.h>
    #include "platform/haiku/BeAPIView.h"
#elif defined (BACKEND_WINAPI)
    #include <windows.h>
    #include <winuser.h>
#endif
#include <cstring>
//#include <iostream>

namespace
{
    unsigned long _RGB(int r,int g, int b)
    {
        //return b | (g<<8) | (r<<16);
        return ((r << 16) | (g << 8) | (b));
    }

    XftFont      *font;
    XftDraw      *xftdraw;
    XRenderColor xrcolor;
    XftColor     xftcolor;
    XGlyphInfo xglyphinfo;
    //XftTextExtents8
    //X11Display* dx11;
}

FX::FXDisplay::FXDisplay()
{
    #if defined(BACKEND_X11)
            display = nullptr; screen = 0; window = 0; gc = nullptr;
            //X11Display* dx11 = new X11Display();
    #elif defined(BACKEND_BEAPI)
        view = nullptr;
    #endif
}

FX::FXDisplay::FXDisplay(FX::FXRect& size)
{

}

FX::FXDisplay::~FXDisplay()
{
    Cleanup();
}

bool FX::FXDisplay::Init()
{
    #ifdef PLATFORM_MACOSX
        return true;
    #elif defined(BACKEND_X11)
        display = XOpenDisplay(nullptr);
        //display = dx11->GetPlatformDisplay();
        if (!display) return false;
        screen = DefaultScreen(display);
        return true;
    #elif defined(BACKEND_BEAPI)
        return true;
    #endif
    //return true;
}

void FX::FXDisplay::Cleanup()
{
    #ifdef BACKEND_X11
        //if(xftdraw) { XftDrawDestroy(xftdraw); }
        if (gc) { XFreeGC(display, gc); gc = nullptr; }
        if (display) { XCloseDisplay(display); display = nullptr; }
    #endif
}

void*
FX::FXDisplay::GetNativeContext() const
{
        #if defined(BACKEND_X11)
            return static_cast<void*>(display);
        #elif defined(BACKEND_BEAPI)
            return static_cast<void*>(view);
        #endif
}

void
FX::FXDisplay::Clear()
{
    #if defined(PLATFORM_LINUX)
        if (display && window && gc)
        {
            XClearWindow(display, window);
        }
    #elif defined(PLATFORM_HAIKU)
        if (view)
        {
            view->LockLooper();
            view->Invalidate();
            view->UnlockLooper();
        }
    #endif
}

/*void
FX::FXDisplay::ClearDisplay()
{
}*/

void
FX::FXDisplay::DrawText(const char* text, int x, int y, FX::FXColor color)
{
    #if defined(PLATFORM_LINUX)
        if (display && window && gc) {
        XSetForeground(display, gc, _RGB(color.red,color.green,color.blue));
            //XDrawString(display, window, gc, x, y, text, strlen(text));
        font = XftFontOpenName(display,0,"Arial-10");
        //font = SetFont()
        //if (!font) return 1;
        /*xrcolor.red  =0x0000;
        xrcolor.green=0x0000;
        xrcolor.blue =0x0000;*/
        xrcolor.red = color.red;
        xrcolor.green = color.green;
        xrcolor.blue = color.blue;
        xrcolor.alpha=0xFFFF;
        XftColorAllocValue(display,DefaultVisual(display,0),DefaultColormap(display,0),&xrcolor,&xftcolor);
        xftdraw = XftDrawCreate(display,window,DefaultVisual(display,0),DefaultColormap(display,0));
        XftDrawString8(xftdraw, &xftcolor, font, x, y, (XftChar8 *)text, strlen(text));
        XftTextExtents8 (display, font, (XftChar8 *)text, strlen(text), &xglyphinfo);
        //std::cout << xglyphinfo.width << std::endl;
        //xglyphinfo->width;
        XftDrawDestroy(xftdraw);
        XftColorFree(display,DefaultVisual(display,0),DefaultColormap(display,0),&xftcolor);
        //font->height;
        }
    #elif defined(PLATFORM_HAIKU)
        // Text drawing handled in FHaikuView::Draw()
        view->LockLooper();
        view->SetHighColor(color.red, color.green, color.blue, color.alpha);
        view->DrawString(text, BPoint(x, y));
        view->UnlockLooper();
    #endif
}

void
FX::FXDisplay::DrawText(const char* text, FX::FXPoint point, FX::FXColor color)
{
    DrawText(text, point.x, point.y, color);
}

void
FX::FXDisplay::DrawCircle(int center_x, int center_y, int radius, FX::FXColor color)
{
    #if defined(PLATFORM_HAIKU)
        view->LockLooper();
        view->SetHighColor(color.red, color.green, color.blue, color.alpha);
        view->StrokeEllipse(BPoint(center_x,center_y),radius,radius, B_SOLID_HIGH);
        view->UnlockLooper();
    #elif defined (PLATFORM_LINUX)
        XSetForeground(display, gc, _RGB(color.red,color.green,color.blue));
        XDrawArc(display, window, gc, center_x, center_y, radius*2, radius*2, 0, 360*64);
        XFlush(display);
    #endif
}

void
FX::FXDisplay::DrawCircle(FX::FXPoint point, int radius, FX::FXColor color)
{
    FXDisplay::DrawCircle(point.x, point.y, radius, color);
}

void
FX::FXDisplay::DrawPoint(int center_x, int center_y, FX::FXColor color)
{
    #if defined(PLATFORM_HAIKU)
    #elif defined (PLATFORM_LINUX)
    #endif
}

void
FX::FXDisplay::DrawPoint(FX::FXPoint where, FX::FXColor color)
{
    DrawPoint(where.x, where.y, color);
}

void
FX::FXDisplay::DrawLine(int center_x_begin, int center_y_begin,int center_x_end, int center_y_end, FX::FXColor color)
{
    #if defined(PLATFORM_HAIKU)
    	view->LockLooper();
        view->SetHighColor(color.red, color.green, color.blue, color.alpha);
        view->StrokeLine(BPoint(center_x_begin,center_y_begin), BPoint(center_x_end,center_y_end),B_SOLID_HIGH);
        //view->StrokeEllipse(BPoint(center_x,center_y),radius,radius, B_SOLID_HIGH);
        view->UnlockLooper();
    #elif defined (PLATFORM_LINUX)
        XDrawLine(display, window, gc, center_x_begin, center_y_begin, center_x_end, center_y_end);
    #endif
}

void
FX::FXDisplay::DrawLine(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color)
{
    DrawLine(where_begin.x, where_begin.y,where_end.x, where_end.y, color);
}

void
FX::FXDisplay::DrawRect(int x_begin, int y_begin,int width, int height, FX::FXColor color)
{
    #if defined(BACKEND_X11)
        XDrawRectangle(display, window, gc, x_begin, y_begin, width, height);
        XFlush(display);
    #elif defined(PLATFORM_HAIKU)
        view->LockLooper();
        view->SetHighColor(color.red, color.green, color.blue, color.alpha);
        view->StrokeRect(BRect(x_begin,y_begin,width,height),B_SOLID_HIGH);
        view->UnlockLooper();
    #endif
}
void
FX::FXDisplay::DrawRect(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color)
{
    DrawRect(where_begin.x, where_begin.y, where_end.width, where_end.height, color);
}

void
FX::FXDisplay::FillRect(int x_begin, int y_begin, int width, int height, FX::FXColor color)
{
    #if defined(PLATFORM_HAIKU)
        view->LockLooper();
        view->SetHighColor(color.red, color.green, color.blue, color.alpha);
        view->FillRect(BRect(x_begin,y_begin,width,height),B_SOLID_HIGH);
        view->UnlockLooper();
    #elif defined (PLATFORM_LINUX)
        XSetForeground(display, gc, _RGB(color.red,color.green,color.blue));
        XFillRectangle(display,window, gc, x_begin, y_begin, width, height);
        XFlush(display);
    #endif
}
void
FX::FXDisplay::FillRect(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color)
{
    FillRect(where_begin.x, where_begin.y, where_end.width, where_end.height, color);
}

void
FX::FXDisplay::FillCircle(int center_x, int center_y, int radius, FX::FXColor color)
{
    #if defined(PLATFORM_HAIKU)
        view->LockLooper();
        view->SetHighColor(color.red, color.green, color.blue, color.alpha);
        view->FillEllipse(BPoint(center_x,center_y),radius,radius, B_SOLID_HIGH);
        view->UnlockLooper();
    #elif defined (PLATFORM_LINUX)
        XSetForeground(display, gc, _RGB(color.red,color.green,color.blue));
        XFillArc(display, window, gc, center_x, center_y, radius*2, radius*2, 0, 360*64);
        XFlush(display);
    #endif
}

void
FX::FXDisplay::FillCircle(FX::FXPoint point, int radius, FX::FXColor color)
{
    FXDisplay::FillCircle(point.x, point.y, radius, color);
}

void
FX::FXDisplay::SetFont(FX::FXFont fxfont)
{
    #if defined (BACKEND_X11)
        const char* name = fxfont.GetFontName();
        //char font_buffer[256];
        //sprintf(font_buffer, name , "-10", "\n");
        //std::cout << font_buffer << std::endl;
        //font = XftFontOpenName(display,0, font_buffer/*"Arial-10"*/);
        //font = XSetFont(display, gc , font_buffer);
        /*font = (XftFont*)fxfont.GetPlatformFont();
        std::cout << font->height << std::endl;*/
    #endif
}

void
FX::FXDisplay::SetViewColor(FX::FXColor color)
{
    #if defined(PLATFORM_HAIKU)
        view->LockLooper();
        view->SetViewColor(color.red, color.green, color.blue, color.alpha);
        view->UnlockLooper();
    #elif defined (PLATFORM_LINUX)
        //XColor c;
        //c = {color.red,color.green,color.blue};
        //c = {160, 160, 160, 255};
        XSetForeground(display, gc, _RGB(color.red,color.green,color.blue));
        //XSetForeground(display, gc, /*{color.red. color.green, color.blue,255}*/0xCCCCCC/*_RGB(color.red,color.green,color.blue)*/);
        //XSetColor();
        //XSetForeground(display,gc, BlackPixel(display, DefaultScreen(display)));
        XWindowAttributes attr;
        XGetWindowAttributes(display,window,&attr);
        //attr->height/
        XFillRectangle(display,window,gc,0, 0, attr.width, attr.height);
        XFlush(display);
    #endif
}

FX::FXColor
FX::FXDisplay::GetViewColor() const
{
    #if defined(BACKEND_X11)
        FXColor viewcolor = {0, 0, 0, 255};
        return viewcolor;
    #elif defined(PLATFORM_HAIKU)
        view->LockLooper();
        FXColor viewcolor = {view->ViewColor().red, view->ViewColor().green, view->ViewColor().blue, 255};
        view->UnlockLooper();
        return viewcolor;
    #endif
}

FX::FXRect
FX::FXDisplay::GetDisplaySize() const
{
    #if defined(BACKEND_X11)
        XWindowAttributes attr;
        XGetWindowAttributes(display,window,&attr);
        return {0,0,attr.width,attr.height};
    #elif defined(PLATFORM_HAIKU)
        view->LockLooper();
        BRect frame = view->Frame();
        view->UnlockLooper();
        return {0,0,(int)frame.Width(),(int)frame.Height()};
    #endif
}

void
FX::FXDisplay::Present()
{
    #if defined(BACKEND_X11)
        //if (display) XFlush(display);
    #elif defined(PLATFORM_HAIKU)
        // Presentation handled automatically by Haiku
    #endif
}
