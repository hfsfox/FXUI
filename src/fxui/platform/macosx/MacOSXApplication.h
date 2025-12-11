//-----------------------------------------------------------------------------
// FXUI SDK
// FXUI: Graphical User Interface Framework:
//
// Version 0.1       Date :
//
//-----------------------------------------------------------------------------
// MIT
// © 2025, , All Rights Reserved
//-----------------------------------------------------------------------------

#ifndef __MACOSXAPPLICATION_H__
#define __MACOSXAPPLICATION_H__

#ifdef BACKEND_COCOA

class MacOSXApplication
{
    public:
        static MacOSXApplication *GetMacOSXApplicationInstance()
        {
            static MacOSXApplication *mac_app = NULL;
            if (!mac_app)
                app = new MacOSXApplication(/*int *argc, char *argv[]*/);
            return mac_app;
        };
        virtual void Run();
        virtual void Shutdown();
    private:
    MacOSXApplication();
};

#endif //BACKEND_COCOA
#endif //__MACOSXAPPLICATION_H__
