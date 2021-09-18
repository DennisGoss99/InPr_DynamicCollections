#include "DictionaryTest.h"

#include <stdio.h>
#include <stdlib.h>

#include "../DynamicCollections/BaseContainer/Dictionary.h"
#include "../DynamicCollections/BaseContainer/Dictionary.c"

#include "TestSystem/Tester.h"
#include "TestSystem/CollectionTester.h"

void DictionaryTests();



void DictionaryTestStart()
{
	testPrintHeader("-----<Testing Dictionary.h>-----");

	DictionaryTests();

}

void DictionaryTests() {
	
	{
		Dictionary test;

		DictionaryInitialize(&test, sizeof(int), sizeof(char*));

		char* outputAddress;
	 
		int testInt1 = 2;
		int testInt2 = 5;
		int testInt3 = 99;
		int testInt4 = 1;
		int testInt5 = 0;

		test_collectionError(CollectionNoError, DictionaryAdd(&test, &testInt1, "a"), "Dictionary Add Test 1");

		test_collectionError(CollectionNoError, DictionaryGet(&test, &testInt1, &outputAddress), "Dictionary Add Test 2");
	
		if(DictionaryGet(&test, &testInt1, &outputAddress) == CollectionNoError)
			test_string("a", outputAddress, "Dictionary Add Test 2");

		test_collectionError(CollectionArrayIndexOutOfBounds, DictionaryGet(&test, &testInt2, &outputAddress), "Dictionary Add Test 3");

		test_collectionError(CollectionKeyAlreadyExists, DictionaryAdd(&test, &testInt1, "test"), "Dictionary Add Test 4");

		DictionaryAdd(&test, &testInt2, "bbb");
		DictionaryAdd(&test, &testInt3, "c");
		DictionaryAdd(&test, &testInt4, "bbbbbb");
	
		test_collectionError(CollectionNoError, DictionaryGet(&test, &testInt4,&outputAddress), "Dictionary Add Test 5");

		if (DictionaryGet(&test, &testInt4, &outputAddress) == CollectionNoError)
			test_string("bbbbbb", outputAddress, "Dictionary Add Test 5");

		test_int( 1, DictionaryContainsKey(&test, &testInt4), "Dictionary Add Test 6");
		test_int(0, DictionaryContainsKey(&test, &testInt5), "Dictionary Add Test 7");
	
		DictionaryDestruction(&test);
	}
	

	{
		Dictionary test;

		DictionaryInitialize(&test, sizeof(int), sizeof(int));

		int testInt1 = 10;
		int testInt2 = 19;
		int testInt3 = 13;
		int testInt4 = 11;
		int testInt5 = 12;
		int testInt6 = 5;
		int testInt7 = 4;
		int testInt8 = 3;
		int testInt9 = 6;
		int testInt10 = 20;
		int testInt11 = 7;

		size_t outputAddress;

		DictionaryAdd(&test, &testInt1, 10);
		DictionaryAdd(&test, &testInt2, 19);
		DictionaryAdd(&test, &testInt3, 13);
		DictionaryAdd(&test, &testInt4, 11);
		DictionaryAdd(&test, &testInt5, 12);
		DictionaryAdd(&test, &testInt6, 5);
		DictionaryAdd(&test, &testInt7, 4);
		DictionaryAdd(&test, &testInt8, 3);
		DictionaryAdd(&test, &testInt9, 6);
		DictionaryAdd(&test, &testInt10, 20);
		DictionaryAdd(&test, &testInt11, 7);

		//has no Child
		test_collectionError(CollectionNoError, DictionaryRemove(&test, &testInt8), "Dictionary Remove Test 1");
		test_collectionError(CollectionArrayIndexOutOfBounds, DictionaryGet(&test, &testInt8, &outputAddress), "Dictionary Remove Test 2");

		DictionaryAdd(&test, &testInt8, 3);
		test_collectionError(CollectionNoError, DictionaryGet(&test, &testInt8, &outputAddress), "Dictionary Remove Test 3");

		//has one Child
		test_collectionError(CollectionNoError, DictionaryRemove(&test, &testInt9), "Dictionary Remove Test 4");
		test_collectionError(CollectionNoError, DictionaryRemove(&test, &testInt7), "Dictionary Remove Test 5");

		//has two Children
		test_collectionError(CollectionNoError, DictionaryRemove(&test, &testInt6), "Dictionary Remove Test 6");

		test_collectionError(CollectionNoError, DictionaryRemove(&test, &testInt1), "Dictionary Remove Test 7");

		test_collectionError(CollectionArrayIndexOutOfBounds, DictionaryGet(&test, &testInt1, &outputAddress), "Dictionary Remove Test 8");

		test_collectionError(CollectionNoError, DictionaryRemove(&test, &testInt2), "Dictionary Remove Test 8");

		DictionaryRemove(&test, &testInt5);
		DictionaryRemove(&test, &testInt4);
		DictionaryRemove(&test, &testInt11);
		DictionaryRemove(&test, &testInt3);
		DictionaryRemove(&test, &testInt10);
		DictionaryRemove(&test, &testInt8);

		test_int(0, test.Size, "Dictionary Remove Test 9");

		DictionaryDestruction(&test);
	}
}