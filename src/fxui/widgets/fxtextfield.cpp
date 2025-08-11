#include <fxtextfield.h>

FX::FXTextField::FXTextField()
{
}
FX::FXTextField::FXTextField(const char* init_text, FX::FXRect check_box_r, FX::FXDisplay* display)
    :
    FX::FXTextView(init_text, check_box_r, display)
    /*d(display),
    rect(check_box_r),
    text(init_text)
    {
    }*/
    {
        d->FillRect(rect.x, rect.y, rect.width, rect.height, {255,255,255,255});
    }
