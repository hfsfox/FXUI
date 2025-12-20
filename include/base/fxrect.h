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

#ifndef __FXRECT_H__
#define __FXRECT_H__

// Rectangle structure
namespace FX{
struct FXRect
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
