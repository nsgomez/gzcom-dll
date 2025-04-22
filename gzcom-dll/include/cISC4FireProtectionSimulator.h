#pragma once
#include "cIGZUnknown.h"
#include "ilist.h"
#include <list>

class cISC4DepartmentBudget;
class cISC4Occupant;
class SC4Percentage;

template<typename T> class cISC4SimGrid;

class cISC4FireProtectionSimulator : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual cISC4SimGrid<int16_t>* GetFireProtectionGrid() const = 0;

	virtual cISC4DepartmentBudget* GetDepartmentBudget() const = 0;

	virtual bool IsFireStation(cISC4Occupant* pStation) const = 0;

	virtual bool GetStationFunding(cISC4Occupant* pStation, int32_t& nFunding, SC4Percentage& sFundingPercent) const = 0;
	virtual bool SetStationFunding(cISC4Occupant* pStation, SC4Percentage const& sFundingPercent) = 0;

	virtual float GetStationEfficiency() = 0;
	virtual bool IsOnStrike() = 0;
	virtual float GetChanceOfStrike() = 0;
	virtual bool BeginStrike(cISC4Occupant* pStation) = 0;
	virtual bool EndStrike() = 0;

	virtual uint32_t GetStrikeStartDate() = 0;
	virtual uint32_t GetStrikeLength() = 0;

	virtual bool GetStrikingStations(std::list<cISC4Occupant*>& list) = 0;
	virtual bool IsStationOnStrike(cISC4Occupant* pStation) = 0;

	virtual float GetAverageCoverage() = 0;
	virtual float GetPercentCoverage() = 0;
	virtual bool GetOccupantCoverage(cISC4Occupant* pStation, SC4Percentage const& sPercentage, float& fRadiusX, float& fRadiusZ) = 0;

	virtual int32_t GetFireStations(ilist<cISC4Occupant*>& list) = 0;
	virtual uint32_t GetFireStationCount() = 0;
	virtual float GetStationDispatchRadius(cISC4Occupant* pStation) = 0;
	virtual uint32_t GetTotalDispatchCount() = 0;
};