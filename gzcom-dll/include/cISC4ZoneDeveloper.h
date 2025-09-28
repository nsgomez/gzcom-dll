/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4ZoneDeveloper.h
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
#include "cISC4ZoneManager.h"

template<typename T> class SC4CellRegion;
template<typename T> class SC4Point;

class cISC4ZoneDeveloper : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void HighlightParcels(SC4CellRegion<long> const& region, cISC4ZoneManager::ZoneType zoneType, SC4Point<long>* unknown3, SC4CellRegion<long>** unknown4) = 0;
	virtual void DoParcellization(SC4CellRegion<long> const& region, cISC4ZoneManager::ZoneType zoneType, bool unknown3) = 0;
	virtual void SetOptions(bool alternateOrientation, bool placeStreets, bool customZoneSize) = 0;

	virtual bool ExistsNetworkOfType(int32_t x, int32_t z, uint32_t networkFlags) = 0;
	virtual bool IsCellWater(int32_t x, int32_t z) = 0;
};