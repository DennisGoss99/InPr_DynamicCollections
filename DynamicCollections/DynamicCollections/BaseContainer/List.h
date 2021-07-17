#ifndef ListInclude
#define ListInclude

#define EMPTYLIST (List){0}

#include "CollectionError.h"



typedef struct List_
{
	void** Content;
	unsigned int SizeOfSingleElement;
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
void ListInitialize(List* list, unsigned int count, unsigned int sizeOfSingleElement);

void ListDestruction(List* list);

/*
 * Function:  ListItemInsertAt
 * --------------------
 * adds parameter value to index in parameter list->Content
 * --------------------
 */
CollectionError ListItemInsertAt(List* list, unsigned int indexValue, void* value);

/*
 * Function:  ListItemGet
 * --------------------
 * adds parameter value to index in parameter list->Content
 * --------------------
 */
CollectionError ListItemGet(List* list, unsigned int index, void* element);

/*
 * Function:  ListItemAdd
 * --------------------
 * adds parameter value to next free value in parameter list->Content
 * --------------------
 *
 * When the List is full, it will be made bigger
 */
CollectionError ListItemAdd(List* list, void* value);

/*
 * Function:  ListItemRemove
 * --------------------
 * adds parameter value to index in parameter list->Content
 * --------------------
 */
CollectionError ListItemRemove(List* list, unsigned int index);

/*
 * Function:  ListClear
 * --------------------
 * sets all values in list->Content = 0
 * --------------------
 */
CollectionError ListClear(List* list);

//void ListPrint_string(List* list);
//
//void ListPrint_int(List* list);

#endif