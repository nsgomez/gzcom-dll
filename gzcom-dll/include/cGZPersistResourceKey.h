#pragma once
#include "stdint.h"

class cGZPersistResourceKey
{
public:
	cGZPersistResourceKey()
		: type(0), group(0), instance(0)
	{
	}

	cGZPersistResourceKey(uint32_t type, uint32_t group, uint32_t instance)
		: type(type), group(group), instance(instance)
	{
	}


	uint32_t type;
	uint32_t group;
	uint32_t instance;
};
