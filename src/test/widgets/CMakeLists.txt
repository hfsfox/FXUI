add_executable(test_menubar
    test_menubar.cpp
    )

if(LINUX)
    if (BACKEND_X11)
    target_link_libraries(test_menubar PUBLIC 
    ${CMAKE_PROJECT_NAME}
    )
    endif()
    if (BACKEND_WAYLAND)
        target_link_libraries(test_menubar PUBLIC 
        ${CMAKE_PROJECT_NAME}
        )
    endif()
 elseif(WIN32)
    target_link_libraries(test_menubar PUBLIC 
    ${CMAKE_PROJECT_NAME} 
     )
elseif(HAIKU)
   target_link_libraries(test_menubar PUBLIC
    ${CMAKE_PROJECT_NAME}
    )
endif()

