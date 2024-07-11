#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;

template<typename T> class cISC4SimGrid;
template<typename T> class SC4CellRegion;

class cISC4ZoneManager : public cIGZUnknown
{
public:
	enum class ZoneType : int32_t
	{
		None = 0,
		ResidentialLowDensity = 1,
		ResidentialMediumDensity = 2,
		ResidentialHighDensity = 3,
		CommercialLowDensity = 4,
		CommercialMediumDensity = 5,
		CommercialHighDensity = 6,
		Agriculture = 7,
		IndustrialMediumDensity = 8,
		IndustrialHighDensity = 9,
		Military = 10,
		Airport = 11,
		Seaport = 12,
		Spaceport = 13,
		Landfill = 14,
		Plopped = 15,
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual cISC4SimGrid<int8_t>* GetZoneGrid() const = 0;
	virtual int32_t GetZoneCount(ZoneType type) = 0;
	virtual int32_t GetUndevelopedTileCount() = 0;
	virtual int32_t GetUndevelopedTileCount(ZoneType type) = 0;
	virtual int32_t GetDevelopmentFailureCount(int x, int z) = 0;
	virtual int32_t GetAbandonedTileCount() = 0;

	virtual bool PlaceZone(SC4CellRegion<long>& cellRegion, ZoneType zoneType, bool unknown3, bool unknown4, bool checkAreaSlope, bool unknown6, bool unknown7, int64_t* unknown8, int32_t* unknown9, intptr_t outLotsDemolishedSet) = 0;

	virtual ZoneType GetZoneType(int x, int z) = 0;
	virtual bool IsRCIZone(ZoneType type) = 0;

	virtual bool GetTextureForZone(ZoneType type, cGZPersistResourceKey& key) = 0;
	virtual uint32_t GetZoneDragColor(ZoneType type) const = 0;
	virtual uint8_t GetZoneDisplayAlpha() const = 0;
	virtual uint8_t GetDefaultZoneDisplayAlpha() const = 0;
	virtual void SetZoneDisplayAlpha(uint8_t value) = 0;

	virtual int32_t GetMinZoneSize(ZoneType type) = 0;
	virtual int32_t GetMaxZoneSize(ZoneType type) = 0;
};