#include "Stack.h"
#include <stdlib.h>

void StackInitialize(Stack* stack, unsigned int sizeOfSingleElement)
{
	stack->Content = 0;
	stack->SizeOfSingleElement = sizeOfSingleElement;
	stack->SizeUsed = 0;
	stack->SizeAllocated = 0;
}

void StackClear(Stack* stack)
{
	free(stack->Content);

	stack->Content = 0;
	stack->SizeUsed = 0;
	stack->SizeAllocated = 0;
}

CollectionError StackPush(Stack* stack, void* element)
{
	unsigned int sizeOfElement = stack->SizeOfSingleElement;
	size_t dataSizeCurrent = stack->SizeUsed;
	unsigned int dataSizeNew = (dataSizeCurrent + 1);
	char needToReallocate = dataSizeNew >= stack->SizeAllocated;
	void* dataCurrent = stack->Content;
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
		unsigned int allocateSpace = dataSizeCurrent + StackThreshold;
		unsigned int allocateSpaceInBytes = allocateSpace * sizeOfElement;

		dataNew = realloc(dataCurrent, allocateSpaceInBytes);

		if (!dataNew)
		{
			return CollectionOutOfMemory;
		}

		stack->SizeAllocated = allocateSpace;
		stack->Content = dataNew;
	}

	dataNew = stack->Content;
	dataInsertionPoint = (size_t)dataNew + dataSizeCurrent;

	memcpy(dataInsertionPoint, element, sizeOfElement);

	stack->SizeUsed++;

	return CollectionNoError;
}

CollectionError StackPull(Stack* stack, void* element)
{
	unsigned int sizeOfElement = stack->SizeOfSingleElement;
	unsigned int dataSizeCurrent = stack->SizeUsed;
	unsigned int dataSizeNew = (dataSizeCurrent - 1);
	char needToReallocate = (int)dataSizeNew < ((int)stack->SizeAllocated - (int)StackThreshold);
	void* dataCurrent = stack->Content;
	void* dataNew = 0;
	void* dataExtractionPoint = 0;

	if (!element)
	{
		return CollectionElementIsNullPointer;
	}

	if (!stack->Content)
	{
		return CollectionEmpty;
	}

	// Extract data before reallocation
	dataExtractionPoint = (size_t)dataCurrent + dataSizeCurrent - 1u;
	memcpy(element, dataExtractionPoint, sizeOfElement);

	// if only one element is remaining, you can clear the container.
	if (dataSizeCurrent == 1)
	{
		StackClear(stack);

		return CollectionNoError;
	}

	if (needToReallocate)
	{
		unsigned int allocateSpace = dataSizeNew + StackThreshold;
		unsigned int allocateSpaceInBytes = allocateSpace * sizeOfElement;

		dataNew = realloc(dataCurrent, allocateSpaceInBytes);

		if (!dataNew)
		{
			return CollectionOutOfMemory;
		}

		stack->Content = dataNew;
		stack->SizeAllocated = allocateSpace;
	}

	stack->SizeUsed--;

	return CollectionNoError;
}