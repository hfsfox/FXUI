#include <fxwindow.h>
#include <fxplatformuidefs.h>

#if defined BACKEND_X11 && !defined BACKEND_BEAPI
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <X11/xpm.h>
    #include <xkbcommon/xkbcommon.h>

    #include<X11/Xft/Xft.h>

    #include <cstdlib>
    #include <cstring>

    #include <mutex>
    #include <memory>


class X11DisplayInstance
{
    public:
        static ::Display* GetDisplayInstance();
        // Prevent copying and assignment
        X11DisplayInstance(const X11DisplayInstance&) = delete;
        X11DisplayInstance& operator=(const X11DisplayInstance&) = delete;
    private:
		X11DisplayInstance() = default;
        static std::once_flag initialized;
    	static std::unique_ptr<::Display*> instance;
};

/*struct X11Platform
{
    ::Display* x11display;
    ::Window x11window;
    ::GC x11gc;
    int screen;
    ::XImage img;
};*/

/*
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
    //formats  = XListPixmapFormats(window_data_x11->display, &formatCount);
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
*/


 /*
    class X11APIWindow
    {
        public:
            X11APIWindow()
            {
                //char *displayName = getenv("DISPLAY");
                xDisplay = nullptr; xWindow = 0;
            }
            ~X11APIWindow();
        public:
            ::Display* GetX11Display() const {return xDisplay;};
            void X11OpenDisplay()
            {
                char *displayName = getenv("DISPLAY");
                if (!displayName || !strlen(displayName))
                {
                    printf("err: get $DISPLAY from envirioment failed \n");
                    printf("using fallback value to :0.0 \n");
                    // fallback value for connect to default address
                    displayName = (char*)":0.0";
                }
                xDisplay = XOpenDisplay(displayName);
            }
            void X11CreateWindow()
            {
                FX::FXRect rect = {100,100,100,100};
                xWindow = XCreateSimpleWindow(xDisplay, RootWindow(xDisplay, 0),
                                     rect.x, rect.y, rect.width, rect.height, 1,
                                     BlackPixel(xDisplay, 0),
                                     WhitePixel(xDisplay, 0));
            }
        public:
            ::Display* xDisplay;
            ::Window xWindow;
            ::Atom wmDeleteMessage;
    };
    */
#endif
