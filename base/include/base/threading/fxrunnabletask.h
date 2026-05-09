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

#ifndef     __FXRUNNABLETASK_H__
#define     __FXRUNNABLETASK_H__

#include <base/stdlib/fxstatuscode.h>

namespace FX
{
    class FXRunnableTask
    {
        public:
            explicit FXRunnableTask()
            {
            };

            virtual ~FXRunnableTask()
            {
            };

            virtual status_code_t Run()
            {
                return fx::status::FX_STATUS_OK;
            };
        private:
            // Deny copying
            FXRunnableTask & operator = (const FXRunnableTask &source_task);
    };
}

#endif //__FXRUNNABLETASK_H__
