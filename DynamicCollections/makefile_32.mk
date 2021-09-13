#---<TEST-System>--------------------------------------------------------------
DynamicCollectionsTest.run: DynamicCollectionsTest.o  Tester.o CollectionTester.o DictionaryTest.o LinkedListTest.o ListTest.o QueueTest.o StackTest.o String.o StringTest.o GeneralContainer.lib
	gcc -m32 bin/DynamicCollectionsTest.o bin/Tester.o bin/CollectionTester.o bin/DictionaryTest.o bin/LinkedListTest.o bin/ListTest.o bin/QueueTest.o bin/StackTest.o bin/String.o bin/StringTest.o bin/GeneralContainer.lib -o DynamicCollectionsTest.run


DynamicCollectionsTest.o: DynamicCollectionsTest/DynamicCollectionsTest.c
	gcc -m32 -c DynamicCollectionsTest/DynamicCollectionsTest.c -o bin/DynamicCollectionsTest.o

Tester.o: DynamicCollectionsTest/TestSystem/Tester.c
	gcc -m32 -c DynamicCollectionsTest/TestSystem/Tester.c -o bin/Tester.o

CollectionTester.o: DynamicCollectionsTest/TestSystem/CollectionTester.c
	gcc -m32 -c DynamicCollectionsTest/TestSystem/CollectionTester.c  -o bin/CollectionTester.o



DictionaryTest.o: DynamicCollectionsTest/DictionaryTest.c
	gcc -m32 -c DynamicCollectionsTest/DictionaryTest.c  -o bin/DictionaryTest.o

LinkedListTest.o: DynamicCollectionsTest/LinkedListTest.c
	gcc -m32 -c DynamicCollectionsTest/LinkedListTest.c  -o bin/LinkedListTest.o

ListTest.o: DynamicCollectionsTest/ListTest.c
	gcc -m32 -c DynamicCollectionsTest/ListTest.c -o bin/ListTest.o

QueueTest.o: DynamicCollectionsTest/QueueTest.c
	gcc -m32 -c DynamicCollectionsTest/QueueTest.c  -o bin/QueueTest.o

StackTest.o: DynamicCollectionsTest/StackTest.c
	gcc -m32 -c DynamicCollectionsTest/StackTest.c  -o bin/StackTest.o

StringTest.o: DynamicCollectionsTest/StringTest.c
	gcc -m32 -c DynamicCollectionsTest/StringTest.c  -o bin/StringTest.o

#---<General Container>--------------------------------------------------------
GeneralContainer.lib: CollectionError.o Dictionary.o LinkedListNode.o LinkedList.o  List.o Queue.o Stack.o
	ar rcs bin/GeneralContainer.lib bin/CollectionError.o bin/Dictionary.o bin/LinkedListNode.o bin/LinkedList.o bin/List.o bin/Queue.o bin/Stack.o

CollectionError.o: DynamicCollections/BaseContainer/CollectionError.c
	gcc -m32 -c DynamicCollections/BaseContainer/CollectionError.c -o bin/CollectionError.o

Dictionary.o: DynamicCollections/BaseContainer/Dictionary.c
	gcc -m32 -c DynamicCollections/BaseContainer/Dictionary.c -o bin/Dictionary.o

LinkedListNode.o: DynamicCollections/BaseContainer/LinkedListNode.c
	gcc -m32 -c DynamicCollections/BaseContainer/LinkedListNode.c -o bin/LinkedListNode.o

LinkedList.o: DynamicCollections/BaseContainer/LinkedList.c
	gcc -m32 -c DynamicCollections/BaseContainer/LinkedList.c -o bin/LinkedList.o

List.o: DynamicCollections/BaseContainer/List.c
	gcc -m32 -c DynamicCollections/BaseContainer/List.c -o bin/List.o

Queue.o: DynamicCollections/BaseContainer/Queue.c
	gcc -m32 -c DynamicCollections/BaseContainer/Queue.c -o bin/Queue.o

Stack.o: DynamicCollections/BaseContainer/Stack.c
	gcc -m32 -c DynamicCollections/BaseContainer/Stack.c  -o bin/Stack.o
#------------------------------------------------------------------------------

String.o: DynamicCollections/GeneralContainer/String.c
	gcc -m32 -c DynamicCollections/GeneralContainer/String.c  -o bin/String.o

