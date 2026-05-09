#tests

#app class
add_executable(${CMAKE_PROJECT_NAME}_test_app
    src/test/app/main.cpp
    )

target_link_libraries(${CMAKE_PROJECT_NAME}_test_app PUBLIC
    ${CMAKE_PROJECT_NAME}
    )

# atomic ops
add_executable(${CMAKE_PROJECT_NAME}_test_atomic
    src/test/base/memory/atomic.cpp
    )

target_link_libraries(${CMAKE_PROJECT_NAME}_test_atomic PUBLIC
    ${CMAKE_PROJECT_NAME}
    )

#threading
add_executable(${CMAKE_PROJECT_NAME}_test_thread
    src/test/threading/thread.cpp
    )

target_link_libraries(${CMAKE_PROJECT_NAME}_test_thread PUBLIC
    ${CMAKE_PROJECT_NAME}
    )

#shared memory
