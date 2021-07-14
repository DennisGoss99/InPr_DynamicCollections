#pragma once

#include "../../DynamicCollections/BaseContainer/CollectionError.h"

#include <stddef.h>
#include <string.h>

#ifndef TesterInclude
#define TesterInclude

int testCount;
int testFailedCount;

void testPrintSummery();
void testPrintHeader(char* headerContent);

void testPrint(char result, char* expectedInputAsString, char* inputAsString, char* dataType, char* name);
void testPrint_int(char result, int expectedInput, int input, char* dataType, char* name);

void test_int(int expectedInput, int input, char* name);
void test_int_Failure(int expectedInput, int input, char* name);

void test_string(char* expectedInput, char* input, char* name);
void test_string_Failure(char* expectedInput, char* input, char* name);

void test_t(void* expectedInput, void* input, size_t typeSize, char* dataType, char* name);
void test_t_Failure(void* expectedInput, void* input, size_t typeSize, char* dataType, char* name);

#endif