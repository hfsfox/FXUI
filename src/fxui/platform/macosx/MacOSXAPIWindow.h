#include <fxrect.h>
#ifdef BACKEND_COCOA

#include <Cocoa/Cocoa.h>
#include <Foundation/Foundation.h>
#include <Carbon/Carbon.h>
#include <objc/message.h>
#include <objc/runtime.h>

//NSApplication       *NSApplicationInstance;

class MacOSXWindow
{
    public:
        MacOSXWindow(FX::FXRect frame, const char* title);
        virtual bool QuitRequested();
        bool ShouldClose() const { return fShouldClose; }
        volatile bool fShouldClose;
};

#endif
