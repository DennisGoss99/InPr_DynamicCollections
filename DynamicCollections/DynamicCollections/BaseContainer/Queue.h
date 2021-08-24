#ifndef QueueInclude
#define QueueInclude

#include "CollectionError.h"

#define QueueThreshold 20u

typedef struct Queue_
{
	void* Content;
	unsigned int DataOffset;
	unsigned int SizeOfSingleElement;
	unsigned int SizeUsed;
	unsigned int SizeAllocated;
}Queue;

void QueueInitialize(Queue* queue, unsigned int sizeOfSingleElement);
void QueueClear(Queue* queue);
CollectionError QueuePush(Queue* queue, void* element);
CollectionError QueuePull(Queue* queue, void* element);

#endif
