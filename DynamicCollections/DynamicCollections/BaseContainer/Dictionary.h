#ifndef DictionaryInclude
#define DictionaryInclude
#include "CollectionError.h"

#define EMPTYDICTIONARY (Dictionary){0}

typedef struct DictionaryTreeItem_
{
	void* Key;
	void* Value;

	struct DictionaryTreeItem_* LeftChild;
	struct DictionaryTreeItem_* RightChild;
}DictionaryTreeItem;

/*
 * Dictionary:
 * --------------------
 * SizeOfKey
 * SizeOfValue
 * Size: Number of all nodes
 */
typedef struct Dictionary_
{
	unsigned int SizeOfKey;
	unsigned int SizeOfValue;
	unsigned int Size;

	//Don't Touch
	DictionaryTreeItem* Root;
}Dictionary;

/*
 * Function:  DictionaryInitialize
 * --------------------
 * Acts like a constructor
 * ! Dictionaries must be set to EMPTYDICTIONARY before each initialization
 * eg: 'List a = EMPTYDICTIONARY;'
 * --------------------
 */
void DictionaryInitialize(Dictionary* dictionary, unsigned int sizeOfKey, unsigned int sizeOfValue);

void DictionaryDestroy(Dictionary* dictionary);

/*
 * Function:  DictionaryContainsKey
 * --------------------
 * Returns true if the dictionary contains the transmitted key
 * --------------------
 *  returns: 0 (false)
 *	   1 (true)
 */
char DictionaryContainsKey(Dictionary* dictionary, void* key);

/*
 * Function:  DictionaryAdd
 * --------------------
 * Adds parameter value to the internal binary tree
 *
 * --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionOutOfMemory
 *	   CollectionKeyAlreadyExists
 */
CollectionError DictionaryAdd(Dictionary* dictionary, void* key, void* value);

/*
 * Function:  DictionaryGet
 * --------------------
 * Gets the value of the corresponding key and safes it in out
 *
 * --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionArrayIndexOutOfBounds
 */
CollectionError DictionaryGet(Dictionary* dictionary, void* key, void* out);

/*
 * Function:  DictionaryRemove
 * --------------------
 * Deletes entry of key
 *
 * --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionElementIsNullPointer
 */
CollectionError DictionaryRemove(Dictionary* dictionary, void* key);

#endif