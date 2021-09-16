	char x = 0;
	CollectionError collectionError;
	Stack stack;
	StackInitialize(&stack, sizeof(char));

	//---<Add>----------------------------------	
	char a[] = "Hello";

	StackPush(&stack, &a[0]); // Add 'H'
	StackPush(&stack, &a[1]); // Add 'e'
	StackPush(&stack, &a[2]); // Add 'l'
	StackPush(&stack, &a[3]); // Add 'l'
	StackPush(&stack, &a[4]); // Add 'o'
	//------------------------------------------

	//---<Pull>---------------------------------	
	StackPull(&stack, &x); // x now contains 'o'
	StackPull(&stack, &x); // x now contains 'l'
	StackPull(&stack, &x); // x now contains 'l'
	StackPull(&stack, &x); // x now contains 'e'
	StackPull(&stack, &x); // x now contains 'H'
	//------------------------------------------

	//---<Clear>--------------------------------
	collectionError = StackPull(&stack, &x); // Will return that the List is Empty
	//------------------------------------------