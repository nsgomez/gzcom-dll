#pragma once
#include "PersistResourceKeyFilterBase.h"

class PersistResourceKeyFilterByTypeAndGroup : public PersistResourceKeyFilterBase
{
public:
	PersistResourceKeyFilterByTypeAndGroup(uint32_t type, uint32_t group);

	// cIGZPersistResourceKeyFilter

	bool IsKeyIncluded(cGZPersistResourceKey const& key) override;

private:
	uint32_t type;
	uint32_t group;
};
