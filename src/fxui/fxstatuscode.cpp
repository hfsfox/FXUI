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

#include <fxstatuscode.h>
#include <stdint.h> // for NULL

namespace
{
    const char *status_descriptions[] =
    {
        "OK",
        "NULL",
        "Unspecified",
        "Loading",
        "In process",
        "Unknown error",
        "No memory",
        "Not found",
        "I/O error",
        "No file",
        "End of file",
        "Bad arguments",
        //
        NULL
    };
}

const char*
fx::get_status(status_code_t code)
{
    return ((code >= 0) && (code < FX_STATUS_TOTAL)) ? status_descriptions[code] : NULL;
}

bool
fx::status_is_success(status_code_t code)
{
    return code == FX_STATUS_OK;
}

bool
fx::status_is_error(status_code_t code)
{
    if (status_is_success(code))
        return true;

    return false;
}
