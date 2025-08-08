
#include <fxplatformuidefs.h>

#if defined BACKEND_WAYLAND

#include <wayland-client.h>
#include <wayland-cursor.h>
    #if WINDOW_CUSTOM_DECORATIONS
            #include <libdecor.h>
    #endif
#include <xkbcommon/xkbcommon.h>

#include <mutex>
#include <memory>

class WaylandDisplayInstance
{
    public:
        static struct wl_display* GetDisplayInstance();
        // Prevent copying and assignment
        WaylandDisplayInstance(const WaylandDisplayInstance&) = delete;
        WaylandDisplayInstance& operator=(const WaylandDisplayInstance&) = delete;
    private:
		WaylandDisplayInstance() = default;
        static std::once_flag initialized;
    	static std::unique_ptr<struct wl_display*> instance;
};

    /*class WaylandAPIWindow
    {
        public:
            WaylandAPIWindow();
            ~WaylandAPIWindow();
        public:
    };*/
#endif
