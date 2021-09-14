#include "LinkedList.h"
#include <stdlib.h>

void LinkedListInitialize(LinkedList* linkedList, unsigned int sizeOfElement)
{
	linkedList->FirstNode = 0;
	linkedList->SizeOfSingleElement = sizeOfElement;
	linkedList->Size = 0;
}

void LinkedListClear(LinkedList* linkedList)
{
	while (linkedList->FirstNode != 0)
	{
		LinkedListNode* node = linkedList->FirstNode;

		linkedList->FirstNode = node->ElementNext;

		free(node->ElementCurrent);
		free(node);

		linkedList->Size--;
	}
}

CollectionError LinkedListInsert(LinkedList* linkedList, unsigned int index, void* element)
{
	LinkedListNode* nodeIntertionParent = 0;
	LinkedListNode* nodeInsertionPoint = 0;
	CollectionError collectionError = LinkedListGetNode(linkedList, index - 1, &nodeIntertionParent);

	if (collectionError != CollectionNoError)
	{
		return collectionError;
	}

	nodeInsertionPoint = (LinkedListNode*)nodeIntertionParent->ElementNext;

	nodeIntertionParent->ElementNext = LinkedNodeCreate(linkedList->SizeOfSingleElement, element, nodeInsertionPoint);

	linkedList->Size++;

	return CollectionNoError;
}

CollectionError LinkedListAddToEnd(LinkedList* linkedList, void* element)
{
	char firstElement = -1;
	LinkedListNode* newNode = LinkedNodeCreate(linkedList->SizeOfSingleElement, element, 0);
	LinkedListNode* insertionNode = 0;	
	CollectionError collectionError = LinkedListGetLastElement(linkedList, &insertionNode);

	if (collectionError != CollectionNoError)
	{
		return collectionError;
	}

	firstElement = insertionNode == 0;

	if (firstElement)
	{
		linkedList->FirstNode = newNode;		
	}
	else
	{
		insertionNode->ElementNext = newNode;
	}

	linkedList->Size++;

	return CollectionNoError;
}

CollectionError LinkedListRemoveAtIndex(LinkedList* linkedList, unsigned int index, void* element)
{
	LinkedListNode* nodeParent = 0;
	LinkedListNode* node = 0;

	CollectionError collectionError = LinkedListGetElement(linkedList, index - 1, &nodeParent);

	if (collectionError != CollectionNoError)
	{
		return collectionError;
	}

	node = nodeParent->ElementNext;

	nodeParent->ElementNext = node->ElementNext;

	free(node->ElementCurrent);
	free(node);

	linkedList->Size--;

	return CollectionNoError;
}

CollectionError LinkedListGetElement(LinkedList* linkedList, unsigned int index, void* element)
{
	LinkedListNode* nodeCursor = linkedList->FirstNode;

	if (index == -1)
	{
		return CollectionArrayIndexOutOfBounds;
	}

	while (index != -1 && nodeCursor)
	{
		memcpy(element, nodeCursor->ElementCurrent, linkedList->SizeOfSingleElement);

		nodeCursor = nodeCursor->ElementNext;
		index--;
	}

	return index > 0 ? CollectionNoError : CollectionArrayIndexOutOfBounds;
}

CollectionError LinkedListGetNode(LinkedList* linkedList, unsigned int index, LinkedListNode** linkedListNode)
{
	LinkedListNode* nodeCursor = linkedList->FirstNode;

	while (index != -1 && nodeCursor)
	{
		*linkedListNode = nodeCursor;

		nodeCursor = nodeCursor->ElementNext;
		index--;
	}

	return nodeCursor ? CollectionNoError : CollectionArrayIndexOutOfBounds;
}

CollectionError LinkedListGetLastElement(LinkedList* linkedList, LinkedListNode** linkedListNode)
{
	LinkedListNode* nodeCursor = linkedList->FirstNode;
	
	*linkedListNode = 0;

	while (nodeCursor)
	{
		*linkedListNode = nodeCursor;
		nodeCursor = nodeCursor->ElementNext;
	}	

	return CollectionNoError;
}