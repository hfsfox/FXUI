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

#ifndef     __FXRECT_H__
#define     __FXRECT_H__

#include <gui/support/fxguitypes.h>

/**
 * Structure for represent rectangle with some metrics, like widget plcaement,
 * widget, screen, window or surface geometry.
**/

typedef struct rectangle_t
        {
            float             _left;
            float             _top;
            float             _width;
            float             _height;

            inline rectangle_t&
            SetTo(int new_x, int new_y, int new_w, int new_h)
            {
                _left = new_x;
                _top = new_y;
                _width = new_w;
                _height = new_h;
                return *this;
            }
            inline rectangle_t&
            operator=(rectangle_t otherRect)
            {
                return SetTo(otherRect._left, otherRect._top, otherRect._width, otherRect._height);
            }
        } rectangle_t;

namespace FX
{
    struct FX_GUI_API_EXPORT FXRect
    {
        int x, y, width, height;
        FXRect(int x = 0, int y = 0, int w = 0, int h = 0)
        :
        x(x), y(y), width(w), height(h)
        {
        }
        inline FXRect&
        SetTo(int new_x, int new_y, int new_w, int new_h)
        {
            x = new_x;
            y= new_y;
            width = new_w;
            height = new_h;
            return *this;
        }
        inline FXRect&
        operator=(FX::FXRect otherRect)
        {
            return SetTo(otherRect.x, otherRect.y, otherRect.width, otherRect.height);
        }
    };
}

#endif
