/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4FloraOccupant.h
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

class cISC4Occupant;
class cSC4StaticFloraData;

static const uint32_t GZIID_cISC4FloraOccupant = 0xc83dd057;

class cISC4FloraOccupant : public cIGZUnknown
{
	public:
		virtual cISC4Occupant* AsOccupant(void) = 0;

		virtual uint32_t GetFloraType(void) = 0;
		virtual bool SetFloraType(uint32_t) = 0;

		virtual uint32_t GetBirthDate(void) = 0;
		virtual bool SetBirthDate(uint32_t) = 0;

		virtual uint32_t GetLastSeedingDate(void) = 0;
		virtual bool SetLastSeedingDate(uint32_t) = 0;

		virtual int32_t GetState(void) = 0;
		virtual bool SetState(int32_t) = 0;

		virtual uint32_t GetOrientation(void) = 0;
		virtual bool SetOrientation(uint32_t) = 0;

		virtual bool SetStaticFloraData(cSC4StaticFloraData*) = 0;
};