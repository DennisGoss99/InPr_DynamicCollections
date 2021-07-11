#ifndef LinkedListInclude
#define LinkedListInclude

#include "LinkedListNode.h"

typedef struct LinkedList_
{
	LinkedListNode FirstNode;
	unsigned int SizeOfSingleElement;
	unsigned int Size;
}LinkedList;

void LinkedListInitialize(LinkedList* linkedList);
void LinkedListDestroy(LinkedList* linkedList);

#endif