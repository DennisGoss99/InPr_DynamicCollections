#ifndef LinkedListInclude
#define LinkedListInclude

#include "CollectionError.h"
#include "LinkedListNode.h"

// Container that holds data in a 'Node-Chain'
// Very flexible but has slow seek-time.
typedef struct LinkedList_
{
	// First element of the 'Node-Chain'
	LinkedListNode* FirstNode;

	// Size of one object contained in 'Node-Chain'
	unsigned int SizeOfSingleElement;

	// Amount of elements in 'Node-Chain'
	unsigned int Size;
}LinkedList;

// Initialize the Container. Call this directly after creation.
// @param linkedList: Address of LinkedList object
// @param sizeOfSingleElement: Size of used objects in bytes [sizeof(Type)]
void LinkedListInitialize(LinkedList* linkedList, unsigned int sizeOfElement);

// Frees all used resources form the stack and resets everything. 
// SizeOfSingleElement is preserved. You don't need to call 'StackInitialize()' again.
// @param linkedList: Address of LinkedList object
void LinkedListClear(LinkedList* linkedList);

// Insert data at a specific index into the 'Node-Chain', the node will be created internally.
// @param linkedList: Address of LinkedList object
// @param index: Index of data in the 'Node-Chain'
// @return CollectionError: Errorcode that contains information about the operation.
CollectionError LinkedListInsert(LinkedList* linkedList, unsigned int index, void* element);

// Insert data at the end into the 'Node-Chain', the node will be created internally.
// @param linkedList: Address of LinkedList object
// @return CollectionError: Errorcode that contains information about the operation.
CollectionError LinkedListAddToEnd(LinkedList* linkedList, void* element);

// Delete Node at specific position and free it. 
// @param linkedList: Address of LinkedList object
// @param index: Index of data in the 'Node-Chain'
// @return CollectionError: Errorcode that contains information about the operation.
CollectionError LinkedListRemoveAtIndex(LinkedList* linkedList, unsigned int index, void* element);

// Get data at specific position from a node. 
// @param linkedList: Address of LinkedList object
// @param index: Index of data in the 'Node-Chain'
// @return CollectionError: Errorcode that contains information about the operation.
CollectionError LinkedListGetElement(LinkedList* linkedList, unsigned int index, void* element);

// Get node from specific position
// @param linkedList: Address of LinkedList object
// @param index: Index of data in the 'Node-Chain'
// @param linkedListNode: location of the extracted Node where t will be copied.
// @return CollectionError: Errorcode that contains information about the operation.
CollectionError LinkedListGetNode(LinkedList* linkedList, unsigned int index, LinkedListNode** linkedListNode);

// Get last node from chain.
// @param linkedList: Address of LinkedList object
// @param linkedListNode: location of the extracted Node where t will be copied.
// @return CollectionError: Errorcode that contains information about the operation.
CollectionError LinkedListGetLastElement(LinkedList* linkedList, LinkedListNode** linkedListNode);

#endif