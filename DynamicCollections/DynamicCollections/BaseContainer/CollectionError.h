#ifndef CollectionErrorInclude
#define CollectionErrorInclude

typedef enum CollectionError_
{
	CollectionNoError,


	CollectionOutOfMemory,


	CollectionEmpty,



}CollectionError;

const char* CollectionErrorToString(CollectionError collectionError);


#endif
