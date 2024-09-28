#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

#if KRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level {
	LOG_LEVEL_FATAL = 0,
	LOG_LEVEL_ERROR = 1,
	LOG_LEVEL_WARN = 2,
	LOG_LEVEL_INFO = 3,
	LOG_LEVEL_DEBUG = 4,
	LOG_LEVEL_TRACE = 5,
} log_level;

/**
 * @brief Initializes the logging system.
 * 
 * This function sets up the necessary components for the logging system to function.
 * It should be called before any logging operations are performed.
 * 
 * @return Returns true (b8) if the logging system was successfully initialized, false otherwise.
 */
b8 initialize_logging();


/**
 * @brief Shuts down the logging system.
 *
 * This function is responsible for properly shutting down the logging system,
 * ensuring that all log messages are flushed and any resources allocated for
 * logging are released.
 */
void shutdown_logging();

KAPI void log_output(log_level level, const char* message, ...);

// Logs fatal level messages.
#define KFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__)

#ifndef KERROR
// Logs error level messages.
#define KERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__)
#endif

#if LOG_WARN_ENABLED == 1
// Logs warning level messages.
#define KWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__)
#else
// Does nothing if warning level logging is disabled.
#define KWARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
// Logs info level messages.
#define KINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__)
#else
// Does nothing if info level logging is disabled.
#define KINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// Logs debug level messages.
#define KDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__)
#else
// Does nothing if debug level logging is disabled.
#define KDEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// Logs trace level messages.
#define KTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__)
#else
// Does nothing if trace level logging is disabled.
#define KTRACE(message, ...)
#endif