#pragma once
#include "cIGZUnknown.h"
#include "cISC4BuildingDevelopmentSimulator.h"
#include "cISC4ZoneManager.h"
#include <list>
#include <map>

class cISCPropertyHolder;
class cISC4BusinessUnit;
class cISC4LotConfiguration;
class cISC4LotConfigurationObject;
class cISC4Occupant;
class cISC4TrafficSource;
class SC4Percentage;

template<typename T> class SC4Rect;

static const uint32_t GZIID_cISC4Lot = 0xe818fced;

class cISC4Lot : public cIGZUnknown
{
	public:
		enum class HabitationState : uint32_t
		{
			Created = 0,
			Ready = 1,
			Constructing = 2,
			Occupied = 3,
			Vacant = 4,
			Destructing = 5,
			Destroyed = 6
		};

		enum class VacateReason : int8_t
		{
			None = 0,
			LowDesirability = 1,
			NoPower = 2,
			NoWater = 3,
			CommuteTime = 4,
			KickOutOccupants = 5,
			LowDemand = 6
		};

		virtual cISCPropertyHolder* AsPropertyHolder(void) = 0;
		virtual cISC4TrafficSource* AsTrafficSource(void) = 0;

		virtual bool Init(void) = 0;
		virtual bool IsInitialized(void) const = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool PostCityInit(void) = 0;

		virtual cISC4LotConfiguration* GetLotConfiguration(void) = 0;
		virtual bool SetLotConfiguration(cISC4LotConfiguration* pConfig) = 0;
		virtual cISC4LotConfigurationObject* GetLotConfigurationObject(cISC4Occupant* pOccupant) = 0;

		virtual uint32_t GetFlags(void) const = 0;
		virtual bool SetFlags(uint32_t dwFlags) = 0;

		virtual bool GetBoundingRect(SC4Rect<int32_t>& sRect) const = 0;
		virtual bool GetCenter(float* fCenter) const = 0;

		virtual float GetAltitude(void) const = 0;
		virtual bool SetAltitude(float fAltitude) = 0;

		virtual float GetSlope(void) const = 0;
		virtual float GetSlopeAtTimeOfConstruction(void) const = 0;
		virtual bool UpdateSlope(void) = 0;

		virtual bool GetLocation(int32_t& nPosX, int32_t& nPosZ) const = 0;
		virtual bool GetSize(uint8_t& nSizeX, uint8_t& nSizeZ) const = 0;

		virtual int32_t GetFacing(void) const = 0;
		virtual bool SetFacing(int32_t nFacing) = 0;

		virtual cISC4BusinessUnit* GetUnit(void) = 0;
		virtual bool SetUnit(cISC4BusinessUnit* pUnit) = 0;

		virtual bool HasJobAccess(void) const = 0;
		virtual bool HasRoadAccess(void) const = 0;
		virtual bool HasOrganicRoadAccess(uint32_t dwPurposeType) const = 0;
		virtual bool UpdateRoadAccess(void) = 0;

		virtual cISC4ZoneManager::ZoneType GetZoneType(void) const = 0;
		virtual bool UpdateZoneType(void) = 0;

		virtual HabitationState GetState(void) const = 0;
		virtual bool SetState(HabitationState dwHabitationState, cISC4BuildingOccupant::WealthType eWealthType, VacateReason cVacateReason) = 0;

		virtual uint32_t GetCondition(void) const = 0;
		virtual bool SetCondition(uint32_t dwBuildingCondition) = 0;

		virtual bool IsInLivableState(void) const = 0;
		virtual bool HasCapacity(void) const = 0;
		virtual bool IsInDemolishableState(void) const = 0;

		virtual uint32_t GetDaysSinceLastStateChange(void) const = 0;

		virtual uint32_t GetOccupantWealth(void) const = 0;
		virtual uint32_t GetLandValue(void) const = 0;

		virtual bool IsHistorical(void) const = 0;
		virtual bool SetHistorical(bool bHistorical) = 0;

		virtual VacateReason GetVacateReason(void) const = 0;

		virtual uint32_t GetBuildingType(bool bForceCalculation) const = 0;
		virtual bool SetBuildingType(uint32_t dwBuildingType) = 0;

		virtual cISC4BuildingOccupant* GetBuilding(void) const = 0;
		virtual bool GetLotOccupants(std::list<cISC4Occupant*>& sOccupants) const = 0;

		virtual uint16_t GetCapacity(cISC4BuildingOccupant::WealthType eWealthType) const = 0;
		virtual uint16_t GetCapacity(cISC4BuildingDevelopmentSimulator::DeveloperType eDeveloperType, bool bForceCalculation) const = 0;
		virtual uint16_t GetAvailableCapacity(cISC4BuildingDevelopmentSimulator::DeveloperType eDeveloperType, bool bForceCalculation) const = 0;

		virtual uint16_t GetPopulation(cISC4BuildingDevelopmentSimulator::DeveloperType eDeveloperType) const = 0;
		virtual intptr_t GetPopulations(void) const = 0; // Returns a vector<map<cISC4BuildingDevelopmentSimulator::DeveloperType, uint16_t>>
		virtual bool SetPopulation(cISC4BuildingDevelopmentSimulator::DeveloperType eDeveloperType, uint16_t wPopulation) = 0;

		virtual uint16_t GetTravelPopulation(cISC4BuildingDevelopmentSimulator::DeveloperType eDeveloperType) const = 0;
		virtual bool ResetTravelPopulation(void) = 0;
		virtual bool AddTravelPopulation(cISC4Lot* pLot) = 0;

		virtual cISC4Lot* GetTravelDesignate(void) const = 0;
		virtual bool SetTravelDesignate(cISC4Lot* pDesignate) = 0;

		virtual float GetOccupancy(void) const = 0;
		virtual bool GetOccupancyByType(std::map<uint32_t, SC4Percentage>& sOccupancies) const = 0;

		virtual float GetTravelJobs(cISC4BuildingOccupant::WealthType eWealthType) const = 0;
		virtual bool GetJobs(float fJobs[]) const = 0; // An array of four floats it seems

		virtual bool GetNeedsPower(void) const = 0;
		virtual bool GetHasPower(void) const = 0;
		virtual bool SetHasPower(bool bHasPower) = 0;

		virtual bool GetVerticesAreLocked(void) const = 0;
		virtual bool SetVerticesAreLocked(bool bLocked) = 0;
};