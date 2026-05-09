add_executable(${CMAKE_PROJECT_NAME}_test_color
    src/test/support/color_test.cpp
    )

target_link_libraries(${CMAKE_PROJECT_NAME}_test_color PUBLIC
    ${CMAKE_PROJECT_NAME}
    )
