#pragma once
#include "cISC4OccupantFilter.h"
#include "cRZBaseUnknown.h"

class cSC4BaseOccupantFilter : public cRZBaseUnknown, public cISC4OccupantFilter
{
public:
	// cIGZUnknown

	bool QueryInterface(uint32_t riid, void** ppvObj) override;
	uint32_t AddRef() override;
	uint32_t Release() override;

	// cISC4OccupantFilter

	bool IsOccupantIncluded(cISC4Occupant* pOccupant) override;
	bool IsOccupantTypeIncluded(uint32_t dwType) override;
	bool IsPropertyHolderIncluded(cISCPropertyHolder* pProperties) override;
};