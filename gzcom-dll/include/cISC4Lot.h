#pragma once
#include "cIGZUnknown.h"
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

class cISC4Lot : public cIGZUnknown
{
	public:
		virtual cISCPropertyHolder* AsPropertyHolder(void) = 0;
		virtual cISC4TrafficSource* AsTrafficSource(void) = 0;

		virtual bool Init(void) = 0;
		virtual bool IsInitialized(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool PostCityInit(void) = 0;

		virtual cISC4LotConfiguration* GetLotConfiguration(void) = 0;
		virtual bool SetLotConfiguration(cISC4LotConfiguration* pConfig) = 0;
		virtual cISC4LotConfigurationObject* GetLotConfigurationObject(cISC4Occupant* pOccupant) = 0;

		virtual uint32_t GetFlags(void) = 0;
		virtual bool SetFlags(uint32_t dwFlags) = 0;

		virtual bool GetBoundingRect(SC4Rect<int32_t>& sRect) = 0;
		virtual bool GetCenter(float* fCenter) = 0;
		
		virtual float GetAltitude(void) = 0;
		virtual bool SetAltitude(float fAltitude) = 0;
		
		virtual float GetSlope(void) = 0;
		virtual float GetSlopeAtTimeOfConstruction(void) = 0;
		virtual bool UpdateSlope(void) = 0;

		virtual bool GetLocation(int32_t& nPosX, int32_t& nPosZ) = 0;
		virtual bool GetSize(uint8_t& nSizeX, uint8_t& nSizeZ) = 0;

		virtual int32_t GetFacing(void) = 0;
		virtual bool SetFacing(int32_t nFacing) = 0;

		virtual cISC4BusinessUnit* GetUnit(void) = 0;
		virtual bool SetUnit(cISC4BusinessUnit* pUnit) = 0;

		virtual bool HasJobAccess(void) = 0;
		virtual bool HasRoadAccess(void) = 0;
		virtual bool HasOrganicRoadAccess(uint32_t dwPurposeType) = 0;
		virtual bool UpdateRoadAccess(void) = 0;

		virtual uint32_t GetZoneType(void) = 0;
		virtual bool UpdateZoneType(void) = 0;

		virtual uint32_t GetState(void) = 0;
		virtual bool SetState(uint32_t dwHabitationState, uint32_t dwWealthType, int8_t cVacateReason) = 0;
		
		virtual uint32_t GetCondition(void) = 0;
		virtual bool SetCondition(uint32_t dwBuildingCondition) = 0;

		virtual bool IsInLivableState(void) = 0;
		virtual bool HasCapacity(void) = 0;
		virtual bool IsInDemolishableState(void) = 0;

		virtual uint32_t GetDaysSinceLastStateChange(void) = 0;
		
		virtual uint32_t GetOccupantWealth(void) = 0;
		virtual uint32_t GetLandValue(void) = 0;

		virtual bool IsHistorical(void) = 0;
		virtual bool SetHistorical(bool bHistorical) = 0;

		virtual int8_t GetVacateReason(void) = 0;
		
		virtual uint32_t GetBuildingType(bool bUnknown) = 0;
		virtual bool SetBuildingType(uint32_t dwBuildingType) = 0;

		virtual intptr_t GetBuilding(void) = 0; // TODO: type??
		virtual bool GetLotOccupants(std::list<cISC4Occupant*>& sOccupants) = 0;

		virtual uint32_t GetCapacity(uint32_t dwWealthType) = 0;
		virtual uint32_t GetCapacity(uint32_t dwDeveloperType, bool bForceCalculation) = 0;
		virtual uint32_t GetAvailableCapacity(uint32_t dwDeveloperType, bool bForceCalculation) = 0;

		virtual uint32_t GetPopulation(uint32_t dwDeveloperType) = 0;
		virtual uint32_t GetPopulations(void) = 0;
		virtual bool SetPopulation(uint32_t dwDeveloperType, uint16_t wPopulation) = 0;

		virtual uint32_t GetTravelPopulation(uint32_t dwDeveloperType) = 0;
		virtual bool ResetTravelPopulation(void) = 0;
		virtual bool AddTravelPopulation(cISC4Lot* pLot) = 0;
		
		virtual cISC4Lot* GetTravelDesignate(void) = 0;
		virtual bool SetTravelDesignate(cISC4Lot* pDesignate) = 0;

		virtual float GetOccupancy(void) = 0;
		virtual bool GetOccupancyByType(std::map<uint32_t, SC4Percentage>& sOccupancies) = 0;

		virtual float GetTravelJobs(uint32_t dwWealthType) = 0;
		virtual bool GetJobs(float fJobs[]) = 0; // An array of four floats it seems

		virtual bool GetNeedsPower(void) = 0;
		virtual bool GetHasPower(void) = 0;
		virtual bool SetHasPower(bool bHasPower) = 0;

		virtual bool GetVerticesAreLocked(void) = 0;
		virtual bool SetVerticesAreLocked(bool bLocked) = 0;
};