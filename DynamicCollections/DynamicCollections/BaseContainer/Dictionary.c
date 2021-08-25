#include "Dictionary.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DictionaryTreeItem_
{
	void* Key;
	void* Value;

	struct DictionaryTreeItem_* LeftChild;
	struct DictionaryTreeItem_* RightChild;
}DictionaryTreeItem;

static DictionaryTreeItem* Root;

void DictionaryInitialize(Dictionary* dictionary, unsigned int sizeOfKey, unsigned int sizeOfValue)
{
	dictionary->Size = 0;
	dictionary->SizeOfKey = sizeOfKey;
	dictionary->SizeOfValue = sizeOfValue;
}

void DictionaryDestroy(Dictionary* dictionary)
{
	//Todo: free
}

char DictionaryContainsKey(Dictionary* dictionary, void* key)
{
	if (dictionary->Size == 0)
		return 0;

	int compareKeyValue;
	DictionaryTreeItem* currentElement = Root;

	do {
		compareKeyValue = memcmp(currentElement->Key, key, dictionary->SizeOfKey);
		
		if (compareKeyValue > 0)
			currentElement = currentElement->LeftChild;

		if (compareKeyValue < 0)
			currentElement = currentElement->RightChild;

		if (currentElement == NULL)
			return 0;


	} while (compareKeyValue != 0);

	return 1;
}

CollectionError DictionaryAdd(Dictionary* dictionary, void* key, void* value)
{
	// no root exists
	if (dictionary->Size == 0)
	{
		Root = calloc(1, sizeof(DictionaryTreeItem));
		
		if (!Root)
			return CollectionOutOfMemory;

		Root->Key = key;
		Root->Value = value;

		dictionary->Size++;
		
	}else
	{

		int compareKeyValue = memcmp(Root->Key, key, dictionary->SizeOfKey); 

		if (compareKeyValue == 0)
			return CollectionKeyAlreadyExists;


		DictionaryTreeItem* insertItem = calloc(1, sizeof(DictionaryTreeItem));
		insertItem->Key = key;
		insertItem->Value = value;

		DictionaryTreeItem* insertItemParent = Root;
		
		while((compareKeyValue > 0 ? insertItemParent->LeftChild : insertItemParent->RightChild) != NULL)
		{
			insertItemParent = compareKeyValue > 0 ? insertItemParent->LeftChild : insertItemParent->RightChild;
			compareKeyValue = memcmp(insertItemParent->Key, key, dictionary->SizeOfKey);
			
			if (compareKeyValue == 0)
				return CollectionKeyAlreadyExists;
		}
		
		if(compareKeyValue > 0)
			insertItemParent->LeftChild = insertItem;
		else
			insertItemParent->RightChild = insertItem;
		
	}
	
	dictionary->Size++;
	return CollectionNoError;
	
}

CollectionError DictionaryGet(Dictionary* dictionary, void* key, void* out)
{
	if (dictionary->Size == 0)
		return CollectionEmpty;
	
	int compareKeyValue;
	DictionaryTreeItem* currentElement = Root;
	
	do {
		compareKeyValue = memcmp(currentElement->Key, key, dictionary->SizeOfKey);

		if (compareKeyValue > 0)
			currentElement = currentElement->LeftChild;
		

		if (compareKeyValue < 0)
			currentElement = currentElement->RightChild;

		if (currentElement == NULL)
			return CollectionArrayIndexOutOfBounds;


	} while (compareKeyValue != 0);

	
	memcpy( out, &currentElement->Value, sizeof(void*));
	
	return CollectionNoError;
}

CollectionError DictionaryRemove(Dictionary* dictionary)
{
	//Todo: free
	return CollectionNoError;
}
