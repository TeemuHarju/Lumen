cmake_minimum_required(VERSION 3.15)
project(GameEngineProject)

# Set common compiler options
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Create options for debug and release
set(CMAKE_C_FLAGS_DEBUG "-D_DEBUG -g")
set(CMAKE_C_FLAGS_RELEASE "-O3")

# Include the engine and testbed directories
add_subdirectory(engine)
add_subdirectory(testbed)
