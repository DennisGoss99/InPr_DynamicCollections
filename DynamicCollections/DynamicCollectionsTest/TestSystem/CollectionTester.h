#pragma once
#include "Tester.h"

#ifndef TesterInclude
#define TesterInclude

void test_collectionError(CollectionError expectedInput, CollectionError input, char* name);
void test_collectionError_Failure(CollectionError expectedInput, CollectionError input, char* name);

#endif