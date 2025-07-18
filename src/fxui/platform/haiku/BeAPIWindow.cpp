#include "BeAPIWindow.h"
#include "BApplicationInstance.h"
#include <game/DirectWindow.h>

BeAPIWindow::BeAPIWindow(BRect frame, const char* title)
    :
    BDirectWindow(frame, title, B_TITLED_WINDOW, B_QUIT_ON_WINDOW_CLOSE), fShouldClose(false)
    {
    }

bool
BeAPIWindow::QuitRequested()
{
        fShouldClose = true;
        BApplicationInstance::GetInstance()->PostMessage(B_QUIT_REQUESTED);
        return true;
}


