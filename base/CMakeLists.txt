include_directories(${CMAKE_PROJECT_NAME}_base PUBLIC
    base/include
    )

set(FX_UI_BASE_SOURCES
    src/base/fxapplication.cpp
    )

add_library(${CMAKE_PROJECT_NAME}_base STATIC
    ${FX_UI_BASE_SOURCES}
    #${PLATFORM_SOURCES}
    )



if(LINUX)
    if (BACKEND_X11)
        target_link_libraries(${CMAKE_PROJECT_NAME}_base PUBLIC
        ${X11_LIBRARIES}
        ${X11_Xpm_LIB}
        ${OPENGL_LIBRARIES}
        Xft
        ${FREETYPE_LIBRARIES}
        )
    endif()
    if (BACKEND_WAYLAND)
        target_link_libraries(${CMAKE_PROJECT_NAME}_base PUBLIC
        wayland-client
        wayland-cursor
        Xpm
        GL
        GLU
        ${FREETYPE_LIBRARIES}
        )
    endif()
 elseif(WIN32)
    set(DWMAPI_LIBS
    dwmapi
    uxtheme
    )
    target_link_libraries(${CMAKE_PROJECT_NAME}_base PUBLIC
     user32
     gdi32
     opengl32
     ${DWMAPI_LIBS}
     )
elseif(HAIKU)
   target_link_libraries(${CMAKE_PROJECT_NAME}_base PUBLIC
    #${CMAKE_PROJECT_NAME}
    be
    root
    game
    tracker
    textencoding
    GL
    stdc++
    supc++
    )
endif()
