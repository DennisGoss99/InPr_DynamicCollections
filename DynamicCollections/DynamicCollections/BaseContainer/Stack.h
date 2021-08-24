#ifndef StackInclude
#define StackInclude

#include "CollectionError.h"

#define StackThreshold 20u

typedef struct Stack_
{
	void* Content;
	unsigned int SizeOfSingleElement;
	unsigned int SizeUsed;
	unsigned int SizeAllocated;
}Stack;

void StackInitialize(Stack* stack, unsigned int sizeOfSingleElement);
void StackClear(Stack* stack);
CollectionError StackPush(Stack* stack, void* element);
CollectionError StackPull(Stack* stack, void* element);

#endif
