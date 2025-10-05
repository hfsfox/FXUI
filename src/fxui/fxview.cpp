#include <fxview.h>
#include <fxfont.h>

namespace
{
}

FX::FXView::FXView()
:
viewRect(0,0,0,0),
visibility(true)
{
    //
}

FX::FXView::FXView(FX::FXRect& size)

    :
    viewRect(size),
    visibility(true)
{
    //
}

FX::FXView::~FXView()
{
}

bool
FX::FXView::Init()
{
    bool status = true;
    return status;
}

void
FX::FXView::Cleanup()
{
}

void
FX::FXView::Clear()
{
}

// Drawing primitives

void
FX::FXView::DrawText(const char* text, int x, int y, FX::FXColor color)
{
    #if defined (BACKEND_WINAPI)
    #endif
}
void
FX::FXView::DrawText(const char* text, FX::FXPoint point, FX::FXColor color)
{
    DrawText(text, point.x, point.y, color);
}

void
FX::FXView::DrawCircle(int center_x, int center_y, int radius, FX::FXColor color)
{
}
void
FX::FXView::DrawCircle(FX::FXPoint where, int radius, FX::FXColor color)
{
}
void
FX::FXView::DrawArc(int center_x, int center_y, int begin_angle, int end_angle, FX::FXColor color)
{
}
void
FX::FXView::DrawArc(FX::FXPoint where, int begin_angle, int end_angle, FX::FXColor color)
{
}
void
FX::FXView::DrawPoint(int center_x, int center_y, FX::FXColor color)
{
}
void
FX::FXView::DrawPoint(FX::FXPoint where, FX::FXColor color)
{
}
void
FX::FXView::DrawLine(int center_x_begin, int center_y_begin,int center_x_end, int center_y_end, FX::FXColor color)
{
}
void
FX::FXView::DrawLine(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color)
{
}
void
FX::FXView::DrawRect(int x_begin, int y_begin, int width, int height, FX::FXColor color)
{
}
void
FX::FXView::DrawRect(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color)
{
}
void
FX::FXView::DrawTriangle(int x_a_begin, int y_a_begin,int x_b_begin, int y_b_begin,int x_c_begin, int y_c_begin, FX::FXColor color)
{
}
void
FX::FXView::DrawTriangle(FX::FXPoint where_a_begin, FX::FXPoint where_b_begin, FX::FXPoint where_c_begin, FX::FXColor color)
{
}
void
FX::FXView::DrawPolygon(int x, int y, uint32_t point_count, FX::FXColor color)
{
}
void
FX::FXView::DrawPolygon(FX::FXPoint point, uint32_t point_count, FX::FXColor color)
{
}
void
FX::FXView::DrawPolyLine(int x, int y, uint32_t point_count, FX::FXColor color)
{
}
void
FX::FXView::DrawPolyLine(FX::FXPoint point, uint32_t point_count, FX::FXColor color)
{
}
// Draw filled primitives
void
FX::FXView::FillRect(int x_begin, int y_begin, int width, int height, FX::FXColor color)
{
}
void
FX::FXView::FillRect(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color)
{
}
void
FX::FXView::FillCircle(int center_x, int center_y, int radius, FX::FXColor color)
{
}
void
FX::FXView::FillCircle(FX::FXPoint where, int radius, FX::FXColor color)
{
}
void
FX::FXView::FillArc(int center_x, int center_y, int begin_angle, int end_angle, FX::FXColor color)
{
}
void
FX::FXView::FillArc(FX::FXPoint where, int begin_angle, int end_angle, FX::FXColor color)
{
}
void
FX::FXView::FillTriangle(int x_a_begin, int y_a_begin,int x_b_begin, int y_b_begin,int x_c_begin, int y_c_begin, FX::FXColor color)
{
}
void
FX::FXView::FillTriangle(FX::FXPoint where_a_begin, FX::FXPoint where_b_begin, FX::FXPoint where_c_begin, FX::FXColor color)
{
}
void
FX::FXView::FillPolygon(int x, int y, uint32_t point_count, FX::FXColor color)
{
}
void
FX::FXView::FillPolygon(FX::FXPoint point, uint32_t point_count, FX::FXColor color)
{
}

// other methods

void FX::FXView::SetFont(FX::FXFont font)
{
}

FX::FXFont 
FX::FXView::GetFont() const
{
    FXFont f(NULL, "");
    return f;
}

void
FX::FXView::SetViewColor(FX::FXColor view_color)
{
}

FX::FXColor 
FX::FXView::GetViewColor() const
{
    return {0,0,0};
}

void
FX::FXView::SetPenSize(uint32_t pen_size)
{
}

uint32_t 
FX::FXView::GetPenSize() const
{
    return 0;
}

FX::FXRect 
FX::FXView::GetViewSize() const
{
    FX::FXRect r(0,0,0,0);
    return r;
}
void
FX::FXView::SetViewSize(FX::FXRect size)
{
}

void 
FX::FXView::Present()
{
}

