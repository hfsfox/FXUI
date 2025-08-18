#include "MacOSXAPIWindow.h"

#if defined (BACKEND_COCOA)

#include <Cocoa/Cocoa.h>
#include <Foundation/Foundation.h>
#include <Carbon/Carbon.h>
#include <objc/message.h>
#include <objc/runtime.h>

#define cls objc_getClass
#define sel sel_getUid
#define msg ((id(*)(id, SEL, ...))objc_msgSend)
#define cls_msg ((id(*)(Class, SEL, ...))objc_msgSend)

@interface CocoaAPIWindow : NSWindow
{
}
@end

@implementation CocoaAPIWindow

@end

@interface CocoaAPIView : NSView
//- (BOOL)	acceptsFirstResponder;
//- (BOOL)	isOpaque;

@end

@implementation CocoaAPIView

@end

@interface CocoaAPIMenuBar: NSMenu
@end

@implementation CocoaAPIMenuBar: NSMenu
@end

MacOSXAPIApplication::MacOSXAPIApplication()
{
    //[NSApplication sharedApplication];
    //[NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
    /*id app = [NSApplication sharedApplication];
    [app setActivationPolicy:NSApplicationActivationPolicyRegular];
    [app activateIgnoringOtherApps:YES];
    [app run];*/
};

MacOSXAPIWindow::MacOSXAPIWindow(FX::FXRect rect, const char* title)
{
    //MacOSXAPIApplication macapp;
    //macapp.MacOSXAPIApplication();
    //id app = [NSApplication sharedApplication];
    //[app setActivationPolicy:NSApplicationActivationPolicyRegular];
    //[NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
    //Get screen size
    //NSRect screenRect = [[NSScreen mainScreen] frame];
    //[app run];
    //struct CGRect frameRect = {0, 0, 500, 300};

    id app = [NSApplication sharedApplication];
    [app setActivationPolicy:NSApplicationActivationPolicyRegular];
    [app activateIgnoringOtherApps:YES];

    struct CGRect frameRect = {static_cast<CGFloat>(rect.x), static_cast<CGFloat>(rect.y), static_cast<CGFloat>(rect.x + rect.width), static_cast<CGFloat>(rect.y + rect.height)};
    id window = [[NSWindow alloc] initWithContentRect:frameRect
    styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable|NSWindowStyleMaskResizable
    backing:NSBackingStoreBuffered defer:NO];
    [window makeKeyAndOrderFront:nil];
    //
    [app run];
};

bool
MacOSXAPIWindow::QuitRequested()
{
};



#endif



