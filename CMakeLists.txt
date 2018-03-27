# Unfortunately, GLFW is not CYGWIN aware - so we'll set a legacy flag. As such, WIN32 will now be defined.
# This means we can't upgrade CMAKE minimum version past 2.8.3 until/unless GLFW is updated to be CYGWIN aware.
cmake_minimum_required(VERSION 3.9.1)
set(CMAKE_LEGACY_CYGWIN_WIN32 1)
set (CMAKE_CXX_STANDARD 11) # Set C++11
project(CHIP8)

# To maintain a clean tree, set some useful variables so we're not building everything in root.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # static library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # dynamic library
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # executables

# Include the GLFW source, and set some flags, which will instruct cmake to perform instructions as per its CMakeLists.txt (and our custom flags).
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation")
add_subdirectory(${CMAKE_SOURCE_DIR}/dep/GLFW)
include_directories(${CMAKE_SOURCE_DIR}/dep/GLFW/include)

# Add our test directory
add_subdirectory (test)

# Include all other libraries.
find_package(OpenGL REQUIRED)

# Add our own source code directories.
include_directories(${CMAKE_SOURCE_DIR}/src/game)
include_directories(${CMAKE_SOURCE_DIR}/src/chipeight)

# Here we will include all our source files to be built to the executable (include all so they show in IDE).
add_executable(CHIP8 
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/game/game.h
    ${CMAKE_SOURCE_DIR}/src/game/game.cpp
    ${CMAKE_SOURCE_DIR}/src/chipeight/chipeight.h
    ${CMAKE_SOURCE_DIR}/src/chipeight/chipeight.cpp
)

# Here we will link those previously found libraries so we can use them.
target_link_libraries(CHIP8 
    ${OPENGL_LIBRARIES} 
    glfw 
    ${GLFW_LIBRARIES}
)

# Some libraries need to be specifically linked if we're running Windows.
if (WIN32)
    target_link_libraries(CHIP8 
        gdi32
    )
endif (WIN32)