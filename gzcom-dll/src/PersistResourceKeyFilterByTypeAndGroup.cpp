#include "PersistResourceKeyFilterByTypeAndGroup.h"

PersistResourceKeyFilterByTypeAndGroup::PersistResourceKeyFilterByTypeAndGroup(uint32_t type, uint32_t group)
	: type(type), group(group)
{
}

bool PersistResourceKeyFilterByTypeAndGroup::IsKeyIncluded(cGZPersistResourceKey const& key)
{
	return key.group == group && key.type == type;
}
