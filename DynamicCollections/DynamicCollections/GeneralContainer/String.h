#ifndef StringInclude
#define StringInclude

#include "../BaseContainer/List.h"

#define EMPTYSTRING (String){0}

typedef struct String_
{
	struct List_ list;
	unsigned int Count;
}String;

/*
 * Function:  PathListInitialize
 * --------------------
 * Acts like a constructor
 * ! A list must be set to EMPTYLIST before each initialization
 * eg: 'List a = EMPTYLIST;'
 * --------------------
 */
void StringInitialize(String* string, char* inputString);

void StringDestruction(String* string);

/*
 * Function:  PathListItemInsertAt
 * --------------------
 * adds parameter value to index in parameter list->content
 * --------------------
 *  returns: 0 if successful
 *	  -1 List is NULL
 *	  -2 Out of bounds
 */
CollectionError StringCharInsertAt(String* string, unsigned int indexValue, char value);

/*
 * Function:  PathListItemGet
 * --------------------
 * adds parameter value to index in parameter list->content
 * --------------------
 *  returns: Value if successful
 *	  NULL List is NULL
 *	  NULL Out of bounds
 */
CollectionError StringCharGet(String* string, unsigned int index, char* out);

/*
 * Function:  PathListItemAdd
 * --------------------
 * adds parameter value to next free value in parameter list->content
 * --------------------
 *
 * When the List is full, it will be made bigger
 *
 *  returns: 0 if successful
 *	  -1 List is NULL
 *	  -2 Out of bounds
 *	  -9 Calloc failed
 */
CollectionError StringCharAdd(String* string, char addChar);

/*
 * Function:  PathListItemAdd
 * --------------------
 * adds parameter value to next free value in parameter list->content
 * --------------------
 *
 * When the List is full, it will be made bigger
 *
 *  returns: 0 if successful
 *	  -1 List is NULL
 *	  -2 Out of bounds
 *	  -9 Calloc failed
 */
CollectionError StringConcat(String* string, char* addString);

/*
 * Function:  PathListItemAdd
 * --------------------
 * adds parameter value to next free value in parameter list->content
 * --------------------
 *
 * When the List is full, it will be made bigger
 *
 *  returns: 0 if successful
 *	  -1 List is NULL
 *	  -2 Out of bounds
 *	  -9 Calloc failed
 */
CollectionError StringGetFullString(String* string, char** out);

#endif