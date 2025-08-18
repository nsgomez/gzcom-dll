#pragma once
#include "cIGZUnknown.h"
#include "cISC4NeighborsSimulator.h"

class cISCPropertyHolder;
class cISC4TrafficSource;

class cISC4NeighborConnection : public cIGZUnknown
{
public:
	virtual cISCPropertyHolder* AsISCPropertyHolder() = 0;
	virtual cISC4TrafficSource* AsTrafficSource() = 0;

	virtual cISC4NeighborsSimulator::ConnectionType GetType() const = 0;

	virtual void GetConnectionCell(int32_t& cellX, int32_t& cellZ) const = 0;
	virtual bool GetConnectionInnerCell(int32_t& cellX, int32_t& cellZ) const = 0;
	virtual void GetRegionCellOnOtherSideOfConnection(int32_t& cellX, int32_t& cellZ) const = 0;

	virtual cISC4RegionalCity* GetCityOnOtherSideOfConnection() const = 0;

	virtual void Repair(cISC4RegionalCity* pCity) = 0;

	virtual bool GetVisitedThisCycle() const = 0;
	virtual void SetVisitedThisCycle(bool visited) = 0;

	virtual bool GetIsActive() const = 0;
	virtual void SetIsActive(bool active) = 0;
};