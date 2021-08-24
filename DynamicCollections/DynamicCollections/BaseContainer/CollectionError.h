#ifndef CollectionErrorInclude
#define CollectionErrorInclude

typedef enum CollectionError_
{
	CollectionNoError,
	
	CollectionOutOfMemory,
	CollectionEmpty,
	CollectionArrayIndexOutOfBounds,

	CollectionNoElementSizeSpecified,
	CollectionElementIsNullPointer

}CollectionError;

const char* CollectionErrorToString(CollectionError collectionError);


#endif
