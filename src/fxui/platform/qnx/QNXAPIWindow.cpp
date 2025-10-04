#include <fxplatformuidefs.h>
#ifdef BACKEND_PHOTON
    #include <screen/screen.h>
    screen_context_t screen_context = 0;
    screen_window_t screen_window = 0;
    screen_display_t* screen_displays = 0;
    int display_count = 0;
#endif
