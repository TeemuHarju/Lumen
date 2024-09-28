# Set engine as a shared library
add_library(engine SHARED)

# Find the Vulkan package
find_package(Vulkan REQUIRED)

# Define platform-specific sources
if(WIN32)
	set(PLATFORM_SOURCES
		src/platform/platform_win32.c
	)
elseif(UNIX)
	set(PLATFORM_SOURCES
		src/platform/platform_linux.c
	)
endif()

# Add sources to the library
target_sources(engine
	PRIVATE
	src/defines.h
	src/core/logger.c
	src/core/logger.h
	src/core/asserts.h
	${PLATFORM_SOURCES} # Include platform-specific sources
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
target_link_libraries(engine
	PRIVATE Vulkan::Vulkan
	$<$<PLATFORM_ID:Windows>:user32>
	$<$<PLATFORM_ID:Linux>:xcb X11 X11-xcb xkbcommon>
)
