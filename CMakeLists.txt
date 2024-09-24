cmake_minimum_required(VERSION 3.30)
project(GameEngineProject)

# Set common compiler options
set(CMAKE_C_STANDARD 17)

# set output directories
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Include the engine and testbed directories
add_subdirectory(engine)
add_subdirectory(testbed)
