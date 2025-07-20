#include <fxplatformuidefs.h>

#if defined BACKEND_X11 && !defined BACKEND_BEAPI
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <X11/xpm.h>
    #include <xkbcommon/xkbcommon.h>

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
            void X11OpenDisplay()
            {
                char *displayName = getenv("DISPLAY");
                if (!displayName || !strlen(displayName))
                {
                    displayName = (char*)":0.0";
                }
                xDisplay = XOpenDisplay(displayName);
            }
        public:
            ::Display* xDisplay;
            ::Window xWindow;
            ::Atom wmDeleteMessage;
    };
#endif
