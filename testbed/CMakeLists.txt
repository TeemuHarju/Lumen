# Set testbed as an executable
add_executable(testbed)

# Set compile definitions
target_compile_definitions(testbed PRIVATE -DKIMPORT)

# Link against the engine library
target_link_libraries(testbed PRIVATE engine)

# Add sources to the executable
target_sources(testbed
	PRIVATE
	src/entry.c
	src/game.c
	src/game.h
)
