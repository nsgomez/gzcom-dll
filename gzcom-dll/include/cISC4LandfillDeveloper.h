/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4LandfillDeveloper.h
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

class SC4Percentage;

template <typename T> class SC4CellRegion;

class cISC4LandfillDeveloper : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual SC4Percentage GetEfficiency() = 0;

	virtual uint32_t GetSimulatorType() = 0;

	virtual int64_t GetMaintenanceCosts() = 0;
	virtual int64_t GetCurrentBudget() = 0;
	virtual int32_t GetZoningCost(SC4CellRegion<int32_t> const* cellRegion) = 0;

	virtual void GetLandfillUsage(uint32_t& usage, uint32_t& capacity) = 0;
	virtual int32_t GetLandfillTileCount() const = 0;
	virtual intptr_t GetLandfillZoneFromCell(int cellX, int cellZ) = 0; // Returns cSC4LandfillZone*
};