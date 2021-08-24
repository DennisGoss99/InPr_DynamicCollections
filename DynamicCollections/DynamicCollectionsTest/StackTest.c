#include "StackTest.h"
#include "../DynamicCollections/BaseContainer/Stack.h"
#include "TestSystem/Tester.h"

#include <assert.h>

void StackTestStart()
{
	testPrintHeader("-----<Testing Stack.h>-----");
	StackAddElementTest();
	StackRemoveNothingTest();	
	StackAddAndRemoveTest();
	StackComplexTest();
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

void StackComplexTest()
{
	char x = 0;
	CollectionError collectionError;
	Stack stack;
	StackInitialize(&stack, sizeof(char));

	// Add
	{
		char a[] = "Hello";
		StackPush(&stack, &a[0]);
		StackPush(&stack, &a[1]);
		StackPush(&stack, &a[2]);
		StackPush(&stack, &a[3]);
		StackPush(&stack, &a[4]);
	}

	// Pull
	{
		StackPull(&stack, &x);
		assert(x == 'o');

		StackPull(&stack, &x);
		assert(x == 'l');

		StackPull(&stack, &x);
		assert(x == 'l');

		StackPull(&stack, &x);
		assert(x == 'e');

		StackPull(&stack, &x);
		assert(x == 'H');
	}

	// Empty
	collectionError = StackPull(&stack, &x);
	assert(collectionError == CollectionEmpty);

	// Add
	{
		char b[] = "123";
		StackPush(&stack, &b[0]);
		StackPush(&stack, &b[1]);
		StackPush(&stack, &b[2]);
	}

	// Pull
	{
		StackPull(&stack, &x);
		assert(x == '3');

		StackPull(&stack, &x);
		assert(x == '2');

		StackPull(&stack, &x);
		assert(x == '1');
	}

	collectionError = StackPull(&stack, &x);
	assert(collectionError == CollectionEmpty);
}