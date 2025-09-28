/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4DisasterInstanceFire.h
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
#include "SC4Rect.h"

class cISC4Occupant;

class cISC4DisasterInstanceFire : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Update(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool Ignite(cISC4Occupant* pOccupant, bool bIgnorePause, uint32_t dwFireIID, bool bTeleport) = 0;
		virtual bool IgniteCell(uint32_t dwCellX, uint32_t dwCellZ, bool bUseProbability, bool bTeleport, uint32_t dwFireIID) = 0;
		virtual bool ExtinguishCell(uint32_t dwCellX, uint32_t dwCellZ, uint32_t dwUnknown) = 0; // unknown may have to do with fire phase
		virtual bool QuickBurnCell(uint32_t dwCellX, uint32_t dwCellZ) = 0;
		virtual bool IgniteCellRadius(uint32_t dwCenterX, uint32_t dwCenterZ, float fRadiusX, float fRadiusZ) = 0;
		virtual bool Extinguish(cISC4Occupant* pOccupant) = 0;
		virtual bool BurnDown(cISC4Occupant* pOccupant) = 0;
		
		virtual int32_t SetCause(uint32_t dwCause) = 0;
		virtual int32_t GetCause(void) = 0;

		virtual int32_t GetFireCountInCellRect(SC4Rect<long>& sRect) = 0;
		virtual int32_t GetFireCount(void) = 0;
};