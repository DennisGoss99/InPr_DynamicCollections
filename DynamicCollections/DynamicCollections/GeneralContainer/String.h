#ifndef StringInclude
#define StringInclude

#include "../BaseContainer/List.h"

#define EMPTYSTRING (String){0}

/*
 * List : inner element (contains char´s)
 * Count: contains number of chars
 */
typedef struct String_
{
	struct List_ List;
	unsigned int Count;
}String;

// Acts like a constructor
// ! A string must be set to EMPTYSTRING before each initialization
// eg: 'String a = EMPTYSTRING;'
// @param string: Address of string object
// @param inputString: Initial string
void StringInitialize(String* string, char* inputString);

void StringDestruction(String* string);

// Puts char at index position
// @param string: Address of string object
// @param indexValue: insert char at this position
// @param value: Char that will be added
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
* returns: CollectionNoError
*	 CollectionEmpty
*	 CollectionArrayIndexOutOfBounds
*/
CollectionError StringCharInsertAt(String* string, unsigned int indexValue, char value);

// Gets char at transmitted index and saves it in out
// @param string: Address of string object
// @param index: position of desired char
// @param out: contains the output
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
* returns: CollectionNoError
* CollectionEmpty
* CollectionArrayIndexOutOfBounds
*/
CollectionError StringCharGet(String* string, unsigned int index, char* out);

// Adds char to the end of string
// When the string is full, it will be made bigger
// @param string: Address of string object
// @param addChar: will at the end
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
* returns: CollectionNoError
*	 CollectionEmpty
*	 CollectionOutOfMemory
*/
CollectionError StringCharAdd(String* string, char addChar);

// Adds the transmitted string to the end
// @param string: Address of string object
// @param addString: will be saved at the end
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
* returns: CollectionNoError
*	 CollectionEmpty
*	 CollectionOutOfMemory
*/
CollectionError StringConcat(String* string, char* addString);

/*
 * Function:  StringGetFullString
 * --------------------
 * Returns string object as normal string
 *
 * Returned string must be freed!
 * --------------------
 *
 *  returns: string
 */

// Returns string object as normal string
// Returned string must be freed!
// @param string: Address of string object
// @return string: contains converted string object
char* StringGetFullString(String* string);

#endif