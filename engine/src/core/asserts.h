#pragma once

#include "defines.h"

// Disable assertions in release builds.
#define KASSERTIONS_ENABLED 1

#ifdef KASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debug_break() __debugbreak()
#else
#define debug_break() __builtin_trap()
#endif


/**
 * @brief Reports an assertion failure.
 *
 * This function is called when an assertion fails. It logs the details of the 
 * failed assertion including the expression that failed, an optional message, 
 * the file in which the assertion failed, and the line number.
 *
 * @param expression The expression that failed.
 * @param message An optional message providing additional information about the failure.
 * @param file The file in which the assertion failed.
 * @param line The line number at which the assertion failed.
 */
KAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define KASSERT(expression) 												\
	{																		\
		if (expression) {													\
		} else {															\
			report_assertion_failure(#expression, "", __FILE__, __LINE__);	\
			debug_break();													\
		}																	\
	}																		

#define KASSERT_MSG(expression, message)						\
	{																			\
		if (expression) {														\
		} else {																\
			report_assertion_failure(#expression, message, __FILE__, __LINE__);	\
			debug_break();														\
		}																		\
	}

#ifdef _DEBUG
#define KASSERT_DEBUG(expression)											\
	{																		\
		if (expression) {													\
		} else {															\
			report_assertion_failure(#expression, "", __FILE__, __LINE__);	\
			debug_break();													\
		}																	\
	}
#else
#define KASSERT_DEBUG(expression)
#endif

#else
#define KASSERT(expression)
#define KASSERT_MSG(expression, message)
#define KASSERT_DEBUG(expression)
#endif