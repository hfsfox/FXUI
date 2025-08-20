#include <fxui.h>
#include <fxwidgets.h>
#include <iostream>

#include <thread>
#include <chrono>

int
main(int argc, char** argv)
{
    /*FX::FXDisplay display;
    if (!display.Init()) {
        std::cerr << "Failed to initialize display" << std::endl;
        return -1;
    }*/

    //FX::FXApplication* app = new FX::FXApplication();
    FX::FXApplication app(argc, argv);

    FX::FXDisplay* display = new FX::FXDisplay();

    if(!display->Init())
    {
        std::cerr << "Failed to initialize display" << std::endl;
        return -1;
    }

    /*
    FX::FXDisplay* dpy = new FX::FXDisplay();
    //FX::FXDisplay dpy;
    if (!dpy->Init()) {
        std::cerr << "Failed to initialize display" << std::endl;
        return -1;
    }
    */

    /*
    FX::FXRect msgbox_r(100,100,600,200);
    FX::FXMessageBox* messagebox = new FX::FXMessageBox(display, msgbox_r, "Message box", "This is example message box");

    if (!messagebox->Create()) {
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }
    messagebox->Show();
    */

    FX::FXRect windowRect(100, 100, 500, 400);
    FX::FXWindow window(display, windowRect, "Cross-Platform FXWindow Demo");

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

    #elif defined(PLATFORM_WINDOWS)
        std::cout << "Widnows" << std::endl;

    #elif defined(PLATFORM_MACOSX)
        std::cout << "macOS X" << std::endl;
    #endif

    window.SetTitle("FXWindow");
    FX::FXColor color = {216, 216, 216, 255};

    //FX::FXMessageBox* messagebox = new FX::FXMessageBox(&display, {100,100,600,200}, "Message box");

    //if (!messagebox->Create()) {
    //    std::cerr << "Failed to create window" << std::endl;
    //    return -1;
    //}
    //messagebox->Show();

    FX::FXRect examplecontainer = {0+40, 10+40, 80, 100};

    FX::FXRect button_1_rect(examplecontainer.x+50, examplecontainer.y+40, 70, 25);
    FX::FXRect button_2_rect(button_1_rect.x+button_1_rect.width+10, button_1_rect.y, 70, 25);
    FX::FXRect button_3_rect(button_2_rect.x+button_2_rect.width+10, button_2_rect.y, 70, 25);

    FX::FXRect progressbar_rect(button_1_rect.x, button_1_rect.y+button_1_rect.height+10, button_1_rect.width+button_3_rect.width+button_3_rect.width+10+10, 25);

    FX::FXRect radio_button_1_rect(progressbar_rect.x, progressbar_rect.y+progressbar_rect.height+10,20,0);
    FX::FXRect radio_button_2_rect(radio_button_1_rect.x+radio_button_1_rect.width+3, progressbar_rect.y+progressbar_rect.height+10,15,0);

    FX::FXRect check_box_1_rect(radio_button_2_rect.x+radio_button_2_rect.width+3+3, progressbar_rect.y+progressbar_rect.height+10,15,0);

    FX::FXRect check_box_2_rect(check_box_1_rect.x+check_box_1_rect.width+3+3, progressbar_rect.y+progressbar_rect.height+10,15,0);

    FX::FXRect slider_1_rect(progressbar_rect.x,radio_button_1_rect.y+10+10,progressbar_rect.width,15);

    while (window.ProcessEvents() && !window.ShouldClose() /*|| messagebox->ProcessEvents() && !messagebox->ShouldClose()*/)
    {
        /*FX::FXColor text_color = {0,0,0,255};
        display->SetViewColor({250,250,250,255});
        const char* text = "some text";
        display->DrawText(text, msgbox_r.x+100+strlen(text), msgbox_r.y+10, text_color);
        FX::FXRect fill_rect(0, msgbox_r.y+50, display->GetDisplaySize().width, msgbox_r.height);
        display->FillRect(fill_rect.x, fill_rect.y, fill_rect.width, fill_rect.height, {160,160,160,255});
        FX::FXRect button_1_rect(fill_rect.width-80, fill_rect.height-30, 70, 25);
        FX::FXButton* ok_btn = new FX::FXButton("OK",FX::FXRect(button_1_rect),display);

        dpy->Present();*/
        //
        display->SetViewColor(color);

        FX::FXRect menubar_r(0, 0, display->GetDisplaySize().width-1, 20);
        FX::FXMenuBar m(menubar_r, display);
        FX::FXRect toolbar_r(0, 20, display->GetDisplaySize().width-1, 40);
        FX::FXToolBar* t = new FX::FXToolBar(toolbar_r, display);

        FX::FXButton* button1 = new FX::FXButton("Button 1",FX::FXRect(button_1_rect),display);

        FX::FXButton* button2 = new FX::FXButton("Button 2",FX::FXRect(button_2_rect),display);

        FX::FXButton* button3 = new FX::FXButton("Button 3",FX::FXRect(button_3_rect),display);

        FX::FXProgressBar* pb = new FX::FXProgressBar("Progress",FX::FXRect(progressbar_rect),display);

        FX::FXRadioButton* rb_1 = new FX::FXRadioButton("",radio_button_1_rect, display);
        rb_1->Selected(true);

        FX::FXRadioButton* rb_2 = new FX::FXRadioButton("",radio_button_2_rect, display);
        rb_2->Selected(false);

        FX::FXCheckBox* cb_1 = new FX::FXCheckBox("",check_box_1_rect, display);
        cb_1->Selected(true);

        FX::FXCheckBox* cb_2 = new FX::FXCheckBox("",check_box_2_rect, display);
        cb_2->Selected(false);

        pb->SetLimits(0, 10);
        pb->SetProgress(45);

        FX::FXSlider* slider = new FX::FXSlider("Slider",FX::FXRect(slider_1_rect),display, FX_HORIZONTAL);

        display->Present();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    return app.Run();
}
