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

#ifndef     __FXWINDOW__
#define     __FXWINDOW__

// platform specific headers

//common headers
#include <base/stdlib/fxstatuscode.h>
#include <gui/fxdisplay.h>
#include <gui/support/fxrect.h>
#include <support/fxeventhandler.h>

namespace FX
{
    class FXWindow
    {
        public:
            explicit FXWindow(FXDisplay *dpy, void* parentptr, FX::FXEventHandler *handler, bool embedded)
            {
                if(!handler == NULL)
                    _window_handler = handler;
                _window_handler = NULL;
            };
            virtual ~FXWindow()
            {
                _window_handler = NULL;
            };
        public:
            virtual void Show()
            {
            };
            virtual void Hide()
            {
            };
            /** Return current screen of the window
              * @return screen of the window
              **/
            virtual unsigned int Screen()
            {
                return 0;
            };
            /*virtual void AddHandler(FX::FXEventHandler* h)
            {
                _window_handler = h;
            }*/
            /** Get left coordinate of window
                 *
                 * @return value
                 */
                virtual unsigned int left() { return window_rect.y; }

                /** Get top coordinate of window
                 *
                 * @return value
                 */
                virtual unsigned int top() { return window_rect.x; }

                /** Get width of the window
                 *
                 * @return value
                 */
                virtual unsigned int width() { return window_rect.width; }

                /** Get height of the window
                 *
                 * @return value
                 */
                virtual unsigned int  height() { return window_rect.height; }

                /** Get window visibility
                 *
                 * @return true if window is visible
                 */
                virtual bool isVisible() { return is_visible; }
             /**
              * @param handler event handler
              **/
            inline void SetHandler(FX::FXEventHandler* handler)     { _window_handler = handler; }

            virtual status_code_t SetTitle(const char* title)
            {
                window_title = title;
                return fx::status::FX_STATUS_OK;
            }
            virtual status_code_t SetIcon(const void *bgra, unsigned int width, unsigned int height)
            {
                //lsp_error("not implemented");
                return fx::status::FX_STATUS_NOT_IMPLEMENTED;
            }
        protected:
            //FXEventHandler  *pHandler;
            //FXDisplay       *pDisplay;
            FX::FXEventHandler* _window_handler;
            bool is_visible;
            bool is_closed;
            bool is_maximized;
            bool is_minimized;
            FX::FXRect window_rect;
            const char* window_title;

    };
}

#endif
