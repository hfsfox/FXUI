#include <support/fxeventhandler.h>

namespace FX
{
    FXEventHandler::FXEventHandler()
    {
    };

    FXEventHandler::~FXEventHandler()
    {
    };


    status_code_t
    FXEventHandler::HandleEvent(const fx::event::event_t* handled_event)
    {
        return fx::status::FX_STATUS_OK;
    };
}
