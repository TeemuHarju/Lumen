# Set engine as a shared library
add_library(engine SHARED)

# Find the Vulkan package
find_package(Vulkan REQUIRED)

# Add sources to the library
target_sources(engine
	PRIVATE
	src/defines.h
	src/core/logger.c
	src/core/logger.h
	src/core/asserts.h
	src/platform/platform.h
	src/platform/platform_win32.c
)

# Include Vulkan headers
target_include_directories(engine
	PRIVATE
	${Vulkan_INCLUDE_DIRS}
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/src>
)

# Set compile definitions
target_compile_definitions(engine PRIVATE -DKEXPORT)

# Link against Vulkan and other necessary libraries
target_link_libraries(engine PRIVATE Vulkan::Vulkan user32)
