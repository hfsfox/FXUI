#include <fxui.h>
#include <fxwidgets.h>
#include <iostream>

#include <cstring>

#include <thread>
#include <chrono>

int
main()
{
    FX::FXApplication app;

    FX::FXDisplay* display = new FX::FXDisplay();
    if (!display->Init()) {
        std::cerr << "Failed to initialize display" << std::endl;
        return -1;
    }

    FX::FXRect rect ={100,100,600,200};

    const char* text = "This is example message box";
    FX::FXMessageBox* messagebox = new FX::FXMessageBox(display, rect, "Message box", text);

    if (!messagebox->Create()) {
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }
    messagebox->Show();


    FX::FXColor text_color = {0,0,0,255};

    while (messagebox->ProcessEvents() && !messagebox->ShouldClose())
    {
        display->SetViewColor({250,250,250,255});
                    //const char* t = "some text";
        display->DrawText(text, rect.x+100+strlen(text), rect.y+10, text_color);
        FX::FXRect fill_rect(0, rect.y+50, display->GetDisplaySize().width, rect.height);
        display->FillRect(fill_rect.x, fill_rect.y, fill_rect.width, fill_rect.height, {160,160,160,255});
        FX::FXRect button_1_rect(fill_rect.width-80, fill_rect.height-30, 70, 25);
        FX::FXButton* ok_btn = new FX::FXButton("OK",FX::FXRect(button_1_rect),display);

        display->Present();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    return app.Run();
}
