#ifndef __FXBITMAP_H__
#define __FXBITMAP_H__

#include <stdint.h>

namespace FX
{
    class FXBitmap
    {
        public:
            FXBitmap();
            FXBitmap(uint32_t resourceID);
            FXBitmap(int width, int height);
            ~FXBitmap();
        public:
            inline uint32_t GetWidth(void) { return width; }
            inline uint32_t GetHeight (void) { return height; }
        public:
            bool IsLoaded ();
        public:
            uint32_t resourceID;
            uint32_t width;
            uint32_t height;
            int pixel_format;
        private:
    };
}

#endif
