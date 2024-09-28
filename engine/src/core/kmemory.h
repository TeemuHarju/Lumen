#pragma once

#include "defines.h"

typedef enum memory_tag
{
	// For temporary use. Should be assigned one of the below or have a new tag created.
	MEMORY_TAG_UNKNOWN,
	MEMORY_TAG_ARRAY,
	MEMORY_TAG_DARRAY,
	MEMORY_TAG_DICT,
	MEMORY_TAG_RING_QUEUE,
	MEMORY_TAG_BST,
	MEMORY_TAG_STRING,
	MEMORY_TAG_APPLICATION,
	MEMORY_TAG_JOB,
	MEMORY_TAG_TEXTURE,
	MEMORY_TAG_MATERIAL_INSTANCE,
	MEMORY_TAG_RENDERER,
	MEMORY_TAG_GAME,
	MEMORY_TAG_TRANSFORM,
	MEMORY_TAG_ENTITY,
	MEMORY_TAG_ENTITY_NODE,
	MEMORY_TAG_SCENE,
	MEMORY_TAG_MAX_TAGS
} memory_tag;

/**
 * @brief Initializes the memory subsystem.
 */
KAPI void initialize_memory();

/**
 * @brief Shuts down the memory subsystem.
 */
KAPI void shutdown_memory();

/**
 * @brief Allocates a block of memory.
 * 
 * @param size The size of the memory block to allocate.
 * @param tag The memory tag to associate with the allocation.
 * @return A pointer to the allocated memory block.
 */
KAPI void* kallocate( u64 size, memory_tag tag );

/**
 * @brief Frees a previously allocated block of memory.
 * 
 * @param block A pointer to the memory block to free.
 * @param size The size of the memory block to free.
 * @param tag The memory tag associated with the allocation.
 */
KAPI void kfree( void* block, u64 size, memory_tag tag );

/**
 * @brief Sets a block of memory to zero.
 * 
 * @param block A pointer to the memory block to set to zero.
 * @param size The size of the memory block to set to zero.
 * @return A pointer to the memory block.
 */
KAPI void* kzero_memory( void* block, u64 size );

/**
 * @brief Copies a block of memory from source to destination.
 * 
 * @param dest A pointer to the destination memory block.
 * @param source A pointer to the source memory block.
 * @param size The size of the memory block to copy.
 * @return A pointer to the destination memory block.
 */
KAPI void* kcopy_memory( void* dest, const void* source, u64 size );

/**
 * @brief Sets a block of memory to a specified value.
 * 
 * @param dest A pointer to the memory block to set.
 * @param value The value to set the memory block to.
 * @param size The size of the memory block to set.
 * @return A pointer to the memory block.
 */
KAPI void* kset_memory( void* dest, i32 value, u64 size );

/**
 * @brief Gets a string representation of the current memory usage.
 * 
 * @return A string representing the current memory usage.
 */
KAPI char* get_memory_usage_str();