#pragma once
#include "cIGZUnknown.h"
#include "ilist.h"

class cISC4Occupant;
class SC4Percentage;

template<typename T> class cISC4SimGrid;

class cISC4PlumbingSimulator : public cIGZUnknown
{
	public:
		virtual bool Init() = 0;
		virtual bool Shutdown() = 0;

		virtual intptr_t GetSupplyValue(int32_t unknown1) = 0;
		virtual bool GetSupplyValueMapPtr(cISC4SimGrid<uint8_t>*& grid) = 0;
		virtual cISC4SimGrid<uint8_t>* GetWateredGrid() = 0;

		virtual bool AreWateredBuildingsInCell(int32_t cX, int32_t cZ) = 0;
		virtual bool IsBuildingWatered(cISC4Occupant* occupant) = 0;
		virtual uint32_t GetWaterProduction(cISC4Occupant* occupant) = 0;
		virtual bool IsCellWatered(int32_t unknown1, int32_t unknown2) = 0;

		virtual uint32_t GetNumWaterSources() = 0;
		virtual uint32_t GetNumPollutedWaterSources() = 0;

		virtual int64_t GetWaterProductionCapacity() = 0;
		virtual int64_t GetWaterConsumed() = 0;
		virtual int64_t GetWaterImported() = 0;
		virtual int64_t GetWaterExported() = 0;

		virtual uint32_t GetNumPipes() = 0;
		virtual uint32_t GetNumDistressedPipes() = 0;
		virtual uint32_t GetNumBurstPipes() = 0;
		virtual uint32_t GetNumWateredBuildings() = 0;
		virtual uint32_t GetNumUnwateredBuildings() = 0;

		virtual int64_t GetWaterDemand() = 0;

		/**
		 * @brief Gets information about the specified water producer.
		 * @param producer The water producer.
		 * @param currentCapacity A pointer to a variable to retrieve the current capacity. Can be NULL if not required.
		 * @param maxCapacity A pointer to a variable to retrieve the max capacity. Can be NULL if not required.
		 * @param efficiency A pointer to a variable to retrieve the efficiency. Can be NULL if not required.
		 * @param shutDownByPollution A pointer to a variable to retrieve whether the producer is shut down by pollution. Can be NULL if not required.
		 * @param waterUsed A pointer to a variable to retrieve the water used. Can be NULL if not required.
		 * @return True on success; otherwise, false.
		*/
		virtual bool GetWaterProducerInfo(cISC4Occupant* producer, uint32_t* currentCapacity, uint32_t* maxCapacity, SC4Percentage* efficiency, bool* shutDownByPollution, uint32_t* waterUsed) = 0;
		virtual bool GetWaterProducerConditionPercent(cISC4Occupant* producer, SC4Percentage& conditionPercent) = 0;
		virtual bool GetOccupantMonthlyUpkeepCost(cISC4Occupant* occupant, int64_t& monthlyUpkeepCost) = 0;

		virtual bool FindWaterBuildings(cISC4Occupant** unknown1, SC4Percentage& unknown2, cISC4Occupant** unknown3, long& unknown4) = 0;
		virtual bool GetWaterProducers(ilist<cISC4Occupant*>& list) = 0;
};

