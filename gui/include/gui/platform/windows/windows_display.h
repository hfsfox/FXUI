
#ifndef __WINDOWS_DISPLAY_H__
#define __WINDOWS_DISPLAY_H__

#include <windows.h>
#include <base/stdlib/fxstatuscode.h>

class WindowsDisplay
{
    public:
        WindowsDisplay()
        {
        }
        ~WindowsDisplay()
        {
        }

    public:
        status_code_t Init()
        {
            return fx::FX_STATUS_OK;
        }
        status_code_t Close()
        {
        }
    private:
    protected:
};

#endif // __WINDOWS_DISPLAY_H__
