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

#ifndef __FXSYSTEMENV_H__
#define __FXSYSTEMENV_H__

//#include <fxstatuscode.h>
#include <base/stdlib/fxstatuscode.h>

namespace fx
{
    namespace systemenv
    {
        /**
         * Get environment variable
         * @param name environment variable name
         * @param dst string to store environment variable value, NULL for
         *  check-only
         * @return status of operation or STATUS_NOT_FOUND if there is no
         *  environment variable
         */
        //status_t get_env_var(const FXString *name, FXString *dst);
        /**
         * Get environment variable
         * @param name environment variable name in UTF-8
         * @param dst string to store environment variable value, NULL for
         *  check-only
         * @return status of operation or STATUS_NOT_FOUND if there is no
         *  environment variable
         */
        status_code_t get_env_var(const char* name, /*FXString*/ const char* dst)
        {
            return fx::FX_STATUS_NOT_IMPLEMENTED;
        };
    }
}

#endif
