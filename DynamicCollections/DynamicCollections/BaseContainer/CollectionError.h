#ifndef CollectionErrorInclude
#define CollectionErrorInclude

// Errorcode used in Containers.
// Describes how a command has succeeded or failed.
typedef enum CollectionError_
{
	// Successful / No Error
	CollectionNoError,
	
	// Some internal allocation failed
	CollectionOutOfMemory,

	// There is no data to pull.
	CollectionEmpty,

	// Specified index points not to any data.
	CollectionArrayIndexOutOfBounds,

	// Specified 'ElementSize' was Zero.
	CollectionNoElementSizeSpecified,

	// Specified 'data' is Null-Pointer
	CollectionElementIsNullPointer,

	//Dictionary specific
	CollectionKeyAlreadyExists

}CollectionError;

const char* CollectionErrorToString(CollectionError collectionError);

#endif