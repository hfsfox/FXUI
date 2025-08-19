#include <fxapplication.h>
#include <fxplatformuidefs.h>

#if defined (BACKEND_X11)
#elif defined (BACKEND_WAYLAND)
#elif defined (BACKEND_COCOA)
#elif defined (BACKEND_BEAPI)
#elif defined (BACKEND_WINAPI)
#endif

FX::FXApplication::FXApplication()
{
}

FX::FXApplication::~FXApplication()
{
}

uint32_t
FX::FXApplication::Run()
{
    return 0;
}
