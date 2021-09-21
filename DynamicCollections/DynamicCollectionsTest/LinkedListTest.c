#include "LinkedListTest.h"

#include <assert.h>
#include <stdio.h>

#include "TestSystem/Tester.h"
#include "TestSystem/CollectionTester.h"

void LinkedListTestStart()
{
	testPrintHeader("-----<Testing LinkedList.h>-----");
	LinkedListAddElementTest();
	LinkedListAddMultipleElementsTest();
	LinkedListRemoveAllElementsTest();

	//LinkedListMemoryLeakTest();
}

void LinkedListAddElementTest()
{
	LinkedList linkedList;

	LinkedListInitialize(&linkedList, sizeof(float));

	float x = 42.69;

	LinkedListAddToEnd(&linkedList, &x);
	
	assert(linkedList.FirstNode != 0);
	
	test_int(1, linkedList.Size, "LinkedList Add Test: Size");
	assert(linkedList.Size == 1);

	test_int(sizeof(float), linkedList.SizeOfSingleElement, "LinkedList Add Test: SizeOfSingleElement");
	assert(linkedList.SizeOfSingleElement == sizeof(float));

	float value = *(float*)linkedList.FirstNode->ElementCurrent;

	assert(value == x);

	LinkedListClear(&linkedList);
}

void LinkedListAddMultipleElementsTest()
{
	LinkedList linkedList;

	LinkedListInitialize(&linkedList, sizeof(int));

	int data[] = {10,20,30,40,50,60};

	LinkedListAddToEnd(&linkedList, &data[0]);
	LinkedListAddToEnd(&linkedList, &data[1]);
	LinkedListAddToEnd(&linkedList, &data[2]);
	LinkedListAddToEnd(&linkedList, &data[3]);
	LinkedListAddToEnd(&linkedList, &data[4]);
	LinkedListAddToEnd(&linkedList, &data[5]);

	test_int(6, linkedList.Size, "LinkedList Add Test: Size");
	assert(linkedList.Size == 6);
	
	test_int(sizeof(int), linkedList.SizeOfSingleElement, "LinkedList AddMultipleElements Test: SizeOfSingleElement");
	assert(linkedList.SizeOfSingleElement == sizeof(int));

	int extractedData[6];

	LinkedListGetElement(&linkedList, 0, &extractedData[0]);
	LinkedListGetElement(&linkedList, 1, &extractedData[1]);
	LinkedListGetElement(&linkedList, 2, &extractedData[2]);
	LinkedListGetElement(&linkedList, 3, &extractedData[3]);
	LinkedListGetElement(&linkedList, 4, &extractedData[4]);
	LinkedListGetElement(&linkedList, 5, &extractedData[5]);

	test_int(10, extractedData[0], "LinkedList AddMultipleElements Test: GetElement 1");
	assert(extractedData[0] == 10);
	assert(extractedData[1] == 20);
	assert(extractedData[2] == 30);
	assert(extractedData[3] == 40);
	assert(extractedData[4] == 50);
	test_int(60, extractedData[5], "LinkedList AddMultipleElements Test: GetElement 2");
	assert(extractedData[5] == 60);

	LinkedListClear(&linkedList);
}

void LinkedListRemoveAllElementsTest()
{	
	LinkedList linkedList;
	CollectionError collectionError;
	
	LinkedListInitialize(&linkedList, sizeof(int));

	int data[] = { 10,20,30,40,50,60 };

	
	collectionError = LinkedListAddToEnd(&linkedList, &data[0]);
	test_collectionError(CollectionNoError, collectionError, "LinkedList Test: Add Element");
	
	LinkedListAddToEnd(&linkedList, &data[1]);
	LinkedListAddToEnd(&linkedList, &data[4]);
	LinkedListAddToEnd(&linkedList, &data[5]);

	//LinkedListPrintContent(&linkedList);

	collectionError = LinkedListInsert(&linkedList, 2, &data[2]);
	test_collectionError(CollectionNoError, collectionError, "LinkedList Test: Insert Element");
	
	//LinkedListPrintContent(&linkedList);

	LinkedListInsert(&linkedList, 3, &data[3]);

	//LinkedListPrintContent(&linkedList);

	test_int(6, linkedList.Size, "LinkedList Test: Size");
	assert(linkedList.Size == 6);
	test_int(sizeof(int), linkedList.SizeOfSingleElement, "LinkedList Test: SizeOfSingleElement");
	assert(linkedList.SizeOfSingleElement == sizeof(int));

	int extractedData[6];

	LinkedListGetElement(&linkedList, 0, &extractedData[0]);
	LinkedListGetElement(&linkedList, 1, &extractedData[1]);
	LinkedListGetElement(&linkedList, 2, &extractedData[2]);
	LinkedListGetElement(&linkedList, 3, &extractedData[3]);
	LinkedListGetElement(&linkedList, 4, &extractedData[4]);
	LinkedListGetElement(&linkedList, 5, &extractedData[5]);

	test_int(10, extractedData[0], "LinkedList Test: Get Element");
	assert(extractedData[0] == 10);
	assert(extractedData[1] == 20);
	assert(extractedData[2] == 30);
	assert(extractedData[3] == 40);
	assert(extractedData[4] == 50);
	test_int(60, extractedData[5], "LinkedList Test: Get Element 2");
	assert(extractedData[5] == 60);

	LinkedListClear(&linkedList);
}

void LinkedListPrintContent(LinkedList* linkedList)
{
	LinkedListNode* linkedListNode = linkedList->FirstNode;
	unsigned int index = 0;

	printf("---[content]---\n");

	while (linkedListNode)
	{
		printf("[%i] %p (%i) -> %p\n", ++index, linkedListNode, *(int*)linkedListNode->ElementCurrent, linkedListNode->ElementNext);

		linkedListNode = linkedListNode->ElementNext;
	}

	printf("---------------\n");
}

void LinkedListMemoryLeakTest()
{
	while (1)
	{
		LinkedList linkedList;
		CollectionError collectionError;

		LinkedListInitialize(&linkedList, sizeof(int));

		int data[] = { 10,20,30,40,50,60 };


		collectionError = LinkedListAddToEnd(&linkedList, &data[0]);
		test_collectionError(CollectionNoError, collectionError, "LinkedList Test: Add Element");

		LinkedListAddToEnd(&linkedList, &data[1]);
		LinkedListAddToEnd(&linkedList, &data[4]);
		LinkedListAddToEnd(&linkedList, &data[5]);

		//LinkedListPrintContent(&linkedList);

		collectionError = LinkedListInsert(&linkedList, 2, &data[2]);
		test_collectionError(CollectionNoError, collectionError, "LinkedList Test: Insert Element");

		//LinkedListPrintContent(&linkedList);

		LinkedListInsert(&linkedList, 3, &data[3]);

		//LinkedListPrintContent(&linkedList);

		test_int(6, linkedList.Size, "LinkedList Test: Size");
		assert(linkedList.Size == 6);
		test_int(sizeof(int), linkedList.SizeOfSingleElement, "LinkedList Test: SizeOfSingleElement");
		assert(linkedList.SizeOfSingleElement == sizeof(int));

		int extractedData[6];

		LinkedListGetElement(&linkedList, 0, &extractedData[0]);
		LinkedListGetElement(&linkedList, 1, &extractedData[1]);
		LinkedListGetElement(&linkedList, 2, &extractedData[2]);
		LinkedListGetElement(&linkedList, 3, &extractedData[3]);
		LinkedListGetElement(&linkedList, 4, &extractedData[4]);
		LinkedListGetElement(&linkedList, 5, &extractedData[5]);

		test_int(10, extractedData[0], "LinkedList Test: Get Element");
		assert(extractedData[0] == 10);
		assert(extractedData[1] == 20);
		assert(extractedData[2] == 30);
		assert(extractedData[3] == 40);
		assert(extractedData[4] == 50);
		test_int(60, extractedData[5], "LinkedList Test: Get Element 2");
		assert(extractedData[5] == 60);

		LinkedListClear(&linkedList);
	}
}