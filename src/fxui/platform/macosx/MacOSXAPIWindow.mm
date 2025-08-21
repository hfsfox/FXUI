#include "MacOSXAPIWindow.h"

#if defined (BACKEND_COCOA)

#include <AppKit/AppKit.h>
#include <Cocoa/Cocoa.h>
#include <Foundation/Foundation.h>
#include <Foundation/NSString.h>
#include <Carbon/Carbon.h>
#include <objc/message.h>
#include <objc/runtime.h>
#include <objc/objc-runtime.h>

#define cls objc_getClass
#define sel sel_getUid
#define msg ((id(*)(id, SEL, ...))objc_msgSend)
#define cls_msg ((id(*)(Class, SEL, ...))objc_msgSend)

extern "C"
{
    void* objc_autoreleasePoolPush(void);
    void objc_autoreleasePoolPop(void* pool);
}

@interface CocoaAPIWindow : NSWindow
{
}
@end

@implementation CocoaAPIWindow

@end

@interface CocoaAPIView : NSView
//- (BOOL)	acceptsFirstResponder;
//- (BOOL)	isOpaque;
{
}
@end

/*@interface CocoaAPIMenu : NSMenu
{
}
//-(void)dealloc;
//- (id)copyWithZone:(NSZone *)zone;
@end

@implementation CocoaAPIMenu

@end*/

@implementation CocoaAPIView

@end

@interface CocoaAPIMenuBar: NSMenu
@end

@implementation CocoaAPIMenuBar
@end

namespace
{
    NSString*
    ConvertFromChar(const char* char_str)
    {
        return [[NSString stringWithUTF8String: char_str]autorelease];
    };

    NSMenu*
    CreateMenuBar(const char* init_label)
    {
        CocoaAPIMenuBar* mainMenuBar;
        NSString* label = (NSString *)ConvertFromChar(init_label);
        mainMenuBar=[[CocoaAPIMenuBar alloc] initWithTitle:label];
        [label release];
        mainMenuBar=[[CocoaAPIMenuBar alloc] init];
        [mainMenuBar setAutoenablesItems:NO];
        return mainMenuBar;
    };

}


MacOSXAPIMenuBar::MacOSXAPIMenuBar(const char* _label)
{
    CocoaAPIMenuBar* mainMenuBar;
    NSString* label = (NSString *)ConvertFromChar(_label);
    mainMenuBar=[[CocoaAPIMenuBar alloc] initWithTitle:label];
    [label release];
    //

    /*id appMenuItem = msg(cls_msg(cls("NSMenuItem"), sel("alloc")), sel("init"));
    
    // Add application menu item to main menu bar
    msg(mainMenuBar, sel("addItem:"), appMenuItem);
    
    // Create application submenu
    id appTitle = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "Application");
    id appMenu = msg(cls_msg(cls("NSMenu"), sel("alloc")), sel("initWithTitle:"), appTitle);
    
    // Set the submenu for the application menu item
    msg(appMenuItem, sel("setSubmenu:"), appMenu);
    
    // Add some common application menu items
    
    // About menu item
    id aboutTitle = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "About");
    id aboutItem = msg(cls_msg(cls("NSMenuItem"), sel("alloc")), 
                      sel("initWithTitle:action:keyEquivalent:"), 
                      aboutTitle, sel("orderFrontStandardAboutPanel:"), 
                      cls_msg(cls("NSString"), sel("string")));
    //msg(aboutItem, sel("setTarget:"), app);
    msg(appMenu, sel("addItem:"), aboutItem);
    
    // Separator
    id separator = cls_msg(cls("NSMenuItem"), sel("separatorItem"));
    msg(appMenu, sel("addItem:"), separator);
    
    // Quit menu item
    id quitTitle = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "Quit");
    id quitKeyEquiv = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "q");
    id quitItem = msg(cls_msg(cls("NSMenuItem"), sel("alloc")),
                     sel("initWithTitle:action:keyEquivalent:"),
                     quitTitle, sel("terminate:"), quitKeyEquiv);
    //msg(quitItem, sel("setTarget:"), app);
    msg(appMenu, sel("addItem:"), quitItem);
    
    // Set the main menu
    //msg(app, sel("setMainMenu:"), mainMenuBar);
    
    // Clean up (release objects)
    msg(appMenuItem, sel("release"));
    msg(appMenu, sel("release"));
    msg(aboutItem, sel("release"));
    msg(quitItem, sel("release"));
    msg(mainMenuBar, sel("release"));
    */
    //
    mainMenuBar=[[CocoaAPIMenuBar alloc] init];
    [menubar setAutoenablesItems:NO];
};

MacOSXAPIMenuBar::~MacOSXAPIMenuBar()
{
    //NSMenu *menubar=(NSMenu *)CocoaAPIMenuBar;
    [menubar release];
}

/*NSMenu*
MacOSXAPIMenuBar::MacOSXAPIMenuBar()
{
    retunr menu
}*/

//MacOSXAPIMenuBar::

MacOSXAPIApplication::MacOSXAPIApplication()
{
    //[NSApplication sharedApplication];
    //[NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
    /*id app = [NSApplication sharedApplication];
    [app setActivationPolicy:NSApplicationActivationPolicyRegular];
    [app activateIgnoringOtherApps:YES];
    [app run];
    */
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

    //id pool = cls_msg(cls("NSAutoreleasePool"),sel("new"));
    //NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    NSAutoreleasePool *pool = msg(cls_msg(cls("NSAutoreleasePool"), sel("alloc")), sel("init"));

    NSApplication* app = NSApplication.sharedApplication;
    app.ActivationPolicy = NSApplicationActivationPolicyRegular;
    //id app = [NSApplication sharedApplication];
    //[app setActivationPolicy:NSApplicationActivationPolicyRegular];
    [app activateIgnoringOtherApps:YES];

    struct CGRect frameRect = {static_cast<CGFloat>(rect.x), static_cast<CGFloat>(rect.y), static_cast<CGFloat>(rect.x + rect.width), static_cast<CGFloat>(rect.y + rect.height)};
    //id window
    CocoaAPIWindow* window = (NSWindow*)[[CocoaAPIWindow alloc] initWithContentRect:frameRect
    styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable|NSWindowStyleMaskResizable
    backing:NSBackingStoreBuffered defer:NO];

    if (window == NULL)
    {
        fprintf(stderr, "Failed to create NSWindow\n");
    }

    //[window setStyleMask: NSResizableWindowMask | NSClosableWindowMask | NSTitledWindowMask];

    //msg(window, sel("setTitle:"), cls_msg(cls("NSString"), sel("stringWithUTF8String:"), title));

    [window setTitle: ConvertFromChar(title)];

    //[app setMainMenu: CreateMenuBar("File")];

    //[window makeKeyAndOrderFront:nil];
    [window makeKeyAndOrderFront: app];
    [window setOpaque:NO];
    
    //MacOSXAPIMenuBar* mb = new MacOSXAPIMenuBar("File");

    //
    //
    //msg(app, sel("setMainMenu:"), mb->MainMenuBar());
    //[app setMainMenu: mb->menubar];

    //[app setMainMenu: CreateMenuBar("File")];

    //NSPoint windowOrigin = [[window contentView] convertPoint:NSMakePoint(0,0) fromView:myView];
    //NSRect viewFrameInWindowCoords = [myView convertRect: [myView bounds] toView: nil];
    //NSRect contentRect = NSMakeRect (0, 0, config.size.x, config.size.y);

    //NSRect contentRect = NSMakeRect (0, 0, config.size.x, config.size.y);

    NSView *view = [[NSView alloc] initWithFrame: /*frameRect*/ NSMakeRect(0, 0, frameRect.size.width/*100*/, frameRect.size.height/*100*/)];
    [view setWantsLayer:YES];
    //NSColor* bg_color = [[NSColor alloc] init: CGColor{static_cast<CGFloat>(0),static_cast<CGFloat>(0),static_cast<CGFloat>(0),static_cast<CGFloat>(255)}];
    view.layer.backgroundColor = [[NSColor grayColor] CGColor];
    //CGColor* graycolor = { .red= 160, .green= 160, .blue= 160, .alpha= 1.0};
    //NSColor* bg_color = [[NSColor alloc] init: CGColor.init(red:160, green:160, blue:160, alpha: 1.0)];
    //view.layer.backgroundColor = bg_color;
    //NSRect viewFrameInWindowCoords = [view convertRect: [view bounds] toView: nil];

    //[[NSColor redColor] setFill];
    //NSRect rectToDraw = NSMakeRect(20, 20, 100, 50);
    //NSRectFill(rectToDraw);

    [window.contentView addSubview:view];

    //[app ]
    //msg(pool, sel("drain"));

    [app run];

    [pool release];
    //[pool drain]; //or, even older, [pool release];

    //msg(pool, sel("drain"));

    /*id pool = cls_msg(cls("NSAutoreleasePool"),sel("new"));
    // Create main menu bar
    id mainMenuBar = msg(cls_msg(cls("NSMenu"), sel("alloc")), sel("init"));
    
    // Create application menu item (this will be the first item in the menu bar)
    id appMenuItem = msg(cls_msg(cls("NSMenuItem"), sel("alloc")), sel("init"));
    
    // Add application menu item to main menu bar
    msg(mainMenuBar, sel("addItem:"), appMenuItem);
    
    // Create application submenu
    id appTitle = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "@Application");
    id appMenu = msg(cls_msg(cls("NSMenu"), sel("alloc")), sel("initWithTitle:"), appTitle);
    
    // Set the submenu for the application menu item
    msg(appMenuItem, sel("setSubmenu:"), appMenu);
    
    // Add some common application menu items
    
    // About menu item
    id aboutTitle = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "@About");
    id aboutItem = msg(cls_msg(cls("NSMenuItem"), sel("alloc")), 
                      sel("initWithTitle:action:keyEquivalent:"), 
                      aboutTitle, sel("orderFrontStandardAboutPanel:"), 
                      cls_msg(cls("NSString"), sel("string")));
    msg(aboutItem, sel("setTarget:"), app);
    msg(appMenu, sel("addItem:"), aboutItem);
    
    // Separator
    id separator = cls_msg(cls("NSMenuItem"), sel("separatorItem"));
    msg(appMenu, sel("addItem:"), separator);
    
    // Quit menu item
    id quitTitle = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "@Quit");
    id quitKeyEquiv = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "@q");
    id quitItem = msg(cls_msg(cls("NSMenuItem"), sel("alloc")),
                     sel("initWithTitle:action:keyEquivalent:"),
                     quitTitle, sel("terminate:"), quitKeyEquiv);
    msg(quitItem, sel("setTarget:"), app);
    msg(appMenu, sel("addItem:"), quitItem);

    id fileMenuItem = msg(cls_msg(cls("NSMenuItem"), sel("alloc")), sel("init"));

    msg(mainMenuBar, sel("addItem:"), fileMenuItem);

    // Create application submenu
    id fileTitle = cls_msg(cls("NSString"), sel("stringWithUTF8String:"), "@File");
    id fileMenu = msg(cls_msg(cls("NSMenu"), sel("alloc")), sel("initWithTitle:"), fileTitle);
    
    // Set the submenu for the application menu item
    msg(appMenuItem, sel("setSubmenu:"), fileMenu);
    
    
    // Set the main menu
    msg(app, sel("setMainMenu:"), mainMenuBar);
    
    // Clean up (release objects)
    msg(appMenuItem, sel("release"));
    msg(appMenu, sel("release"));
    msg(aboutItem, sel("release"));
    msg(quitItem, sel("release"));
    msg(mainMenuBar, sel("release"));

    msg(pool, sel("drain"));
    */
};

bool
MacOSXAPIWindow::QuitRequested()
{
    //[NSApp terminate:[NSApplication sharedApplication]];
};


void
MacOSXAPIWindow::SetTitle(const char* title)
{
    //CocoaAPIWindow* window = (NSWindow*)[CocoaAPIWindow setTitle: ConvertFromChar(title)];
    [window setTitle: ConvertFromChar(title)];
};

/*
   NSApplication* app = NSApplication.sharedApplication;
    app.ActivationPolicy = NSApplicationActivationPolicyRegular;
    NSMenuItem* item = [NSMenuItem new];
    NSApp.mainMenu = [NSMenu new];
    item.submenu = [NSMenu new];
    [app.mainMenu addItem: item];
    [item.submenu addItem: [[NSMenuItem alloc] initWithTitle: [@"Quit " stringByAppendingString: NSProcessInfo.processInfo.processName] action:@selector(terminate:) keyEquivalent:@"q"]];
    AppDelegate* appDelegate = [AppDelegate new]; // cannot collapse this and next line because .delegate is weak
    app.delegate = appDelegate;
    [app run];
*/


CocoaApplication::CocoaApplication(int _argc, char** _argv)
{
    /*return*/ NSApplicationMain(0, 0/*(const char*)_argv*/);
};

int
CocoaApplication::Return()
{
    //return NSApplicationMain(_argc, _argv);
};


FXCocoaAutoreleasePool::FXCocoaAutoreleasePool()
//:
//pool(objc_autoreleasePoolPush())
{
    autorelease_pool = objc_autoreleasePoolPush();
};

FXCocoaAutoreleasePool::~FXCocoaAutoreleasePool()
{
    objc_autoreleasePoolPop(autorelease_pool);
};

#endif



