#include "PersistResourceKeyFilterByType.h"

PersistResourceKeyFilterByType::PersistResourceKeyFilterByType(uint32_t type)
	: type(type)
{
}

bool PersistResourceKeyFilterByType::IsKeyIncluded(cGZPersistResourceKey const& key)
{
	return key.type == type;
}
