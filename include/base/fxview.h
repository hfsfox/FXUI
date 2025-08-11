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

#ifndef __FXVIEW_H__
#define __FXVIEW_H__

#include <fxplatformdefs.h>
#include <fxplatformuidefs.h>
#include <fxuicolor.h>
#include <fxpoint.h>
#include <fxrect.h>

#include <cstdint>

namespace FX
{
    typedef struct FXColor FXColor;
    class FXFont;
}

namespace FX
{
    class FXView
    {
        friend class FWindow;

        public:
            FXView();
            FXView(FX::FXRect& size);
            ~FXView();
        public:
            bool Init();
            void Cleanup();
        //public:
            //void* GetNativeContext() const;
        public:
            void Clear();
            //void ClearDisplay();
        public:
            void DrawText(const char* text, int x, int y, FX::FXColor color);
            void DrawText(const char* text, FX::FXPoint where, FX::FXColor color);
            void DrawCircle(int center_x, int center_y, int radius, FX::FXColor color);
            void DrawCircle(FX::FXPoint where, int radius, FX::FXColor color);
            void DrawArc(int center_x, int center_y, int begin_angle, int end_angle, FX::FXColor color);
            void DrawArc(FX::FXPoint where, int begin_angle, int end_angle, FX::FXColor color);
            void DrawPoint(int center_x, int center_y, FX::FXColor color);
            void DrawPoint(FX::FXPoint where, FX::FXColor color);
            void DrawLine(int center_x_begin, int center_y_begin,int center_x_end, int center_y_end, FX::FXColor color);
            void DrawLine(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color);
            void DrawRect(int x_begin, int y_begin, int width, int height, FX::FXColor color);
            void DrawRect(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color);
            void DrawTriangle(int x_a_begin, int y_a_begin,int x_b_begin, int y_b_begin,int x_c_begin, int y_c_begin, FX::FXColor color);
            void DrawTriangle(FX::FXPoint where_a_begin, FX::FXPoint where_b_begin, FX::FXPoint where_c_begin, FX::FXColor color);
            void DrawPolygon(int x, int y, uint32_t point_count, FX::FXColor color);
            void DrawPolygon(FX::FXPoint point, uint32_t point_count, FX::FXColor color);
            void DrawPolyLine(int x, int y, uint32_t point_count, FX::FXColor color);
            void DrawPolyLine(FX::FXPoint point, uint32_t point_count, FX::FXColor color);
        public:
            void FillRect(int x_begin, int y_begin, int width, int height, FX::FXColor color);
            void FillRect(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color);
            void FillCircle(int center_x, int center_y, int radius, FX::FXColor color);
            void FillCircle(FX::FXPoint where, int radius, FX::FXColor color);
            void FillArc(int center_x, int center_y, int begin_angle, int end_angle, FX::FXColor color);
            void FillArc(FX::FXPoint where, int begin_angle, int end_angle, FX::FXColor color);
            void FillTriangle(int x_a_begin, int y_a_begin,int x_b_begin, int y_b_begin,int x_c_begin, int y_c_begin, FX::FXColor color);
            void FillTriangle(FX::FXPoint where_a_begin, FX::FXPoint where_b_begin, FX::FXPoint where_c_begin, FX::FXColor color);
            void FillPolygon(int x, int y, uint32_t point_count, FX::FXColor color);
            void FillPolygon(FX::FXPoint point, uint32_t point_count, FX::FXColor color);
        public:
            void SetFont(FX::FXFont);
            FX::FXFont GetFont() const;

            void SetViewColor(FX::FXColor view_color);
            FX::FXColor GetViewColor() const;

            void SetPenSize(uint32_t pen_size);
            uint32_t GetPenSize() const;

            FX::FXRect GetViewSize() const;
            void SetViewSize(FX::FXRect size);

            void Present();
    };
}

#endif
