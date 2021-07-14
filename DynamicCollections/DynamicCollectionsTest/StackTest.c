#include "StackTest.h"
#include "../DynamicCollections/BaseContainer/Stack.h"
#include "TestSystem/Tester.h"

#include <assert.h>

void StackTestStart()
{
	testPrintHeader("-----<Testing Stack.h>-----");
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

	const CollectionError error = StackPush(&stack, &a);

	test_collectionError(error, CollectionNoError, "Stack Test: Push int value");
}

void StackRemoveNothingTest()
{
	Stack stack;
	int dummy = -1;

	StackInitialize(&stack, sizeof(int));

	const CollectionError error = StackPull(&stack, &dummy);

	test_collectionError(error, CollectionEmpty, "Stack Test: Pull empty stack");
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
		
		test_int(5, expectedA, "Stack Test: Pull int value");
	}
}