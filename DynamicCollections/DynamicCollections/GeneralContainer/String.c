#include "String.h"

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void StringInitialize(String* string, char* inputString)
{
	const size_t inputStringLength = strlen(inputString);

	ListInitialize(&string->list, inputStringLength, sizeof(char*));

	for (int i = 0; i < inputStringLength; ++i)
	{
		StringCharInsertAt(string, i, inputString[i]);
	}
}

void StringDestruction(String* string)
{
	//ListDestruction(string);
	free(string->list.Content);
	string->list.Content = NULL;
}

CollectionError StringCharInsertAt(String* string, unsigned int indexValue, char value)
{
	if (string == NULL)
		return CollectionEmpty;

	if (indexValue > string->list.Size - 1)
		return CollectionArrayIndexOutOfBounds;

	if (string->list.Content[indexValue] == NULL)
		string->Count++;
	
	string->list.Content[indexValue] = value;

	return CollectionNoError;
}

CollectionError StringCharGet(String* string, unsigned int index, char* out)
{
	return ListItemGet(&string->list, index, out);
}

CollectionError StringCharAdd(String* string, char addChar)
{
	string->Count++;
	return ListItemAdd(&string->list, addChar);
}

CollectionError StringConcat(String* string, char* addString)
{
	if (string == NULL)
		return CollectionEmpty;

	for (int i = 0; i < strlen(addString); ++i)
	{
		StringCharAdd(&string->list, addString[i]);
	}
	
	return CollectionNoError;
}

CollectionError StringGetFullString(String* string, char** out)
{
	char* returnString = calloc(string->Count + 1, sizeof(char));

	for (int i = 0; i < string->Count; ++i)
	{
		returnString[i] = string->list.Content[i];
	}
	
	memcpy(out, &returnString, sizeof(char*));
	
	return CollectionNoError;
}


