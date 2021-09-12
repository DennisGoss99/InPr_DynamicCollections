#---<TEST-System>--------------------------------------------------------------
DynamicCollectionsTest.run: DynamicCollectionsTest.o  Tester.o CollectionTester.o DictionaryTest.o LinkedListTest.o ListTest.o QueueTest.o StackTest.o GeneralContainer.lib
	gcc bin/DynamicCollectionsTest.o bin/Tester.o bin/CollectionTester.o bin/DictionaryTest.o bin/LinkedListTest.o bin/ListTest.o bin/QueueTest.o bin/StackTest.o bin/GeneralContainer.lib -o DynamicCollectionsTest.run


DynamicCollectionsTest.o: DynamicCollectionsTest/DynamicCollectionsTest.c
	gcc -c DynamicCollectionsTest/DynamicCollectionsTest.c -o bin/DynamicCollectionsTest.o

Tester.o: DynamicCollectionsTest/TestSystem/Tester.c
	gcc -c DynamicCollectionsTest/TestSystem/Tester.c -o bin/Tester.o

CollectionTester.o: DynamicCollectionsTest/TestSystem/CollectionTester.c
	gcc -c DynamicCollectionsTest/TestSystem/CollectionTester.c  -o bin/CollectionTester.o



DictionaryTest.o: DynamicCollectionsTest/DictionaryTest.c
	gcc -c DynamicCollectionsTest/DictionaryTest.c  -o bin/DictionaryTest.o

LinkedListTest.o: DynamicCollectionsTest/LinkedListTest.c
	gcc -c DynamicCollectionsTest/LinkedListTest.c  -o bin/LinkedListTest.o

ListTest.o: DynamicCollectionsTest/ListTest.c
	gcc -c DynamicCollectionsTest/ListTest.c -o bin/ListTest.o

QueueTest.o: DynamicCollectionsTest/QueueTest.c
	gcc -c DynamicCollectionsTest/QueueTest.c  -o bin/QueueTest.o

StackTest.o: DynamicCollectionsTest/StackTest.c
	gcc -c DynamicCollectionsTest/StackTest.c  -o bin/StackTest.o


#---<General Container>--------------------------------------------------------
GeneralContainer.lib: CollectionError.o Dictionary.o LinkedListNode.o LinkedList.o  List.o Queue.o Stack.o
	ar rcs bin/GeneralContainer.lib bin/CollectionError.o bin/Dictionary.o bin/LinkedListNode.o bin/LinkedList.o bin/List.o bin/Queue.o bin/Stack.o

CollectionError.o: DynamicCollections/BaseContainer/CollectionError.c
	gcc -c DynamicCollections/BaseContainer/CollectionError.c -o bin/CollectionError.o

Dictionary.o: DynamicCollections/BaseContainer/Dictionary.c
	gcc -c DynamicCollections/BaseContainer/Dictionary.c -o bin/Dictionary.o

LinkedListNode.o: DynamicCollections/BaseContainer/LinkedListNode.c
	gcc -c DynamicCollections/BaseContainer/LinkedListNode.c -o bin/LinkedListNode.o

LinkedList.o: DynamicCollections/BaseContainer/LinkedList.c
	gcc -c DynamicCollections/BaseContainer/LinkedList.c -o bin/LinkedList.o

List.o: DynamicCollections/BaseContainer/List.c
	gcc -c DynamicCollections/BaseContainer/List.c -o bin/List.o

Queue.o: DynamicCollections/BaseContainer/Queue.c
	gcc -c DynamicCollections/BaseContainer/Queue.c -o bin/Queue.o

Stack.o: DynamicCollections/BaseContainer/Stack.c
	gcc -c DynamicCollections/BaseContainer/Stack.c  -o bin/Stack.o
#------------------------------------------------------------------------------



