/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4LotBaseTextureOccupant.h
 *
 * Copyright (C) 2016 Nelson Gomez
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
#include "SC4Point.h"

class cISC4Occupant;
template <typename T> class SC4Vector;

class cISC4LotBaseTextureOccupant : public cIGZUnknown
{
	public:
		class LotBaseTextureSpecification;

		virtual cISC4Occupant* AsOccupant(void) = 0;

		virtual int32_t GetUsage(void) = 0;
		virtual bool SetUsage(int32_t) = 0;

		virtual bool GetCellCoverage(SC4Vector<SC4Point<int>>&, SC4Vector<bool>*) = 0;
		virtual bool IsCellCovered(int32_t, int32_t, bool*) = 0;

		virtual bool SetTextureSpecification(cISC4LotBaseTextureOccupant::LotBaseTextureSpecification const*, uint32_t, bool*) = 0;

		virtual bool UpdateVertexAltitudes(bool, bool, bool*) = 0;

		virtual bool LoadModels(bool) = 0;
		virtual bool UnloadModels(void) = 0;
};