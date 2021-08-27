#include "LinkedListTest.h"

#include <assert.h>

void LinkedListTestStart()
{
	LinkedListAddElementTest();
	LinkedListAddMultibleElementsTest();
	LinkedListRemoveAllElementsTest();
}

void LinkedListAddElementTest()
{
	LinkedList linkedList;

	LinkedListInitialize(&linkedList, sizeof(float));

	float x = 42.69;

	LinkedListAddToEnd(&linkedList, &x);

	assert(linkedList.FirstNode != 0);
	assert(linkedList.Size == 1);
	assert(linkedList.SizeOfSingleElement == sizeof(float));

	float value = *(float*)linkedList.FirstNode->ElementCurrent;

	assert(value == x);
}

void LinkedListAddMultibleElementsTest()
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

	assert(linkedList.Size == 6);
	assert(linkedList.SizeOfSingleElement == sizeof(int));

	int extractedData[6];

	LinkedListGetElement(&linkedList, 0, &extractedData[0]);
	LinkedListGetElement(&linkedList, 1, &extractedData[1]);
	LinkedListGetElement(&linkedList, 2, &extractedData[2]);
	LinkedListGetElement(&linkedList, 3, &extractedData[3]);
	LinkedListGetElement(&linkedList, 4, &extractedData[4]);
	LinkedListGetElement(&linkedList, 5, &extractedData[5]);

	assert(extractedData[0] == 10);
	assert(extractedData[1] == 20);
	assert(extractedData[2] == 30);
	assert(extractedData[3] == 40);
	assert(extractedData[4] == 50);
	assert(extractedData[5] == 60);

	LinkedListClear(&linkedList);
}

void LinkedListRemoveAllElementsTest()
{
	
	LinkedList linkedList;

	LinkedListInitialize(&linkedList, sizeof(int));

	int data[] = { 10,20,30,40,50,60 };

	LinkedListAddToEnd(&linkedList, &data[0]);
	LinkedListAddToEnd(&linkedList, &data[1]);
	LinkedListAddToEnd(&linkedList, &data[4]);
	LinkedListAddToEnd(&linkedList, &data[5]);

	LinkedListPrintContent(&linkedList);

	LinkedListInsert(&linkedList, 2, &data[2]);

	LinkedListPrintContent(&linkedList);

	LinkedListInsert(&linkedList, 3, &data[3]);

	LinkedListPrintContent(&linkedList);

	assert(linkedList.Size == 6);
	assert(linkedList.SizeOfSingleElement == sizeof(int));

	int extractedData[6];

	LinkedListGetElement(&linkedList, 0, &extractedData[0]);
	LinkedListGetElement(&linkedList, 1, &extractedData[1]);
	LinkedListGetElement(&linkedList, 2, &extractedData[2]);
	LinkedListGetElement(&linkedList, 3, &extractedData[3]);
	LinkedListGetElement(&linkedList, 4, &extractedData[4]);
	LinkedListGetElement(&linkedList, 5, &extractedData[5]);

	assert(extractedData[0] == 10);
	assert(extractedData[1] == 20);
	assert(extractedData[2] == 30);
	assert(extractedData[3] == 40);
	assert(extractedData[4] == 50);
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