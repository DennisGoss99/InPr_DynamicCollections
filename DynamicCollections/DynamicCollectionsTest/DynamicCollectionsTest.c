#include <stdio.h>

#include "ListTest.h"
#include "StackTest.h"
#include "QueueTest.h"
#include "DictionaryTest.h"
#include "TestSystem/Tester.h"


int main()
{
    testPrintHeader("-----<Starting Tests>-----");

    StackTestStart();
    QueueTestStart();

    ListTestStart();

    DictionaryTestStart();
	
    testPrintSummery();
    
    return 0;
}