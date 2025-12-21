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

#ifndef __FXUIDEFS__
#define __FXUIDEFS__

enum window_look_t
{
    FX_WF_DEFAUILT = 0,
    FX_WF_MODAL,
    FX_WF_BORDERLESS,
    FX_WF_FULLSCREEN
};

enum window_flags_t
{
    FX_WF_RESIZABLE,
    FX_WF_ZOOMABLE,
    FX_WF_CLOSABLE
};

enum ui_direction
{
    FX_VERTICAL,
    FX_HORIZONTAL
};

enum widget_abilities
{
    FX_HAVE_PLATFORM_EQUIVALENT
};

/**
 * Widget draw flags
 */
enum draw_flags_t
{
    DRAW_NONE           = 0,
    DRAW_SURFACE        = 1 << 0,
    DRAW_CHILD          = 1 << 1,

    DRAW_DEFAULT        = DRAW_SURFACE,
    DRAW_ALL            = DRAW_SURFACE | DRAW_CHILD
};

/**
 * Text adjusing modes
 **/
enum text_draw_case_t
{
    FX_TEXT_DRAW_NONE,                          //!< No text adjust
    FX_TEXT_DRAW_DEFAULT = FX_TEXT_DRAW_NONE,   //!< Default value (no text adjust)
    FX_TEXT_DRAW_TO_UPPER,                      //!< Convert to upper case
    FX_TEXT_DRAW_TO_LOWER                       //!< Convert to lower case
};

#endif
