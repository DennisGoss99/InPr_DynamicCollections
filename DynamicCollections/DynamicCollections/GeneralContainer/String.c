#include "String.h"

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void StringInitialize(String* string, char* inputString)
{
	const size_t inputStringLength = strlen(inputString);

	ListInitialize(&string->List, inputStringLength, sizeof(char*));

	for (int i = 0; i < inputStringLength; ++i)
	{
		StringCharInsertAt(string, i, inputString[i]);
	}
}

void StringDestruction(String* string)
{
	//ListDestruction(string);
	free(string->List.Content);
	string->List.Content = NULL;
}

CollectionError StringCharInsertAt(String* string, unsigned int indexValue, char value)
{
	if (string == NULL)
		return CollectionEmpty;

	if (indexValue > string->List.Size - 1)
		return CollectionArrayIndexOutOfBounds;

	if (string->List.Content[indexValue] == NULL)
		string->Count++;
	
	string->List.Content[indexValue] = value;

	return CollectionNoError;
}

CollectionError StringCharGet(String* string, unsigned int index, char* out)
{
	return ListItemGet(&string->List, index, out);
}

CollectionError StringCharAdd(String* string, char addChar)
{
	string->Count++;
	return ListItemAdd(&string->List, addChar);
}

CollectionError StringConcat(String* string, char* addString)
{
	if (string == NULL)
		return CollectionEmpty;

	for (int i = 0; i < strlen(addString); ++i)
	{
		StringCharAdd(&string->List, addString[i]);
	}
	
	return CollectionNoError;
}

char* StringGetFullString(String* string)
{
	char* returnString = calloc(string->Count + 1, sizeof(char));

	for (int i = 0; i < string->Count; ++i)
	{
		returnString[i] = string->List.Content[i];
	}
		
	return returnString;
}


