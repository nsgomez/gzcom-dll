#pragma once
#include "cIGZUnknown.h"
#include "ilist.h"
#include <vector>

class cISC4Occupant;
class SC4Percentage;

template <typename T> class cISC4SimGrid;

static const uint32_t GZIID_cISC4PowerSimulator = 0xE9E7BFF5;

class cISC4PowerSimulator : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void PositionToCell(float unknown1, float unknown2, int32_t& unknown3, int32_t& unknown4) = 0;
	virtual void CellToPosition(int32_t unknown1, int32_t unknown2, float& unknown3, float& unknown4) = 0;
	virtual void CellToStandardCityCell(int32_t unknown1, int32_t unknown2, int32_t& unknown3, int32_t& unknown4) = 0;
	virtual void StandardCityCellToCell(int32_t unknown1, int32_t unknown2, int32_t& unknown3, int32_t& unknown4) = 0;

	virtual uint32_t GetAnnualConsumption() = 0;
	virtual uint32_t GetAnnualConsumptionByPowerType(int32_t powerType) = 0;

	virtual int32_t GetMonthlyRequirement() = 0;
	virtual int32_t GetMonthlyProduction() = 0;
	virtual int32_t GetMonthlyImport() = 0;
	virtual int32_t GetMonthlyExport() = 0;
	virtual int32_t GetMonthlyDemand() = 0;
	virtual int32_t GetMonthlyConsumption() = 0;
	virtual int32_t GetMonthlyConsumption(int32_t x, int32_t z) = 0;
	virtual void GetMonthlyConsumptionMapPtr(std::vector<std::vector<int16_t>>*& vector) = 0;

	virtual bool GetSupplyValue(int32_t x, int32_t z) = 0; // Same as IsPowered
	virtual void GetSupplyValueMapPtr(cISC4SimGrid<uint8_t>*& grid) = 0;

	virtual int32_t GetUnpoweredConsumerCount() = 0;
	virtual int32_t GetPoweredConsumerCount() = 0;

	virtual int32_t GetPowerPlantCount() = 0;
	virtual int32_t GetPowerPlantCount(int32_t powerType) = 0;

	virtual void GetPowerPlants(ilist<cISC4Occupant*>& list) = 0;
	virtual uint32_t GetPowerPoleCount() = 0;

	virtual int32_t GetOverworkedPowerPlantCount() = 0;
	virtual int32_t GetAgedPowerPlantCount() = 0;
	virtual int32_t GetDistressedPowerPlantCount() = 0;
	virtual void FindPowerPlants(cISC4Occupant** unknown1, SC4Percentage& unknown2, cISC4Occupant** unknown3, int32_t& unknown4) = 0;

	virtual bool IsOccupantPowered(cISC4Occupant* occupant) = 0;
	virtual void GetOccupantPowerConsumed(cISC4Occupant* occupant, uint32_t& powerConsumed) = 0;
	virtual void GetOccupantPowerProduced(cISC4Occupant* occupant, uint32_t& powerProduced, uint32_t& powerUsed) = 0;
	virtual void GetOccupantMaxPowerProduced(cISC4Occupant* occupant, uint32_t& maxPowerProduced) = 0;

	virtual cISC4SimGrid<uint8_t>* GetPoweredGrid() const = 0;
	virtual cISC4SimGrid<uint8_t>* GetPoweredGrid() = 0;

	virtual bool IsPowered(int32_t x, int32_t z) = 0;
	virtual bool IsWired(int32_t x, int32_t z) = 0;

	virtual bool IsOnStrike() = 0; // Returns false
	virtual void GetChanceOfStrike(SC4Percentage& chance) = 0; // Percentage is always 0
	virtual bool BeginStrike() = 0; // Returns false
	virtual bool EndStrike() = 0; // Returns false
	virtual int32_t GetStrikeStartDate() = 0;
	virtual int32_t GetStrikeLength() = 0;

	virtual float GetCurrentPlantEfficiencyPercent(cISC4Occupant* occupant) = 0;
	virtual float GetCurrentPlantConditionPercent(cISC4Occupant* occupant) = 0;
	virtual SC4Percentage* GetStrikeEfficiencyPercent() = 0;
	virtual SC4Percentage* GetFundingPercent() = 0;

	virtual bool GetMonthlyPowerGenerationCost(cISC4Occupant* occupant, int64_t& cost) = 0;
	virtual bool GetPowerPlantFundingPercentage(cISC4Occupant* occupant, SC4Percentage& fundingPercentage) = 0;
	virtual bool SetPowerPlantFundingPercentage(cISC4Occupant* occupant, SC4Percentage const& fundingPercentage) = 0;
};