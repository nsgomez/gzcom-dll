/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4Region.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2024, 2025 Nicholas Hayes
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
class cISC4RegionalCity;
class SC4String;

template <typename T> class SC4List;
template <typename T> class SC4Vector;

class cISC4Region : public cIGZUnknown
{
	public:
		enum class eCityTileSize : uint32_t
		{
			// Small city tile (4,096 cells)
			Small = 0,
			// Medium city tile (16,384 cells)
			Medium = 1,
			// Large city tile (65,536 cells)
			Large = 2
		};

		class cLocation
		{
		public:
			uint32_t x;
			uint32_t z;
			eCityTileSize cityTileSize;
		};

		virtual SC4String* GetName(void) = 0;
		virtual bool SetName(const cIGZString& szName) = 0;

		virtual SC4String* GetDirectoryName(void) = 0;
		virtual bool SetDirectoryName(const cIGZString& szName) = 0;

		virtual bool LoadConfig(void) = 0;

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;
		virtual bool Delete(void) = 0;

		virtual cISC4RegionalCity* GetCity(uint32_t x, uint32_t y) = 0;
		virtual cISC4RegionalCity**& InsertCity(cISC4RegionalCity* pCity) = 0;
		virtual bool RemoveCity(cISC4RegionalCity*& pCity) = 0;
		virtual bool DeleteCity(cISC4RegionalCity*& pCity) = 0;
		virtual bool ReloadCity(cISC4RegionalCity*& pCity) = 0;
		virtual bool MoveCity(cISC4Region* pRegion, cISC4RegionalCity* pCity, int32_t x, int32_t y) = 0;
		virtual bool GetAllCities(SC4List<cISC4RegionalCity*>& pList) = 0;

		virtual int GetBaseTerrainType(void) = 0;
		virtual cISC4Region* SetBaseTerrainType(int nType) = 0;

		virtual int GetBaseTerrainHeight(void) = 0;
		virtual int32_t GetWaterPrefs(uint8_t& cUnknown1, uint8_t& cUnknown2) = 0;

		virtual bool ResetTutorialCity(uint32_t dwTutorialCityID) = 0;

		virtual bool GetCityLocations(SC4Vector<cLocation>& cityLocations) = 0;
		virtual int32_t GetBoundingRect(intptr_t pRectLongs) = 0;
};