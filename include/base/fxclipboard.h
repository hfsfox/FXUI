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

#ifndef     __FXCLIPBOARD__
#define     __FXCLIPBOARD__

#include <base/fxstatuscode.h>

namespace FX
{
    class FXClipboard
    {
        public:
            FXClipboard();
            ~FXClipboard();
        public:
            status_code_t close_clipboard();
            status_code_t read_clipboard();
    };
}

#endif
