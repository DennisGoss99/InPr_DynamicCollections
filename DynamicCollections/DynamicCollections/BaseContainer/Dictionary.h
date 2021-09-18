#ifndef DictionaryInclude
#define DictionaryInclude
#include <stddef.h>

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
	size_t SizeOfKey;
	size_t SizeOfValue;
	unsigned int Size;

	//Don't Touch
	DictionaryTreeItem* Root;
}Dictionary;


// Acts like a constructor
// Dictionaries must be set to EMPTYDICTIONARY before each initialization
// eg: 'List a = EMPTYDICTIONARY;'
// @param dictionary: Address of dictionary object
// @param sizeOfKey: Size of used key objects in bytes [sizeof(Type)]
// @param sizeOfValue: Size of used value objects in bytes [sizeof(Type)]
void DictionaryInitialize(Dictionary* dictionary, size_t sizeOfKey, size_t sizeOfValue);

// Frees all entries keys of this dictionary
// @param dictionary: Address of dictionary object
void DictionaryDestruction(Dictionary* dictionary);

// Returns true if the dictionary contains the transmitted key
// @param dictionary: Address of Dictionary object
// @param key: will be compared
// @return char: 0 false/ 1 true
char DictionaryContainsKey(Dictionary* dictionary, void* key);

// Adds parameter value to the internal binary tree, if it doesn't contain this key
// @param dictionary: Address of dictionary object
// @param key: will be added
// @param value: will be added
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionOutOfMemory
 *	   CollectionKeyAlreadyExists
 */
CollectionError DictionaryAdd(Dictionary* dictionary, void* key, void* value);



// Gets the value of the corresponding key and returns it in 'out'
// @param dictionary: Address of dictionary object
// @param key: will be added
// @param out: contains the output
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionArrayIndexOutOfBounds
 */
CollectionError DictionaryGet(Dictionary* dictionary, void* key, void* out);


// Deletes entry of key
// @param dictionary: Address of dictionary object
// @param key: that will be removed
// @return CollectionError: Errorcode that contains information about the operation.
/* --------------------
 *  returns: CollectionNoError
 *	   CollectionEmpty
 *	   CollectionElementIsNullPointer
 */
CollectionError DictionaryRemove(Dictionary* dictionary, void* key);

#endif