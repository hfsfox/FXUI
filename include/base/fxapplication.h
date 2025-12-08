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

#ifndef     __FXAPPLICATION__
#define     __FXAPPLICATION__

#include <cstdint>

namespace FX
{
    class FXApplication
    {
        public:
            FXApplication();
            FXApplication(const char* vendor_descriptor);
            FXApplication(int argc, char** argv);
            FXApplication(int argc, char** argv, 
                const char* vendor_descriptor);
            ~FXApplication();
        public:
            uint32_t Run();
            const char* GetAppLocation();
            const char* GetAppVersion();
        private:
            void _Init(int argc, char** argv,
                const char* vendor_descripto);
        private:
            int argc_state;
            char** argv_state;
    };
}

extern FX::FXApplication* fxapp;

#endif
