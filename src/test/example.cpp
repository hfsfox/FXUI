#include "fxpoint.h"
#ifdef PLATFORM_HAIKU
#include <InterfaceDefs.h>
#endif

#include <fxui.h>

#include <iostream>
#include <thread>
#include <chrono>

// Example usage
int main()
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

    int frameCount = 0;
    // Main loop
    while (window.ProcessEvents() && !window.ShouldClose()) {
        display.Clear();
        window.SetTitle("FXWindow");
        #if defined (PLATFORM_HAIKU)
            FX::FXColor color = {ui_color(B_CONTROL_BACKGROUND_COLOR).red, ui_color(B_CONTROL_BACKGROUND_COLOR).green, ui_color(B_CONTROL_BACKGROUND_COLOR).blue,ui_color(B_CONTROL_BACKGROUND_COLOR).alpha};
        #elif defined PLATFORM_LINUX
            //XColor xcolor = { 160, 160, 160, 255};
            //XColor xcolor = { 237, 237, 237, 255};
            XColor xcolor = { 216, 216, 216, 255};
            FX::FXColor color = {xcolor.red, xcolor.green, xcolor.blue, 255};
        #endif
        FX::FXColor textColor = {0,0,0,255};
        //display.SetViewColor(ui_color(B_CONTROL_TEXT_COLOR));
        display.SetViewColor(color);
        // Draw some text
        char buffer[256];
        sprintf(buffer, "Frame: %d", frameCount++);
        display.DrawText(buffer, 50, 80, textColor);
        //display.SetViewColor(ui_color(B_CONTROL_TEXT_COLOR));
        display.DrawText("Hello, Haiku World!", 50, 50, textColor);
        int radius = 20;
        display.DrawCircle(radius+30, 100, radius, textColor);
        FX::FXColor c1Color = {255,0,0,255};
        display.DrawCircle((radius*2)+10, 200, radius, c1Color);
        FX::FXColor c2Color = {0,255,0,255};
        display.DrawCircle((radius*4)+10, 200, radius, c2Color);
        FX::FXColor c3Color = {0,0,255,255};
        display.DrawCircle((radius*6)+10, 200, radius, c3Color);
        FX::FXColor line_color = {0,0,255,255};
        display.DrawLine(FX::FXPoint(((radius*6)+10), 200-10),FX::FXPoint(((radius*6)+90),200-10),line_color);
        display.Present();
        //display.DrawText("Hello, Haiku World!", 50, 50);
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    std::cout << "Window closed" << std::endl;
    return 0;
}
