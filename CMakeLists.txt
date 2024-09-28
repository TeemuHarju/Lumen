cmake_minimum_required(VERSION 3.25)
project(LumenGameEngine)

# Set common compiler options
set(CMAKE_C_STANDARD 17)

# Set output directories for libraries and executables
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set the compile commands to be exported.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include the engine and testbed directories
add_subdirectory(engine)
add_subdirectory(testbed)
