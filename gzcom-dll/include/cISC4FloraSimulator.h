/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4FloraSimulator.h
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

class cGZPersistResourceKey;
class cIGZPersistDBSegment;
class cISC4FloraOccupant;
class cISC4FloraTypeFilter;
class cISC4Occupant;
class cISCResExemplar;
class cSC4StaticFloraData;

template <typename T> class SC4Rect;
template <typename T> class SC4Vector;

class cISC4FloraSimulator : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool AddStaticFloraData(cSC4StaticFloraData* unknown1) = 0;
	virtual bool AddStaticFloraData(cGZPersistResourceKey* unknown1, cISCResExemplar* unknown2) = 0;
	virtual cSC4StaticFloraData* GetStaticFloraData(uint32_t type) = 0;

	virtual uint32_t GetAllFloraTypes(uint32_t* buffer, uint32_t& count) = 0;
	virtual void GetAllFloraTypes(SC4Vector<uint32_t>& vector) = 0;
	virtual void GetAllFloraFamilyTypes(SC4Vector<uint32_t>& vector) = 0;
	virtual bool IsFloraTypeValid(uint32_t type) = 0;
	virtual bool IsFloraFamilyTypeValid(uint32_t type) = 0;

	virtual uint32_t GetFloraTypesByFilter(intptr_t& hash_set, cISC4FloraTypeFilter* unknown2) = 0;
	virtual uint32_t GetFloraTypesByFamily(intptr_t& hash_set, uint32_t unknown2) = 0;

	virtual bool LocationIsOKForNewFlora(uint32_t unknown1, float unknown2, float unknown3, cISC4Occupant* pOccupant) = 0;
	virtual uint32_t GetBestFloraTypeForLocation(float unknown1, float unknown2, float& unknown3) = 0;

	virtual bool AddNewFloraOccupant(cISC4Occupant* pOccupant) = 0;
	virtual cISC4FloraOccupant* AddNewFloraOccupant(uint32_t unknown1, float* unknown2, bool unknown3) = 0;
	virtual bool DemolishFloraOccupant(cISC4Occupant* pOccupant, int32_t unknown2) = 0;
	virtual bool DemolishFloraInCellArea(SC4Rect<int32_t> const& rect, int32_t unknown2) = 0;
	virtual bool DemolishFloraInBoundingBox(float const* unknown1, float const* unknown2, int32_t unknown3) = 0;
	virtual int64_t GetCostOfOccupantDemolition(cISC4Occupant* pOccupant, int32_t unknown2) = 0;

	virtual bool KillFloraOccupant(cISC4Occupant* pOccupant) = 0;
	virtual bool SaveObliterated(cIGZPersistDBSegment* pSegment) = 0;
};