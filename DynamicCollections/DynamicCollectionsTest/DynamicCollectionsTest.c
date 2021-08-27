#include <stdio.h>

#include "ListTest.h"
#include "StackTest.h"
#include "QueueTest.h"
#include "LinkedListTest.h"
#include "DictionaryTest.h"
#include "TestSystem/Tester.h"


int main()
{
    testPrintHeader("-----<Starting Tests>-----");

    StackTestStart();
    QueueTestStart();
    LinkedListTestStart();

    ListTestStart(); 

    DictionaryTestStart();
	
    testPrintSummery();
    
    return 0;
}