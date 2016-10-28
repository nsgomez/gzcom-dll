#pragma once
#include "cIGZUnknown.h"
#include <unordered_set>
#include <vector>

class cGZPersistResourceKey;
class cIGZString;
class cISC4BuildingOccupant;
class cISC4BuildingTypeFilter;
class cISC4FoundationOccupant;
class cISC4LotDeveloper;
class cISC4LotRetainingWallOccupant;
class cISC4TractDeveloper;

class cISC4BuildingDevelopmentSimulator : public cIGZUnknown
{
	public:
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

		virtual int32_t GetDeveloperType(int32_t nPurposeType, int32_t nWealthType) = 0;
		virtual int32_t GetWealth(int32_t nDeveloperType) = 0;
		virtual intptr_t GetDeveloper(int32_t nPurposeType, int32_t nWealthType) = 0;
		virtual intptr_t GetDeveloper(int32_t nDeveloperType) = 0;
		virtual intptr_t GetDevelopers(void) = 0;
		virtual cISC4TractDeveloper* GetTractDeveloper(void) = 0;
		virtual cISC4LotDeveloper* GetLotDeveloper(void) = 0;
		virtual cIGZString* GetExemplarName(uint32_t dwExemplar) = 0;
		virtual cIGZString* GetBuildingName(uint32_t dwBuilding) = 0;
		virtual int32_t GetBuildingProfile(uint32_t dwBuilding) = 0;
		virtual intptr_t GetBuildingProfilePtr(uint32_t dwBuilding) = 0;
		virtual intptr_t GetBuildingMap(void) = 0;
		virtual intptr_t GetBuildingMapKey(cISC4BuildingDevelopmentSimulator* pSimulator) = 0;
		virtual intptr_t GetBuildingMapKey(int32_t nPurpose, int32_t nWealth) = 0;
		virtual intptr_t GetSpecialBuildings(void) = 0;

		virtual int64_t GetMaxCapacity(int32_t nZoneType, int32_t nPurpose, int32_t nWealth) = 0;
		virtual bool IsSuitableForConstruction(intptr_t const& sConstructionProfile, int32_t& nReasonForFail) = 0;
		virtual bool PlopBuilding(intptr_t const& sConstructionProfile) = 0;
		
		virtual int16_t GetFreeConstructionResources(void) = 0;
		virtual int16_t GetTotalConstructionResources(void) = 0;
		virtual bool ClaimConstructionResources(uint16_t wResources) = 0;
		virtual bool ReleaseConstructionResources(uint16_t wResources) = 0;

		virtual int32_t GetDayOfLastSuccessfulBuild(int32_t nDeveloperType) = 0;
		
		virtual float GetStagePopulationMultiplier(void) = 0;
		
		virtual bool CheatIgnorePlumbing(void) = 0;
		virtual bool CheatIgnorePower(void) = 0;
		virtual bool CheatIgnoreCaps(void) = 0;
		virtual bool CheatDebugGrowth(void) = 0;
		virtual bool CheatCoffeeBar(void) = 0;
};