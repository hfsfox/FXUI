add_executable(test_window
    test_window.cpp
    )

target_link_libraries(test_window PUBLIC
    ${CMAKE_PROJECT_NAME}
    )