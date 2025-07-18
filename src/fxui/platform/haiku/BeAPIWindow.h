/*
 * Copyright 2018, Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef __BEAPIWINDOW_H__
#define __BEAPIWINDOW_H__

#include <game/DirectWindow.h>

class BDirectWindow;

class BeAPIWindow : public BDirectWindow
{
    public:
        BeAPIWindow(BRect frame, const char* title);
        virtual bool QuitRequested() override;
        bool ShouldClose() const { return fShouldClose; }
    //private:
        volatile bool fShouldClose;
};



#endif // _H
