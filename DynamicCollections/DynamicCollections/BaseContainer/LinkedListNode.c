#include "LinkedListNode.h"

void LinkedNodeInitialize(LinkedListNode* linkedListNode)
{
	linkedListNode->ElementCurrent = 0;
	linkedListNode->ElementNext = 0;
}

LinkedListNode* LinkedNodeCreate(unsigned int sizeOfElement, void* dataCurrent, void* dataNext)
{
	const unsigned int size = sizeof(LinkedListNode);
	LinkedListNode* newNode = (LinkedListNode*)malloc(size);

	LinkedNodeInitialize(newNode);

	if (dataCurrent)
	{
		newNode->ElementCurrent = malloc(sizeOfElement);
		memcpy(newNode->ElementCurrent, dataCurrent, sizeOfElement);
	}

	if (dataNext)
	{
		newNode->ElementNext = malloc(size);
		memcpy(newNode->ElementNext, dataNext, size);
	}

	return newNode;
}
