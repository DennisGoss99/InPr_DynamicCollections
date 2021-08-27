#ifndef LinkedListNodeInclude
#define LinkedListNodeInclude

typedef struct LinkedListNode_
{
	void* ElementCurrent;
	void* ElementNext; // LinkedListNode
}LinkedListNode;

void LinkedNodeInitialize(LinkedListNode* linkedListNode);
LinkedListNode* LinkedNodeCreate(unsigned int sizeOfElement, void* dataCurrent, void* dataNext);

#endif