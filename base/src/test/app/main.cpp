#include <base/app/fxapplication.h>
#include <base/stdlib/fxstatuscode.h>

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

int main(int argc, char** argv)
{
    MainApp* app = new MainApp(argc, argv);
    if ( !app->Init() == fx::status::FX_STATUS_OK)
    {
        return -1;
    }

    std::cout << "Application init:" << fx::status::get_status(app->Init()) << std::endl;


    std::cout << "Application path:" << app->GetAppLocation() << std::endl;
    std::cout << "Application ver :" << app->GetAppVersion() << std::endl;

    if (app->Run() == fx::status::FX_STATUS_OK)
    {
        return 0;
    }
};
