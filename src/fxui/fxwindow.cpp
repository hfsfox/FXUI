#include <fxwindow.h>
#include <fxplatformuidefs.h>

#if defined BACKEND_X11 && !defined BACKEND_BEAPI
    #include "platform/unix/x11/X11APIWindow.h"
#elif defined BACKEND_WAYLAND && !defined BACKEND_BEAPI
    #include "platform/unix/wayland/WaylandAPIWindow.h"
    //#include "platform/unix/wayland/protocols/xdg-shell-client-protocol.h"
    //#include "platform/unix/wayland/protocols/xdg-decoration-unstable-v1.h"
    #include <wayland-client-protocol.h>
    //#include <sys/mman.h>
    //#include <sys/stat.h>
    //#include <errno.h>
    //#include <fcntl.h>
    //#include <unistd.h>
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
#include <cstring>

#if defined(BACKEND_BEAPI)
    static BApplication* app = nullptr;
#elif defined (BACKEND_WAYLAND)
    static struct wl_surface *surface = NULL;
    static struct wl_compositor* compositor = NULL;
    static struct wl_buffer *buffer = NULL;
    static struct xdg_toplevel *xdg_toplevel = NULL;
    static struct xdg_surface *xdg_surface = NULL;
    static struct xdg_wm_base *xdg_wm_base = NULL;
    static struct wl_registry* registry = NULL;

    static struct wl_shm* shm = NULL;

    void* shm_data = NULL;

    struct zxdg_decoration_manager_v1* decoration_manager;
    struct zxdg_toplevel_decoration_v1* decoration;

    bool configured;
    bool running;
    bool toplevel_close;

    int width, height, stride;
    //struct xdg_toplevel *xdg_toplevel;
#endif

#if defined (BACKEND_WAYLAND) && !defined (BACKEND_X11)

    // XDG WM Base callbacks
    static void xdg_wm_base_ping(void *data, struct xdg_wm_base *xdg_wm_base, uint32_t serial)
    {
        xdg_wm_base_pong(xdg_wm_base, serial);
    }

    static const struct xdg_wm_base_listener xdg_wm_base_listener = {
        .ping = xdg_wm_base_ping,
    };

    // XDG toplevel callbacks
        static void xdg_toplevel_configure(void *data, struct xdg_toplevel *xdg_toplevel,
                                 int32_t width, int32_t height, struct wl_array *states)
        {
            int activated = 0;
            int maximized = 0;
            int fullscreen = 0;
            int resizing = 0;
            int floating = 1;
            if (width > 0 && height > 0)
            {
                width = width;
                height = height;
            }
        }

        static void xdg_toplevel_close(void *data, struct xdg_toplevel *xdg_toplevel)
        {
        //struct wayland_window *state = (wayland_window*)data;
        //state->running = false;
            //run
            toplevel_close = true;
        }

    static const struct xdg_toplevel_listener xdg_toplevel_listener =
    {
        .configure = xdg_toplevel_configure,
        .close = xdg_toplevel_close
    };

    // XDG surface callbacks
static void xdg_surface_configure(void *data, struct xdg_surface *xdg_surface, uint32_t serial) {
    //struct wayland_window *state = (wayland_window*)data;
    xdg_surface_ack_configure(xdg_surface, serial);
    configured = true;
}

static const struct xdg_surface_listener xdg_surface_listener = {
    .configure = xdg_surface_configure,
};

// Create anonymous file for shared memory
static int create_shm_file(off_t size)
{
    /*char name[1024] = "";

    const char *path = getenv("XDG_RUNTIME_DIR");
    if (!path) {
        fprintf(stderr, "Please define environment variable XDG_RUNTIME_DIR\n");
        exit(1);
    }

    strcpy(name, path);
    strcat(name, "/wl_shm-XXXXXX");
    */

    char name[] = "/wl_shm-XXXXXX";
    //int fd = mkstemp(name);
    int fd = shm_open(name, O_RDWR | O_CREAT, DEFFILEMODE);
    ftruncate(fd, size);
    if (fd < 0) {
        fprintf(stderr, "Failed to create temporary file: %s\n", strerror(errno));
        return -1;
    }

    unlink(name);

    if (ftruncate(fd, size) < 0) {
        fprintf(stderr, "Failed to truncate file: %s\n", strerror(errno));
        close(fd);
        return -1;
    }

    return fd;
}


// Create shared memory buffer
static struct wl_buffer *create_buffer(int32_t width, int32_t height)
{
    int32_t stride = width * 4; // 4 bytes per pixel (ARGB)
    int32_t size = stride * height;

    int fd = create_shm_file(size);
    if (fd < 0) {
        return NULL;
    }

    void *data = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (data == MAP_FAILED) {
        fprintf(stderr, "mmap failed: %s\n", strerror(errno));
        close(fd);
        return NULL;
    }

    struct wl_shm_pool *pool = wl_shm_create_pool(shm, fd, size);
    struct wl_buffer *buffer = wl_shm_pool_create_buffer(pool, 0, width, height, stride, WL_SHM_FORMAT_ARGB8888);

    wl_shm_pool_destroy(pool);
    close(fd);

    shm_data = data;
    return buffer;
}

// Main render loop
static void render_frame(/*struct wayland_window *state*/)
{
    if (buffer) {
        wl_buffer_destroy(buffer);
        munmap(shm_data, width * height * 4);
    }
    buffer = create_buffer(width, height);
    if (!buffer) {
        fprintf(stderr, "Failed to create buffer\n");
        return;
    }

    uint32_t *pixel = (uint32_t *)shm_data;

    memset(pixel, 0x00EEEEEEEE, width * height * 4);

    // Attach buffer and commit
    wl_surface_attach(surface, buffer, 0, 0);
    wl_surface_damage(surface, 0, 0, width, height);
    wl_surface_commit(surface);
}

#endif

namespace
{
    #if defined(BACKEND_X11)
        ::Display* xDisplay;
        ::Window xWindow;
        ::Atom wmDeleteMessage;
    #elif defined (BACKEND_WAYLAND)
        ::wl_display* wDisplay;
        //::wl_compositor* compositor;
        //::wl_surface* surface;

        // Registry callbacks
        static void registry_global(void *data, struct wl_registry *registry, uint32_t id,
                          const char *interface, uint32_t version)
        {
    //struct wayland_window *state = (wayland_window*)data;

        if (strcmp(interface, wl_compositor_interface.name) == 0)
        {
            compositor = (wl_compositor*)wl_registry_bind(registry, id, &wl_compositor_interface, 4);
        }
        else if (strcmp(interface, xdg_wm_base_interface.name) == 0)
        {
            //xdg_wm_base = (xdg_wm_base*)wl_registry_bind(registry, id, &xdg_wm_base_interface, 1);
            xdg_wm_base = static_cast<struct xdg_wm_base*>( wl_registry_bind(registry, id, &xdg_wm_base_interface, 1));
            xdg_wm_base_add_listener(xdg_wm_base, &xdg_wm_base_listener, NULL);
        }

        else if (strcmp(interface, zxdg_decoration_manager_v1_interface.name) == 0)
        {
            decoration_manager = (zxdg_decoration_manager_v1*)wl_registry_bind(registry, id, &zxdg_decoration_manager_v1_interface, 1);
        //state->decoration = zxdg_decoration_manager_v1_get_toplevel_decoration(state->decoration_manager, state->xdg_toplevel);
        //zxdg_toplevel_decoration_v1_set_mode(state->decoration, ZXDG_TOPLEVEL_DECORATION_V1_MODE_SERVER_SIDE);
        }
        else if (strcmp(interface, wl_shm_interface.name) == 0)
        {
            shm = (wl_shm*)wl_registry_bind(registry, id, &wl_shm_interface, 1);
        }
    /*else if (strcmp(interface, wl_shm_interface.name) == 0) {
        state->shm = (wl_shm*)wl_registry_bind(registry, id, &wl_shm_interface, 1);
        state->cursor_theme = wl_cursor_theme_load(NULL, 32, state->shm);
    } else if (strcmp(interface, xdg_wm_base_interface.name) == 0) {
        state->xdg_wm_base = (xdg_wm_base*)wl_registry_bind(registry, id, &xdg_wm_base_interface, 1);
        xdg_wm_base_add_listener(state->xdg_wm_base, &xdg_wm_base_listener, state);
    } else if (strcmp(interface, zxdg_decoration_manager_v1_interface.name) == 0){
        state->decoration_manager = (zxdg_decoration_manager_v1*)wl_registry_bind(registry, id, &zxdg_decoration_manager_v1_interface, 1);
        //state->decoration = zxdg_decoration_manager_v1_get_toplevel_decoration(state->decoration_manager, state->xdg_toplevel);
        //zxdg_toplevel_decoration_v1_set_mode(state->decoration, ZXDG_TOPLEVEL_DECORATION_V1_MODE_SERVER_SIDE);
    }
            else if (strcmp(interface, wl_seat_interface.name) == 0)
            {
            state->seat = (wl_seat*)wl_registry_bind(registry, id, &wl_seat_interface, 2);
            wl_seat_add_listener(state->seat, &seat_listener, state);
            }
            */
        }

        static void registry_global_remove(void *data, struct wl_registry *registry, uint32_t id)
        {
            // Handle global object removal if needed
        }

        static const struct wl_registry_listener registry_listener =
        {
            .global = registry_global,
            .global_remove = registry_global_remove,
        };

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
    #if defined(PLATFORM_LINUX) && defined (BACKEND_X11)
        if (xDisplay && xWindow)
        {
            XUnmapWindow(xDisplay, xWindow);
            XDestroyWindow(xDisplay, xWindow);
        }
    #elif defined(PLATFORM_LINUX) && defined (BACKEND_WAYLAND)
        fprintf(stdout, "cleanup window structs \n");
        if (buffer)
        {
            wl_buffer_destroy(buffer);
            munmap(shm_data, width * height * 4);
        }
        if (xdg_toplevel) {
            xdg_toplevel_destroy(xdg_toplevel);
        }
        if (xdg_surface) {
            xdg_surface_destroy(xdg_surface);
        }
        if (surface) {
            wl_surface_destroy(surface);
        }

        if (xdg_wm_base) {
            xdg_wm_base_destroy(xdg_wm_base);
        }
        if (shm) {
            wl_shm_destroy(shm);
        }
        if (compositor) {
            wl_compositor_destroy(compositor);
        }
        if (registry) {
            wl_registry_destroy(registry);
        }
        if(wDisplay)
        {
            wl_display_disconnect(wDisplay);
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
    fprintf(stdout, "try to create window\n");
    #if defined(BACKEND_X11)
        if (!display->display) return false;
        //xDisplay = display->display;
        X11DisplayInstance* xdi;
        xDisplay = xdi->GetDisplayInstance();

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
        //XSelectInput(xDisplay, xWindow, ExposureMask | KeyPressMask | StructureNotifyMask);
        XSelectInput(xDisplay, xWindow,
        KeyPressMask | KeyReleaseMask
        | ButtonPressMask | ButtonReleaseMask | PointerMotionMask
        | StructureNotifyMask | ExposureMask
        | FocusChangeMask
        | EnterWindowMask | LeaveWindowMask
        );
        return true;

    #elif defined (BACKEND_WAYLAND)
        if (!display->display) return false;
        WaylandDisplayInstance* wdi;
        wDisplay = wdi->GetDisplayInstance();

        // Get registry
        registry = wl_display_get_registry(wDisplay);
        wl_registry_add_listener(registry, &registry_listener, NULL);
        // Wait for registry events
        wl_display_roundtrip(wDisplay);

        surface = wl_compositor_create_surface(compositor);
        if (!surface)
        {
            fprintf(stderr, "Failed to create surface\n");
            return false;
        }

        xdg_surface = xdg_wm_base_get_xdg_surface(xdg_wm_base,surface);
        if (!xdg_surface)
        {
        fprintf(stderr, "Failed to create XDG surface\n");
        return false;
        }

        xdg_surface_add_listener(xdg_surface, &xdg_surface_listener, NULL);

        //width = 800;
        //height = 600;

        //rect.x, rect.y, rect.width, rect.height

        width = rect.width;
        height = rect.height;

        // Create XDG toplevel
        xdg_toplevel = xdg_surface_get_toplevel(xdg_surface);
        if (!xdg_toplevel)
        {
            fprintf(stderr, "Failed to create XDG toplevel\n");
            return false;
        }
        xdg_toplevel_add_listener(xdg_toplevel, &xdg_toplevel_listener, NULL);

    // Set window properties
    xdg_toplevel_set_title(xdg_toplevel, "Wayland Window");
    xdg_toplevel_set_app_id(xdg_toplevel, "simple-wayland-window");

    xdg_toplevel_set_min_size(xdg_toplevel, 100, 100);

    decoration = zxdg_decoration_manager_v1_get_toplevel_decoration(decoration_manager, xdg_toplevel);
    zxdg_toplevel_decoration_v1_add_listener(decoration, NULL/*&decoration_listener*/, NULL);

    wl_surface_commit(surface);

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
    #if defined(PLATFORM_LINUX) && defined (BACKEND_X11)
        if (xDisplay && xWindow) //XMapWindow(xDisplay, xWindow);
            XMapRaised(xDisplay, xWindow);
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
    #if defined(BACKEND_X11)
        if (!xDisplay) return false;
        XEvent event;
        while (XPending(xDisplay) > 0)
        {
            XNextEvent(xDisplay, &event);
            if (event.type == ClientMessage && event.xclient.data.l[0] == wmDeleteMessage)
            {
                shouldClose = true;
                return false;
            }
            if (event.type == Expose)
            {
                //display->Clear();
                //display->Present();
            }
            if (event.type == ButtonPress)
            {
                if (event.xbutton.button == 1)
                {
                    fprintf(stdout, "right click \n");
                }
                if (event.xbutton.button == 3)
                {
                    fprintf(stdout, "left click \n");
                }
            //exit(0);
            //return NULL;
            }
        }
        return !shouldClose;
    #elif defined (BACKEND_WAYLAND)
    if(!wDisplay) return false;
    //wl_display_dispatch(wDisplay);
        //while (!configured && shouldClose)
    //{
        //wl_display_dispatch(wDisplay);
    //}

    while (!shouldClose /*== toplevel_close*/)
    {
        if (configured)
        {
            render_frame();
        }
        SetTitle(title);
        //ResizeTo(FX::FXRect rect());
        if (wl_display_dispatch(wDisplay) == -1) {
            fprintf(stderr, "Display dispatch failed\n");
            break;
        }
        if(toplevel_close == true)
        {
            shouldClose = toplevel_close;
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
    #elif defined (BACKEND_WAYLAND)
        xdg_toplevel_set_title(xdg_toplevel, title);
        //wl_surface_commit(surface);
        //wl_display_flush(wDisplay);
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
