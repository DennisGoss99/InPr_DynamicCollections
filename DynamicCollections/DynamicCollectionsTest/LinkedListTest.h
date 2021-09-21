#ifndef LinkedListTestInclude
#define LinkedListTestInclude

#include "../DynamicCollections/BaseContainer/LinkedList.h"

void LinkedListTestStart();
static void LinkedListAddElementTest();
static void LinkedListAddMultipleElementsTest();
static void LinkedListRemoveAllElementsTest();
static void LinkedListPrintContent(LinkedList* linkedList);
static void LinkedListMemoryLeakTest();

#endif