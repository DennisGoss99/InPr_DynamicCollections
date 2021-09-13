#include "Dictionary.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





void DictionaryInitialize(Dictionary* dictionary, unsigned int sizeOfKey, unsigned int sizeOfValue)
{
	dictionary->Size = 0;
	dictionary->SizeOfKey = sizeOfKey;
	dictionary->SizeOfValue = sizeOfValue;
}

static void DeleteNode(DictionaryTreeItem* deleteNode)
{
	if (deleteNode->LeftChild != NULL)
		DeleteNode(deleteNode->LeftChild);
	
	if (deleteNode->RightChild != NULL)
		DeleteNode(deleteNode->RightChild);

	free(deleteNode->Key);
	free(deleteNode);
}

void DictionaryDestroy(Dictionary* dictionary)
{
	dictionary->Size = 0;
	dictionary->SizeOfKey = 0;
	dictionary->SizeOfValue = 0;

	DictionaryTreeItem* destroyItem = dictionary->Root;

	if (dictionary->Root != NULL)
		DeleteNode(dictionary->Root);

	dictionary->Root = NULL;
}



char DictionaryContainsKey(Dictionary* dictionary, void* key)
{
	if (dictionary->Size == 0)
		return 0;

	int compareKeyValue;
	DictionaryTreeItem* currentElement = dictionary->Root;

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
	if (dictionary == NULL)
		return CollectionEmpty;
	
	// no root exists
	if (dictionary->Size == 0)
	{
		dictionary->Root = calloc(1, sizeof(DictionaryTreeItem));
		
		if (!dictionary->Root)
			return CollectionOutOfMemory;

		dictionary->Root->Key = calloc(1, dictionary->SizeOfKey);

		if (!dictionary->Root->Key)
			return CollectionOutOfMemory;

		memcpy(dictionary->Root->Key, key, dictionary->SizeOfKey);
		
		dictionary->Root->Value = value;
		
	}
	else
	{

		int compareKeyValue = memcmp(dictionary->Root->Key, key, dictionary->SizeOfKey);

		if (compareKeyValue == 0)
			return CollectionKeyAlreadyExists;


		DictionaryTreeItem* insertItem = calloc(1, sizeof(DictionaryTreeItem));
		insertItem->Key = calloc(1, dictionary->SizeOfKey);

		if (!insertItem->Key)
			return CollectionOutOfMemory;

		memcpy(insertItem->Key, key, dictionary->SizeOfKey);
		insertItem->Value = value;

		DictionaryTreeItem* insertItemParent = dictionary->Root;
		
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
	DictionaryTreeItem* currentElement = dictionary->Root;
	
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
	
	DictionaryTreeItem* currentItem = dictionary->Root;
	
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
		free(currentItem->Key);
		free(currentItem);

		if (side == 0)
			dictionary->Root = NULL;
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

		free(currentItem->Key);
		free(currentItem);

		if (side == 0)
			dictionary->Root = child;
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

		free(currentItem->Key);
		free(currentItem);

		if (side == 0)
			dictionary->Root = biggestLowestChild;
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
