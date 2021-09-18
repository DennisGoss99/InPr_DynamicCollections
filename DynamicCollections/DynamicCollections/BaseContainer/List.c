#include "List.h"

#include <stdlib.h>
#include <string.h>


void ListInitialize(List* list, unsigned int count, size_t sizeOfSingleElement)
{
	if (list->Content != NULL || list->SizeOfSingleElement != 0)
		return;

	list->Content = calloc(count, sizeOfSingleElement);
	list->Size = count;
	list->SizeOfSingleElement = sizeOfSingleElement;
}

void ListDestruction(List* list)
{
	if (list == NULL) // Parameter NULL
		return;

	if (list->Content == NULL) // No data to delete
		return;

	for (int i = 0; i < list->Size; ++i)
	{
		void* element = list->Content[i];

		if (element != NULL)
		{
			free(element);
			list->Content[i] = NULL;
		}
	}

	free(list->Content);
	list->Content = NULL;
	
}

CollectionError ListItemInsertAt(List* list, unsigned int indexValue, void* value)
{
	if (list == NULL)
		return CollectionEmpty;

	if (indexValue > list->Size - 1)
		return CollectionArrayIndexOutOfBounds;

	list->Content[indexValue] = value;

	return CollectionNoError;
}

CollectionError ListItemGet(List* list, unsigned int index, void* out)
{
	if (index > list->Size - 1)
	{
		void* null = NULL;
		memcpy(out, &null, sizeof(void*));
		return CollectionArrayIndexOutOfBounds;
	}

	if (list == NULL)
	{
		void* null = NULL;
		memcpy(out, &null, sizeof(void*));
		return CollectionEmpty;
	}

	if(list->Content[index] == NULL)
	{
		int null = NULL;
		memcpy(out, &null, sizeof(void*));
		return CollectionNoError;
	}
	
	memcpy(out, &list->Content[index], sizeof(void*));

	return CollectionNoError;
}

CollectionError ListItemAdd(List* list, void* value)
{
	if (list == NULL)
		return CollectionEmpty;

	int unsigned addLocation = 0;

	while (list->Content[addLocation] != NULL && addLocation <= list->Size - 1)
		addLocation++;


	if (addLocation >= list->Size)
	{
		const unsigned int oldSize = list->Size;

		list->Size = (int)(1.5 * (list->Size + 1));


		void* reallocOutput = realloc(list->Content, list->Size * list->SizeOfSingleElement);

		if (reallocOutput == NULL)
			return CollectionOutOfMemory;


		list->Content = reallocOutput;

		for (int i = oldSize; i < list->Size; ++i)
			list->Content[i] = NULL;
	}

	return ListItemInsertAt(list, addLocation, value);
}

CollectionError ListItemRemove(List* list, unsigned int index)
{
	if (index > list->Size - 1)
		return CollectionArrayIndexOutOfBounds;

	if (list == NULL)
		return CollectionEmpty;

	if (list->Content[index] == NULL)
		return CollectionNoError;

	if (list->Content[index] != NULL)
	{
		free(list->Content[index]);
		list->Content[index] = NULL;
	}

	return CollectionNoError;
}

CollectionError ListClear(List* list)
{
	if (list == NULL)
		return CollectionEmpty;

	for (int i = 0; i < list->Size; ++i)
		ListItemRemove(list, i);

	return CollectionNoError;
}