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

	Dictionary test;

	DictionaryInitialize(&test, sizeof(int), sizeof(char*));

	char* outputAddress;
	 
	int testInt1 = 2;
	int testInt2 = 5;
	int testInt3 = 99;
	int testInt4 = 1;
	int testInt5 = 0;

	test_collectionError(CollectionNoError, DictionaryAdd(&test, &testInt1, "a"), "Dictionary Test 1");

	test_collectionError(CollectionNoError, DictionaryGet(&test, &testInt1, &outputAddress), "Dictionary Test 2");
	
	if(DictionaryGet(&test, &testInt1, &outputAddress) == CollectionNoError)
		test_string("a", outputAddress, "Dictionary Test 2");

	test_collectionError(CollectionArrayIndexOutOfBounds, DictionaryGet(&test, &testInt2, &outputAddress), "Dictionary Test 3");

	test_collectionError(CollectionKeyAlreadyExists, DictionaryAdd(&test, &testInt1, "test"), "Dictionary Test 4");

	DictionaryAdd(&test, &testInt2, "bbb");
	DictionaryAdd(&test, &testInt3, "c");
	DictionaryAdd(&test, &testInt4, "bbbbbb");
	
	test_collectionError(CollectionNoError, DictionaryGet(&test, &testInt4,&outputAddress), "Dictionary Test 5");

	if (DictionaryGet(&test, &testInt4, &outputAddress) == CollectionNoError)
		test_string("bbbbbb", outputAddress, "Dictionary Test 5");

	test_int( 1, DictionaryContainsKey(&test, &testInt4), "Dictionary Test 6");
	test_int(0, DictionaryContainsKey(&test, &testInt5), "Dictionary Test 7");
	
	DictionaryDestroy(&test);	
}