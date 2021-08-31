#ifndef DictionaryInclude
#define DictionaryInclude
#include "CollectionError.h"

typedef struct DictionaryTreeItem_
{
	void* Key;
	void* Value;

	struct DictionaryTreeItem_* LeftChild;
	struct DictionaryTreeItem_* RightChild;
}DictionaryTreeItem;

typedef struct Dictionary_
{
	unsigned int SizeOfKey;
	unsigned int SizeOfValue;
	unsigned int Size;
	
	DictionaryTreeItem* Root;
}Dictionary;

void DictionaryInitialize(Dictionary* dictionary, unsigned int sizeOfKey, unsigned int sizeOfValue);
void DictionaryDestroy(Dictionary* dictionary);

char DictionaryContainsKey(Dictionary* dictionary, void* key);

CollectionError DictionaryAdd(Dictionary* dictionary, void* key, void* value); 
CollectionError DictionaryGet(Dictionary* dictionary, void* key, void* out);
CollectionError DictionaryRemove(Dictionary* dictionary, void* key);

#endif