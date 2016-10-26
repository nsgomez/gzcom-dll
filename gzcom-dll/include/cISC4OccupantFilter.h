#pragma once
#include "cIGZUnknown.h"

class cISC4Occupant;
class cISCPropertyHolder;

class cISC4OccupantFilter : public cIGZUnknown
{
	public:
		virtual bool IsOccupantIncluded(cISC4Occupant* pOccupant) = 0;
		virtual bool IsOccupantTypeIncluded(uint32_t dwType) = 0;
		virtual bool IsPropertyHolderIncluded(cISCPropertyHolder* pProperties) = 0;
};