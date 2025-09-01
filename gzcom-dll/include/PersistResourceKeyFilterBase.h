#pragma once
#include "cRZBaseUnknown.h"
#include "cGZPersistResourceKey.h"
#include "cIGZPersistResourceKeyFilter.h"

class PersistResourceKeyFilterBase : public cRZBaseUnknown, public cIGZPersistResourceKeyFilter
{
protected:
	PersistResourceKeyFilterBase();

public:
	// cIGZUnknown

	bool QueryInterface(uint32_t riid, void** ppvObj) override;
	uint32_t AddRef() override;
	uint32_t Release() override;
};
