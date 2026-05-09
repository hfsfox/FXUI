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

#ifndef     __FXEVENTHANDLER_H__
#define     __FXEVENTHANDLER_H__

#include <stdint.h>
#include <base/stdlib/fxstatuscode.h>

namespace fx
{
    namespace event
    {
        typedef uint64_t    ui_timestamp_t;
        typedef uint32_t    raw_code_t;

        enum event_code_t
        {
            // Special events
            FX_EVENT_NULL,
            FX_EVENT_UNKNOWN,
            FX_EVENT_CUSTOM,
            // Keyboard events
            FX_EVENT_KEY_DOWN,
            FX_EVENT_KEY_UP,
            // Mouse events
            FX_EVENT_MOUSE_DOWN,
            FX_EVENT_MOUSE_UP,
            FX_EVENT_MOUSE_CLICK,
            FX_EVENT_MOUSE_DOUBLE_CLICK,
            FX_EVENT_MOUSE_MOVE,
            FX_EVENT_MOUSE_IN,
            FX_EVENT_MOUSE_OUT,
            //Surface events
            FX_EVENT_REDRAW,
            FX_EVENT_RENDER,
            //Window events
            FX_EVENT_WINDOW_RESIZE,                     // Window has been resized
            FX_EVENT_WINDOW_SHOW,                       // Window becomes visible
            FX_EVENT_WINDOW_HIDE,                       // Window becomes hidden
            FX_EVENT_WINDOW_CLOSE,                      // Window has been closed
            FX_EVENT_WINDOW_FOCUS_IN,                   // Window has been focused in
            FX_EVENT_WINDOW_FOCUS_OUT,                  // Window has been focused out
            FX_EVENT_WINDOW_MAXIMIZED,
            FX_EVENT_WINDOW_MINIMIZED,
            //DnD events
            FX_EVENT_DRAG,
            FX_EVENT_DROP,
            // Application events
            FX_EVENT_APP_QUIT_REQUESTED,
            // Supplementary constants
            FX_EVENT_TOTAL,
            //FX_EVENT_FIRST = FX_EVENT_KEY_DOWN,
            //FX_EVENT_LAST = FX_EVENT_DRAG_REQUEST,
            FX_EVENT_END = FX_EVENT_UNKNOWN
        };

        typedef struct event_t
        {
            raw_code_t raw_code;            //raw code
            raw_code_t code;                // Key code, button, scroll direction
            event_code_t type;              //type of event, see event_code_t
            ui_timestamp_t event_timecode;  //timestamp in millisecons
        } event_t;
    }
}

namespace FX
{
    class FXEventHandler
    {
        public:
            explicit FXEventHandler();
            virtual ~FXEventHandler();
        public:
            /**
             * Handle event
             * @param handled_event event
             * @return status code of operation
             **/
            virtual status_code_t HandleEvent(const fx::event::event_t*
            handled_event);
    };
}

#endif
