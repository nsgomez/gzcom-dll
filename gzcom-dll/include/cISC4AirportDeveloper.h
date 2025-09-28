/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4AirportDeveloper.h
 *
 * Copyright (C) 2025 Nicholas Hayes
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, under
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <https://www.gnu.org/licenses/>.
 */

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
