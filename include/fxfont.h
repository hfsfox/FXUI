#pragma once

#ifndef __FXFONT_H__
#define __FXFONT_H__

#include <stdint.h>

namespace FX
{
    class FXFont
    {
        public:
            FXFont();
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
            void SetFontStyle(int32_t newStyle);
            //void SetSize ( FX::FXCoord newSize);
        private:
        virtual const void* GetPlatformFont () const;
        public:
            const char* font_name;
            int32_t font_style;

    };
}


#endif
