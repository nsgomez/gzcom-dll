/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4DisasterLayer.h
 *
 * Copyright (C) 2016 Nelson Gomez
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

class cISC4DisasterInstance;
class cISC4DisasterManager;
class cISC4Occupant;

class cISC4DisasterLayer : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool EnableDisasters(bool bToggle) = 0;
		virtual bool DisastersEnabled(void) = 0;

		virtual cISC4DisasterManager* GetDisasterManager(uint32_t dwDisasterType) = 0;

		virtual bool DisasterHasBegun(cISC4DisasterInstance* pDisaster) = 0;
		virtual bool DisasterHasEnded(cISC4DisasterInstance* pDisaster) = 0;
		virtual bool IsADisasterOngoing(void) = 0;
		virtual bool GoToNextDisaster(void) = 0;

		virtual bool GetMostRecentDisasterLocation(cISC4DisasterInstance* pDisaster, int& nX, int& nY) = 0;
		virtual bool RegisterDisasterLocation(cISC4DisasterInstance* pDisaster, int nX, int nY, cISC4Occupant* pOccupant, int32_t nUnknown, bool bTeleportCam) = 0;
		virtual bool UnregisterDisasterLocations(cISC4DisasterInstance* pDisaster) = 0;
		virtual bool UnregisterDisasterLocationByOccupant(cISC4DisasterInstance* pDisaster, cISC4Occupant* pOccupant) = 0;
		virtual int32_t GetDisasterLocationCount(void) = 0;

		virtual bool GetDisasterLocationByIndex(int32_t nIndex, cISC4DisasterInstance** ppDisaster, int& nX, int& nY) = 0;
		virtual int32_t GetDisasterCost(void) = 0;
};