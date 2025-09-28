/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4LotRetainingWallOccupant.h
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

class cISC4Lot;
class cISC4Occupant;

class cISC4LotRetainingWallOccupant : public cIGZUnknown
{
	public:
		virtual cISC4Occupant* AsOccupant(void) = 0;

		virtual bool SetSize(float const*) = 0;

		virtual cISC4Lot* GetLot(void) = 0;
		virtual bool SetLot(cISC4Lot*) = 0;

		virtual int32_t GetEdgeFlags(void) = 0;
		virtual bool SetEdgeFlags(int32_t) = 0;

		virtual bool GetEdgeHashArray(int32_t*) = 0;
		virtual bool SetEdgeHashArray(int32_t const*) = 0;

		virtual uint32_t GetRetainingWallType(void) = 0;
		virtual bool SetRetainingWallType(uint32_t) = 0;
};