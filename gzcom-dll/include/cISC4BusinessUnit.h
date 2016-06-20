#pragma once
#include "cIGZUnknown.h"
#include "cRZAutoRefCount.h"
#include <list>

class cISC4Lot;

class cISC4BusinessUnit : public cIGZUnknown
{
	public:
		virtual bool Add(cISC4Lot* pLot) = 0;
		virtual bool Remove(cISC4Lot* pLot) = 0;

		virtual std::list<cRZAutoRefCount<cISC4Lot>>* GetMembers(void) = 0;
};