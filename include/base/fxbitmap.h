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

#ifndef __FXBITMAP_H__
#define __FXBITMAP_H__

#include <stdint.h>

enum colorspace
{
    FX_RGB = 0,
    FX_RGBA,
    FX_GRAYSCALE
};

/**
 *
 *Pixel description format for color component
 *
 **/

enum pixel_format_t
{
    PIXEL_RGBA,
    PIXEL_BGRA,
    PIXEL_RGB,
    PIXEL_BGR
};

namespace FX
{
    class FXBitmap
    {
        public:
            FXBitmap();
            FXBitmap(uint32_t resourceID);
            FXBitmap(int width, int height, colorspace colorspace);
            ~FXBitmap();
        public:
            uint32_t GetWidth(void) { return width; }
            uint32_t GetHeight (void) { return height; }
        public:
            bool IsLoaded () {return loaded;}
        public:
            //void* PlatformBitmap(void) const { return platform_bitmap; }
        public:
            uint32_t resourceID;
            uint32_t width;
            uint32_t height;
            int pixel_format;
            bool loaded;
            //
            //void* platform_bitmap;
        private:
    };
}

#endif
