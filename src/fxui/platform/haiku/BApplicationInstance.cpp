#include "BApplicationInstance.h"
#include <mutex>
#include <memory>
// Static member definitions
std::once_flag BApplicationInstance::initialized;
std::unique_ptr<BApplication> BApplicationInstance::instance;

BApplication*
BApplicationInstance::GetInstance()
{
    std::call_once(initialized, []()
    {
        instance = std::make_unique<BApplication>("application/x-vnd.example-bitmaprender");
    }
    );
    return instance.get();
}
