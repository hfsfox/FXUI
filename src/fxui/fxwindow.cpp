#include <fxwindow.h>
#include <fxplatformuidefs.h>

#if defined BACKEND_X11 && !defined BACKEND_BEAPI
    #include "platform/unix/x11/X11APIWindow.h"
#elif defined BACKEND_WAYLAND
    #include "platform/unix/wayland/WaylandAPIWindow.h"
#elif defined BACKEND_BEAPI
    #include <app/Application.h>
    //#include <interface/Window.h>
    #include <game/DirectWindow.h>
    #include <interface/View.h>
    //#include <support/String.h>
    //#include <interface/Font.h>
    //#include <app/Cursor.h>
    #include <interface/Bitmap.h>
    #include <translation/TranslationUtils.h>
    #include <storage/Resources.h>
    #include <GraphicsDefs.h>
    #include <InterfaceDefs.h>
    //#include <iostream>
    #include "platform/haiku/BApplicationInstance.h"
    #include "platform/haiku/BeAPIWindow.h"
    #include "platform/haiku/BeAPIView.h"
#elif defined BACKEND_WINAPI
    #include <windows.h>
#endif

#include <cstdio>

#if defined(BACKEND_BEAPI)
    static BApplication* app = nullptr;
#elif defined (BACKEND_WAYLAND)
    static struct wl_surface *surface = NULL;
    static struct xdg_toplevel *xdg_toplevel = NULL;
#endif

namespace
{
    #if defined(BACKEND_X11)
        ::Display* xDisplay;
        ::Window xWindow;
        ::Atom wmDeleteMessage;
    #elif defined (BACKEND_WAYLAND)
        ::wl_display* wDisplay;
        //::xdg_toplevel *xdg_toplevel;
    #elif defined(BACKEND_BEAPI)
        //class FHaikuWindow;
        //class FHaikuView;

        BeAPIWindow* haikuWindow;
        BeAPIView* haikuView;
        //int haikuView::frameCount = 0;
    #elif defined (BACKEND_WINAPI)
        ::HWND hWindow;
    #endif

    #ifdef BACKEND_BEAPI
/*class FHaikuView : public BView {
public:
    FHaikuView(BRect frame, FX::FXDisplay* display)
    :
    BView(frame, "FView", B_FOLLOW_ALL, B_WILL_DRAW | B_SUBPIXEL_PRECISE | B_PULSE_NEEDED), fDisplay(display)
    {
    }

    virtual void Draw(BRect updateRect) override
    {
    }

    virtual void MouseUp(BPoint point) override
    {
        std::cout << "click up" << std::endl;
        BView::MouseUp(point);
    }

    virtual void MouseDown(BPoint point) override
    {
        std::cout << "click down" << std::endl;
        BView::MouseDown(point);
    }


private:
    FX::FXDisplay* fDisplay;
    static int frameCount;
};*/

/*class FHaikuWindow : public BDirectWindow
    {
    public:
        FHaikuWindow(BRect frame, const char* title)
            :
            BDirectWindow(frame, title, B_TITLED_WINDOW, B_QUIT_ON_WINDOW_CLOSE), fShouldClose(false)
            {
            }
        virtual bool QuitRequested() override {
            fShouldClose = true;
            BApplicationInstance::GetInstance()->PostMessage(B_QUIT_REQUESTED);
            return true;
        }

        bool ShouldClose() const { return fShouldClose; }

    private:
        volatile bool fShouldClose;
    };
*/

//#define FHaikuWindow Be;

    //int BeAPIView::frameCount = 0;
    //int BeAPIView::frameCount = 0;
    #endif
}

FX::FXWindow::FXWindow(FX::FXDisplay* display, const FX::FXRect& rect, const char* title)
    :
    display(display), rect(rect), title(title), shouldClose(false)
    {
        #if defined (BACKEND_X11)
            xDisplay = nullptr; xWindow = 0; wmDeleteMessage = 0;
        #elif defined (BACKEND_WAYLAND)
            wDisplay = nullptr;
        #elif defined (BACKEND_BEAPI)
            haikuWindow = nullptr; haikuView = nullptr;
        #endif
    }

FX::FXWindow::~FXWindow()
{
    #if defined(PLATFORM_LINUX)
        if (xDisplay && xWindow)
        {
            XUnmapWindow(xDisplay, xWindow);
            XDestroyWindow(xDisplay, xWindow);
        }
    #elif defined(PLATFORM_HAIKU)
        // Window cleanup handled by Haiku - no manual locking needed
        if (haikuWindow && haikuWindow->Lock())
        {
            haikuWindow->Quit();
        }
    #endif
}

bool
FX::FXWindow::Create()
{
    #if defined(BACKEND_X11)
        if (!display->display) return false;
        xDisplay = display->display;

        xWindow = XCreateSimpleWindow(xDisplay, RootWindow(xDisplay, display->screen),
                                     rect.x, rect.y, rect.width, rect.height, 1,
                                     BlackPixel(xDisplay, display->screen),
                                     WhitePixel(xDisplay, display->screen));
        if (!xWindow) return false;

        XStoreName(xDisplay, xWindow, title);
        wmDeleteMessage = XInternAtom(xDisplay, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(xDisplay, xWindow, &wmDeleteMessage, 1);

        display->window = xWindow;
        display->gc = XCreateGC(xDisplay, xWindow, 0, nullptr);
        XSelectInput(xDisplay, xWindow, ExposureMask | KeyPressMask | StructureNotifyMask);
        return true;

    #elif defined(BACKEND_BEAPI)
        // Create BApplication only once
        if (!app) {
            //app = new BApplication("application/x-vnd.FWindow");
            app = BApplicationInstance::GetInstance();
        }

        BRect windowRect(rect.x, rect.y, rect.x + rect.width, rect.y + rect.height);
        //haikuWindow = new FHaikuWindow(windowRect, title);
        haikuWindow = new BeAPIWindow(windowRect, title);

        haikuView = new BeAPIView(haikuWindow->Bounds(), display);
        haikuWindow->AddChild(haikuView);
        //haikuView->EnableDirectMode(false);
        //haikuWindow

        display->view = haikuView;
        //display->
        return true;
    #endif
}

void
FX::FXWindow::Show()
{
    #if defined(PLATFORM_LINUX)
        if (xDisplay && xWindow) XMapWindow(xDisplay, xWindow);
    #elif defined(PLATFORM_HAIKU)
        if (haikuWindow) haikuWindow->Show();
    #endif
}

void
FX::FXWindow::Hide()
{
    #if defined(PLATFORM_LINUX)
    #elif defined(PLATFORM_HAIKU)
        if(!haikuWindow->IsHidden())
        {
            haikuWindow->Hide();
        }
    #endif
}

bool
FX::FXWindow::ProcessEvents()
{
    #if defined(PLATFORM_LINUX)
        if (!xDisplay) return false;
        XEvent event;
        while (XPending(xDisplay)) {
            XNextEvent(xDisplay, &event);
            if (event.type == ClientMessage && event.xclient.data.l[0] == wmDeleteMessage) {
                shouldClose = true;
                return false;
            }
            if (event.type == Expose) {
                display->Clear();
                /*FColor textColor = {0,0,0,255};
                display->DrawText("Hello, Linux World!", 50, 50, textColor);*/
                display->Present();
            }
        }
        return !shouldClose;

    #elif defined(PLATFORM_HAIKU)
        // Process events without blocking
        if (app) {
            //BMessage* msg = app->MessageQueue()->NextMessage(0); // Non-blocking
            //app->MessageQueue();
            /*BMessage* msg = app->CurrentMessage();
            if (msg) {
                app->DispatchMessage(msg, app);
                delete msg;
            }*/
        }

        // Check window close status without locking issues
        if (haikuWindow) {
            shouldClose = haikuWindow->ShouldClose();
        }

        return !shouldClose;
    #endif
}

void
FX::FXWindow::SetTitle(const char* title)
{
    #if defined (PLATFORM_HAIKU)
        haikuWindow->SetTitle(title);
    #elif defined (BACKEND_X11)
        char title_buffer[1024];
        sprintf(title_buffer, title , "\n");
        XStoreName(xDisplay, xWindow, title_buffer);
    #endif
}


void
FX::FXWindow::MoveTo(FX::FXPoint where)
{
    #if defined(PLATFORM_LINUX)
    #elif defined(PLATFORM_HAIKU)
    #endif
}

void
FX::FXWindow::ResizeTo(FX::FXRect& newSize)
{
    #if defined(PLATFORM_LINUX)
    #elif defined(PLATFORM_HAIKU)
    #endif
}
