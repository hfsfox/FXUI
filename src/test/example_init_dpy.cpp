#include <fxui.h>
#include <fxwidgets.h>
#include <iostream>

int
main()
{
    FX::FXDisplay display;
    if (!display.Init()) {
        std::cerr << "Failed to initialize display" << std::endl;
        return -1;
    }

    FX::FXRect windowRect(100, 100, 800, 600);
    FX::FXWindow window(&display, windowRect, "Cross-Platform Window Demo");

    if (!window.Create()) {
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }

    window.Show();

        std::cout << "Window created successfully on ";
    #if defined(PLATFORM_LINUX)
        std::cout << "Linux" << std::endl;
    #elif defined(PLATFORM_HAIKU)
        std::cout << "Haiku OS" << std::endl;
    #endif

    while (window.ProcessEvents() && !window.ShouldClose())
    {
    }

    return 0;
}
