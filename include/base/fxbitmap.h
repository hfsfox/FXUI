#ifndef __FXBITMAP_H__
#define __FXBITMAP_H__

#include <stdint.h>

enum colorspace
{
    FX_RGB = 0,
    FX_RGBA,
    FX_GRAYSCALE
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
            uint32_t resourceID;
            uint32_t width;
            uint32_t height;
            int pixel_format;
            bool loaded;
        private:
    };
}

#endif
