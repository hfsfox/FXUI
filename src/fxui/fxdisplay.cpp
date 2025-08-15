//#include "fxwindow.h"
/*#include <X11/Xft/Xft.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrender.h>*/
#include <fxpoint.h>
#include <fxdisplay.h>
#include <fxfont.h>

#if defined (BACKEND_X11)
    #include "platform/unix/x11/X11APIWindow.h"
#elif defined (BACKEND_WAYLAND)
    #include "platform/unix/wayland/WaylandAPIWindow.h"
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
#elif defined (BACKEND_COCOA)
    #include <Carbon/Carbon.h>
    #include <objc/message.h>
    #include <objc/runtime.h>
#endif
#include <cstring>
//#include <iostream>

namespace
{
#ifdef BACKEND_X11
        unsigned long _RGB(int r,int g, int b)
        {
            //return b | (g<<8) | (r<<16);
            //int x = 0x00;
            ulong xrgb( (0x00 << 24) |/*(x << 32 ) |*/ (r << 16) | (g << 8) | (b));
            //return 0x10000000 + rgb;
            return xrgb;
        }

        XftFont      *font;
        XftDraw      *xftdraw;
        XRenderColor xrcolor;
        XftColor     xftcolor;
        XGlyphInfo xglyphinfo;
        //XftTextExtents8

        /*struct X11Platform
        {
            ::Display* x11display;
            ::Window x11window;
            ::GC x11gc;
            int screen;
            ::XImage img;
        };

        class X11Display
        {
            public:
                X11Display()
                {
                    x11p = new X11Platform;
                    x11p->x11display = nullptr;
                    x11p->x11window = 0;
                    x11p->x11gc = nullptr;
                    x11p->screen = 0;
                }
                ~X11Display()
                {
                }
    public:
        void OpenPlatformDisplay()
        {
            if(!x11p)
            {
                printf("err: init X11 backend structure failed \n");
            }
            char *displayName = getenv("DISPLAY");
            if (!displayName || !strlen(displayName))
            {
                printf("err: get $DISPLAY from envirioment failed \n");
            }
            x11p->x11display = XOpenDisplay(0);
            if(!x11p->x11display)
            {
                printf("err: open display failed \n");
            }
            x11dpy = x11p->x11display;
        }
        void OpenPlatformWindow(const char *title, unsigned width, unsigned height, unsigned flags)
        {
            XSetWindowAttributes windowAttributes;
            Visual* visual;
            int depth;

            x11p->screen = DefaultScreen(x11p->x11display);
            ::Window defaultRootWindow = DefaultRootWindow(x11p->x11display);
            int screenWidth  = DisplayWidth(x11p->x11display, x11p->screen);
            int screenHeight = DisplayHeight(x11p->x11display, x11p->screen);

            windowAttributes.border_pixel     = BlackPixel(x11p->x11display, x11p->screen);
            windowAttributes.background_pixel = BlackPixel(x11p->x11display, x11p->screen);
            windowAttributes.backing_store    = NotUseful;

            visual   = DefaultVisual(x11p->x11display, x11p->screen);
            depth    = DefaultDepth(x11p->x11display, x11p->screen);

            int windowWidth  = width;
            int windowHeight = height;

            x11p->x11window = XCreateWindow(
                    x11p->x11display,
                    defaultRootWindow,
                    //posX, posY,
                    10,10,
                    windowWidth, windowHeight,
                    0,
                    depth,
                    InputOutput,
                    visual,
                    CWBackPixel | CWBorderPixel | CWBackingStore,
                    &windowAttributes);
            //XStoreName(x11p->x11display, x11p->x11window, title);
                SetPlatformWindowName(title);

                XSelectInput(x11p->x11display, x11p->x11window,
                KeyPressMask | KeyReleaseMask
                | ButtonPressMask | ButtonReleaseMask | PointerMotionMask
                | StructureNotifyMask | ExposureMask
                | FocusChangeMask
                | EnterWindowMask | LeaveWindowMask
                );

            }

            void SetPlatformWindowName(const char* title)
            {
                XStoreName(x11p->x11display, x11p->x11window, title);
            }
        public:
            ::Display* GetPlatformDisplay() const {return x11dpy;}
            ::Window GetPlatformWindow() const {return x11p->x11window;}
            ::GC GetPlatformGC() const {return x11p->x11gc;}
            int GetPlatformScreen() const {return x11p->screen;}
        private:
            ::Display* x11dpy;
            X11Platform* x11p;

        };

        X11Display* dx11;
        */
    #elif defined BACKEND_COCOA
        //bool standaloneApp = NULL;
        #define cls objc_getClass
        #define sel sel_getUid
        #define msg ((id(*)(id, SEL, ...))objc_msgSend)
        #define cls_msg ((id(*)(Class, SEL, ...))objc_msgSend)

        // poor man's bindings!
typedef enum NSApplicationActivationPolicy {
  NSApplicationActivationPolicyRegular = 0,
  NSApplicationActivationPolicyAccessory = 1,
  NSApplicationActivationPolicyERROR = 2,
} NSApplicationActivationPolicy;

typedef enum NSWindowStyleMask
   {
        NSWindowStyleMaskBorderless = 0,
        NSWindowStyleMaskTitled = 1 << 0,
        NSWindowStyleMaskClosable = 1 << 1,
        NSWindowStyleMaskMiniaturizable = 1 << 2,
        NSWindowStyleMaskResizable = 1 << 3,
    } NSWindowStyleMask;

    typedef enum NSBackingStoreType
    {
        NSBackingStoreBuffered = 2,
    } NSBackingStoreType;


    #endif
}

FX::FXDisplay::FXDisplay()
{
    #if defined(BACKEND_X11)
            display = nullptr; screen = 0; window = 0; gc = nullptr;
            //X11Display* dx11 = new X11Display();
    #elif defined (BACKEND_WAYLAND)
        display = nullptr;
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
    #if defined BACKEND_COCOA
        //if (NSApp == NULL)
        //        {
        //            [NSApplication sharedApplication];
        //           [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
        //            [NSApp activateIgnoringOtherApps:YES];
        //            standaloneApp = true;
        //        }
        //       else
	//	{
        //            standaloneApp = false;
	//	}
        id app = cls_msg(cls("NSApplication"), sel("sharedApplication"));
        msg(app, sel("setActivationPolicy:"), NSApplicationActivationPolicyRegular);
        msg(app, sel("activateIgnoringOtherApps:"), true);

// Create main menu bar
    id mainMenuBar = msg(cls_msg(cls("NSMenu"), sel("alloc")), sel("init"));
    
    // Create application menu item (this will be the first item in the menu bar)
    id appMenuItem = msg(cls_msg(cls("NSMenuItem"), sel("alloc")), sel("init"));
    
    // Add application menu item to main menu bar
    msg(mainMenuBar, sel("addItem:"), appMenuItem);
    
    // Create application submenu
    id appTitle = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "Application");
    id appMenu = msg(cls_msg(cls("NSMenu"), sel("alloc")), sel("initWithTitle:"), appTitle);
    
    // Set the submenu for the application menu item
    msg(appMenuItem, sel("setSubmenu:"), appMenu);
    
    // Add some common application menu items
    
    // About menu item
    id aboutTitle = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "About");
    id aboutItem = msg(cls_msg(cls("NSMenuItem"), sel("alloc")), 
                      sel("initWithTitle:action:keyEquivalent:"), 
                      aboutTitle, sel("orderFrontStandardAboutPanel:"), 
                      cls_msg(cls("NSString"), sel("string")));
    msg(aboutItem, sel("setTarget:"), app);
    msg(appMenu, sel("addItem:"), aboutItem);
    
    // Separator
    id separator = cls_msg(cls("NSMenuItem"), sel("separatorItem"));
    msg(appMenu, sel("addItem:"), separator);
    
    // Quit menu item
    id quitTitle = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "Quit");
    id quitKeyEquiv = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "q");
    id quitItem = msg(cls_msg(cls("NSMenuItem"), sel("alloc")),
                     sel("initWithTitle:action:keyEquivalent:"),
                     quitTitle, sel("terminate:"), quitKeyEquiv);
    msg(quitItem, sel("setTarget:"), app);
    msg(appMenu, sel("addItem:"), quitItem);
    
    // Set the main menu
    msg(app, sel("setMainMenu:"), mainMenuBar);
    
    // Clean up (release objects)
    msg(appMenuItem, sel("release"));
    msg(appMenu, sel("release"));
    msg(aboutItem, sel("release"));
    msg(quitItem, sel("release"));
    msg(mainMenuBar, sel("release"));


        msg(app, sel("run"));
        return true;
    #elif defined(BACKEND_X11)
        //display = XOpenDisplay(nullptr);
        X11DisplayInstance* xdi;
        display = xdi->GetDisplayInstance();
        //dx11->OpenPlatformDisplay();
        //display = dx11->GetPlatformDisplay();
        if (!display) return false;
        screen = DefaultScreen(display);
        //screen = dx11->GetPlatformScreen();
        return true;
    #elif defined (BACKEND_WAYLAND)
        WaylandDisplayInstance* wdi;
        display = wdi->GetDisplayInstance();
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
        #elif defined(BACKEND_WAYLAND)
            return static_cast<void*>(display);
        #elif defined(BACKEND_BEAPI)
            return static_cast<void*>(view);
        #elif defined (BACKEND_COCOA)
            //int* dpy;
            //dpy = 1; 
	    //return static_cast<void*>(dpy);
           return static_cast<void*>(app); 
        #endif
}

void
FX::FXDisplay::Clear()
{
    #if defined (BACKEND_X11)
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
    #if defined (BACKEND_X11)
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
    #elif defined(BACKEND_BEAPI)
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
    #if defined(BACKEND_BEAPI)
        view->LockLooper();
        view->SetHighColor(color.red, color.green, color.blue, color.alpha);
        view->StrokeEllipse(BPoint(center_x,center_y),radius,radius, B_SOLID_HIGH);
        view->UnlockLooper();
    #elif defined (BACKEND_X11)
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
    #if defined(BACKEND_BEAPI)
    #elif defined (BACKEND_X11)
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
    #if defined(BACKEND_BEAPI)
    	view->LockLooper();
        view->SetHighColor(color.red, color.green, color.blue, color.alpha);
        view->StrokeLine(BPoint(center_x_begin,center_y_begin), BPoint(center_x_end,center_y_end),B_SOLID_HIGH);
        //view->StrokeEllipse(BPoint(center_x,center_y),radius,radius, B_SOLID_HIGH);
        view->UnlockLooper();
    #elif defined (BACKEND_X11)
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
    #elif defined(BACKEND_BEAPI)
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
    #if defined(BACKEND_BEAPI)
        view->LockLooper();
        view->SetHighColor(color.red, color.green, color.blue, color.alpha);
        view->FillRect(BRect(x_begin,y_begin,width,height),B_SOLID_HIGH);
        view->UnlockLooper();
    #elif defined (BACKEND_X11)
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
    #if defined(BACKEND_BEAPI)
        view->LockLooper();
        view->SetHighColor(color.red, color.green, color.blue, color.alpha);
        view->FillEllipse(BPoint(center_x,center_y),radius,radius, B_SOLID_HIGH);
        view->UnlockLooper();
    #elif defined (BACKEND_X11)
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
FX::FXDisplay::DrawTriangle(int x_a_begin, int y_a_begin,int x_b_begin, int y_b_begin,int x_c_begin, int y_c_begin)
{
    #if defined (BACKEND_X11)
    #endif
}

void
FX::FXDisplay::DrawTriangle(FX::FXPoint where_a_begin, FX::FXPoint where_b_begin, FX::FXPoint where_c_begin)
{
    FXDisplay::DrawTriangle(where_a_begin.x, where_a_begin.y, where_b_begin.x, where_b_begin.y, where_c_begin.x, where_c_begin.y);
}

void
FX::FXDisplay::FillTriangle(int x_a_begin, int y_a_begin,int x_b_begin, int y_b_begin,int x_c_begin, int y_c_begin)
{
    #if defined (BACKEND_X11)
    #endif
}

void
FX::FXDisplay::FillTriangle(FX::FXPoint where_a_begin, FX::FXPoint where_b_begin, FX::FXPoint where_c_begin)
{
    FXDisplay::FillTriangle( where_a_begin.x, where_a_begin.y, where_b_begin.x, where_b_begin.y, where_c_begin.x, where_c_begin.y);
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
    #if defined(BACKEND_BEAPI)
        view->LockLooper();
        view->SetViewColor(color.red, color.green, color.blue, color.alpha);
        view->UnlockLooper();
    #elif defined (BACKEND_X11)
        //XColor c;
        //c = {color.red,color.green,color.blue};
        //c = {160, 160, 160, 255};
        XSetForeground(display, gc, _RGB(color.red,color.green,color.blue));
        //XSetForeground(display, gc, 0x00CCCCCC);
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
    #elif defined(BACKEND_BEAPI)
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
    #elif defined(BACKEND_BEAPI)
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
    #elif defined(BACKEND_BEAPI)
        // Presentation handled automatically by Haiku
    #endif
}
