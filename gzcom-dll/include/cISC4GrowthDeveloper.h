#pragma once
#include "cIGZUnknown.h"
#include "cISC4BuildingDevelopmentSimulator.h"
#include "cISC4BuildingOccupant.h"

class cISC4Demand;
class cISCPropertyHolder;
template<typename T> class cISC4SimGrid;
template<typename T> class SC4Vector;

class cISC4GrowthDeveloper : public cIGZUnknown
{
public:
	class GrowthItem
	{
	public:
		intptr_t unknown1;
		intptr_t unknown2;
		uint8_t unknown3;
		uint8_t unknown4;
		uint8_t unknown5;
		uint8_t unknown6;
	};

	enum class MonopolyPieceUse : int32_t
	{
		UseRealBuildingsOnly = 0,
		UseRealIfAvailable = 1,
		UseMonopolyBuildingsOnly = 2
	};

	enum class TargetZoneType : int32_t
	{
		Residential = 1,
		Commercial = 2,
		Industrial = 3
	};

	virtual bool Init(cISCPropertyHolder* pPropertyHolder) = 0;
	virtual bool Shutdown() = 0;

	virtual TargetZoneType GetType() = 0;
	virtual uint32_t GetSubType() = 0;

	virtual cISC4BuildingOccupant::PurposeType GetPurpose() = 0;
	virtual cISC4BuildingOccupant::WealthType GetWealth() = 0;
	virtual void GetConstructionInfo(cISC4BuildingDevelopmentSimulator::ConstructionProfile& constructionProfile) = 0;

	virtual bool GrowthAndDeclineListsAreValid() = 0;
	virtual SC4Vector<GrowthItem>& GetGrowthList() = 0;
	virtual SC4Vector<GrowthItem>& GetDeclineList() = 0;

	virtual cISC4SimGrid<int16_t>* GetDesirabilityMap() = 0;
	virtual cISC4SimGrid<uint16_t>* GetCapacityMap() = 0;
	virtual cISC4SimGrid<int16_t>* GetPopulationMap() = 0;
	virtual cISC4SimGrid<uint16_t>* GetMaxCapacityMap() = 0;

	virtual uint32_t GetTotalCapacity() = 0;
	virtual cISC4Demand* GetSourceDemand() = 0;
	virtual uint8_t GetPowerSupplyCap() = 0;
	virtual uint8_t GetWaterSupplyCap() = 0;
	virtual uint8_t GetFireCoverageCap() = 0;
	virtual uint8_t GetParkCap() = 0;
	virtual int32_t GetDesirabilityThreshold() = 0;
	virtual float GetAbandonmentThreshold(int32_t densityType) = 0;
	virtual MonopolyPieceUse GetMonopolyUse() = 0;
	virtual intptr_t GetStylePercentages() = 0; // Returns a map<uint32_t, uint32_t>

	virtual void StartMapUpdate() = 0;
	virtual bool IsMapUpdateFinished() = 0;
	virtual int32_t EstimateDesirability(int32_t cellX, int32_t cellZ) = 0;
	virtual void GetSubjectiveThresholds(int32_t index, int32_t& min, int32_t& max) = 0;
};