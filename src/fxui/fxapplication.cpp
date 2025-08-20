#include <fxapplication.h>
#include <fxplatformuidefs.h>

#if defined (BACKEND_X11)
#elif defined (BACKEND_WAYLAND)
#elif defined (BACKEND_COCOA)
    //#include <Cocoa/Cocoa.h>
    //#include <Foundation/Foundation.h>
    //#include <Foundation/NSString.h>
    #include <Carbon/Carbon.h>
    #include <objc/message.h>
    #include <objc/runtime.h>
    #define cls objc_getClass
    #define sel sel_getUid
    #define msg ((id(*)(id, SEL, ...))objc_msgSend)
    #define cls_msg ((id(*)(Class, SEL, ...))objc_msgSend)
#elif defined (BACKEND_BEAPI)
    #include "platform/haiku/BApplicationInstance.h"
#elif defined (BACKEND_WINAPI)
#endif

#if defined(BACKEND_BEAPI)
    static BApplication* app = nullptr;
#endif

FX::FXApplication::FXApplication()
{
	/*#if defined(BACKEND_BEAPI)
	if (!app)
	{
        //app = new BApplication("application/x-vnd.FWindow");
        app = BApplicationInstance::GetInstance();
    }
    #endif*/
    FXApplication("");
}

FX::FXApplication::FXApplication(const char* vendor_descriptor)
{
	#if defined(BACKEND_BEAPI)
	if (!app)
	{
        //app = new BApplication("application/x-vnd.FWindow");
        app = BApplicationInstance::GetInstance();
    }
    #endif
}

FX::FXApplication::~FXApplication()
{
}

uint32_t
FX::FXApplication::Run()
{
    #if defined (BACKEND_X11)
    return 0;
    #elif defined (BACKEND_WAYLAND)
    return 0;
    #elif defined (BACKEND_COCOA)
    return 0;
    #elif defined (BACKEND_BEAPI)
    return 0;
    #elif defined (BACKEND_WINAPI)
    return 0;
    #endif
    //return 0;
}
