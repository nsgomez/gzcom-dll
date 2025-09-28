/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4BuildingDevelopmentSimulator.h
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
#include "cISC4BuildingOccupant.h"
#include "cISC4ZoneManager.h"
#include <unordered_set>

class cGZPersistResourceKey;
class cIGZString;
class cISC4BuildingTypeFilter;
class cISC4FoundationOccupant;
class cISC4GrowthDeveloper;
class cISC4LotDeveloper;
class cISC4LotRetainingWallOccupant;
class cISC4TractDeveloper;
template <typename T> class SC4Vector;

class cISC4BuildingDevelopmentSimulator : public cIGZUnknown
{
	public:
		class ConstructionProfile
		{
		public:
			uint32_t unknown1;
			uint32_t unknown2;
			cISC4BuildingOccupant::WealthType wealth;
			cISC4BuildingOccupant::PurposeType purpose;
			uint8_t landValueRangeMin;
			uint8_t landValueRangeMax;
			uint32_t buildingType;
			uint32_t unknown3; // facing?
			uint32_t cellCenterX;
			uint32_t cellCenterZ;
		};

		enum class DeveloperType : uint32_t
		{
			None = 0,
			ResidentialLowWealth = 0x1010,
			ResidentialMediumWealth = 0x1020,
			ResidentialHighWealth = 0x1030,
			CommercialServicesLowWealth = 0x3110,
			CommercialServicesMediumWealth = 0x3120,
			CommercialServicesHighWealth = 0x3130,
			CommercialOfficeMediumWealth = 0x3320,
			CommercialOfficeHighWealth = 0x3330,
			IndustrialAgriculture = 0x4100,
			IndustrialProcessing = 0x4200,
			IndustrialManufacturing = 0x4300,
			IndustrialHighTech = 0x4400,
		};

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool LocationIsOKForNewBuilding(uint32_t dwBuilding, float fPosX, float fPosZ) = 0;

		virtual bool AddNewBuildingOccupant(cISC4BuildingOccupant* pOccupant) = 0;
		virtual bool AddNewBuildingOccupant(uint32_t dwUnknown, float* pfUnknown, int32_t nUnknown) = 0;
		virtual bool AddNewBuildingOccupant(uint32_t dwUnknown, int32_t nUnknown1, int32_t nUnknown2, int32_t nUnknown3) = 0;

		virtual int64_t GetCostOfOccupantDemolition(cISC4BuildingOccupant* pOccupant, uint32_t dwUnknown) = 0;

		virtual size_t GetAllBuildingTypes(uint32_t* pArray, uint32_t& nCount) = 0;
		virtual size_t GetAllBuildingTypes(SC4Vector<uint32_t>& sList) = 0;
		virtual size_t GetAllBuildingFamilyTypes(SC4Vector<uint32_t>& sList) = 0;

		virtual bool GetBuildingKeyFromType(uint32_t dwType, cGZPersistResourceKey& sKey) = 0;

		virtual bool IsBuildingTypeValid(uint32_t dwType) = 0;
		virtual bool IsBuildingFamilyTypeValid(uint32_t dwFamilyType) = 0;

		virtual bool GetBuildingTypesByFilter(std::unordered_set<uint32_t>& sList, cISC4BuildingTypeFilter* pFilter) = 0;
		virtual bool GetBuildingTypesByFamily(std::unordered_set<uint32_t>& sList, uint32_t dwFamily) = 0;
		virtual bool GetBuildingTypesByFamily(SC4Vector<uint32_t>& sList, uint32_t dwFamily) = 0;

		virtual bool IsBuildingInFamily(uint32_t dwBuilding, uint32_t dwFamily) = 0;

		virtual bool GetAllFoundationTypes(SC4Vector<uint32_t>& sList) = 0;
		virtual bool GetFoundationKeyFromType(uint32_t dwType, cGZPersistResourceKey& sKey) = 0;
		virtual bool AddNewFoundationOccupant(cISC4FoundationOccupant* pOccupant) = 0;
		virtual bool AddNewFoundationOccupant(uint32_t, int32_t, float*, float, float, int, float) = 0;
		virtual bool DemolishFoundationOccupant(cISC4FoundationOccupant* pOccupant, uint32_t) = 0;
		virtual int64_t GetCostOfOccupantDemolition(void) = 0;
		virtual bool LoadFoundationProperties(cISC4FoundationOccupant* pOccupant, uint32_t) = 0;

		virtual bool GetAllLotRetainingWallTypes(SC4Vector<uint32_t>& sList) = 0;
		virtual bool GetLotRetainingWallKeyFromType(uint32_t dwType, cGZPersistResourceKey& sKey) = 0;
		virtual bool LoadLotRetainingWallProperties(cISC4LotRetainingWallOccupant* pOccupant, uint32_t) = 0;

		virtual DeveloperType GetDeveloperType(cISC4BuildingOccupant::PurposeType purpose, cISC4BuildingOccupant::WealthType wealth) = 0;
		virtual cISC4BuildingOccupant::WealthType GetWealth(DeveloperType developerType) = 0;
		virtual cISC4GrowthDeveloper* GetDeveloper(cISC4BuildingOccupant::PurposeType purpose, cISC4BuildingOccupant::WealthType wealth) const = 0;
		virtual cISC4GrowthDeveloper* GetDeveloper(DeveloperType developerType) const = 0;
		virtual intptr_t GetDevelopers(void) = 0;
		virtual cISC4TractDeveloper* GetTractDeveloper(void) = 0;
		virtual cISC4LotDeveloper* GetLotDeveloper(void) = 0;
		virtual cIGZString* GetExemplarName(uint32_t dwExemplar) = 0;
		virtual cIGZString* GetBuildingName(uint32_t dwBuilding) = 0;
		virtual cISC4BuildingOccupant::BuildingProfile& GetBuildingProfile(uint32_t dwBuilding) const = 0;
		virtual cISC4BuildingOccupant::BuildingProfile* GetBuildingProfilePtr(uint32_t dwBuilding) const = 0;
		virtual intptr_t GetBuildingMap(void) = 0;
		virtual intptr_t GetBuildingMapKey(uint32_t dwBuilding) = 0;
		virtual intptr_t GetBuildingMapKey(cISC4BuildingOccupant::PurposeType purpose, cISC4BuildingOccupant::WealthType wealth) = 0;
		virtual intptr_t GetSpecialBuildings(void) = 0;

		virtual int64_t GetMaxCapacity(cISC4ZoneManager::ZoneType zone, cISC4BuildingOccupant::PurposeType purpose, cISC4BuildingOccupant::WealthType wealth) = 0;
		virtual bool IsSuitableForConstruction(intptr_t const& sConstructionProfile, int32_t& nReasonForFail) = 0;
		virtual bool PlopBuilding(ConstructionProfile const& sConstructionProfile) = 0;

		virtual int16_t GetFreeConstructionResources(void) = 0;
		virtual int16_t GetTotalConstructionResources(void) = 0;
		virtual bool ClaimConstructionResources(uint16_t wResources) = 0;
		virtual bool ReleaseConstructionResources(uint16_t wResources) = 0;

		virtual int32_t GetDayOfLastSuccessfulBuild(DeveloperType developerType) = 0;

		virtual float GetStagePopulationMultiplier(void) = 0;

		virtual bool CheatIgnorePlumbing(void) = 0;
		virtual bool CheatIgnorePower(void) = 0;
		virtual bool CheatIgnoreCaps(void) = 0;
		virtual bool CheatDebugGrowth(void) = 0;
		virtual bool CheatCoffeeBar(void) = 0;
};