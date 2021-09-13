#include "StringTest.h"

#include <stdio.h>
#include <stdlib.h>

#include "TestSystem/Tester.h"
#include "TestSystem/CollectionTester.h"
#include "../DynamicCollections/BaseContainer/List.h"
#include "../DynamicCollections/GeneralContainer/String.h"

void StringTests();

void StringTestStart()
{
	testPrintHeader("-----<Testing String.h>-----");
	StringTests();
}

void StringTests()
{	
	
	String testString = EMPTYSTRING;
	char* outputChar;
	
	char* testChar2 = calloc(12, sizeof(char));
	memcpy(testChar2, "Test String", 11 * sizeof(char));

	
	StringInitialize(&testString, testChar2);

	StringCharGet(&testString, 3, &outputChar);
	test_int('t', outputChar, "String test: Get");

	StringCharGet(&testString, 10, &outputChar);
	test_int('g', outputChar, "String test: Get 2");

	test_collectionError(CollectionNoError, StringCharAdd(&testString, '!'), "String test: Add 1");
	
	StringCharGet(&testString, 11, &outputChar);
	test_int('!', outputChar, "String test: Get 3");

	StringCharGet(&testString, 2, &outputChar);
	test_int('s', outputChar, "String test: Get 4");

	test_int(12, testString.Count, "String test: String Count");
	
	StringConcat(&testString, "TEST");

	StringCharGet(&testString, 15, &outputChar);
	test_int('T', outputChar, "String test: Get 5");
	
	outputChar = StringGetFullString(&testString);

	test_string("Test String!TEST", outputChar, "String test: Add Full String");
	
	free(outputChar);
	
	StringDestruction(&testString);
		
	free(testChar2);
			
}