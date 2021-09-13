#include "String.h"

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void StringInitialize(String* string, char* inputString)
{
	const size_t inputStringLength = strlen(inputString);

	ListInitialize(string, inputStringLength, sizeof(char*));

	for (int i = 0; i < inputStringLength; ++i)
	{
		StringCharInsertAt(string, i, inputString[i]);
	}
}

void StringDestruction(String* string)
{
	//ListDestruction(string);
	free(string->Content);
	string->Content = NULL;
}

CollectionError StringCharInsertAt(String* string, unsigned int indexValue, char value)
{
	if (string == NULL)
		return CollectionEmpty;

	if (indexValue > string->Size - 1)
		return CollectionArrayIndexOutOfBounds;

	if (string->Content[indexValue] == NULL)
		string->Count++;
	
	string->Content[indexValue] = value;

	return CollectionNoError;
}

CollectionError StringCharGet(String* string, unsigned int index, char* out)
{
	return ListItemGet(string, index, out);
}

CollectionError StringCharAdd(String* string, char addChar)
{
	string->Count++;
	return ListItemAdd(string, addChar);
}

CollectionError StringConcat(String* string, char* addString)
{
	if (string == NULL)
		return CollectionEmpty;

	for (int i = 0; i < strlen(addString); ++i)
	{
		StringCharAdd(string, addString[i]);
	}
	
	return CollectionNoError;
}

CollectionError StringGetFullString(String* string, char** out)
{
	char* returnString = calloc(string->Count + 1, sizeof(char));

	for (int i = 0; i < string->Count; ++i)
	{
		returnString[i] = string->Content[i];
	}
	
	memcpy(out, &returnString, sizeof(char*));
	
	return CollectionNoError;
}


