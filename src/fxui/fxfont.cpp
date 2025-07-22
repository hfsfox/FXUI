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
        #if defined(PLATFORM_HAIKU)
        #elif defined (PLATFORM_LINUX)
        /*xrcolor.red = 0xFFFF;
        xrcolor.green = 0xFFFF;
        xrcolor.blue = 0xFFFF;
        xrcolor.alpha=0xFFFF;
        //display->display
        XftColorAllocValue(display->display,DefaultVisual(display->display,0),DefaultColormap(display->display,0),&xrcolor,&xftcolor);*/
        font = XftFontOpenName(display->display,0,"Arial-10");
        #endif
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
    #if defined BACKEND_X11
        return static_cast<void*>(font);
    #endif
}
