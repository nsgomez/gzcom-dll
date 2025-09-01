#pragma once
#include "PersistResourceKeyFilterBase.h"

class PersistResourceKeyFilterByType : public PersistResourceKeyFilterBase
{
public:
	PersistResourceKeyFilterByType(uint32_t type);

	// cIGZPersistResourceKeyFilter

	bool IsKeyIncluded(cGZPersistResourceKey const& key) override;

private:
	uint32_t type;
};
