#pragma once
#include "cISC4PortDeveloper.h"

class cISC4SeaportDeveloper : public cISC4PortDeveloper
{
public:
	virtual cISC4PortDeveloper* AsISC4PortDeveloper() = 0;

	virtual uint32_t GetNumSeaports(ePortSize portSize) = 0;
	virtual bool GetSeaportUsageValues(cISC4Lot* pLot, uint32_t& usage, uint32_t& capacity) = 0;
	virtual uint32_t GetNumSeaportTrips() = 0;
	virtual int64_t GetMaintenanceCost(cISC4Lot* pLot) = 0;
	virtual bool CityHasSea() = 0;
	virtual uint8_t GetCellSeaAccess(uint32_t cellX, uint32_t cellZ) = 0;
};