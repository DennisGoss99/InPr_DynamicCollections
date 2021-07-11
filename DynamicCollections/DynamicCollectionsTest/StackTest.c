#include "StackTest.h"
#include "../DynamicCollections/BaseContainer/Stack.h"

#include <assert.h>

void StackTestStart()
{
	StackAddElementTest();
	StackRemoveNothingTest();
	StackRemoveElementTest();
	StackAddAndRemoveTest();
}

void StackAddElementTest()
{
	int a = 5;
	Stack stack;

	StackInitialize(&stack, sizeof(int));

	CollectionError error = StackPush(&stack, &a);

	assert(error == CollectionNoError);
}

void StackRemoveNothingTest()
{
	Stack stack;
	int dummy = -1;

	StackInitialize(&stack, sizeof(int));
	
	CollectionError error = StackPull(&stack, &dummy);

	assert(error == CollectionEmpty);
}

void StackRemoveElementTest()
{

}

void StackAddAndRemoveTest()
{
	Stack stack;

	StackInitialize(&stack, sizeof(int));

	// Add
	{
		int a = 5;
		StackPush(&stack, &a);
	}

	// Pull
	{
		int expectedA = -1;
		StackPull(&stack, &expectedA);

		assert(expectedA == 5);
	}
}