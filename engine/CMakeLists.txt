# Define the engine library
add_library(engine SHARED)

# Add source files
file(GLOB_RECURSE ENGINE_SRC src/*.c)

find_package(Vulkan REQUIRED)

# Specify include directories
include_directories(${Vulkan_INCLUDE_DIRS})

# Specify the source files
target_sources(engine PRIVATE ${ENGINE_SRC})

# Set compiler flags
target_compile_definitions(engine PRIVATE _DEBUG KEXPORT _CRT_SECURE_NO_WARNINGS -DBUILDING_DLL)
target_compile_options(engine PRIVATE -g -Wall -Werror)
target_link_libraries(engine PRIVATE ${Vulkan_LIBRARIES} user32)
