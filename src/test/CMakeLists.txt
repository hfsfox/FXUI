# tests

add_executable(${CMAKE_PROJECT_NAME}_example
    example.cpp
    )

add_executable(${CMAKE_PROJECT_NAME}_init_dpy
    #WIN32
    example_init_dpy.cpp
    )

add_executable(${CMAKE_PROJECT_NAME}_init_messagebox
    example_init_messagebox.cpp
    )

add_executable(test_create_window
    test_create_window.cpp
    )

target_link_libraries(${CMAKE_PROJECT_NAME}_example PUBLIC
    ${CMAKE_PROJECT_NAME} 
    )
target_link_libraries(${CMAKE_PROJECT_NAME}_init_dpy PUBLIC
    ${CMAKE_PROJECT_NAME}
    )
target_link_libraries(${CMAKE_PROJECT_NAME}_init_messagebox PUBLIC
    ${CMAKE_PROJECT_NAME}
    )
target_link_libraries( test_create_window PUBLIC
    ${CMAKE_PROJECT_NAME}
    )

add_subdirectory(app)
add_subdirectory(window)
add_subdirectory(widgets)