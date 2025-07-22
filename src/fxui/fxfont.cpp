#include <fxfont.h>
#include <fxdisplay.h>
#include <fxplatformuidefs.h>

#if defined BACKEND_X11
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <X11/xpm.h>
    #include <X11/Xft/Xft.h>
    #include <X11/extensions/Xrender.h>
#endif

//#include <iostream>

namespace
{
    #if defined BACKEND_X11
        XftFont      *font;
        XftDraw      *xftdraw;
        XRenderColor xrcolor;
        XftColor     xftcolor;
        XGlyphInfo xglyphinfo;
    #endif
}

FX::FXFont::FXFont(FXDisplay* display, const char* fontName)
    :
    font_name(fontName),
    font_style(FONT_STYLE_DEFAULT),
    font_size(FONT_SIZE_PLAIN_UI),
    d(display)
    {
    }

FX::FXFont::~FXFont()
{
}

void
FX::FXFont::Init()
{
}

void
FX::FXFont::Cleanup()
{
}

void
FX::FXFont::SetFontName(const char* fontName)
{
}

void
FX::FXFont::SetFontStyle(uint32_t newFontStyle)
{
}

const void*
FX::FXFont::GetPlatformFont() const
{
}
