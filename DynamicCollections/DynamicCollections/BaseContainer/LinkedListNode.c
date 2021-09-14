#include "LinkedListNode.h"
#include <stdlib.h>

void LinkedNodeInitialize(LinkedListNode* linkedListNode)
{
	linkedListNode->ElementCurrent = 0;
	linkedListNode->ElementNext = 0;
}

LinkedListNode* LinkedNodeCreate(unsigned int sizeOfElement, void* data, LinkedListNode* nextNode)
{
	const unsigned int linkedListNodeSize = sizeof(LinkedListNode);
	LinkedListNode* newNode = (LinkedListNode*)malloc(linkedListNodeSize);

	if (!newNode)
	{
		return 0; // Creation failed!
	}

	LinkedNodeInitialize(newNode);

	// Copy data from source to safe in container
	if (data)
	{
		newNode->ElementCurrent = malloc(sizeOfElement);
		memcpy(newNode->ElementCurrent, data, sizeOfElement);
	}

	newNode->ElementNext = nextNode;

	return newNode;
}
