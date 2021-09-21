#include <stdio.h>

#include "ListTest.h"
#include "StackTest.h"
#include "QueueTest.h"
#include "LinkedListTest.h"
#include "DictionaryTest.h"
#include "StringTest.h"
#include "TestSystem/Tester.h"

#define DEBUG_RepeatTestProgramForever 0

int main()
{

#if DEBUG_RepeatTestProgramForever
    while (1)
    {
#endif

        testPrintHeader("-----<Starting Tests>-----");

        StackTestStart();
        QueueTestStart();
        LinkedListTestStart();

        ListTestStart();

        DictionaryTestStart();

        StringTestStart();

        testPrintSummery();

#if DEBUG_RepeatTestProgramForever
    }
#endif
    
    return 0;
}