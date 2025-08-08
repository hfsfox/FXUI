#include "WaylandAPIWindow.h"

#if defined (BACKEND_WAYLAND)

#include <mutex>
#include <memory>

#include <wayland-client.h>
#include <wayland-cursor.h>

// Static member definitions
std::once_flag WaylandDisplayInstance::initialized;
std::unique_ptr<struct wl_display*> WaylandDisplayInstance::instance;

::wl_display*
WaylandDisplayInstance::GetDisplayInstance()
{
    std::call_once(initialized, []()
    {
        instance = std::make_unique<struct wl_display*>(wl_display_connect(NULL));
    }
    );
    return *instance.get();
};

#endif
