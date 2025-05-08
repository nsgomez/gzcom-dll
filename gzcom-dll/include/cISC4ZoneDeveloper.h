#pragma once
#include "cIGZUnknown.h"
#include "cISC4ZoneManager.h"

template<typename T> class SC4CellRegion;
template<typename T> class SC4Point;

class cISC4ZoneDeveloper : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void HighlightParcels(SC4CellRegion<long> const& region, cISC4ZoneManager::ZoneType zoneType, SC4Point<long>* unknown3, SC4CellRegion<long>** unknown4) = 0;
	virtual void DoParcellization(SC4CellRegion<long> const& region, cISC4ZoneManager::ZoneType zoneType, bool unknown3) = 0;
	virtual void SetOptions(bool alternateOrientation, bool placeStreets, bool customZoneSize) = 0;

	virtual bool ExistsNetworkOfType(int32_t x, int32_t z, uint32_t networkFlags) = 0;
	virtual bool IsCellWater(int32_t x, int32_t z) = 0;
};