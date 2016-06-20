#pragma once
#include "cIGZUnknown.h"
#include <list>

class cSC4TripData;

template <typename T> class SC4Rect;

class cISC4TrafficSource : public cIGZUnknown
{
	public:
		virtual std::list<cSC4TripData>* GetTripDataList(void) = 0;
		virtual bool UpdateTrafficVolume(void) = 0;
		virtual bool GetSourceCells(SC4Rect<uint32_t>& sCellRect) = 0;
};