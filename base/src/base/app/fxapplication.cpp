#include <base/app/fxapplication.h>
#include <base/stdlib/fxstatuscode.h>
//
#include <stdlib.h>
//
#include <base/common/fxplatformdefs.h>

// platform specific
#if defined (PLATFORM_WINDOWS)
    #include <windows.h>
#elif defined(PLATFORM_MACOSX)
    #include <mach-o/dyld.h>
#endif
//

namespace
{
    #ifdef PLATFORM_WINDOWS
        status_code_t CloseWindowsConsole(void)
        {
            return fx::status::FX_STATUS_OK;
        }
    #endif

}

namespace FX
{
    FXApplication::FXApplication(int argc, char** argv, const char* vendor_descriptor)
    :
    argc_state(argc),
    argv_state(argv),
    vendor_descriptor_state(vendor_descriptor)
    {
        status_state = fx::status::FX_STATUS_OK;
    };

    FXApplication::~FXApplication()
    {
        _app_event_handler = NULL;
    };

    status_code_t FXApplication::Init()
    {
        status_code_t status;
        /*
         *  #ifdef PLATFORM_WINDOWS
         *  if(status = CloseWindowsConsole() != fx::FX_STATUS_OK)
         *      return status;
         *  #endif
         */

        status = fx::status::FX_STATUS_OK;
        //if(status && status_state)
        //return fx::FX_STATUS_UNKNOWN_ERR;

        return status;
        //return fx::FX_STATUS_OK;
        //return fx::FX_STATUS_UNKNOWN_ERR;
    };

    status_code_t FXApplication::Run()
    {
        return fx::status::FX_STATUS_OK;
    };

    const char* FXApplication::GetAppLocation()
    {
        //const char* location;
        //return location;
        #ifndef MAX_PATH
        #define MAX_PATH 128
        #endif // !MAX_PATH
        static char path[MAX_PATH];
        //snprintf(path, 128, "%s", "unimplemented");
        //fx::get_status((status_code_t)FX_STATUS_SUCCESS);

        #if defined (PLATFORM_WINDOWS)
        wchar_t wpath[MAX_PATH];
        GetModuleFileNameW(NULL, wpath, MAX_PATH);
        // Convert wchar_t to UTF-8
        WideCharToMultiByte(CP_UTF8, 0, wpath, -1, path, MAX_PATH, NULL, NULL);
        //return buffer;
        #elif defined(PLATFORM_HAIKU)
        snprintf(path, 128, "%s", "unimplemented");
        #elif defined(PLATFORM_LINUX)
        snprintf(path, 128, "%s", "unimplemented");
        #elif defined (PLATFORM_MACOSX)
        uint32_t path_size = sizeof(path);
        _NSGetExecutablePath(path, &path_size);
        #else
            snprintf(path, 128, "%s", "unimplemented");
        #endif

        return path;
    };

    const char* FXApplication::GetAppVersion()
    {
        //const char* version;
        //return version;
        static char version[128];
        snprintf(version, 128, "%s", "1.0");
        //fx::get_status((status_code_t)FX_STATUS_SUCCESS);
        return version;
    };

    status_code_t FXApplication::SetHandler(FX::FXEventHandler* handler)
    {
        _app_event_handler = handler;
        return fx::status::FX_STATUS_OK;
    };
}
