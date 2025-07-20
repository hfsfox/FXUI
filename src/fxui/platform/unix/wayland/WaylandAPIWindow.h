#if defined BACKEND_WAYLAND
    #include <wayland-client.h>
    #include <wayland-cursor.h>
        #if WINDOW_CUSTOM_DECORATIONS
            #include <libdecor.h>
        #endif
    #include <xkbcommon/xkbcommon.h>
    class WaylandAPIWindow
    {
        public:
            WaylandAPIWindow();
            ~WaylandAPIWindow();
        public:
    };
#endif
