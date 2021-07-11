#ifndef LinkedListNodeInclude
#define LinkedListNodeInclude

typedef struct LinkedListNode_
{
	void* ElementCurrent;
	void* ElementNext;
}LinkedListNode;

void LinkedNodeInitialize(LinkedListNode* linkedListNode);

#endif