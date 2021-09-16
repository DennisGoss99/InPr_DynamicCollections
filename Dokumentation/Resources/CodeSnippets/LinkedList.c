	LinkedList linkedList;

	LinkedListInitialize(&linkedList, sizeof(int));

	//---<Insert>------------------------------------------
	int data[] = {10,20,30,40,50,60};

	LinkedListAddToEnd(&linkedList, &data[0]);
	LinkedListAddToEnd(&linkedList, &data[1]);
	LinkedListAddToEnd(&linkedList, &data[2]);
	LinkedListAddToEnd(&linkedList, &data[3]);
	LinkedListAddToEnd(&linkedList, &data[4]);
	LinkedListAddToEnd(&linkedList, &data[5]);
	//-----------------------------------------------------

	//---<Read>--------------------------------------------
	int extractedData[6];

	// Get elements form index
	LinkedListGetElement(&linkedList, 0, &extractedData[0]);
	LinkedListGetElement(&linkedList, 1, &extractedData[1]);
	LinkedListGetElement(&linkedList, 2, &extractedData[2]);
	LinkedListGetElement(&linkedList, 3, &extractedData[3]);
	LinkedListGetElement(&linkedList, 4, &extractedData[4]);
	LinkedListGetElement(&linkedList, 5, &extractedData[5]);
	//-----------------------------------------------------