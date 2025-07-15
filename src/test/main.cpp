#include <fxui.h>
//#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#elif defined(__linux__) || defined(__unix__)
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <cstring>
#endif

#include <iostream>
#include <thread>
#include <chrono>

// Forward declarations
class FDisplay;
class FWindow;

/*// Rectangle structure for window dimensions
struct FRect {
    int x, y, width, height;

    FRect(int x = 0, int y = 0, int w = 800, int h = 600)
        : x(x), y(y), width(w), height(h) {}
};*/

// Display context class
class FDisplay {
private:
#ifdef _WIN32
    HDC hdc;
    HWND hwnd;
#elif defined(__linux__) || defined(__unix__)
    Display* display;
    int screen;
    Window window;
    GC gc;
#endif

public:
    FDisplay();
    ~FDisplay();

    // Platform-specific initialization
    bool Initialize();
    void Cleanup();

    // Get native display context
    void* GetNativeContext() const;

    // Drawing operations
    void Clear();
    void DrawText(const char* text, int x, int y);
    void Present();

    // Friend class to allow FWindow to access private members
    friend class FWindow;
};

// Window class
class FWindow {
private:
    FDisplay* display;
    FX::FXRect rect;
    const char* title;
    bool isVisible;

#ifdef _WIN32
    HWND hwnd;
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    static bool classRegistered;
#elif defined(__linux__) || defined(__unix__)
    Display* xDisplay;
    Window xWindow;
    Atom wmDeleteMessage;
#endif

public:
    FWindow(FDisplay* display, const FX::FXRect& rect, const char* title);
    ~FWindow();

    // Window operations
    bool Create();
    void Show();
    void Hide();
    void SetTitle(const char* newTitle);

    // Event handling
    bool ProcessEvents();
    bool ShouldClose();

    // Get associated display
    FDisplay* GetDisplay() const { return display; }

    // Get window dimensions
    const FX::FXRect& GetRect() const { return rect; }
};

// Implementation

// FDisplay Implementation
FDisplay::FDisplay() {
#ifdef _WIN32
    hdc = nullptr;
    hwnd = nullptr;
#elif defined(__linux__) || defined(__unix__)
    display = nullptr;
    screen = 0;
    window = 0;
    gc = nullptr;
#endif
}

FDisplay::~FDisplay() {
    Cleanup();
}

bool FDisplay::Initialize() {
#ifdef _WIN32
    // Windows implementation will be handled by FWindow
    return true;
#elif defined(__linux__) || defined(__unix__)
    display = XOpenDisplay(nullptr);
    if (!display) {
        return false;
    }
    screen = DefaultScreen(display);
    return true;
#endif
}

void FDisplay::Cleanup() {
#ifdef _WIN32
    if (hdc) {
        ReleaseDC(hwnd, hdc);
        hdc = nullptr;
    }
#elif defined(__linux__) || defined(__unix__)
    if (gc) {
        XFreeGC(display, gc);
        gc = nullptr;
    }
    if (display) {
        XCloseDisplay(display);
        display = nullptr;
    }
#endif
}

void* FDisplay::GetNativeContext() const {
#ifdef _WIN32
    return static_cast<void*>(hdc);
#elif defined(__linux__) || defined(__unix__)
    return static_cast<void*>(display);
#endif
}

void FDisplay::Clear() {
#ifdef _WIN32
    if (hdc && hwnd) {
        RECT clientRect;
        GetClientRect(hwnd, &clientRect);
        FillRect(hdc, &clientRect, (HBRUSH)(COLOR_WINDOW + 1));
    }
#elif defined(__linux__) || defined(__unix__)
    if (display && window && gc) {
        XClearWindow(display, window);
    }
#endif
}

void FDisplay::DrawText(const char* text, int x, int y) {
#ifdef _WIN32
    if (hdc) {
        TextOutA(hdc, x, y, text, strlen(text));
    }
#elif defined(__linux__) || defined(__unix__)
    if (display && window && gc) {
        XDrawString(display, window, gc, x, y, text, strlen(text));
    }
#endif
}

void FDisplay::Present() {
#ifdef _WIN32
    // Windows automatically presents, no action needed
#elif defined(__linux__) || defined(__unix__)
    if (display) {
        XFlush(display);
    }
#endif
}

// FWindow Implementation
#ifdef _WIN32
bool FWindow::classRegistered = false;

LRESULT CALLBACK FWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
#endif

FWindow::FWindow(FDisplay* display, const FX::FXRect& rect, const char* title)
    : display(display), rect(rect), title(title), isVisible(false) {
#ifdef _WIN32
    hwnd = nullptr;
#elif defined(__linux__) || defined(__unix__)
    xDisplay = nullptr;
    xWindow = 0;
    wmDeleteMessage = 0;
#endif
}

FWindow::~FWindow() {
#ifdef _WIN32
    if (hwnd) {
        DestroyWindow(hwnd);
    }
#elif defined(__linux__) || defined(__unix__)
    if (xDisplay && xWindow) {
        XDestroyWindow(xDisplay, xWindow);
    }
#endif
}

bool FWindow::Create() {
#ifdef _WIN32
    if (!classRegistered) {
        WNDCLASS wc = {};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = GetModuleHandle(nullptr);
        wc.lpszClassName = "FWindowClass";
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

        if (!RegisterClass(&wc)) {
            return false;
        }
        classRegistered = true;
    }

    hwnd = CreateWindowEx(
        0,
        "FWindowClass",
        title,
        WS_OVERLAPPEDWINDOW,
        rect.x, rect.y, rect.width, rect.height,
        nullptr, nullptr, GetModuleHandle(nullptr), nullptr
    );

    if (!hwnd) {
        return false;
    }

    display->hwnd = hwnd;
    display->hdc = GetDC(hwnd);

    return true;

#elif defined(__linux__) || defined(__unix__)
    if (!display->display) {
        return false;
    }

    xDisplay = display->display;

    xWindow = XCreateSimpleWindow(
        xDisplay,
        RootWindow(xDisplay, display->screen),
        rect.x, rect.y, rect.width, rect.height,
        1,
        BlackPixel(xDisplay, display->screen),
        WhitePixel(xDisplay, display->screen)
    );

    if (!xWindow) {
        return false;
    }

    // Set window title
    XStoreName(xDisplay, xWindow, title);

    // Set up window close protocol
    wmDeleteMessage = XInternAtom(xDisplay, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(xDisplay, xWindow, &wmDeleteMessage, 1);

    // Create graphics context
    display->window = xWindow;
    display->gc = XCreateGC(xDisplay, xWindow, 0, nullptr);

    // Select input events
    XSelectInput(xDisplay, xWindow, ExposureMask | KeyPressMask | ButtonPressMask | StructureNotifyMask);

    return true;
#endif
}

void FWindow::Show() {
#ifdef _WIN32
    if (hwnd) {
        ShowWindow(hwnd, SW_SHOW);
        UpdateWindow(hwnd);
        isVisible = true;
    }
#elif defined(__linux__) || defined(__unix__)
    if (xDisplay && xWindow) {
        XMapWindow(xDisplay, xWindow);
        isVisible = true;
    }
#endif
}

void FWindow::Hide() {
#ifdef _WIN32
    if (hwnd) {
        ShowWindow(hwnd, SW_HIDE);
        isVisible = false;
    }
#elif defined(__linux__) || defined(__unix__)
    if (xDisplay && xWindow) {
        XUnmapWindow(xDisplay, xWindow);
        isVisible = false;
    }
#endif
}

void FWindow::SetTitle(const char* newTitle) {
    title = newTitle;
#ifdef _WIN32
    if (hwnd) {
        SetWindowTextA(hwnd, newTitle);
    }
#elif defined(__linux__) || defined(__unix__)
    if (xDisplay && xWindow) {
        XStoreName(xDisplay, xWindow, newTitle);
    }
#endif
}

bool FWindow::ProcessEvents() {
#ifdef _WIN32
    MSG msg;
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            return false;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return true;

#elif defined(__linux__) || defined(__unix__)
    if (!xDisplay) return false;

    XEvent event;
    while (XPending(xDisplay)) {
        XNextEvent(xDisplay, &event);

        switch (event.type) {
            case ClientMessage:
                if (event.xclient.data.l[0] == wmDeleteMessage) {
                    return false;
                }
                break;
            case Expose:
                // Window needs redrawing
                break;
        }
    }
    return true;
#endif
}

bool FWindow::ShouldClose() {
#ifdef _WIN32
    return !IsWindow(hwnd);
#elif defined(__linux__) || defined(__unix__)
    return !isVisible;
#endif
}

int main(int argc, char* argv[])
{
    // Create display
    FDisplay display;
    if (!display.Initialize()) {
        std::cerr << "Failed to initialize display" << std::endl;
        return -1;
    }

    // Create window
    FX::FXRect windowRect(100, 100, 800, 600);
    FWindow window(&display, windowRect, "Cross-Platform Window Demo");

    if (!window.Create()) {
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }

    // Show window
    window.Show();

    std::cout << "Window created successfully!" << std::endl;
    std::cout << "Native display context: " << window.GetDisplay()->GetNativeContext() << std::endl;

    // Main loop
    int frameCount = 0;
    while (window.ProcessEvents() && !window.ShouldClose()) {
        // Clear and draw
        display.Clear();

        // Draw some text
        char buffer[256];
        sprintf(buffer, "Frame: %d", frameCount++);
        display.DrawText(buffer, 50, 50);
        display.DrawText("Hello, Cross-Platform World!", 50, 80);

        // Present
        display.Present();

        // Sleep to limit frame rate
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60 FPS
    }

    std::cout << "Window closed" << std::endl;
    return 0;
}


/*int main(int argc, char* argv[])
{
    fprintf(stdout, "try to initialize display");
    FXUI::FXDisplay* display = new FXUI::FXDisplay();
    //FXUI::FXWindow* window = new FXUI::FXWindow("",NULL, display);
    return 0;
}*/

/*#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

bool quited = false;

void on_delete(Display * display, Window window)
{
    XDestroyWindow(display, window);
    quited = true;
}

extern int main(int argc, char *argv[])
{
    Display * display = XOpenDisplay(NULL);
    if (NULL == display) {
        fprintf(stderr, "Failed to initialize display");
        return EXIT_FAILURE;
    }

    Window root = DefaultRootWindow(display);
    if (None == root) {
        fprintf(stderr, "No root window found");
        XCloseDisplay(display);
        return EXIT_FAILURE;
    }

    Window window = XCreateSimpleWindow(display, root, 0, 0, 800, 600, 0, 0, 0xffffffff);
    if (None == window) {
        fprintf(stderr, "Failed to create window");
        XCloseDisplay(display);
        return EXIT_FAILURE;
    }

    XMapWindow(display, window);

    Atom wm_delete_window = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, & wm_delete_window, 1);

    XEvent event;
    while (!quited) {
        XNextEvent(display, &event);

        switch(event.type) {
        case ClientMessage:
            if(event.xclient.data.l[0] == wm_delete_window) {
                on_delete(event.xclient.display, event.xclient.window);
            }
            break;
        }
    }

    XCloseDisplay(display);

    return 0;
}*/
