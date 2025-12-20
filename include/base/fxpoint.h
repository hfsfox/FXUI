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

#ifndef __FXPOINT_H__
#define __FXPOINT_H__

#include <fxrect.h>

// Point structure
namespace FX
{
    struct FXPoint
        {
            int x, y, width, height;
            FXPoint(int x = 0, int y = 0)
            :
            x(x), y(y)
            {
            }

            bool IsInside(FX::FXRect r)
            {
                {return x <= r.x && y <= r.y && x <= r.height && y <= r.width;}
            }

            inline FXPoint&
            operator == (FXPoint& newPoint)
            {
                this->x = newPoint.x;
                this->y = newPoint.y;
                return *this;
            }
        };
}

#endif
