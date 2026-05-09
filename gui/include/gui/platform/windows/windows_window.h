/**----------------------------------------------------------------------------
 * FXUI SDK
 * FXUI: Graphical User Interface Framework:
 *
 * Version 0.1       Date :
 *
 *------------------------------------------------------------------------------
 * MIT
 * © 2025, , All Rights Reserved
 *------------------------------------------------------------------------------
 **/

#ifndef __WINDOWS_HINSTANCE_H__
#define __WINDOWS_HINSTANCE_H__

#include <windows.h>
#include <stdint.h>

class WindowsHInstance
{
    public:
        WindowsHInstance()
        {
            app_hinstance = GetModuleHandle(NULL);
        }
        virtual ~WindowsHInstance()
        {
        }
    public:
        /**
          * Get HINSTANCE for GUI purposes
          * @return HINSTANCE
          **/
        ::HINSTANCE GetHInstance() { return app_hinstance; }
    protected:
        ::HINSTANCE app_hinstance;
};

#endif
