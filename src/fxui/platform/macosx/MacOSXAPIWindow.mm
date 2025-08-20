#include "MacOSXAPIWindow.h"

#if defined (BACKEND_COCOA)

#include <Cocoa/Cocoa.h>
#include <Foundation/Foundation.h>
#include <Foundation/NSString.h>
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

    [window setStyleMask: NSResizableWindowMask | NSClosableWindowMask | NSTitledWindowMask];

    //msg(window, sel("setTitle:"), cls_msg(cls("NSString"), sel("stringWithUTF8String:"), title));

    [window setTitle: ConvertFromChar(title)];

    //[app setMainMenu: CreateMenuBar("File")];

    //[window makeKeyAndOrderFront:nil];
    [window makeKeyAndOrderFront: app];
    
    //MacOSXAPIMenuBar* mb = new MacOSXAPIMenuBar("File");

    //
    //
    //msg(app, sel("setMainMenu:"), mb->MainMenuBar());
    //[app setMainMenu: mb->menubar];

    //[app setMainMenu: CreateMenuBar("File")];

    //NSPoint windowOrigin = [[window contentView] convertPoint:NSMakePoint(0,0) fromView:myView];
    //NSRect viewFrameInWindowCoords = [myView convertRect: [myView bounds] toView: nil];

    NSView *view = [[NSView alloc] initWithFrame:frameRect/*NSMakeRect(100, 100, 100, 100)*/];
    [view setWantsLayer:YES];
    view.layer.backgroundColor = [[NSColor yellowColor] CGColor];

    [window.contentView addSubview:view];

    //[app ]

    [app run];

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
    //[window setTitle: ConvertFromChar(title)];
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


#endif



