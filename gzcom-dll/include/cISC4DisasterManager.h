/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4DisasterManager.h
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

class cISC4DisasterInstance;

template<typename T> class SC4List;

class cISC4DisasterManager : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual uint32_t GetID(void) = 0;

		virtual cISC4DisasterInstance* AttemptDisasterStart(void) = 0;
		virtual cISC4DisasterInstance* AttemptDisasterStart(int32_t nCellX, int32_t nCellZ) = 0;

		virtual bool AddInstanceToList(cISC4DisasterInstance* pInstance) = 0;
		virtual bool RemoveInstanceFromList(cISC4DisasterInstance* pInstance) = 0;

		virtual int32_t GetActiveInstanceCount(void) = 0;
		virtual SC4List<cISC4DisasterInstance*> const* GetInstances(void) = 0;
};