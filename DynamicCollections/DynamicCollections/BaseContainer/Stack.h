#ifndef StackInclude
#define StackInclude

#include "CollectionError.h"

// Threshold where the container will be resized bigger than needed to reduce reallocations.
#define StackThreshold 20u

// Container as First in last out (FILO) style
typedef struct Stack_
{
	// Array of values.
	void* Content;

	// Size of one object contained in 'Stack.Content'
	unsigned int SizeOfSingleElement;

	// Used space of 'Stack.Content'
	unsigned int SizeUsed;

	// Actual allocated size of 'Stack.Content'
	unsigned int SizeAllocated;
}Stack;

// Initialize the Container. Call this directly after creation.
// @param stack: Address of stack object
// @param sizeOfSingleElement: Size of used objects in bytes [sizeof(Type)]
void StackInitialize(Stack* stack, unsigned int sizeOfSingleElement);

// Frees all used resources form the stack and resets everything. 
// SizeOfSingleElement is preserved. You don't need to call 'StackInitialize()' again.
// @param stack: Address of stack object
void StackClear(Stack* stack);

// Add something to the Container.
// Data will be put after the last data.
// @param stack: Address of stack object
// @param element: Address of the data that will be added.
// @return CollectionError: Errorcode that contains information about the operation.
CollectionError StackPush(Stack* stack, void* element);

// Retrieve something to the Container.
// Data will be pulled from the last position.
// The next element to be pulled will be the one before this.
// @param stack: Address of stack object
// @param element: Address of the destination where data will be copied to.
// @return CollectionError: Errorcode that contains information about the operation.
CollectionError StackPull(Stack* stack, void* element);

#endif
