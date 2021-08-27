#include "LinkedList.h"
#include <malloc.h>
#include <memory.h>

void LinkedListInitialize(LinkedList* linkedList, unsigned int sizeOfElement)
{
	LinkedNodeInitialize(&linkedList->FirstNode);

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

void LinkedListInsert(LinkedList* linkedList, unsigned int index, void* element)
{
	LinkedListNode* nodeIntertionParent = 0;
	LinkedListNode* nodeInsertionPoint = 0;

	LinkedListGetNode(linkedList, index - 1, &nodeIntertionParent);

	nodeInsertionPoint = (LinkedListNode*)nodeIntertionParent->ElementNext;

	nodeIntertionParent->ElementNext = LinkedNodeCreate(linkedList->SizeOfSingleElement, element, nodeInsertionPoint);

	linkedList->Size++;
}

void LinkedListAddToEnd(LinkedList* linkedList, void* element)
{
	char firstElement = -1;
	LinkedListNode* newNode = LinkedNodeCreate(linkedList->SizeOfSingleElement, element, 0);
	LinkedListNode* insertionNode = 0;
	
	LinkedListGetLastElement(linkedList, &insertionNode);	

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
}

void LinkedListRemoveAtIndex(LinkedList* linkedList, unsigned int index, void* element)
{
	LinkedListNode* nodeParent = 0;
	LinkedListNode* node = 0;

	LinkedListGetElement(linkedList, index - 1, &nodeParent);

	node = nodeParent->ElementNext;

	nodeParent->ElementNext = node->ElementNext;

	free(node->ElementCurrent);
	free(node);

	linkedList->Size--;
}

void LinkedListGetElement(LinkedList* linkedList, unsigned int index, void* element)
{
	LinkedListNode* nodeCursor = linkedList->FirstNode;

	while (index != -1 && nodeCursor)
	{
		memcpy(element, nodeCursor->ElementCurrent, linkedList->SizeOfSingleElement);

		nodeCursor = nodeCursor->ElementNext;
		index--;
	}
}

void LinkedListGetNode(LinkedList* linkedList, unsigned int index, LinkedListNode** linkedListNode)
{
	LinkedListNode* nodeCursor = linkedList->FirstNode;

	while (index != -1 && nodeCursor)
	{
		*linkedListNode = nodeCursor;

		nodeCursor = nodeCursor->ElementNext;
		index--;
	}
}

void LinkedListGetLastElement(LinkedList* linkedList, LinkedListNode** linkedListNode)
{
	LinkedListNode* nodeCursor = linkedList->FirstNode;
	
	*linkedListNode = 0;

	while (nodeCursor)
	{
		*linkedListNode = nodeCursor;
		nodeCursor = nodeCursor->ElementNext;
	}	
}