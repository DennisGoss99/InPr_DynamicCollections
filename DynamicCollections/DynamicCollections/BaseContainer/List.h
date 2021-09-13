#ifndef ListInclude
#define ListInclude

#define EMPTYLIST (List){0}

#include <stddef.h>

#include "CollectionError.h"


/*
 * List:
 * --------------------
 * Content
 * SizeOfSingleElement
 * Size: Number of all storage locations
 */
typedef struct List_
{
	void** Content;
	size_t SizeOfSingleElement;
	unsigned int Size;
}List;

/*
 * Function:  ListInitialize
 * --------------------
 * Acts like a constructor
 * ! A list must be set to EMPTYLIST before each initialization
 * eg: 'List a = EMPTYLIST;'
 * --------------------
 */
void ListInitialize(List* list, unsigned int count, size_t sizeOfSingleElement);

void ListDestruction(List* list);

/*
 * Function:  ListItemInsertAt
 * --------------------
 * Adds parameter value to index in parameter list->Content
 * --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionArrayIndexOutOfBounds
 */
CollectionError ListItemInsertAt(List* list, unsigned int indexValue, void* value);

/*
 * Function:  ListItemGet
 * --------------------
 * Get value at transmitted index and saves it in out
 * --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionArrayIndexOutOfBounds
 */
CollectionError ListItemGet(List* list, unsigned int index, void* out);

/*
 * Function:  ListItemAdd
 * --------------------
 * Adds parameter value to next free value in parameter list->Content
 *
 * When the List is full, it will be made bigger
 * --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionOutOfMemory
 */
CollectionError ListItemAdd(List* list, void* value);

/*
 * Function:  ListItemRemove
 * --------------------
 * Removes Element at index
 * --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionArrayIndexOutOfBounds
 */
CollectionError ListItemRemove(List* list, unsigned int index);

/*
 * Function:  ListClear
 * --------------------
 * Sets all values in list->Content = 0
 * --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 */
CollectionError ListClear(List* list);

#endif