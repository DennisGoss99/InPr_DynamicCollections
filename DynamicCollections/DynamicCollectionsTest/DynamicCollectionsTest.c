#include <stdio.h>

#include "ListTest.h"
#include "../DynamicCollections/BaseContainer/List.h"
#include "StackTest.h"
#include "QueueTest.h"
#include "TestSystem/Tester.h"


int main()
{
    testPrintHeader("-----<Starting Tests>-----");

    StackTestStart();
    QueueTestStart();

    ListTestStart();
	
    testPrintSummery();
    
    return 0;
}