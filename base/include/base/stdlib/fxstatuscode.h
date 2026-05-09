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

#ifndef __FXSTATUSCODE_H__
#define __FXSTATUSCODE_H__

#include <stdint.h>

typedef int status_code_t;

namespace fx
{
    namespace status
    {
        enum status_codes
        {
            FX_STATUS_OK,
            FX_STATUS_NULL,
            FX_STATUS_UNSPECIFIED,
            FX_STATUS_LOADING,
            FX_STATUS_IN_PROCESS,
            FX_STATUS_RUNNING,
            FX_STATUS_UNKNOWN_ERR,
            FX_STATUS_NO_MEM,
            FX_STATUS_NOT_FOUND,
            FX_STATUS_IO_ERROR,
            FX_STATUS_NO_FILE,
            FX_STATUS_EOF,
            FX_STATUS_BAD_ARGUMENTS,
            FX_STATUS_NOT_IMPLEMENTED,
            //
            FX_STATUS_TOTAL,
            FX_STATUS_MAX = FX_STATUS_TOTAL - 1,
            FX_STATUS_SUCCESS = FX_STATUS_OK
        };

        const char* get_status(status_code_t code);
        bool status_is_success(status_code_t code);
        bool status_is_error(status_code_t code);
    }

}

#endif
