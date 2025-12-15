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

#include <cstdint>

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
            FXApplication();
            /**
             * Initialize application constructor
             * @param vendor_descriptor vendor descriptor
             * for identifying application for platform mechanisms
             **/
            FXApplication(const char* vendor_descriptor);
            /**
             * Initialize application constructor
             * @param argc number of additional arguments
             * @param argv array of additional arguments
             **/
            FXApplication(int argc, char** argv);
            /**
             * Initialize application constructor
             * @param argc number of additional arguments
             * @param argv array of additional arguments
             * @param vendor_descriptor vendor descriptor
             * for identifying application for platform mechanisms
             **/
            FXApplication(int argc, char** argv, 
                const char* vendor_descriptor);
            ~FXApplication();
        public:
            /**
             * Run application instance
             * @return result of run main loop
             **/
            uint32_t Run();
            /**
             * Get executable file location
             * @return string literal with path
             **/
            const char* GetAppLocation();
            /**
             * Get application version
             * @return string literal with version
             **/
            const char* GetAppVersion();
        private:
            void _Init(int argc, char** argv,
                const char* vendor_descripto);
        private:
            int argc_state;
            char** argv_state;
    };
}

extern FX::FXApplication* fxapp;

#endif
