#ifndef StringInclude
#define StringInclude

#include "../BaseContainer/List.h"

#define EMPTYSTRING (String){0}

/*
 * String:
 * --------------------
 * List : inner element (contains char´s)
 * Count: contains number of chars
 */
typedef struct String_
{
	struct List_ List;
	unsigned int Count;
}String;

/*
 * Function:  StringInitialize
 * --------------------
 * Acts like a constructor
 * ! A string must be set to EMPTYSTRING before each initialization
 * eg: 'String a = EMPTYSTRING;'
 * --------------------
 */
void StringInitialize(String* string, char* inputString);

void StringDestruction(String* string);

/*
 * Function:  StringCharInsertAt
 * --------------------
 * Puts char at index position
 * --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionArrayIndexOutOfBounds
 */
CollectionError StringCharInsertAt(String* string, unsigned int indexValue, char value);

/*
 * Function:  StringCharGet
 * --------------------
 * Get char at transmitted index and saves it in out
 * --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionArrayIndexOutOfBounds
 */
CollectionError StringCharGet(String* string, unsigned int index, char* out);

/*
 * Function:  StringCharAdd
 * --------------------
 * Adds char to the end of string

 * When the string is full, it will be made bigger
 * --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionOutOfMemory
 */
CollectionError StringCharAdd(String* string, char addChar);

/*
 * Function:  StringConcat
 * --------------------
 * Adds the transmitted string to the end
 * --------------------
 *
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionOutOfMemory
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
char* StringGetFullString(String* string);

#endif