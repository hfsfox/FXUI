#ifdef PLATFORM_HAIKU
#include <InterfaceDefs.h>
#endif

#include <fxui.h>
#include <fxwidgets.h>

#include <iostream>
#include <thread>
#include <chrono>

//#include <vector>

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

        //display.DrawLine(FX::FXPoint(50, 50), FX::FXPoint(50,300), textColor);

        FX::FXRect menubar_r(0, 0, display.GetDisplaySize().width-1, 20);
        FX::FXMenuBar m(menubar_r, &display);
        FX::FXRect toolbar_r(0, 20, display.GetDisplaySize().width-1, 40);
        FX::FXToolBar t(toolbar_r, &display);
        t.AddItemSeparator();


        FX::FXRect examplecontainer = {toolbar_r.x+50, toolbar_r.y+50, 80, 100};
        // Draw some text
        //FX::FXFont font(display,"");
        FX::FXFont f(&display,"Arial");
        //font = new FX::FXFont(display,"");
        char buffer[256];
        sprintf(buffer, "Frame: %d", frameCount++);
        display.DrawText(buffer, examplecontainer.x+10, examplecontainer.y+10, textColor);
        //display.SetViewColor(ui_color(B_CONTROL_TEXT_COLOR));
        display.DrawText("Hello, Haiku World!", examplecontainer.x+10, examplecontainer.y+20, textColor);
        int radius = 20;

        /*FX::FXRect menubar_r(0, 0, display.GetDisplaySize().width-1, 20);
        FX::FXColor menubar_color = {0,0,0,255};
        // 800 - width 25 - height
        //display.DrawRect(0, 0, 799, 25, menubar_color);
        //display.DrawRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, menubar_color);
        display.FillRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, {255,255,255,255});
        display.DrawRect(menubar_r.x, menubar_r.y, menubar_r.width, menubar_r.height, menubar_color);
        //
        display.DrawText("File", menubar_r.x+5, menubar_r.y+15, textColor);
        display.DrawText("Edit", menubar_r.x+35, menubar_r.y+15, textColor);
        display.DrawText("View", menubar_r.x+65, menubar_r.y+15, textColor);
        display.DrawText("Help", menubar_r.x+95, menubar_r.y+15, textColor);
        //std::vector<int>menu_vec;
        */
        //


        display.DrawCircle(radius+30, 100, radius, textColor);
        FX::FXColor c1Color = {255,0,0,255};
        display.FillCircle((radius*2)+10, 200, radius, {255,255,255,255});
        display.DrawCircle((radius*2)+10, 200, radius, c1Color);
        FX::FXColor c2Color = {0,255,0,255};
        display.DrawCircle((radius*4)+10, 200, radius, c2Color);
        display.FillCircle((radius*4)+10, 200, radius, {100,100,100,255});
        FX::FXColor c3Color = {0,0,255,255};
        display.DrawCircle((radius*6)+10, 200, radius, c3Color);
        display.FillCircle((radius*6)+10, 200, radius, {0,0,0,255});
        FX::FXColor line_color = {0,0,255,255};
        display.DrawLine(FX::FXPoint(((radius*6)+10), 200-10),FX::FXPoint(((radius*6)+90),200-10),line_color);

        display.Present();
        //display.DrawText("Hello, Haiku World!", 50, 50);
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    std::cout << "Window closed" << std::endl;
    return 0;
}
