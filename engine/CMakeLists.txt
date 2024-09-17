# engine/CMakeLists.txt

# Set engine as a shared library
add_library(engine SHARED)

# Specify the source files for the engine
file(GLOB_RECURSE ENGINE_SOURCES src/*.c)

# Find the Vulkan package
find_package(Vulkan REQUIRED)

# Include Vulkan headers
include_directories(${Vulkan_INCLUDE_DIRS})

# Set compile definitions
target_compile_definitions(engine PRIVATE -DKEXPORT -D_CRT_SECURE_NO_WARNINGS -DBUILDING_DLL)

# Specify the build output
set_target_properties(engine PROPERTIES
    OUTPUT_NAME "engine"
    RUNTIME_OUTPUT_DIRECTORY ../bin
)

# Link against Vulkan and other necessary libraries
target_link_libraries(engine PRIVATE Vulkan::Vulkan user32)

# Add sources to the library
target_sources(engine PRIVATE ${ENGINE_SOURCES})
