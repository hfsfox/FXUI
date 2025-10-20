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

#ifndef __FXWIDGET_H__
#define __FXWIDGET_H__

#include <fxdisplay.h>
#include <fxrect.h>

#include <stdint.h>

namespace FX
{
    class FXWidget
    {
        public:
            FXWidget(FX::FXRect widget_rect);
            ~FXWidget();
        public:
            virtual void Draw();
            virtual void Show();
            virtual void Hide();
            bool IsVisible() { return visible; }
            FX::FXRect GetWidgetSize(void) const { return size; }
            void SetWidgetSize(FX::FXRect newSize) { size = newSize; }
        private:
            FX::FXRect size;
            bool visible;
    };
}

#endif
