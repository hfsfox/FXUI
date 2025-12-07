add_executable(test_app
    test_app.cpp
    )

target_link_libraries(test_app PUBLIC
    ${CMAKE_PROJECT_NAME}
    )