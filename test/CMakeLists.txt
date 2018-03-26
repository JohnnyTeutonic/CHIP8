PROJECT(CHIP8TESTS)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ./includes/)

add_executable(TESTS 
    ./src/tests.cpp
)
target_link_libraries(TESTS
    Catch
)

enable_testing()
add_test(NAME RunTests COMMAND tests)