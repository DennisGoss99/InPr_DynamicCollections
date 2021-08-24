#pragma once

#include "CollectionError.h"

const char* CollectionErrorToString(CollectionError collectionError)
{
	switch (collectionError)
	{
		case CollectionNoError:
			return "Collection: NoError";

		case CollectionOutOfMemory: 
			return "Collection: OutOfMemory";

		case CollectionEmpty: 
			return "Collection: Empty";

		case CollectionArrayIndexOutOfBounds: 
			return "Collection: Index is out of Bounds";

		case CollectionNoElementSizeSpecified:
			return "Collection: No elementsize specified";

		case CollectionElementIsNullPointer:
			return "Collection: Element is NullPointer";

		default: 
			return "Unknown CollectionError";
	}
}
