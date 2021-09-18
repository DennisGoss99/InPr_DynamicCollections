#include <stdio.h>

#include "ListTest.h"
#include "StackTest.h"
#include "QueueTest.h"
#include "LinkedListTest.h"
#include "DictionaryTest.h"
#include "StringTest.h"
#include "TestSystem/Tester.h"


int main()
{
    testPrintHeader("-----<Starting Tests>-----");
	     
    StackTestStart();
    QueueTestStart();
    LinkedListTestStart();
    
    ListTestStart(); 

    DictionaryTestStart();

    StringTestStart();
	
    testPrintSummery();
    
    return 0;
}