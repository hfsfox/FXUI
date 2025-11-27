add_executable(test_window
    test_window.cpp
    ${FXUI_SOURCES}
    ${PLATFORM_SOURCES}
    )

if(LINUX)
    if (BACKEND_X11)
    target_link_libraries(test_window PUBLIC ${X11_LIBRARIES} ${X11_Xpm_LIB} ${OPENGL_LIBRARIES} Xft ${FREETYPE_LIBRARIES})
    endif()
    if (BACKEND_WAYLAND)
        target_link_libraries(test_window PUBLIC 
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
    target_link_libraries(test_window PUBLIC 
     user32 
     gdi32 
     opengl32 
     ${DWMAPI_LIBS}
     )
elseif(HAIKU)
   target_link_libraries(test_window PUBLIC
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
