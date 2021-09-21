#ifndef QueueInclude
#define QueueInclude

#include "CollectionError.h"

// Threshold where the container will be resized bigger than needed to reduce reallocations.
#define QueueThreshold 20u

// Container as First in First out (FIFO) style
typedef struct Queue_
{
	// Array of values.
	void* Content;

	// Offset from 'Queue.Content' to the object that will be fetched next.
	size_t DataOffset;

	// Size of one object contained in 'Queue.Content'
	size_t SizeOfSingleElement;

	// Used space of 'Queue.Content'
	size_t SizeUsed;

	// Actual allocated size of 'Queue.Content'
	size_t SizeAllocated;
}Queue;

// Initialize the Container. Call this directly after creation.
// @param queue: Address of queue object
// @param sizeOfSingleElement: Size of used objects in bytes [sizeof(Type)]
void QueueInitialize(Queue* queue, unsigned int sizeOfSingleElement);

// Frees all used resources form the queue and resets everything. 
// SizeOfSingleElement is preserved. You don't need to call 'QueueInitialize()' again.
// @param queue: Address of stack object
void QueueClear(Queue* queue);

// Add something to the Container.
// Data will be put after the last data.
// @param queue: Address of queue object
// @param element: Address of the data that will be added.
// @return CollectionError: Errorcode that contains information about the operation.
CollectionError QueuePush(Queue* queue, void* element);

// Retrieve something to the Container.
// Data will be pulled from the first-used position. Not the very first one.
// The next element to be pulled will be the one after this.
// @param queue: Address of queue object
// @param element: Address of the destination where data will be copyed to.
// @return CollectionError: Errorcode that contains information about the operation.
CollectionError QueuePull(Queue* queue, void* element);

#endif
