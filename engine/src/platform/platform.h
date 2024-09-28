#pragma once

#include "defines.h"

typedef struct platform_state
{
	void* internal_state;
} platform_state;

/**
 * @brief Initializes the platform layer.
 * 
 * This function initializes the platform layer, setting up any necessary components
 * for the platform to function.
 * 
 * @param plat_state A pointer to the platform state structure to initialize.
 * @param application_name The name of the application.
 * @param x The x position of the window.
 * @param y The y position of the window.
 * @param width The width of the window.
 * @param height The height of the window.
 * 
 * @return Returns a platform startup result code.
 */
b8 platform_startup( platform_state* plat_state, const char* application_name, i32 x, i32 y, i32 width, i32 height );

/**
 * @brief Shuts down the platform layer.
 * 
 * This function shuts down the platform layer, cleaning up any resources allocated
 * for the platform.
 * 
 * @param plat_state A pointer to the platform state structure to shut down.
 */
void platform_shutdown( platform_state* plat_state );

/**
 * @brief Processes messages for the platform.
 * 
 * This function processes messages for the platform, handling any input events
 * or other messages that need to be processed.
 * 
 * @param plat_state A pointer to the platform state structure to process messages for.
 * 
 * @return Returns a platform pump messages result code.
 */
b8 platform_pump_messages( platform_state* plat_state );

KAPI void* plarform_allocate( u64 size, b8 aligned );
KAPI void platform_free( void* block, b8 aligned );
void* platform_zero_memory( void* block, u64 size );
void* platform_copy_memory( void* dest, const void* source, u64 size );
void* platform_set_memory( void* dest, i32 value, u64 size );

void platform_console_write( const char* message, u8 color );
void platform_console_write_error( const char* message, u8 color );

/**
 * @brief Gets the absolute time in seconds.
 * 
 * @return Returns the absolute time in seconds.
 */
f64 platform_get_absolute_time();

/**
 * @brief Sleeps on the thread for the specified number of milliseconds.
 * 
 * @param ms The number of milliseconds to sleep.
 */
void platform_sleep( u64 ms );