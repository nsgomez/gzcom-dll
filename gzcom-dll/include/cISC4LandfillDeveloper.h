#pragma once
#include "cIGZUnknown.h"

class SC4Percentage;

template <typename T> class SC4CellRegion;

class cISC4LandfillDeveloper : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual SC4Percentage GetEfficiency() = 0;

	virtual uint32_t GetSimulatorType() = 0;

	virtual int64_t GetMaintenanceCosts() = 0;
	virtual int64_t GetCurrentBudget() = 0;
	virtual int32_t GetZoningCost(SC4CellRegion<int32_t> const* cellRegion) = 0;

	virtual void GetLandfillUsage(uint32_t& usage, uint32_t& capacity) = 0;
	virtual int32_t GetLandfillTileCount() const = 0;
	virtual intptr_t GetLandfillZoneFromCell(int cellX, int cellZ) = 0; // Returns cSC4LandfillZone*
};