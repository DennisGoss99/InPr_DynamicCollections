#include "Tester.h"

#include <stdio.h>
#include <stdlib.h>

void testPrintHeader(char* headerContent)
{
	printf("\n\n\n -----------------------------------------------\n");
	printf(" - %s\n", headerContent);
	printf(" -----------------------------------------------\n");
}

void testPrintSummery()
{
	printf("\n\n");

	printf(" ------ <Summery> ---------------------------\n");
	printf(" - Tests Failed     : %i\n", testFailedCount);
	printf(" - Tests Successful : %i\n", (testCount - testFailedCount));
	printf(" --------------------------------------------\n");
}

void testPrint(char result, char* expectedInputAsString, char* inputAsString, char* dataType, char* name)
{
	testCount++;


	if (result){
		printf("\n\n  [OK]");
		printf("     +---- Test [%s] [%s] -----------------\n", name, dataType);
		printf("           | Test completed: -Input '%s', '%s'\n", inputAsString, expectedInputAsString);
		printf("           +-----------------------------------------------------------------\n");
	}
	else
	{
		printf("\n\n  [FAILED]");
		printf(" +---- Test [%s] [%s] ----------------\n", name, dataType);
		printf("           | Test failed:\n");
		printf("           |       -Expected input '%s', actual '%s'\n", expectedInputAsString, inputAsString);
		printf("           +------------------------------------------------------------------\n");
		testFailedCount++;
	}


	
}
void testPrint_int(char result, int expectedInput, int input, char* dataType, char* name)
{
	testCount++;

	

	if (result) {
		printf("\n\n  [OK]");
		printf("     +---- Test [%s] [%s] ----------------\n", name, dataType);
		printf("           | Test completed: -Input '%i', '%i'\n", input, expectedInput);
		printf("           +-----------------------------------------------------------------\n");
	}
	else
	{
		printf("\n\n  [FAILED]");
		printf(" +---- Test [%s] [%s] ---------------------\n", name, dataType);
		printf("           | Test failed:\n");
		printf("           |       -Expected input '%i', actual '%i'\n", expectedInput, input);
		printf("           +-----------------------------------------------------------------\n");
		testFailedCount++;
	}

}


void test_int(int expectedInput, int input, char* name)
{
	testPrint_int((expectedInput == input), expectedInput, input, "INT", name);
}
void test_int_Failure(int expectedInput, int input, char* name)
{
	testPrint_int((expectedInput != input), expectedInput, input, "INT", name);
}



/*
Summery: Are strings equal?
 Returns: bool*/
static char testRaw_string(char* expectedInput, char* input)
{
	if (!(expectedInput == NULL && input == NULL))
	{
		if (expectedInput == NULL || input == NULL)
			return 0;

		const unsigned int fullPathLength = (strlen(expectedInput) > strlen(input)) ? strlen(expectedInput) : strlen(input);
		if (memcmp(expectedInput, input, sizeof(char) * fullPathLength) != 0)
			return 0;
		else
			return 1;
	}

	return 1;
}

void test_string(char* expectedInput, char* input, char* name)
{
	testPrint(testRaw_string(expectedInput, input), (char*)expectedInput, (char*)input, "String", name);
}
void test_string_Failure(char* expectedInput, char* input, char* name)
{
	testPrint(testRaw_string(expectedInput, input) == 0, (char*)expectedInput, (char*)input, "String", name);
}


/*
Summery: Are Inputs equal?
 Returns: bool*/
static char testRaw_t(void* expectedInput, void* input, size_t typeSize)
{
	if (!(expectedInput == NULL && input == NULL))
	{
		if (expectedInput == NULL || input == NULL)
			return 0;

		if (memcmp(expectedInput, input, typeSize) != 0)
			return 0;
		else
			return 1;
	}

	return 1;
}

void test_t(void* expectedInput, void* input, size_t typeSize, char* dataType, char* name)
{
	testPrint(testRaw_t(expectedInput, input, typeSize), (char*)expectedInput, (char*)input, dataType, name);
}
void test_t_Failure(void* expectedInput, void* input, size_t typeSize, char* dataType, char* name)
{
	testPrint(testRaw_t(expectedInput, input, typeSize) == 0, (char*)expectedInput, (char*)input, dataType, name);
}