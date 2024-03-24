#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;

static const uint32_t GZIID_cIGZPersistResourceKeyFilter = 0x8865CD89;

class cIGZPersistResourceKeyFilter : public cIGZUnknown
{
	public:
		virtual bool IsKeyIncluded(cGZPersistResourceKey const& key) = 0;
};
