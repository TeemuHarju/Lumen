#pragma once

#include "defines.h"

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

typedef struct vulkan_context
{
	VkInstance instance;
	VkAllocationCallbacks* allocator;
} vulkan_context;