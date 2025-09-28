/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4PropManager.h
 *
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
	virtual cISC4Occupant* AddLotProp(uint32_t propID, cS3DVector3 const& position, int32_t orientation) = 0;
	virtual bool AddLotProp(cISC4Lot* pLot, cISC4Occupant* pOccupant) = 0;
	virtual bool RemoveLotProps(cISC4Lot* pLot) = 0;
	virtual bool RemoveLotProps(int x, int z) = 0;
	virtual bool RemovePropA(cISC4Occupant* pOccupant) = 0;

	virtual bool GetStreetProps(SC4List<cISC4Occupant*>& list, int x, int z) = 0;
	virtual bool GetStreetProps(SC4List<cISC4Occupant*>& list, SC4Rect<int32_t> const& rect) = 0;
	virtual cISC4Occupant* AddStreetProp(uint32_t propID, cS3DVector3 const& position, int32_t orientation) = 0;
	virtual void RemoveStreetPropsFromTile(int x, int z) = 0;

	virtual bool GetBuildingProps(SC4List<cISC4Occupant*>& list, cISC4Occupant* pBuildingOccupant) = 0;
	virtual bool GetBuildingProps(SC4List<cISC4Occupant*>& list, int x, int z) = 0;
	virtual bool AddBuildingProp(cISC4Occupant* pBuildingOccupant, cISC4Occupant* pPropOccupant) = 0;
	virtual bool RemoveBuildingProps(cISC4Occupant* pBuildingOccupant) = 0;
	virtual bool RemoveBuildingProps(int x, int z) = 0;
	virtual bool RemoveBuildingProp(cISC4Occupant* pBuildingOccupant, cISC4Occupant* pPropOccupant) = 0;
};