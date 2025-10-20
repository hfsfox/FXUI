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

#ifndef __FXSTRINGVIEW_H__
#define __FXSTRINGVIEW_H__

#include <fxwidget.h>
#include <fxrect.h>

namespace FX
{
    class FXStringView: public FX::FXWidget
    {
        public:
            FXStringView(FX::FXRect r,const char* string);
            ~FXStringView();
        public:
            void SetRect(FX::FXRect rect);
    };
}

#endif
