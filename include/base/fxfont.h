#pragma once

#ifndef __FXFONT_H__
#define __FXFONT_H__

#include <stdint.h>
#include <fxdisplay.h>

enum
{
    FONT_SIZE_PLAIN_UI =10
};

enum
{
    FONT_STYLE_DEFAULT = 0,
    FONT_STYLE_BOLD,
    FONT_STYLE_ITALIC,
    FONT_STYLE_LIGHT
};

namespace FX
{
    class FXFont
    {
        public:
            FXFont(FX::FXDisplay* display, const char* font_name);
            ~FXFont();
        public:
            void Init();
            void Cleanup();
        public:
            // get the name of the font
            const char* GetFontName () const { return font_name; }
        public:
            // set the name of the font
            void SetFontName (const char* newName);
            // set the style of the font (TODO: see font style defines)
            void SetFontStyle(uint32_t newStyle);
            //void SetSize ( FX::FXCoord newSize);
        public:
        //virtual const void* GetPlatformFont () const;
        public:
            const char* font_name;
            int32_t font_style;
            int32_t font_size;
            FX::FXDisplay* d;
    };
}


#endif
