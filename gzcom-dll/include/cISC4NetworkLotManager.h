/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4NetworkLotManager.h
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
#include "cISC4BuildingOccupant.h"
#include "cISC4ZoneManager.h"

class cIGZPersistDBSegment;
class cISC4Occupant;
class cISC4NetworkLot;
class cISC4NetworkLotConfiguration;

class cISC4NetworkLotManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual cISC4NetworkLot* GetNetworkLot(int32_t x, int32_t z) const = 0;
	virtual void GetNetworkLotConfigurationSet(intptr_t networkLotConfigurationSet) const = 0;
	virtual bool GetNetworkLotConfigurationById(uint32_t id, cISC4NetworkLotConfiguration* pNetworkLotConfiguration) const = 0;

	virtual cISC4Occupant* CreateProp(cISC4NetworkLot* pLot, uint32_t lotConfigurationObjectIndex, uint32_t propType) = 0;
	virtual cISC4ZoneManager::ZoneType GetZoneTypeForNetwork(int32_t x, int32_t z) = 0;
	virtual cISC4BuildingOccupant::WealthType GetWealthForNetwork(int32_t x, int32_t z) = 0;

	typedef bool (*NetworkLotIterationCallback)(uint32_t x, uint32_t z, cISC4NetworkLot* pLot, void* pContext);

	virtual bool IterateAllNetworkLots(NetworkLotIterationCallback callback, void* pContext) = 0;

	virtual void RedevelopLot(uint32_t x, uint32_t z, cISC4NetworkLot* pLot) = 0;
	virtual void SetLotConfigurationForNextPiece(cISC4NetworkLotConfiguration* pConfiguration) = 0;
	virtual bool WriteLotConfiguration(cISC4NetworkLotConfiguration* pConfiguration, cIGZPersistDBSegment* pSegment) = 0;
};