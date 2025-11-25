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

#include <fxdisplay.h>
#include <fxrect.h>
#include <fxwidget.h>

namespace
{
};

FX::FXWidget::FXWidget(FX::FXRect widget_rect)
{
    this->x = widget_rect.x;
    this->y = widget_rect.y;
    this->width = widget_rect.width;
    this->height = widget_rect.height;
    this->visible = true;
    this->enabled = true;
}

FX::FXWidget::~FXWidget()
{
}

void
FX::FXWidget::Draw()
{
}

void
FX::FXWidget::Show()
{
    this->visible = true;
}

void
FX::FXWidget::Hide()
{
    this->visible = false;
}

void
FX::FXWidget::SetEnabled(bool is_enabled)
{
    this->enabled = is_enabled;
}

void
FX::FXWidget::SetVisible(bool is_visible)
{
    this->visible = is_visible;
}
