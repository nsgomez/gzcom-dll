/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4DisasterInstanceVolcano.h
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

class cISC4DisasterInstanceVolcano : public cIGZUnknown
{
	public:
		virtual cISC4DisasterInstance* AsISC4DisasterInstance(void) = 0;
		virtual cISC4DisasterInstance* AsISC4DisasterInstance2(void) = 0;
		
		virtual bool SetLocation(int32_t nCellX, int32_t nCellZ) = 0;
		virtual int32_t GetLavaHeightByCityCell(int32_t nCellX, int32_t nCellZ) = 0;
		
		virtual int32_t GetState(void) = 0;
		virtual bool SetState(int32_t nState) = 0;
};