//-----------------------------------------------------------------------------
// FXUI SDK
// FXUI: Graphical User Interface Framework:
//
// Version 0.1       Date :
//
//-----------------------------------------------------------------------------
// MIT
// © 2025, , All Rights Reserved
//-----------------------------------------------------------------------------

#ifndef     __FXCOCOAAUTORELEASEPOOL__
#define     __FXCOCOAAUTORELEASEPOOL__

#ifdef BACKEND_COCOA

    class FXCocoaAutoreleasePool
    {
        public:
            FXCocoaAutoreleasePool();
            ~FXCocoaAutoreleasePool();
        private:
            void* autorelease_pool;
    };

    #endif
#endif
