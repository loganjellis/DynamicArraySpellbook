#pragma once

#include <stdlib.h>
#include <string.h>

/**
  Initializes the given dynamic array.
  Note that this macro expects a pointer to the dynamic array.

  The given dynamic array must have at least
  3 fields:

  - A pointer representing the array, called 'data.'
  - A size_t called 'size.' This is the array's current size.
  - A size_t called 'capacity.' This is the max size of the array.

  When an array dynamic array is initialized, its size is 0, its capacity
  starts out at 10, and its data is automatically allocated for you.

  @important Make sure you call daspllbk_free(&dynamic array) when you are
  ready to free the dynamic array's memory.
*/
#define daspllbk_init(dynamic_array) \
	do { \
		(dynamic_array) -> size = 0; \
		(dynamic_array) -> capacity = 10; \
		(dynamic_array) -> data = calloc((dynamic_array) -> capacity * sizeof(*(dynamic_array) -> data), sizeof(*(dynamic_array) -> data)); \
	} while(0)

/**
  Frees a dynamic array's data.

  This macro expects a pointer to the dynamic array.
*/
#define daspllbk_free(dynamic_array) \
	do { \
		(dynamic_array) -> size = 0; \
		(dynamic_array) -> capacity = 10; \
		free((dynamic_array) -> data); \
		(dynamic_array) -> data = NULL; \
	} while(0)

/**
  Obtains an item at a given index in a dynamic array.

  This macro expects a pointer to the dynamic array.

  Make sure the index is valid before
  calling this macro, as it does not validate the index.
*/
#define daspllbk_get(dynamic_array, idx) *((dynamic_array) -> data + (idx))

/**
  If the given dynamic array needs to expand, this macro
  will do so by doubling its capacity.
*/
#define daspllbk_expand(dynamic_array) \
	do { \
		if((dynamic_array) -> size >= (dynamic_array) -> capacity) \
		{ \
			if((dynamic_array) -> capacity * 2 <= SIZE_MAX) \
			{ \
				(dynamic_array) -> capacity *= 2; \
				(dynamic_array) -> data = realloc((dynamic_array) -> data, (dynamic_array) -> capacity * sizeof(*(dynamic_array) -> data)); \
			} \
		} \
	} while(0)

/**
  Adds an item to a dynamic array.

  This macro expects a pointer to the dynamic array.

  @note The dynamic array will auto-expand if necessary.
*/
#define daspllbk_add(dynamic_array, item) \
	do { \
		daspllbk_expand(dynamic_array); \
		(dynamic_array) -> data[(dynamic_array) -> size] = (item); \
		(dynamic_array) -> size++; \
	} while(0)

/**
  Inserts an item into a dynamic array at a given index.
  In other words, after insertion, the item
  will be at the exact index given.

  This macro expects a pointer to the dynamic array.

  @note You can use this macro to append a value
  to the array if the given index is equal
  to the size of the array.

  @important The order of arguments should be:
  dynamic_array, index, item.
*/
#define daspllbk_insert(dynamic_array, idx, item) \
	do { \
		daspllbk_expand(dynamic_array); \
		memmove((dynamic_array) -> data + (idx) + 1, (dynamic_array) -> data + (idx), ((dynamic_array) -> size - (idx)) * sizeof(*(dynamic_array) -> data)); \
		(dynamic_array) -> data[(idx)] = (item); \
		(dynamic_array) -> size++; \
	} while(0)

/**
  Sets a specific item at a specific index in a dynamic array.

  This macro expects a pointer to the dynamic array.

  @important The order of arguments should be:
  dynamic_array, index, item.
*/
#define daspllbk_set(dynamic_array, idx, item) \
	do { \
		(dynamic_array) -> data[(idx)] = (item); \
	} while(0)

/**
  Removes an item from a dynamic array at a given index.

  This macro expects a pointer to the dynamic array.
*/
#define daspllbk_remove(dynamic_array, idx) \
	do { \
		memmove((dynamic_array) -> data + (idx), (dynamic_array) -> data + (idx) + 1, ((dynamic_array) -> size - (idx) - 1) * sizeof(*(dynamic_array) -> data)); \
		(dynamic_array) -> size--; \
	} while(0)

#ifdef _WIN32
	#ifdef DASPLLBK_EXPORTS
		#define DASPLLBK_API __declspec(dllexport)
	#else
		#define DASPLLBK_API __declspec(dllimport)
	#endif
#else
	#define DASPLLBK_API
#endif
