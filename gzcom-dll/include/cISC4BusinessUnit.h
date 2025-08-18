#pragma once
#include "cIGZUnknown.h"
#include "cRZAutoRefCount.h"

class cISC4Lot;

template<typename T> class SC4List;

class cISC4BusinessUnit : public cIGZUnknown
{
	public:
		virtual bool Add(cISC4Lot* pLot) = 0;
		virtual bool Remove(cISC4Lot* pLot) = 0;

		virtual SC4List<cISC4Lot*>* GetMembers(void) = 0;
};