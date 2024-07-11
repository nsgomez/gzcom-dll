#pragma once
#include "cIGZUnknown.h"
#include "cISC4BuildingOccupant.h"
#include "cISC4ZoneManager.h"
#include <unordered_set>
#include <vector>

class cGZPersistResourceKey;
class cIGZString;
class cISC4BuildingTypeFilter;
class cISC4FoundationOccupant;
class cISC4LotDeveloper;
class cISC4LotRetainingWallOccupant;
class cISC4TractDeveloper;

class cISC4BuildingDevelopmentSimulator : public cIGZUnknown
{
	public:
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
		virtual size_t GetAllBuildingTypes(std::vector<uint32_t>& sList) = 0;
		virtual size_t GetAllBuildingFamilyTypes(std::vector<uint32_t>& sList) = 0;

		virtual bool GetBuildingKeyFromType(uint32_t dwType, cGZPersistResourceKey& sKey) = 0;

		virtual bool IsBuildingTypeValid(uint32_t dwType) = 0;
		virtual bool IsBuildingFamilyTypeValid(uint32_t dwFamilyType) = 0;

		virtual bool GetBuildingTypesByFilter(std::unordered_set<uint32_t>& sList, cISC4BuildingTypeFilter* pFilter) = 0;
		virtual bool GetBuildingTypesByFamily(std::unordered_set<uint32_t>& sList, uint32_t dwFamily) = 0;
		virtual bool GetBuildingTypesByFamily(std::vector<uint32_t>& sList, uint32_t dwFamily) = 0;

		virtual bool IsBuildingInFamily(uint32_t dwBuilding, uint32_t dwFamily) = 0;

		virtual bool GetAllFoundationTypes(std::vector<uint32_t>& sList) = 0;
		virtual bool GetFoundationKeyFromType(uint32_t dwType, cGZPersistResourceKey& sKey) = 0;
		virtual bool AddNewFoundationOccupant(cISC4FoundationOccupant* pOccupant) = 0;
		virtual bool AddNewFoundationOccupant(uint32_t, int32_t, float*, float, float, int, float) = 0;
		virtual bool DemolishFoundationOccupant(cISC4FoundationOccupant* pOccupant, uint32_t) = 0;
		virtual int64_t GetCostOfOccupantDemolition(void) = 0;
		virtual bool LoadFoundationProperties(cISC4FoundationOccupant* pOccupant, uint32_t) = 0;

		virtual bool GetAllLotRetainingWallTypes(std::vector<uint32_t>& sList) = 0;
		virtual bool GetLotRetainingWallKeyFromType(uint32_t dwType, cGZPersistResourceKey& sKey) = 0;
		virtual bool LoadLotRetainingWallProperties(cISC4LotRetainingWallOccupant* pOccupant, uint32_t) = 0;

		virtual DeveloperType GetDeveloperType(cISC4BuildingOccupant::PurposeType purpose, cISC4BuildingOccupant::WealthType wealth) = 0;
		virtual cISC4BuildingOccupant::WealthType GetWealth(DeveloperType developerType) = 0;
		virtual intptr_t GetDeveloper(cISC4BuildingOccupant::PurposeType purpose, cISC4BuildingOccupant::WealthType wealth) = 0;
		virtual intptr_t GetDeveloper(DeveloperType developerType) = 0;
		virtual intptr_t GetDevelopers(void) = 0;
		virtual cISC4TractDeveloper* GetTractDeveloper(void) = 0;
		virtual cISC4LotDeveloper* GetLotDeveloper(void) = 0;
		virtual cIGZString* GetExemplarName(uint32_t dwExemplar) = 0;
		virtual cIGZString* GetBuildingName(uint32_t dwBuilding) = 0;
		virtual cISC4BuildingOccupant::BuildingProfile& GetBuildingProfile(uint32_t dwBuilding) const = 0;
		virtual cISC4BuildingOccupant::BuildingProfile* GetBuildingProfilePtr(uint32_t dwBuilding) const = 0;
		virtual intptr_t GetBuildingMap(void) = 0;
		virtual intptr_t GetBuildingMapKey(cISC4BuildingDevelopmentSimulator* pSimulator) = 0;
		virtual intptr_t GetBuildingMapKey(cISC4BuildingOccupant::PurposeType purpose, cISC4BuildingOccupant::WealthType wealth) = 0;
		virtual intptr_t GetSpecialBuildings(void) = 0;

		virtual int64_t GetMaxCapacity(cISC4ZoneManager::ZoneType zone, cISC4BuildingOccupant::PurposeType purpose, cISC4BuildingOccupant::WealthType wealth) = 0;
		virtual bool IsSuitableForConstruction(intptr_t const& sConstructionProfile, int32_t& nReasonForFail) = 0;
		virtual bool PlopBuilding(intptr_t const& sConstructionProfile) = 0;

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