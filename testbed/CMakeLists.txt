# Define the testbed executable
add_executable(testbed)

# Add source files
file(GLOB_RECURSE TESTBED_SRC src/*.c)

# Specify include directories
include_directories(src ../engine/src)

# Link the engine library
target_link_libraries(testbed PRIVATE engine)

# Specify the source files
target_sources(testbed PRIVATE ${TESTBED_SRC})

# Set compiler flags
target_compile_definitions(testbed PRIVATE _DEBUG KIMPORT)
target_compile_options(testbed PRIVATE -g)
