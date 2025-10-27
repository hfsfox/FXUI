#include <fxui.h>
#include <iostream>

#include <thread>
#include <chrono>
int
main(int argc, char** argv)
{
	FX::FXApplication app /*= new FX::FXApplication*/(argc, argv);
	FX::FXDisplay* display = new FX::FXDisplay();
	if(!display->Init())
   	 {
        	std::cerr << "Failed to initialize display" << std::endl;
        	return -1;
    	}
	FX::FXRect windowRect(100, 100, 500, 400);
	FX::FXWindow* window = new FX::FXWindow(display, windowRect, "Cross-Platform FXWindow Demo");

	if (!window->Create())
	{
		std::cerr << "Failed to create window" << std::endl;
        	return -1;
	}

	window->Show();
	window->SetTitle("FXWindow creating test");
	while (window->ProcessEvents() && !window->ShouldClose())
	{
		//display->Present();
		//display->Present();
		//display->setDirty(false);
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
	}
	return app.Run();
}
