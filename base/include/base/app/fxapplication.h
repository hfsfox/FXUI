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

#ifndef     __FXAPPLICATION__
#define     __FXAPPLICATION__

#include <base/stdlib/fxdebug.h>
#include <base/stdlib/fxstatuscode.h>
#include <support/fxeventhandler.h>
#include <stdint.h>

#include <base/app/fxappexport.h>

/**
 * Main App interface
 * Abstraction for do platform init if platform need some special things for
 * work with GUI/System
 **/

namespace FX
{
    class FXApplication
    {
        public:
            /**
             * Initialize application constructor
             * @param argc number of additional arguments
             * @param argv array of additional arguments
             * @param vendor_descriptor vendor descriptor
             * for identifying application for platform mechanisms
             **/
            FXApplication(int argc = 0, char** argv = NULL,
                          const char* vendor_descriptor = "");
            virtual ~FXApplication();
        public:
            virtual status_code_t Init();
            /**
             * Run application instance
             * @return status code of end run main loop
             **/
            virtual status_code_t Run();
            /**
             * Get executable file location
             * @return string literal with path
             **/
            virtual const char* GetAppLocation();
            /**
             * Get application version
             * @return string literal with version
             **/
            virtual const char* GetAppVersion();
            virtual status_code_t SetHandler(FX::FXEventHandler* handler);
        private:
            int argc_state;
            char** argv_state;
            const char* vendor_descriptor_state;
        private:
            status_code_t status_state;
        protected:
            FX::FXEventHandler* _app_event_handler;
    };
}

#endif      //__FXAPPLICATION__
