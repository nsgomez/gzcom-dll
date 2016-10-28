#pragma once
#include "cIGZUnknown.h"
#include "SC4Rect.h"

class cISC4BuildingOccupant;
class cISC4BusinessUnit;
class cISC4Lot;
class cISC4LotBaseTextureOccupant;
class cISC4LotConfiguration;
class cISC4LotConfigurationObject;
class cISC4Occupant;

class cISC4LotDeveloper : public cIGZUnknown
{
	public:
		class BoundaryType;

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual int32_t GetSimulatorType(void) = 0;

		virtual bool StartConstruction(cISC4Lot* pLot, cISC4LotConfiguration* pConfig, uint32_t, bool) = 0;
		virtual bool ConstructDefaultLot(cISC4Lot* pLot, cISC4LotConfiguration* pConfig, uint32_t, bool) = 0;

		virtual bool AbandonBuilding(cISC4Lot* pLot, int32_t nVacateReason) = 0;
		virtual bool ReoccupyBuilding(cISC4Lot* pLot, int32_t nDeveloperType) = 0;
		virtual bool ChangeBuilding(cISC4Lot* pLot, uint32_t) = 0;

		virtual bool RemoveBuildingZotProp(cISC4Lot* pLot) = 0;

		virtual bool StartDemolishLot(cISC4Lot* pLot) = 0;
		virtual bool EndDemolishLot(cISC4Lot* pLot) = 0;
		virtual bool ExplodeLot(cISC4Lot* pLot, bool bBurnt) = 0;

		virtual float GetTerrainAltitudeByVertex(int32_t nX, int32_t nZ, bool) = 0;
		virtual float GetLowestOrHighestAreaAltitude(SC4Rect<int32_t> const&, bool, bool) = 0;
		virtual float GetLowestOrHighestAreaAltitude(SC4Rect<float> const&, bool, bool) = 0;
		virtual float GetAverageAreaAltitude(SC4Rect<float> const&, bool) = 0;
		
		virtual bool LevelAreaInternalVertices(SC4Rect<int32_t> const&, float, bool, bool, cISC4Lot*) = 0;
		virtual bool LevelBorderingVertices(SC4Rect<int32_t> const&, float, bool, cISC4Lot*) = 0;
		virtual bool AttemptAreaLevelling(SC4Rect<int32_t> const&, float, bool, bool, float, cISC4Lot*) = 0;

		virtual bool GetOccupantCellCoverage(cISC4Occupant* pOccupant, SC4Rect<int32_t>& sCoverage) = 0;

		virtual bool IsAreaDeveloped(void) = 0;
		virtual bool IsLotDeveloped(cISC4Lot* pLot) = 0;
		virtual bool IsAreaFlat(SC4Rect<int32_t> const& sBounds, bool) = 0;
		virtual bool IsLotFlat(cISC4Lot* pLot, bool) = 0;

		virtual float GetAreaAltitudeRange(SC4Rect<int32_t> const& sBounds, bool) = 0;
		virtual float GetLotAltitudeRange(cISC4Lot* pLot, bool) = 0;
		
		virtual float GetAreaSlope(SC4Rect<int32_t> const& sBounds, bool) = 0;
		virtual float GetLotSlope(cISC4Lot* pLot, bool) = 0;
		virtual float GetOccupantSlope(cISC4Occupant* pOccupant, bool) = 0;

		virtual int64_t GetLotDevelopmentCost(SC4Rect<int32_t> const& sBounds) = 0;

		virtual bool RemoveLotFromItsBusinessUnit(cISC4Lot* pLot) = 0;
		virtual bool UpdateTravelDesignates(cISC4BusinessUnit*& pUnit) = 0;
		virtual bool UpdateTravelPopulations(cISC4BusinessUnit* pUnit) = 0;

		virtual bool NeedsAnchorBuilding(SC4Rect<int32_t> const& sBounds, int32_t nPurpose) = 0;
		
		virtual bool UpdateLotElements(cISC4Lot* pLot, uint32_t) = 0;

		virtual cISC4Occupant* GetFirstBuilding(cISC4Lot* pLot) = 0;

		virtual bool GetPositionForLotConfigurationObject(cISC4Lot* pLot, cISC4LotConfiguration* pConfig, cISC4LotConfigurationObject* pObject, float*, long&) = 0;
		virtual bool GetPositionForBuilding(cISC4Lot* pLot, float*, long&) = 0;

		virtual bool GetLotBaseTextureOccupant(cISC4Lot* pLot, cISC4LotBaseTextureOccupant*& pOccupant, bool) = 0;
		virtual bool GetBoundaryLotTexture(cISC4LotDeveloper::BoundaryType* pType, uint32_t&, uint8_t&, bool&) = 0;
		virtual bool SetEmptyLotBaseTexture(cISC4Lot* pLot) = 0;
		virtual cISC4Lot* SetNormalLotBaseTexture(cISC4Lot* pLot, cISC4LotConfiguration* pConfig, bool) = 0;
		virtual bool UpdateLotBaseTextureOccupant(cISC4Lot* pLot, bool) = 0;
		virtual bool GetForceEmptyLotBaseTextures(void) = 0;
		virtual void SetForceEmptyLotBaseTextures(bool bFlag) = 0;

		virtual intptr_t GetFoundationByOccupant(cISC4Occupant* pOccupant) = 0;
		virtual intptr_t GetFoundationByStandardCityCell(int32_t, int32_t nX, int32_t nZ) = 0;
		virtual intptr_t GetFoundationByPosition(int32_t, float fX, float fZ) = 0;
		virtual intptr_t GetLotFoundation(cISC4Lot* pLot) = 0;
		
		virtual bool RemoveFoundation(int32_t, float, float) = 0;
		virtual bool RemoveLotFoundation(cISC4Lot* pLot) = 0;
		
		virtual bool AddLotFoundation(cISC4Lot* pLot, uint32_t, bool, bool, bool) = 0;
		virtual bool AddLotFoundation(cISC4Lot* pLot, cISC4LotConfiguration* pConfig, bool, bool, bool) = 0;

		virtual bool IsLotObjectFoundationRequired(float*, float*) = 0;
		virtual bool IsLotObjectFoundationRequired(cISC4Occupant* pOccupant) = 0;

		virtual bool AddBuildingFoundation(cISC4BuildingOccupant* pOccupant, uint32_t) = 0;
		virtual bool AddBuildingFoundation(cISC4BuildingOccupant* pOccupant, cISC4LotConfiguration* pConfig) = 0;
		virtual bool RemoveBuildingFoundation(cISC4Occupant* pOccupant) = 0;
		virtual bool UpdateLotFoundation(cISC4Lot* pLot) = 0;
		virtual bool UpdateLotRetainingWalls(cISC4Lot* pLot) = 0;

		virtual bool CreateLotProp(cISC4Lot* pLot, uint32_t, uint32_t) = 0;
		
		virtual bool GetLotConfigurationObjectOccupant(cISC4Lot* pLot, uint32_t, cISC4Occupant*& pOccupant) = 0;
};