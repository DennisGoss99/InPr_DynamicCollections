#ifndef LinkedListInclude
#define LinkedListInclude

#include "LinkedListNode.h"

typedef struct LinkedList_
{
	LinkedListNode* FirstNode;
	unsigned int SizeOfSingleElement;
	unsigned int Size;
}LinkedList;

void LinkedListInitialize(LinkedList* linkedList, unsigned int sizeOfElement);
void LinkedListClear(LinkedList* linkedList);
void LinkedListInsert(LinkedList* linkedList, unsigned int index, void* element);
void LinkedListAddToEnd(LinkedList* linkedList, void* element);
void LinkedListRemoveAtIndex(LinkedList* linkedList, unsigned int index, void* element);
void LinkedListGetElement(LinkedList* linkedList, unsigned int index, void* element);
void LinkedListGetNode(LinkedList* linkedList, unsigned int index, LinkedListNode** linkedListNode);
void LinkedListGetLastElement(LinkedList* linkedList, LinkedListNode** linkedListNode);

#endif