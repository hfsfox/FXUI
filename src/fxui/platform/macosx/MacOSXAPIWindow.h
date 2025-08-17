#include <fxrect.h>
#ifdef BACKEND_COCOA

//NSApplication       *NSApplicationInstance;

class MacOSXAPIWindow
{
    public:
        MacOSXAPIWindow(FX::FXRect frame, const char* title);
        virtual bool QuitRequested();
        bool ShouldClose() const { return fShouldClose; }
    public:
        volatile bool fShouldClose;
    public:
        //NSString*
        void* cocoaWindowTitle = nullptr;
        // CocoaAPIWindow*
        void* window = nullptr;
        // CocoaAPIView*
	    void* view = nullptr;
};

class MacOSAPIView
{

};

class MacOSXAPIMenuBar
{

};

#endif
