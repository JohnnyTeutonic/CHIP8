# This is the CMakeLists.txt for the CHIP8 project, which will assist in building and compiling the project on all platforms.
cmake_minimum_required (VERSION 2.6)
project(CHIP8)

# To maintain a clean tree, set some useful variables so we're not building everything in root.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Here we will find all our 3rd party libraries which are dependencies.
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Add our own headers.
include_directories(${CMAKE_SOURCE_DIR}/src/renderer)

# Here we will include all our source files to be built to the executable (include all so they show in IDE).
add_executable(CHIP8 
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/renderer/renderer.h
    ${CMAKE_SOURCE_DIR}/src/renderer/renderer.cpp
)

# Here we will link those previously found libraries so we can use them.
target_link_libraries(CHIP8 OpenGL glfw)