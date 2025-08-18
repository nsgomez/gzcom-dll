#pragma once
#include "cIGZUnknown.h"


class cISC4Occupant;
class SC4Percentage;

template<typename T> class cISC4SimGrid;
template<typename T> class SC4List;

class cISC4PoliceSimulator : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual cISC4SimGrid<short>* GetPolicePowerGrid(void) = 0;

		virtual intptr_t GetDepartmentBudget(void) = 0;
		
		virtual bool GetStationFunding(cISC4Occupant* pStation, int32_t& nFunding, SC4Percentage& sFundingPercent) = 0;
		virtual bool SetStationFunding(cISC4Occupant* pStation, SC4Percentage const& sFundingPercentage) = 0;
		
		virtual uint32_t GetJailDepartmentBudget(void) = 0;

		virtual bool IsOnStrike(void) = 0;
		virtual float GetChanceOfStrike(void) = 0;		
		
		virtual bool BeginStrike(cISC4Occupant* pStation) = 0;
		virtual bool EndStrike(void) = 0;
		
		virtual uint32_t GetStrikeStartDate(void) = 0;
		virtual uint32_t GetStrikeLength(void) = 0;

		virtual bool GetStrikingStations(SC4List<cISC4Occupant*>& sList) = 0;
		virtual bool IsStationOnStrike(cISC4Occupant* pStation) = 0;
		
		virtual float GetAverageCoverage(void) = 0;
		virtual float GetPercentCoverage(void) = 0;
		virtual bool GetOccupantCoverage(cISC4Occupant* pStation, SC4Percentage const& sPercentage, float& fRadiusX, float& fRadiusZ) = 0;

		virtual bool GetPoliceStations(SC4List<cISC4Occupant*>& sList) = 0;
		virtual bool IsPoliceStation(cISC4Occupant* pBuilding) = 0;
		
		virtual float GetStationDispatchRadius(cISC4Occupant* pStation) = 0;
		
		virtual uint32_t GetPoliceStationCount(void) = 0;
		virtual float GetStationEfficiency(cISC4Occupant* pStation) = 0;

		virtual uint32_t GetTotalDispatchCount(void) = 0;
		
		virtual bool ResetUnjailedCriminals(void) = 0;
		virtual uint32_t GetJailCapacity(void) = 0;
		virtual uint32_t GetJailPopulation(void) = 0;
		virtual uint32_t GetCriminalCount(void) = 0;
		
		virtual int32_t GetJails(SC4List<cISC4Occupant*>& sList) = 0;
		virtual bool IsJail(cISC4Occupant* pBuilding) = 0;

		virtual uint32_t GetArrestCount(void) = 0;
		virtual uint32_t GetJailCount(void) = 0;
		virtual uint32_t GetJailCapacity(cISC4Occupant* pJail) = 0;
		virtual uint32_t GetJailedPercentage(void) = 0;
		virtual int64_t GetJailCurrentUpkeepCost(void) = 0;

		virtual bool ProcessMonthlyCrimeStats(void) = 0;
		
		virtual bool IsInJailbreak(void) = 0;
		virtual float BeginJailbreak(cISC4Occupant* pJail) = 0;
		virtual bool EndJailbreak(cISC4Occupant* pJail) = 0;
		virtual bool GetJailbreakBuildings(SC4List<cISC4Occupant*>& sList) = 0;

		virtual uint32_t GetPoliceStationArrestCount(cISC4Occupant* pStation) = 0;
		virtual uint32_t GetPoliceStationCrimeCount(cISC4Occupant* pStation) = 0;
};