#ifndef LinkedListInclude
#define LinkedListInclude

#include "CollectionError.h"
#include "LinkedListNode.h"

typedef struct LinkedList_
{
	LinkedListNode* FirstNode;
	unsigned int SizeOfSingleElement;
	unsigned int Size;
}LinkedList;

void LinkedListInitialize(LinkedList* linkedList, unsigned int sizeOfElement);
void LinkedListClear(LinkedList* linkedList);
CollectionError LinkedListInsert(LinkedList* linkedList, unsigned int index, void* element);
CollectionError LinkedListAddToEnd(LinkedList* linkedList, void* element);
CollectionError LinkedListRemoveAtIndex(LinkedList* linkedList, unsigned int index, void* element);
CollectionError LinkedListGetElement(LinkedList* linkedList, unsigned int index, void* element);
CollectionError LinkedListGetNode(LinkedList* linkedList, unsigned int index, LinkedListNode** linkedListNode);
CollectionError LinkedListGetLastElement(LinkedList* linkedList, LinkedListNode** linkedListNode);

#endif