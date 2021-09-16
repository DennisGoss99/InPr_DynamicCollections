	char x = 0;
	CollectionError collectionError;
	Queue queue;
	QueueInitialize(&queue, sizeof(char));

	//---<Add>--------------------------------------------	
	char a[6] = "ABCDE";

	collectionError = QueuePush(&queue, &a[0]); // Add 'A' with optional errorCheckValue

	QueuePush(&queue, &a[1]); // Add 'B'
	QueuePush(&queue, &a[2]); // Add 'C'
	QueuePush(&queue, &a[3]); // Add 'D'
	QueuePush(&queue, &a[4]); // Add 'E'	 
	//-----------------------------------------------------

	//--<Pull>---------------------------------------------
	
		QueuePull(&queue, &x); // x will contain 'A'
		QueuePull(&queue, &x); // x will contain 'B'
		QueuePull(&queue, &x); // x will contain 'C'
		QueuePull(&queue, &x); // x will contain 'D'
		QueuePull(&queue, &x); // x will contain 'E'
	//-----------------------------------------------------

	//---<Clear<-------------------------------------------
	collectionError = QueuePull(&queue, &x);
	//-----------------------------------------------------