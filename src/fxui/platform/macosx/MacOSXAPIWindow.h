#include <fxrect.h>
#include <limits>
#ifdef BACKEND_COCOA

//NSApplication       *NSApplicationInstance;

class MacOSXAPIApplication
{
    public:
        MacOSXAPIApplication();
};

class MacOSXAPIWindow
{
    public:
        MacOSXAPIWindow(FX::FXRect frame, const char* title);
        virtual bool QuitRequested();
        virtual void SetTitle(const char* title);
        bool ShouldClose() const { return fShouldClose; }
    public:
        volatile bool fShouldClose;
    public:
        //NSString*
        void* cocoaWindowTitle = nullptr;
        // CocoaAPIWindow*
        void* window;
        // CocoaAPIView*
	    void* view = nullptr;
};

class MacOSAPIView
{

};

class MacOSXAPIMenuBar
{
    public:
        MacOSXAPIMenuBar(const char* _label);
        ~MacOSXAPIMenuBar();
    public:
        void* MainMenuBar() { return menubar; }
    public:
        void* menubar;
};

class CocoaApplication
{
    public:
        CocoaApplication(int argc, char** argv);
        int Return();
    private:
       int _argc;
       char** _argv;
};

#endif
