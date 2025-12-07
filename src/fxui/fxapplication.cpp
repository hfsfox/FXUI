#include <fxapplication.h>
#include <fxplatformuidefs.h>

#include <stddef.h>

#include <iostream>

#if defined (BACKEND_X11)
#elif defined (BACKEND_WAYLAND)
#elif defined (BACKEND_COCOA)
    #include "platform/macosx/MacOSXAPIWindow.h"
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
    #include <windows.h>
    #include "platform/windows/WindowsApiWindow.h"
#endif

#if defined(BACKEND_BEAPI)
    static BApplication* app = nullptr;
#elif defined (BACKEND_COCOA)
#endif

FX::FXApplication::FXApplication()
    :
    argc_state(0),
    argv_state(0)
    {
        std::cerr << "FXApplication" << std::endl;
        #if defined (BACKEND_COCOA)
            FXCocoaAutoreleasePool p();
        #elif defined (BACKEND_WINAPI)
        //FreeConsole();
        #endif
        FXApplication(argc_state, argv_state,"");
    }

FX::FXApplication::FXApplication(const char* vendor_descriptor)
{
    std::cerr << "FXApplication" << std::endl;
	#if defined (BACKEND_COCOA)
        FXCocoaAutoreleasePool p();
	#elif defined(BACKEND_BEAPI)
	    if (!app)
	    {
            //app = new BApplication("application/x-vnd.FWindow");
            app = BApplicationInstance::GetInstance();
        }
    #elif defined (BACKEND_WINAPI)
       //FreeConsole();
    #endif
}

FX::FXApplication::FXApplication(int argc, char** argv)
    :
    argc_state(argc),
    argv_state(argv)
    {
        std::cerr << "FXApplication" << std::endl;
    	#if defined (BACKEND_COCOA)
            FXCocoaAutoreleasePool p();
    	#elif defined(BACKEND_BEAPI)
			if (!app)
			{
        		app = BApplicationInstance::GetInstance();
    		}
        #elif defined (BACKEND_WINAPI)
            //FreeConsole();
    	#endif
    }

FX::FXApplication::FXApplication(int argc, char** argv, const char* vendor_descriptor)
    :
    argc_state(argc),
    argv_state(argv)
    {
        std::cerr << "FXApplication" << std::endl;
    	#if defined (BACKEND_COCOA)
            FXCocoaAutoreleasePool p();
    	#elif defined(BACKEND_BEAPI)
			if (!app)
			{
        		app = BApplicationInstance::GetInstance();
    		}
        #elif defined (BACKEND_WINAPI)
            //FreeConsole();
    	#endif
    }

FX::FXApplication::~FXApplication()
{
}

uint32_t
FX::FXApplication::Run()
{
    std::cerr << "Run()" << std::endl;
    #if defined (BACKEND_X11)
    return 0;
    #elif defined (BACKEND_WAYLAND)
    return 0;
    #elif defined (BACKEND_COCOA)
    CocoaApplication app(argc_state, argv_state);
    return 0;
    //return NSApplicationMain (argc_state, argv_state);
    #elif defined (BACKEND_BEAPI)
    //return app->Run();
    return 0;
    #elif defined (BACKEND_WINAPI)
    return 0;
    #else
    return 0;
    #endif
}

const char*
FX::FXApplication::GetAppLocation()
{
    static char path[MAX_PATH];
    //path = {0};

    #if defined (PLATFORM_WINDOWS)
    wchar_t wpath[MAX_PATH];
    GetModuleFileNameW(NULL, wpath, MAX_PATH);
    // Convert wchar_t to UTF-8
    WideCharToMultiByte(CP_UTF8, 0, wpath, -1, path, MAX_PATH, NULL, NULL);
    //return buffer;
    #elif defined(PLATFORM_HAIKU)
    #elif defined(PLATFORM_LINUX)
    #elif defined (PLATFORM_MACOSX)
    #endif

    return path;
}
