#include "logger.h"
#include "asserts.h"
#include "platform/platform.h"

// TODO: temporary.
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void report_assertion_failure( const char* expression, const char* message, const char* file, i32 line )
{
	log_output( LOG_LEVEL_FATAL, "Assertion failed: %s,message: %s, in file: %s, line: %d", expression, message, file, line );
}

b8 initialize_logging()
{
	// TODO: create log file.
	return TRUE;
}

void shutdown_logging()
{
	// TODO: cleanup logging/write queued messages.
}

void log_output( log_level level, const char* message, ... )
{
	const char* level_strings[ 6 ] = {
		"[FATAL]: ",
		"[ERROR]: ",
		"[WARN]: ",
		"[INFO]: ",
		"[DEBUG]: ",
		"[TRACE]: "
	};
	b8 is_error = level < LOG_LEVEL_WARN;

	// Techinically imposes 32k character limit on log messages.
	const i32 msg_lenght = 32000;
	char out_message[ msg_lenght ];
	memset( out_message, 0, sizeof( out_message ) );

	// Format original message.
	// NOTE: Oddly enough, MS's headers override the GCC/Clang va_list type with a "typedef char* va_list" in some
	// cases, and as a result throws a strange error here. The workaround for now is to just use __builtin_va_list,
	// which is the type GCC/Clang's va_start expects.
	__builtin_va_list arg_ptr;
	va_start( arg_ptr, message );
	vsnprintf( out_message, msg_lenght, message, arg_ptr );
	va_end( arg_ptr );

	char out_message2[ msg_lenght ];
	sprintf( out_message2, "%s%s\n", level_strings[ level ], out_message );

	// Platform specific logging.
	if( is_error )
	{
		platform_console_write_error( out_message2, level );
	}
	else
	{
		platform_console_write( out_message2, level );
	}
}
