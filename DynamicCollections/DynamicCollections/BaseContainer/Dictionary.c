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
	dictionary->Size = 0;
	dictionary->SizeOfKey = 0;
	dictionary->SizeOfValue = 0;
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

		Root->Key = calloc(1, dictionary->SizeOfKey);
		
		Root->Key = key;
		Root->Value = value;
		
	}
	else
	{

		int compareKeyValue = memcmp(Root->Key, key, dictionary->SizeOfKey); 

		if (compareKeyValue == 0)
			return CollectionKeyAlreadyExists;


		DictionaryTreeItem* insertItem = calloc(1, sizeof(DictionaryTreeItem));
		insertItem->Key = calloc(1, dictionary->SizeOfKey);

		if (!insertItem->Key)
			return CollectionOutOfMemory;
		
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

CollectionError DictionaryRemove(Dictionary* dictionary, void* key)
{
	if (dictionary->Size == 0)
		return CollectionEmpty;

	DictionaryTreeItem* currentItemParent = NULL;
	char side = 0;
	
	DictionaryTreeItem* currentItem = Root;
	
	int compareKeyValue = memcmp(currentItem->Key, key, dictionary->SizeOfKey);

	while (compareKeyValue != 0){
		
		currentItemParent = currentItem;
		side = compareKeyValue > 0 ? 1 : 2;
		
		currentItem = compareKeyValue > 0 ? currentItem->LeftChild : currentItem->RightChild;

		if (currentItem == NULL)
			return CollectionElementIsNullPointer;

		compareKeyValue = memcmp(currentItem->Key, key, dictionary->SizeOfKey);
	}

	//has no Children
	if(currentItem->LeftChild == NULL && currentItem->RightChild == NULL)
	{
		free(currentItem);

		if (side == 0)
			Root = NULL;
		if (side == 1)
			currentItemParent->LeftChild = NULL;
		if (side == 2)
			currentItemParent->RightChild = NULL;

		dictionary->Size--;
		
		return CollectionNoError;
	}

	//has one Child
	if(currentItem->LeftChild == NULL || currentItem->RightChild == NULL)
	{
		DictionaryTreeItem* child = currentItem->LeftChild == NULL ? currentItem->RightChild : currentItem->LeftChild;

		free(currentItem);

		if (side == 0)
			Root = child;
		if (side == 1)
			currentItemParent->LeftChild = child;
		if (side == 2)
			currentItemParent->RightChild = child;

		dictionary->Size--;
		return CollectionNoError;
	}

	//has two Children
	{
		DictionaryTreeItem* currentItemRightChild = currentItem->RightChild;
		
		DictionaryTreeItem* biggestLowestChild = currentItem->RightChild;
		DictionaryTreeItem* biggestLowestChildParent = currentItem;

		while (biggestLowestChild->LeftChild != NULL)
		{
			biggestLowestChildParent = biggestLowestChild;
			biggestLowestChild = biggestLowestChild->LeftChild;
		}

		
		biggestLowestChild->LeftChild = currentItem->LeftChild;
		biggestLowestChildParent->LeftChild = NULL;
		
		free(currentItem);

		if (side == 0)
			Root = biggestLowestChild;
		if (side == 1)
			currentItemParent->LeftChild = biggestLowestChild;
		if (side == 2)
			currentItemParent->RightChild = biggestLowestChild;


		DictionaryTreeItem* rightBranchBiggestLowestChild = biggestLowestChild;
		
		while (rightBranchBiggestLowestChild->RightChild != NULL)
		{
			rightBranchBiggestLowestChild = rightBranchBiggestLowestChild->RightChild;
		}

		if(rightBranchBiggestLowestChild != currentItemRightChild)
			rightBranchBiggestLowestChild->RightChild = currentItemRightChild;
		

		dictionary->Size--;
		return CollectionNoError;
	}	
}
