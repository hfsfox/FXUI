#include <fxui.h>
#include <fxwidgets.h>
#include <fxplatformuidefs.h>
#include <iostream>

#include <thread>
#include <chrono>

#if defined (BACKEND_BEAPI)
#include <MenuBar.h>
#include <Font.h>
#endif

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
	window->SetTitle("FXWindow with MenuBar");

	#if defined (BACKEND_BEAPI)
		uint h = be_plain_font->Size()*2;
	#else
		uint h = 20;
	#endif
	
	while (window->ProcessEvents() && !window->ShouldClose())
	{
		FX::FXRect menubar_r(0, 0, display->GetDisplaySize().width-1, h);
		FX::FXMenuBar* menubar = new FX::FXMenuBar(menubar_r, display);
		
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	return app.Run();
}
