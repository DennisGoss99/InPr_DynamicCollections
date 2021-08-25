#ifndef DictionaryInclude
#define DictionaryInclude
#include "CollectionError.h"

typedef struct Dictionary_
{
	unsigned int SizeOfKey;
	unsigned int SizeOfValue;
	unsigned int Size;
}Dictionary;

void DictionaryInitialize(Dictionary* dictionary, unsigned int sizeOfKey, unsigned int sizeOfValue);
void DictionaryDestroy(Dictionary* dictionary);

char DictionaryContainsKey(Dictionary* dictionary, void* key);

CollectionError DictionaryAdd(Dictionary* dictionary, void* key, void* value); 
CollectionError DictionaryGet(Dictionary* dictionary, void* key, void* out);
CollectionError DictionaryRemove(Dictionary* dictionary);

#endif