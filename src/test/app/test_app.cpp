#include <fxui.h>
#include <iostream>

class MainApp: public FX::FXApplication
{
	MainApp::MainApp(int argc, char** argv)
		:
		FX::FXApplication(argc, argv)
		{
			//FX::FXApplication::FXApplication(argc, argv);
		};
	const char* MainApp::Run()
	{
		//FX::FXApplication::Run();
	};
};

int
main(int argc, char** argv)
{
	//MainApp* app = new MainApp(argc, argv);
	FX::FXApplication* app = new FX::FXApplication(argc, argv);
	std::cout  << "Application path: " << app->GetAppLocation() << std::endl;
	return app->Run();
}
