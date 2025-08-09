#include "fxprogressbar.h"
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
    FX::FXWindow window(&display, windowRect, "Cross-Platform FXWindow Demo");

    if (!window.Create()) {
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }

    window.Show();

        std::cout << "Window created successfully on ";
    #if defined(PLATFORM_LINUX)
        std::cout << "Linux with ";
        #if defined (BACKEND_WAYLAND)
            std::cout << "Wayland backend" << std::endl;
        #elif defined (BACKEND_X11)
            std::cout << "X11 backend" << std::endl;
        #endif

    #elif defined(PLATFORM_HAIKU)
        std::cout << "Haiku OS" << std::endl;
    #endif

    window.SetTitle("FXWindow");
    FX::FXColor color = {216, 216, 216, 255};

    while (window.ProcessEvents() && !window.ShouldClose())
    {
        //FX::FXColor color = {216, 216, 216, 255};
        display.SetViewColor(color);

        FX::FXRect menubar_r(0, 0, display.GetDisplaySize().width-1, 20);
        //FX::FXMenuBar m(menubar_r, &display);
        FX::FXRect toolbar_r(0, 20, display.GetDisplaySize().width-1, 40);
        //FX::FXToolBar* t = new FX::FXToolBar(toolbar_r, &display);

        FX::FXRect examplecontainer = {toolbar_r.x+50, toolbar_r.y+50, 80, 100};

        FX::FXRect button_1_rect(examplecontainer.x+50, examplecontainer.y+40, 70, 25);

        FX::FXButton* button1 = new FX::FXButton("Button 1",FX::FXRect(button_1_rect),&display);

        FX::FXRect button_2_rect(button_1_rect.x+button_1_rect.width+10, button_1_rect.y, 70, 25);

        FX::FXButton* button2 = new FX::FXButton("Button 2",FX::FXRect(button_2_rect),&display);

        FX::FXRect button_3_rect(button_2_rect.x+button_2_rect.width+10, button_2_rect.y, 70, 25);

        FX::FXButton* button3 = new FX::FXButton("Button 3",FX::FXRect(button_3_rect),&display);

        FX::FXRect progressbar_rect(button_1_rect.x, /*button_2_rect.height+button_2_rect.height+10*/button_1_rect.y+button_1_rect.height+10, button_1_rect.width+button_3_rect.width+button_3_rect.width+10+10, 25);

        FX::FXProgressBar* p = new FX::FXProgressBar("Progress",FX::FXRect(progressbar_rect),&display);

        p->SetLimits(0, 10);
        p->SetProgress(45);

        display.Present();
    }

    return 0;
}
