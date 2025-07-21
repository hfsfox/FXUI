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
#endif
