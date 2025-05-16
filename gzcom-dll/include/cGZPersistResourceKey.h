#pragma once
#include "stdint.h"

class cGZPersistResourceKey
{
public:
	constexpr cGZPersistResourceKey()
		: type(0), group(0), instance(0)
	{
	}

	constexpr cGZPersistResourceKey(uint32_t type, uint32_t group, uint32_t instance)
		: type(type), group(group), instance(instance)
	{
	}


	uint32_t type;
	uint32_t group;
	uint32_t instance;
};
