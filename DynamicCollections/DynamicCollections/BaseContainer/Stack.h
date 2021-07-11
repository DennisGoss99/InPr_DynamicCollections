#ifndef StackInclude
#define StackInclude

#include "CollectionError.h"

typedef struct Stack_
{
	void* Content;
	unsigned int SizeOfSingleElement;
	unsigned int Size;
}Stack;

void StackInitialize(Stack* stack, unsigned int sizeOfSingleElement);
void StackDestroy(Stack* stack);
CollectionError StackPush(Stack* stack, void* element);
CollectionError StackPull(Stack* stack, void* element);
CollectionError StackClear(Stack* stack);
#endif
