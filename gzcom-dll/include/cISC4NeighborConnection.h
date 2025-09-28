/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4NeighborConnection.h
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