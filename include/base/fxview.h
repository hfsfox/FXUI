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

#ifndef __FXVIEW_H__
#define __FXVIEW_H__
/*
#include <fxplatformdefs.h>
#include <fxplatformuidefs.h>
*/
#include <fxuicolor.h>
#include <fxpoint.h>
#include <fxrect.h>
#include <fxfont.h>

#include <cstdint>

/*namespace FX
{
    typedef struct FXColor FXColor;
    class FXFont;
}*/

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
            virtual bool Init();
            virtual void Cleanup();
        //public:
            //void* GetNativeContext() const;
        public:
            virtual void Clear();
            //void ClearDisplay();
        public:
            virtual void DrawText(const char* text, int x, int y, FX::FXColor color);
            virtual void DrawText(const char* text, FX::FXPoint where, FX::FXColor color);
            virtual void DrawCircle(int center_x, int center_y, int radius, FX::FXColor color);
            virtual void DrawCircle(FX::FXPoint where, int radius, FX::FXColor color); 
            virtual void DrawArc(int center_x, int center_y, int begin_angle, int end_angle, FX::FXColor color);
            virtual void DrawArc(FX::FXPoint where, int begin_angle, int end_angle, FX::FXColor color);
            virtual void DrawPoint(int center_x, int center_y, FX::FXColor color);
            virtual void DrawPoint(FX::FXPoint where, FX::FXColor color);
            virtual void DrawLine(int center_x_begin, int center_y_begin,int center_x_end, int center_y_end, FX::FXColor color);
            virtual void DrawLine(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color);
            virtual void DrawRect(int x_begin, int y_begin, int width, int height, FX::FXColor color);
            virtual void DrawRect(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color);
            virtual void DrawTriangle(int x_a_begin, int y_a_begin,int x_b_begin, int y_b_begin,int x_c_begin, int y_c_begin, FX::FXColor color);
            virtual void DrawTriangle(FX::FXPoint where_a_begin, FX::FXPoint where_b_begin, FX::FXPoint where_c_begin, FX::FXColor color);
            virtual void DrawPolygon(int x, int y, uint32_t point_count, FX::FXColor color);
            virtual void DrawPolygon(FX::FXPoint point, uint32_t point_count, FX::FXColor color);
            virtual void DrawPolyLine(int x, int y, uint32_t point_count, FX::FXColor color);
            virtual void DrawPolyLine(FX::FXPoint point, uint32_t point_count, FX::FXColor color);
        public:
            virtual void FillRect(int x_begin, int y_begin, int width, int height, FX::FXColor color);
            virtual void FillRect(FX::FXPoint where_begin, FX::FXPoint where_end, FX::FXColor color);
            virtual void FillCircle(int center_x, int center_y, int radius, FX::FXColor color);
            virtual void FillCircle(FX::FXPoint where, int radius, FX::FXColor color);
            virtual void FillArc(int center_x, int center_y, int begin_angle, int end_angle, FX::FXColor color);
            virtual void FillArc(FX::FXPoint where, int begin_angle, int end_angle, FX::FXColor color);
            virtual void FillTriangle(int x_a_begin, int y_a_begin,int x_b_begin, int y_b_begin,int x_c_begin, int y_c_begin, FX::FXColor color);
            virtual void FillTriangle(FX::FXPoint where_a_begin, FX::FXPoint where_b_begin, FX::FXPoint where_c_begin, FX::FXColor color);
            virtual void FillPolygon(int x, int y, uint32_t point_count, FX::FXColor color);
            virtual void FillPolygon(FX::FXPoint point, uint32_t point_count, FX::FXColor color);
        public:
            virtual void SetFont(FX::FXFont);
            FX::FXFont GetFont() const;

            virtual void SetViewColor(FX::FXColor view_color);
            FX::FXColor GetViewColor() const;

            void SetPenSize(uint32_t pen_size);
            uint32_t GetPenSize() const;

            FX::FXRect GetViewSize() const;
            void SetViewSize(FX::FXRect size);

            void Present();

            //FXPoint GetMousePoint();
        /*public:
            virtual void SetMouseableRect(const FX::FXRect rect) const { return mousableRect = rect; }
        */
        private:
            const FX::FXRect mousableRect;
            const bool visibility;
            const FX::FXRect viewRect;
    };
}

#endif
