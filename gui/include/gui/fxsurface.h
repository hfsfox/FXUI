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

#ifndef     __FXSURFACE_H__
#define     __FXSURFACE_H__

#include <base/stdlib/fxstatuscode.h>

namespace fx
{
     enum surface_type_t
        {
            //ST_UNKNOWN,         // Unknown surface type
            //ST_IMAGE,           // Image surface
            //ST_XLIB,            // Surface created by XLIB extension (X.11 Linux/FreeBSD)
            //ST_SIMILAR,         // Similar surface to the parent
            //ST_DDRAW,           // Surface created by Direct2D factory (Windows)
            //ST_OPENGL,          // OpenGL surface
            FX_DEFAULT_SURFACE,     // Default surface type connected to window,
                                    // 2D
            FX_IMAGE_SURFACE,       // Surface for drawing static bitmaps
            FX_ANIMATED_SURFACE,     // Surface for drawing changable elements
            FX_3D_SURFACE,          // Surface type for 3D render, OpenGL,
                                    // DirectX, Vulkan, Metal or softrender
            FX_UNKNOWN_SURFACE,     // Unknown type surface, as default
                                    // fallback to 2D
        };
}

namespace FX
{
    class FXSurface
    {
        public:
            protected:
                explicit FXSurface(unsigned int width, unsigned int height, fx::surface_type_t type /*= FX_DEFAULT_SURFACE*/)
                {
                };
        public:
            explicit FXSurface();
            virtual ~FXSurface();
        public:
            /** Create child surface for drawing
              * @param width surface width
              * @param height surface height
              * @return created surface or NULL
              **/
            virtual FXSurface *CreateChildSurface(unsigned int width, unsigned int height)
            {
                return NULL;
            };
            virtual status_code_t Resize(unsigned int width, unsigned int height);
        public:
            /** Get surface width
             * @return surface width
            **/
            inline unsigned int width() const { return _surface_width; }

            /** Get surface height
              * @return surface height
              **/
            inline unsigned int height() const { return _surface_height; }

            /** Get type of surface
              * @return type of surface
              **/
            inline fx::surface_type_t type()  const { return _surface_type; }
        protected:
                unsigned int          _surface_width;
                unsigned int          _surface_height;
                fx::surface_type_t    _surface_type;
    };
}

#endif
