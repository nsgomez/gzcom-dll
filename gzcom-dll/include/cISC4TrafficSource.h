#pragma once
#include "cIGZUnknown.h"

class cSC4TripData;

template <typename T> class SC4List;
template <typename T> class SC4Rect;

class cISC4TrafficSource : public cIGZUnknown
{
	public:
		virtual SC4List<cSC4TripData>* GetTripDataList(void) = 0;
		virtual bool UpdateTrafficVolume(void) = 0;
		virtual bool GetSourceCells(SC4Rect<uint32_t>& sCellRect) = 0;
};