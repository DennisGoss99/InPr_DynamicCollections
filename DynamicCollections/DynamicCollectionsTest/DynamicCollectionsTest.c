#include <stdio.h>

#include "ListTest.h"
#include "../DynamicCollections/BaseContainer/List.h"
#include "StackTest.h"
#include "TestSystem/Tester.h"


int main()
{
    testPrintHeader("-----<Starting Tests>-----");

    StackTestStart();

    ListTestStart();
	
    testPrintSummery();
    
    return 0;
}