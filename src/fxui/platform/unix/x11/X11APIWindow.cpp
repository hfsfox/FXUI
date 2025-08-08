#include "X11APIWindow.h"

#if defined (BACKEND_X11)

#include <mutex>
#include <memory>

// Static member definitions
std::once_flag X11DisplayInstance::initialized;
std::unique_ptr<::Display*> X11DisplayInstance::instance;

::Display*
X11DisplayInstance::GetDisplayInstance()
{
    std::call_once(initialized, []()
    {
        instance = std::make_unique<::Display*>(XOpenDisplay(0));
    }
    );
    return *instance.get();
};

#endif
