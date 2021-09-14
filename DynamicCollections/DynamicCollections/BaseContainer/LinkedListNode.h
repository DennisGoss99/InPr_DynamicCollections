#ifndef LinkedListNodeInclude
#define LinkedListNodeInclude

// Data node. Can be used in a 'LinkedList'
typedef struct LinkedListNode_
{
	// Datacontent, sizeOfElement defines how big one dataBlock is.
	void* ElementCurrent;

	// Node to next node.
	struct LinkedListNode_* ElementNext;
}LinkedListNode;

// LinkedNode.Initialize() -> Sets all values to 0. Prefer using LinkedNodeCreate() for creation.
// @param linkedListNode: Adress of node you wnat to change.
void LinkedNodeInitialize(LinkedListNode* linkedListNode);

// LinkedNode() -> Constructor, use tis to create new nodes.
// @param sizeOfElement : Size of used data in bytes.
// @param data : Adress of Data.
// @param nextNode : Adress of next Node.
// @return Adress to newly created node.
LinkedListNode* LinkedNodeCreate(unsigned int sizeOfElement, void* data, LinkedListNode* nextNode);

#endif