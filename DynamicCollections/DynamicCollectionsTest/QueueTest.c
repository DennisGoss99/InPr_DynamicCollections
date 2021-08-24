#include "QueueTest.h"
#include "../DynamicCollections/BaseContainer/CollectionError.h"
#include "../DynamicCollections/BaseContainer/Queue.h"

#include <assert.h>

void QueueTestStart()
{
	QueueComplexTest();
}

void QueueComplexTest()
{
	char x = 0;
	CollectionError collectionError;
	Queue queue;
	QueueInitialize(&queue, sizeof(char));

	// Add
	{
		char a[] = "ABCDE";
		QueuePush(&queue, &a[0]);
		QueuePush(&queue, &a[1]);
		QueuePush(&queue, &a[2]);
		QueuePush(&queue, &a[3]);
		QueuePush(&queue, &a[4]);
	}

	// Pull
	{
		QueuePull(&queue, &x);
		assert(x == 'A');

		QueuePull(&queue, &x);
		assert(x == 'B');

		QueuePull(&queue, &x);
		assert(x == 'C');

		QueuePull(&queue, &x);
		assert(x == 'D');

		QueuePull(&queue, &x);
		assert(x == 'E');
	}

	// Empty
	collectionError = QueuePull(&queue, &x);
	assert(collectionError == CollectionEmpty);

	// Add
	{
		char b[] = "123";
		QueuePush(&queue, &b[0]);
		QueuePush(&queue, &b[1]);
		QueuePush(&queue, &b[2]);
	}

	// Pull
	{
		QueuePull(&queue, &x);
		assert(x == '1');

		QueuePull(&queue, &x);
		assert(x == '2');

		QueuePull(&queue, &x);
		assert(x == '3');
	}

	collectionError = QueuePull(&queue, &x);
	assert(collectionError == CollectionEmpty);
}
