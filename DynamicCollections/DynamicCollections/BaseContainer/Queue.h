#ifndef QueueInclude
#define QueueInclude

#include "CollectionError.h"

typedef struct Queue_
{
	void** Content;
	unsigned int SizeOfSingleElement;
	unsigned int Size;
}Queue;

void QueueInitialize(Queue* queue);
void QueueDestroy(Queue* queue);
CollectionError QueuePush(Queue* queue, void* element);
CollectionError QueuePull(Queue* queue, void* element);

#endif
