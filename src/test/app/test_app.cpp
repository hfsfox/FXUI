#include <fxui.h>
#include <iostream>

class MainApp: public FX::FXApplication
{
	public:
		MainApp(int argc, char** argv)
		:
		FX::FXApplication(argc, argv)
		{
		};
};

int
main(int argc, char** argv)
{
	MainApp* app = new MainApp(argc, argv);
	//FX::FXApplication* app = new FX::FXApplication(argc, argv);
	std::cout  << "Application path: " << app->GetAppLocation() << std::endl;
	std::cout << "Application ver: " << app->GetAppVersion() << std::endl;
	return app->Run();
}
