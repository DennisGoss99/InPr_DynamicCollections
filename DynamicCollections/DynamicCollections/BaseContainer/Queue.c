#include "Queue.h"
#include <stdlib.h>

void QueueInitialize(Queue* queue, unsigned int sizeOfSingleElement)
{
	queue->Content = 0;
	queue->DataOffset = 0;
	queue->SizeOfSingleElement = sizeOfSingleElement;
	queue->SizeUsed = 0;
	queue->SizeAllocated = 0;
}

void QueueClear(Queue* queue)
{
	free(queue->Content);

	queue->Content = 0;
	queue->DataOffset = 0;
	queue->SizeUsed = 0;
	queue->SizeAllocated = 0;
}

CollectionError QueuePush(Queue* queue, void* element)
{
	unsigned int sizeOfElement = queue->SizeOfSingleElement;
	unsigned int dataSizeCurrent = queue->SizeUsed;
	unsigned int dataSizeNew = (dataSizeCurrent + 1);
	char needToReallocate = dataSizeNew >= queue->SizeAllocated;
	void* dataCurrent = queue->Content;
	void* dataNew = 0;
	void* dataInsertionPoint = 0;

	if (!element)
	{
		return CollectionElementIsNullPointer;
	}

	if (!sizeOfElement)
	{
		return CollectionNoElementSizeSpecified;
	}

	if (needToReallocate)
	{
		unsigned int allocateSpace = dataSizeCurrent + QueueThreshold;
		unsigned int allocateSpaceInBytes = allocateSpace * sizeOfElement;

		dataNew = realloc(dataCurrent, allocateSpaceInBytes);		

		if (!dataNew)
		{
			return CollectionOutOfMemory;
		}

		queue->SizeAllocated = allocateSpace;
		queue->Content = dataNew;
	}

	dataNew = queue->Content;
	dataInsertionPoint = (size_t)dataNew + dataSizeCurrent;

	memcpy(dataInsertionPoint, element, sizeOfElement);

	queue->SizeUsed++;

	return CollectionNoError;
}

CollectionError QueuePull(Queue* queue, void* element)
{
	unsigned int sizeOfElement = queue->SizeOfSingleElement;
	unsigned int dataSizeCurrent = queue->SizeUsed;
	unsigned int dataSizeNew = (dataSizeCurrent - 1);
	char needToReallocate = (int)dataSizeNew < ((int)queue->SizeAllocated - (int)QueueThreshold);
	void* dataCurrent = queue->Content;
	void* dataNew = 0;
	void* dataExtractionPoint = 0;

	if (!element)
	{
		return CollectionElementIsNullPointer;
	}

	if (!queue->Content)
	{
		return CollectionEmpty;
	}

	// Extract data before reallocation
	dataExtractionPoint = (size_t)dataCurrent + queue->DataOffset;
	memcpy(element, dataExtractionPoint, sizeOfElement);

	// if only one element is remaining, you can clear the container.
	if (dataSizeCurrent == 1)
	{
		QueueClear(queue);

		return CollectionNoError;
	}

	if (needToReallocate)
	{
		unsigned int allocateSpace = dataSizeNew + QueueThreshold;
		unsigned int allocateSpaceInBytes = allocateSpace * sizeOfElement;

		dataNew = realloc(dataCurrent, allocateSpaceInBytes);

		if (!dataNew)
		{
			return CollectionOutOfMemory;
		}

		queue->Content = dataNew;
		queue->SizeAllocated = allocateSpace;
	}

	queue->SizeUsed--;
	queue->DataOffset++;

	return CollectionNoError;
}