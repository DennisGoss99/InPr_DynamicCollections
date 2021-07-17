#include "CollectionTester.h"


void test_collectionError(CollectionError expectedInput, CollectionError input, char* name)
{
	test_string(CollectionErrorToString(expectedInput), CollectionErrorToString(input), name);
}
void test_collectionError_Failure(CollectionError expectedInput, CollectionError input, char* name)
{
	test_string_Failure(CollectionErrorToString(expectedInput), CollectionErrorToString(input), name);
}