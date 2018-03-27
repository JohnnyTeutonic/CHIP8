cmake_minimum_required(VERSION 3.9.1)
set (CMAKE_CXX_STANDARD 11) # Set C++11
set(CMAKE_LEGACY_CYGWIN_WIN32 1)

PROJECT(CHIP8TESTS)

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tests.cpp
)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests Catch)

# enable_testing()
# add_test(NAME RunTests COMMAND tests)