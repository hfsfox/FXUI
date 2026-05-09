/**----------------------------------------------------------------------------
* FXUI SDK
* FXUI: Graphical User Interface Framework:
*
* Version 0.1       Date :
*
*------------------------------------------------------------------------------
* MIT
* © 2025, , All Rights Reserved
*------------------------------------------------------------------------------
**/

#ifndef __FXDISPLAY_H__
#define __FXDISPLAY_H__

#include <base/stdlib/fxstatuscode.h>
#include <gui/support/fxrect.h>
#include <gui/fxwindow.h>
#include <support/fxeventhandler.h>
#include <stdint.h>

namespace
{
}

namespace fx
{
    typedef struct monitor_info_t
        {
            const char* name;       // The name of monitor
            bool        primary;    // The monitor is primary
            //FX::FXRect  rect;       // The position and size of monitor
        } monitor_info_t;
}

/**
 * Display interface
 * Get and obtain monitor(s) info form backends for toolkit needs
 **/

namespace FX
{
    class FXDisplay
    {
        public:
            FXDisplay()
            :
            screens(0)
            {
            };
            virtual ~FXDisplay()
            {
            }
        public:
            /**
             * Initialize display
             * @param argc number of additional arguments
             * @param argv array of additional arguments
             * @return status of operation
             **/
            virtual status_code_t Init(int argc = 0, const char **argv = NULL)
            {
                return fx::status::FX_STATUS_OK;
            };
            /**
            * Destroy display
            **/
            virtual void Destroy()
            {
            };
        public:
            virtual status_code_t RunLoop()
            {
                return fx::status::FX_STATUS_OK;
            }
        public:
             /**
            * Perform the underlying protocol transfer synchronization
            **/
            virtual void Sync()
            {
            };
            /**
             * Return number of available screens.
             * @return number of available screens.
             **/
            virtual unsigned int GetAvaliableScreens()
            {
                return 0;
            };
            /**
             * Get number of default screen
             * @return number of default screen
             **/
            virtual unsigned int GetDefaultScreen()
            {
                return 0;
            };
            /**
             * Get size of the screen
             * @param screen sreen number
             * @param w pointer to store width
             * @param h pointer to store height
             * @return status of operation
             **/
            virtual status_code_t GetScreenSize(unsigned int screen = 0,
                                                unsigned int *w = 0,
                                                unsigned int *h = 0)
            {
                if(screen < screens || screen > screens)
                    return fx::status::FX_STATUS_NOT_FOUND;

                return fx::status::FX_STATUS_OK;
            };

            /** Create native window
             *
             * @return FXWindow
             **/
            /*virtual FXWindow *CreateWindow()
            {
            };*/

            /** Create window at the specified screen
             *
             * @param screen screen
             * @return FX::FXWindow
             **/
            /*virtual FXWindow *CreateWindow(unsigned screen)
            {
            };*/
            /** Return screen number from specified window
             *
             * @param FX::Window window
             * @return unsigned int screen
             **/
            virtual unsigned int GetCurrentScreenFromWindow(FX::FXWindow* window)
            {
                return 0;
            };

            virtual FX::FXWindow* CreateWindowAndAttach(unsigned int screen = 0)
            {
                FX::FXEventHandler* h = new FX::FXEventHandler;
                FX::FXWindow* wnd = new FX::FXWindow(h);
                attached_windows++;
                return wnd/*new FX::FXWindow(NULL)*/;
            }

            virtual status_code_t AttachWindow(FX::FXWindow* window = NULL,
                                               unsigned int screen = 0)
            {
                if(screen < screens || screen > screens)
                {
                    return fx::status::FX_STATUS_NOT_FOUND;
                }
                else if (window == NULL)
                {
                    return fx::status::FX_STATUS_UNKNOWN_ERR;
                }

                attached_windows++;
                return fx::status::FX_STATUS_OK;
            }

        private:
            unsigned int screens;
            unsigned int attached_windows;
    };
}

#endif //__FXDISPLAY_H__
