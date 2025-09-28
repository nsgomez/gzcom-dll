/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4Nation.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2024 Nicholas Hayes
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

class cIGZString;
class cISC4Region;
class SC4String;

class cISC4Nation : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual SC4String* GetRegionDirectory(void) = 0;
		virtual int GetRegionCount(void) = 0;

		virtual int GetActiveRegionIndex(void) = 0;
		virtual cISC4Region* GetActiveRegion(void) = 0;
		virtual cISC4Region* SetActiveRegion(cISC4Region* pRegion) = 0;

		virtual bool GetIndexOfCurrentRegionSettingInPreferences(int32_t& nIndexOut) = 0;

		virtual cISC4Region* GetRegion(uint32_t dwIndex) = 0;
		virtual intptr_t DeleteRegion(uint32_t dwIndex) = 0;
		virtual int32_t AddNewRegion(const cIGZString& szName) = 0;

		virtual bool ResetTutorialCities(void) = 0;

		virtual SC4String* GetRegionDownloadDirectory(void) = 0;
		virtual float GetEconomyModifier(uint32_t dwDemandType) = 0;
};