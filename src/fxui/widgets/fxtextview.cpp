#include <fxtextview.h>

FX::FXTextView::FXTextView()
{
}

FX::FXTextView::FXTextView(const char* init_text, FX::FXRect text_control_r, FX::FXDisplay* display)
    :
    d(display),
    rect(text_control_r),
    text(init_text)
    {
        d->FillRect(rect.x, rect.y, rect.width, rect.height, {255,255,255,255});
    }
FX::FXTextView::~FXTextView()
{
}
