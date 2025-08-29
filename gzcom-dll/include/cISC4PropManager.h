#pragma once
#include "cIGZUnknown.h"
#include "cISC4PropOccupant.h"

class cGZPersistResourceKey;
class cIGZString;
class cISC4Lot;
class cISC4Occupant;

template <typename T> class SC4List;
template <typename T> class SC4Rect;
template <typename T> class SC4Vector;

class cISC4PropManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void GetAllPropTypes(SC4Vector<uint32_t>& param_1) = 0;
	virtual void GetAllPropFamilyTypes(SC4Vector<uint32_t>& param_1) = 0;
	virtual bool GetPropKeyFromType(uint32_t propID, cGZPersistResourceKey& key) = 0;

	virtual bool IsPropTypeValid(uint32_t propID) = 0;
	virtual uint32_t GetPropTypesByFamily(SC4Vector<uint32_t>& vector, uint32_t propFamily) = 0;
	virtual bool IsPropInFamily(uint32_t propID, uint32_t familyType) = 0;
	virtual bool IsPropFamilyTypeValid(uint32_t propFamily) = 0;

	virtual cIGZString* GetPropName(uint32_t propID) const = 0;
	virtual cISC4PropOccupant::PropProfile& GetPropProfile(uint32_t propID) const = 0;
	virtual cISC4PropOccupant::PropProfile* GetPropProfilePtr(uint32_t propID) const = 0;

	virtual bool CreateProp(uint32_t param_1, cISC4PropOccupant*& prop) = 0;
	virtual bool CreateGenericProp(cGZPersistResourceKey const& key, cISC4PropOccupant*& prop) = 0;

	virtual bool GetCityProps(SC4List<cISC4Occupant*>& list, SC4Rect<int32_t> const& rect) = 0;
	virtual bool GetCityProps(SC4List<cISC4Occupant*>& list, SC4Rect<float> const& rect) = 0;
	virtual bool AddCityProp(uint32_t propID, cS3DVector3 const& position, int32_t orientation) = 0;
	virtual bool AddCityProp(cISC4Occupant* pOccupant) = 0;
	virtual bool RemoveCityProps(SC4Rect<float> const& rect) = 0;
	virtual bool RemoveCityProps(SC4Rect<int32_t> const& rect) = 0;

	virtual bool GetLotProps(SC4List<cISC4Occupant*>& list, cISC4Lot* pLot) = 0;
	virtual bool GetLotProps(SC4List<cISC4Occupant*>& list, int x, int z) = 0;
	virtual bool AddLotProp(uint32_t propID, cS3DVector3 const& position, int32_t orientation) = 0;
	virtual bool AddLotProp(cISC4Lot* pLot, cISC4Occupant* pOccupant) = 0;
	virtual bool RemoveLotProps(cISC4Lot* pLot) = 0;
	virtual bool RemoveLotProps(int x, int z) = 0;
	virtual bool RemovePropA(cISC4Occupant* pOccupant) = 0;

	virtual bool GetStreetProps(SC4List<cISC4Occupant*>& list, int x, int z) = 0;
	virtual bool GetStreetProps(SC4List<cISC4Occupant*>& list, SC4Rect<int32_t> const& rect) = 0;
	virtual bool AddStreetProp(uint32_t propID, cS3DVector3 const& position, int32_t orientation) = 0;
	virtual void RemoveStreetPropsFromTile(int x, int z) = 0;

	virtual bool GetBuildingProps(SC4List<cISC4Occupant*>& list, cISC4Occupant* pBuildingOccupant) = 0;
	virtual bool GetBuildingProps(SC4List<cISC4Occupant*>& list, int x, int z) = 0;
	virtual bool AddBuildingProp(cISC4Occupant* pBuildingOccupant, cISC4Occupant* pPropOccupant) = 0;
	virtual bool RemoveBuildingProps(cISC4Occupant* pBuildingOccupant) = 0;
	virtual bool RemoveBuildingProps(int x, int z) = 0;
	virtual bool RemoveBuildingProp(cISC4Occupant* pBuildingOccupant, cISC4Occupant* pPropOccupant) = 0;
};