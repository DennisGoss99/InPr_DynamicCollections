#include <stdio.h>

#include "../DynamicCollections/BaseContainer/List.h"
#include "StackTest.h"
#include "TestSystem/Tester.h"


int main()
{
    testPrintHeader("-----<Starting Tests>-----");

    StackTestStart();

    testPrintSummery();
    
    return 0;
}