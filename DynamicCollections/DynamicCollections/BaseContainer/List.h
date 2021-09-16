#ifndef ListInclude
#define ListInclude

#define EMPTYLIST (List){0}

#include <stddef.h>

#include "CollectionError.h"


/*
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


// Acts like a constructor
// ! A list must be set to EMPTYLIST before each initialization
// eg: 'List a = EMPTYLIST;'
// @param list: Address of list object
// @param count: Count of initial storage locations
// @param sizeOfSingleElement: Size of used objects in bytes [sizeof(Type)]
void ListInitialize(List* list, unsigned int count, size_t sizeOfSingleElement);

void ListDestruction(List* list);

// Adds parameter value to index in parameter list->Content
// @param list: Address of list object
// @param indexValue: insert at this position
// @param value: That will be added
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
* returns: CollectionNoError
*	 CollectionEmpty
*	 CollectionArrayIndexOutOfBounds
*/
CollectionError ListItemInsertAt(List* list, unsigned int indexValue, void* value);

// Gets value at transmitted index and saves it in out
// @param list: Address of list object
// @param index: position of desired object
// @param out: contains the output
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
* returns: CollectionNoError
* CollectionEmpty
* CollectionArrayIndexOutOfBounds
*/
CollectionError ListItemGet(List* list, unsigned int index, void* out);

// Adds parameter value to next free value in parameter list->Content
// @param list: Address of list object
// @param value: will be saved in list
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
* returns: CollectionNoError
*	 CollectionEmpty
*	 CollectionOutOfMemory
*/
CollectionError ListItemAdd(List* list, void* value);

// Removes Element at index
// @param list: Address of list object
// @param index: position of the object that will be removed
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
* returns: CollectionNoError
*	 CollectionEmpty
*	 CollectionArrayIndexOutOfBounds
*/
CollectionError ListItemRemove(List* list, unsigned int index);

// Sets all values in list->Content to NULL
// @param list: Address of list object
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 */
CollectionError ListClear(List* list);

#endif