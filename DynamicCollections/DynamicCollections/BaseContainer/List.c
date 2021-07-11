#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ListInitialize(List* list, unsigned int count, unsigned int sizeOfSingleElement)
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

int ListItemInsertAt(List* list, unsigned int indexValue, void* value)
{
	if (list == NULL)
		return -1;

	if (indexValue < 0 || indexValue >(list->Size - 1))
		return -2;

	list->Content[indexValue] = value;

	return 0;
}

void* ListItemGet(List* list, unsigned int index)
{
	if (index > list->Size - 1)
		return NULL;

	if (list == NULL)
		return NULL;

	return list->Content[index];
}

int ListItemAdd(List* list, void* value)
{
	if (list == NULL)
		return -1;

	int unsigned addLocation = 0;

	while (list->Content[addLocation] != NULL && addLocation <= list->Size - 1)
		addLocation++;


	if (addLocation >= list->Size)
	{
		const unsigned int oldSize = list->Size;

		list->Size = (int)(1.5 * (list->Size + 1));


		void* reallocOutput = realloc(list->Content, list->Size * list->SizeOfSingleElement);

		if (reallocOutput == NULL)
			return -9;


		list->Content = reallocOutput;

		for (int i = oldSize; i < list->Size; ++i)
			list->Content[i] = NULL;
	}

	return ListItemInsertAt(list, addLocation, value);
}

int ListItemRemove(List* list, unsigned int index)
{
	if (index > list->Size - 1)
		return -2;

	if (list == NULL)
		return -1;

	if (list->Content[index] == NULL)
		return 1;

	if (list->Content[index] != NULL)
	{
		free(list->Content[index]);
		list->Content[index] = NULL;
	}

	return 0;
}

int ListClear(List* list)
{
	if (list == NULL)
		return -1;

	for (int i = 0; i < list->Size; ++i)
		ListItemRemove(list, i);

	return 0;
}

void ListPrint_string(List* list)
{
	printf("{");
	for (int i = 0; i < list->Size; ++i)
	{
		if (i != 0)
			printf(",");

		printf("%s", ListItemGet(list, i));
	}
	printf("}");
}

void ListPrint_int(List* list)
{
	printf("{");
	for (int i = 0; i < list->Size; ++i)
	{
		if (i != 0)
			printf(",");

		printf("%i", ListItemGet(list, i));
	}
	printf("}");
}