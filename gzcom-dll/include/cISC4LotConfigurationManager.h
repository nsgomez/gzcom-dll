/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4LotConfigurationManager.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2025 Nicholas Hayes, Casper Van Gheluwe
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

class cGZPersistResourceKey;
class cISC4LotConfiguration;
class cISC4LotConfigurationFilter;
class cS3DRect2D;
class cSC4LotConfigurationObject;

template <typename T> class SC4Vector;
template <typename T> struct SC4HashSet;

class cISC4LotConfigurationManager : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool AddLotConfiguration(cISC4LotConfiguration* pConfig, bool bUnknown) = 0;
		virtual bool AddLotConfiguration(cGZPersistResourceKey const& sUnknown, void* pUnknown) = 0;
		virtual bool RemoveLotConfiguration(uint32_t dwConfigID) = 0;

		virtual cISC4LotConfiguration* GetLotConfiguration(uint32_t dwConfigID) = 0;
		virtual bool GetLotConfigurationsByFilter(SC4HashSet<cISC4LotConfiguration*>& sConfigs, cISC4LotConfigurationFilter* pFilter) = 0;
		virtual bool GetLotConfigurationsByFamily(SC4HashSet<cISC4LotConfiguration*>& sConfigs, uint32_t dwFamily) = 0;
		virtual bool GetLotConfigurationsBySize(SC4HashSet<cISC4LotConfiguration*>& sConfigs, uint32_t sX, uint32_t sZ) = 0;
		virtual bool ClearLotConfigurationSet(SC4HashSet<cISC4LotConfiguration*>& sConfigs) = 0;

		virtual bool GetLotConfigurationIDsByFilter(SC4HashSet<uint32_t>& sConfigs, cISC4LotConfigurationFilter* pFilter) = 0;
		virtual bool GetLotConfigurationIDsByFamily(SC4HashSet<uint32_t>& sConfigs, uint32_t dwFamily) = 0;
		virtual bool GetLotConfigurationIDsBySize(SC4HashSet<uint32_t>& sConfigs, uint32_t sX, uint32_t sZ) = 0;

		virtual bool LotConfigurationHasBuildingFamily(cISC4LotConfiguration* pConfig, uint32_t dwFamily, cSC4LotConfigurationObject** ppObj) = 0;
		virtual bool LotConfigurationHasBuildingType(cISC4LotConfiguration* pConfig, uint32_t dwFamily, cSC4LotConfigurationObject** ppObj) = 0;

		virtual bool RegisterLotConfigurationFilter(cISC4LotConfigurationFilter* pFilter) = 0;
		virtual bool UnregisterLotConfigurationFilter(cISC4LotConfigurationFilter* pFilter) = 0;

		virtual intptr_t GetLotConfigurationMap(void) = 0;
		virtual intptr_t GetLotConfigurationFamilyIDSet(void) = 0;

		virtual bool CreateGenericLotConfiguration(cISC4LotConfiguration*& pConfig, uint32_t dwConfigID) = 0;
		virtual bool FixLotConfiguration(cISC4LotConfiguration* pConfig) = 0;

		virtual bool GetMaxFootprintForBuildingFamilies(SC4Vector<uint32_t> const& sFamilies, cS3DRect2D& sRect) = 0;
		virtual bool GetMaxFootprintForFloraFamilies(SC4Vector<uint32_t> const& sFamilies, cS3DRect2D& sRect) = 0;
		virtual bool GetMaxFootprintForPropFamilies(SC4Vector<uint32_t> const& sFamilies, cS3DRect2D& sRect) = 0;

		virtual bool GetObjectIDArray(cSC4LotConfigurationObject* pConfigObj, SC4Vector<uint32_t>& sArray) = 0;
};