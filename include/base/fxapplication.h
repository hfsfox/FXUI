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
         ~FXApplication();
        public:
        uint32_t Run();
    };
}

#endif
