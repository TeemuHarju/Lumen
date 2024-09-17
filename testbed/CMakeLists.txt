# testbed/CMakeLists.txt

# Set testbed as an executable
add_executable(testbed)

# Specify the source files for the testbed
file(GLOB_RECURSE TESTBED_SOURCES src/*.c)

# Include the engine directory and other dependencies
include_directories(src ../engine/src)

# Set compile definitions
target_compile_definitions(testbed PRIVATE -DKIMPORT)

# Specify the build output
set_target_properties(testbed PROPERTIES
    OUTPUT_NAME "testbed"
    RUNTIME_OUTPUT_DIRECTORY ../bin
)

# Link against the engine library
target_link_libraries(testbed PRIVATE engine)

# Add sources to the executable
target_sources(testbed PRIVATE ${TESTBED_SOURCES})
