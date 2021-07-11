#ifndef DictionaryInclude
#define DictionaryInclude

typedef struct Dictionary_
{
	unsigned int Size;
}Dictionary;

void DictionaryInitialize(Dictionary* dictionary);
void DictionaryDestroy(Dictionary* dictionary);

#endif