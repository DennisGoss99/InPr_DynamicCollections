#include "ListTest.h"

#include <stdlib.h>

#include "../DynamicCollections/BaseContainer/List.h"

#include "TestSystem/Tester.h"

void ListTests();

void ListTestStart()
{
	testPrintHeader("-----<Testing List.h>-----");

	ListTests();
	
}

void ListTests()
{

	List a = EMPTYLIST;
	List b = EMPTYLIST;
	List c = EMPTYLIST;
		
	
	// Test: 1 [char*]

	ListInitialize(&a, 3, sizeof(char*));
	
	char* outputChar;

	
	char* testChar1 = calloc(2, sizeof(char));
	memcpy(testChar1, "a", 1 * sizeof(char));

	char* testChar2 = calloc(4, sizeof(char));
	memcpy(testChar2, "bbb", 3 * sizeof(char));

	char* testChar3 = calloc(2, sizeof(char));
	memcpy(testChar3, "c", 1 * sizeof(char));

	ListItemInsertAt(&a, 0, testChar1);
	ListItemInsertAt(&a, 2, testChar2);

	ListItemGet(&a, 0, &outputChar);
	test_string("a", outputChar, "List Test 1");

	ListItemAdd(&a, testChar3);


	ListItemGet(&a, 3, &outputChar);
	test_string(NULL, outputChar, "List Test 2");
	
	ListItemGet(&a, 2, &outputChar);
	test_string("bbb", outputChar, "List Test 3");

	ListItemGet(&a, 1, &outputChar);
	test_string("c", outputChar, "List Test 4");
	
	
	ListDestruction(&a);

	
	// Test: 2 [int]
	ListInitialize(&b, 2, sizeof(int*));

	int* outputInt;
	
	int* testInt1 = calloc(1, sizeof(int*));
	*testInt1 = 12321;

	int* testInt2 = calloc(1, sizeof(int*));
	*testInt2 = 5;

	int* testInt3 = calloc(1, sizeof(int*));
	*testInt3 = 54;

	ListItemAdd(&b, testInt1);
	ListItemAdd(&b, testInt2);
	ListItemAdd(&b, testInt3);

	ListItemGet(&b, 0, &outputInt);
	test_int(12321, *outputInt , "List Test 5");
	
	ListItemGet(&b, 1, &outputInt);
	test_int(5, *outputInt, "List Test 6");

	ListItemGet(&b, 2, &outputInt);
	test_int(54, *outputInt, "List Test 7");

	ListItemGet(&b, 3, &outputInt);
	test_int(NULL, outputInt, "List Test 8");

	ListItemGet(&b, 4, &outputInt);
	test_int(NULL, outputInt, "List Test 9");
	
	ListDestruction(&b);
	
	// Test: 3 (add 150 Int)[int]

	ListInitialize(&c, 2, sizeof(int*));

	
	for (int i = 0; i < 150; ++i)
	{
		int* testIntX = calloc(1, sizeof(int));
		*testIntX = 54;
		ListItemAdd(&c, testIntX);
	}

	int* testInt4 = calloc(1, sizeof(int));
	*testInt4 = 99;

	ListItemInsertAt(&c, 150, testInt4);

	int* testInt5 = calloc(1, sizeof(int));
	*testInt5 = 54;
	ListItemAdd(&c, testInt5);

	ListItemGet(&c, 150, &outputInt);
	test_int(99, *outputInt, "List Test 10");

	ListItemGet(&c, 151, &outputInt);
	test_int(54, *outputInt, "List Test 11");

	ListDestruction(&c);

	// Test: 4 Remove an Clear[int]

	b = EMPTYLIST;

	ListInitialize(&b, 2, sizeof(int*));

	int* testInt6 = calloc(1, sizeof(int));
	*testInt6 = 44;

	int* testInt7 = calloc(1, sizeof(int));
	*testInt7 = 55;

	int* testInt8 = calloc(1, sizeof(int));
	*testInt8 = 56;

	int* testInt9 = calloc(1, sizeof(int));
	*testInt9 = 57;

	int* testInt10 = calloc(1, sizeof(int));
	*testInt10 = 58;

	ListItemAdd(&b, testInt6);
	ListItemAdd(&b, testInt7);
	ListItemAdd(&b, testInt8);
	ListItemAdd(&b, testInt9);
	ListItemAdd(&b, testInt10);


	ListItemGet(&b, 3, &outputInt);
	test_int(57, *outputInt, "List Test 13");

	ListItemRemove(&b, 3);

	ListItemGet(&b, 3, &outputInt);
	test_int(NULL, outputInt, "List Test 14");

	ListClear(&b);

	ListItemGet(&b, 0, &outputInt);
	test_int(NULL, outputInt, "List Test 15");
	
	ListItemGet(&b, 4, &outputInt);
	test_int(NULL, outputInt, "List Test 16");

	ListDestruction(&b);
	
}