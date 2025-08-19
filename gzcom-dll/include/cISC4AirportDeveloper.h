#pragma once
#include "cISC4PortDeveloper.h"

class cISC4AirportDeveloper : public cISC4PortDeveloper
{
public:
	virtual cISC4PortDeveloper* AsISC4PortDeveloper() = 0;

	virtual uint32_t GetNumAirports(ePortSize portSize) = 0;
	virtual bool GetAirportUsageValues(cISC4Lot* pLot, uint32_t& usage, uint32_t& capacity) = 0;
	virtual uint32_t GetNumAirportTrips() = 0;
	virtual int64_t GetMaintenanceCost(cISC4Lot* pLot) = 0;
};
