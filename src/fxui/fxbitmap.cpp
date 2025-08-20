#include <fxbitmap.h>
#include <fxplatformuidefs.h>

#if defined BACKEND_X11
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <X11/xpm.h>
#endif

namespace
{
    #if defined BACKEND_X11
    Pixmap
_LoadPixmap(char** xpm_data)
{
    Pixmap pixmap  = 0;
    /*
    Pixel fg,bg,ns,ts;
    XpmAttributes xpm_attributes;
    GC gc= NULL;
    Dimension thin_borders;
    static Display *display = XtDisplay(toplevel);
    Screen *screen = XtScreen(toplevel);
    Window root = RootWindowOfScreen(screen);
    static XpmColorSymbol XpmTransparentColor[1] = {{ NULL, (char*)"none", 0 }};
    static int depth = DefaultDepth(display,root);

    gc = XCreateGC(display, root, 0, NULL);

    XtVaGetValues(toplevel, XmNforeground, &fg, XmNbackground, &bg, XmNbottomShadowColor, &ns, XmNtopShadowColor, &ts, NULL);

    if(XpmCreatePixmapFromData(XtDisplay(toplevel),
                           RootWindowOfScreen(XtScreen(toplevel)),
                           const_cast<char**>(xpm_data),
                           &pixmap,
                           NULL,
                            NULL) != XpmSuccess) {
                            pixmap = 0;
                            }

    XtReleaseGC(toplevel,gc);
    */
    return pixmap;
    }
    #endif
}

FX::FXBitmap::FXBitmap()
{
}

FX::FXBitmap::FXBitmap(int width, int height, colorspace colorspace)
{
}

FX::FXBitmap::~FXBitmap()
{
}


