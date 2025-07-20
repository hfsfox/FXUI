#include "BeAPIView.h"

#include <interface/View.h>
#include <iostream>

BeAPIView::BeAPIView(BRect frame, FX::FXDisplay* display)
    :
    BView(frame, "FView", B_FOLLOW_ALL, B_WILL_DRAW | B_SUBPIXEL_PRECISE | B_PULSE_NEEDED), fDisplay(display)
    {
    }

void
BeAPIView::Draw(BRect updateRect)
{
}

void
BeAPIView::MouseUp(BPoint point)
{
    std::cout << "click up" << std::endl;
    BView::MouseUp(point);
}

void
BeAPIView::MouseDown(BPoint point)
{
    std::cout << "click down" << std::endl;
    BView::MouseDown(point);
}
