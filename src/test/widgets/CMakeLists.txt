add_executable(test_menubar
    test_menubar.cpp
    )

target_link_libraries(test_menubar PUBLIC
    ${CMAKE_PROJECT_NAME}
    )