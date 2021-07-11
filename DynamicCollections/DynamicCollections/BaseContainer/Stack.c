#include "Stack.h"
#include <malloc.h>

void StackInitialize(Stack* stack, unsigned int sizeOfSingleElement)
{
	stack->Content = 0;
	stack->SizeOfSingleElement = sizeOfSingleElement;
	stack->Size = 0;	
}

void StackDestroy(Stack* stack)
{
	StackClear(stack);
}

CollectionError StackPush(Stack* stack, void* element)
{
	unsigned int newContentSize = ++stack->Size * stack->SizeOfSingleElement;
	void* oldData = stack->Content;
	void* newData = realloc(stack->Content, newContentSize);	// reallocate memory, if the content is null realloc will act like malloc.
	void* insertionAdress = 0;

	if (newData == 0)
	{
		return CollectionOutOfMemory;
	}

	stack->Content = newData;
	insertionAdress = (void*)((unsigned int)stack->Content + stack->Size - 1u);

	memcpy(insertionAdress, element, stack->SizeOfSingleElement);

	return CollectionNoError;
}

CollectionError StackPull(Stack* stack, void* element)
{
	if (stack->Size == 0)
	{
		return CollectionEmpty;
	}

	// Extract data before reallocation
	void* sourceAdress = (unsigned int)stack->Content + stack->Size - 1;

	memcpy(element, sourceAdress, stack->SizeOfSingleElement);

	if (stack->Size == 1)
	{
		return StackClear(stack);
	}

	// Reallocate
	unsigned int newSize = --stack->Size * stack->SizeOfSingleElement;
	void* oldData = stack->Content;
	void* newData = realloc(stack->Content, newSize); // Do not reallocate a size of 0 Bytes. It's not clearly defined. 

	if (newData == 0)
	{
		return CollectionOutOfMemory;
	}
	else
	{
		stack->Content = newData;
	}

	return CollectionNoError;
}

CollectionError StackClear(Stack* stack)
{
	free(stack->Content); // Free can be called even if content is null. It then does nothing

	stack->Content = 0;
	stack->Size = 0;

	return CollectionNoError;
}
