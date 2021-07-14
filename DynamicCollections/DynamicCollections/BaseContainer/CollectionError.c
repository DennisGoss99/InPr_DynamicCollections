#pragma once

#include "CollectionError.h"

const char* CollectionErrorToString(CollectionError collectionError)
{
	switch (collectionError)
	{
	case CollectionNoError: return "Collection: NoError";
	case CollectionOutOfMemory: return "Collection:OutOfMemory";
	case CollectionEmpty: return "Collection: Empty";
	default: return "Unknown CollectionError";
	}
}
