#pragma once

#include "defines.h"

struct game;

// Application configuration.
typedef struct application_config
{
	// Windows starting position x axis, if applicable.
	i16 start_pos_x;

	// Windows starting position y axis, if applicable.
	i16 start_pos_y;

	// Windows width, if applicable.
	i16 start_width;

	// Windows height, if applicable.
	i16 start_height;

	// The application name used in windowing, if applicable.
	const char* name;
} application_config;

/**
 * @brief Create the application.
 * 
 * @return True if the application was created successfully, false otherwise.
 */
KAPI b8 application_create( struct game* game_inst );

/**
 * @brief Run the application.
 * 
 * @return True if the application ran successfully.
 */
KAPI b8 application_run();