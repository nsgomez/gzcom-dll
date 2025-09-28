/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4PylonOccupant.h
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
#include "cISC4DispatchManager.h"

class cIGZString;

class cISC4PylonOccupant : public cIGZUnknown
{
public:
	typedef uint32_t tUIState;

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void SetUIState(tUIState value) = 0;
	virtual tUIState GetUIState() = 0;

	virtual void SetBitmapInfo(uint32_t textureIID, cIGZString const& mysimBitmapPath) = 0;

	virtual void SetDispatchType(cISC4DispatchManager::tDispatchType value) = 0;
	virtual cISC4DispatchManager::tDispatchType GetDispatchType() = 0;

	virtual void SetDispatchState(cISC4DispatchManager::tDispatchState value) = 0;
	virtual cISC4DispatchManager::tDispatchState GetDispatchState() = 0;

	virtual void SetCallNumber(uint16_t value) = 0;
	virtual uint16_t GetCallNumber() = 0;

	virtual void SetDragState(bool dragState) = 0;
	virtual bool GetDragState() = 0;

	virtual void SetSourceOccupant(cISC4Occupant* pOccupant) = 0;
	virtual cISC4Occupant* GetSourceOccupant() = 0;

	virtual void SetPylonOwner(cIGZUnknown* pOwner) = 0;
	virtual cIGZUnknown* GetPylonOwner() = 0;
};