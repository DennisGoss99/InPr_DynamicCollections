#ifndef ListInclude
#define ListInclude

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
void ListInitialize(List* list, unsigned int count, unsigned int sizeOfObject);

void ListDestruction(List* path);

/*
 * Function:  ListItemInsertAt
 * --------------------
 * adds parameter value to index in parameter list->Content
 * --------------------
 *  returns: 0 if successful
 *	  -1 List is NULL
 *	  -2 Out of bounds
 */
int ListItemInsertAt(List* list, unsigned int indexValue, void* value);

/*
 * Function:  ListItemGet
 * --------------------
 * adds parameter value to index in parameter list->Content
 * --------------------
 *  returns: Value if successful
 *	  NULL List is NULL
 *	  NULL Out of bounds
 */
void* ListItemGet(List* list, unsigned int index);

/*
 * Function:  ListItemAdd
 * --------------------
 * adds parameter value to next free value in parameter list->Content
 * --------------------
 *
 * When the List is full, it will be made bigger
 *
 *  returns: 0 if successful
 *	  -1 List is NULL
 *	  -2 Out of bounds
 *	  -9 Calloc failed
 */
int ListItemAdd(List* list, void* value);

/*
 * Function:  ListItemRemove
 * --------------------
 * adds parameter value to index in parameter list->Content
 * --------------------
 *  returns: 0 if successful
 *     1 Removed Value already NULL
 *	  -1 List is NULL
 *	  -2 Out of bounds
 */
int ListItemRemove(List* list, unsigned int index);

/*
 * Function:  ListClear
 * --------------------
 * sets all values in list->Content = 0
 * --------------------
 *  returns: 0 if successful
 *	  -1 List is NULL
 */
int ListClear(List* list);

void ListPrint_string(List* list);

void ListPrint_int(List* list);

#endif