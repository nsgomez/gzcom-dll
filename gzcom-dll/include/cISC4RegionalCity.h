/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4RegionalCity.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2025, 2026 Nicholas Hayes
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
class cISC4City;
class cISC4NeighborConnection;
class cISC4NeighborDeal;
class SC4NewCityPreferences;

template <typename T> class SC4List;
template <typename T> class SC4Vector;

class cISC4RegionalCity : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual void GetPosition(int32_t& nX, int32_t& nZ) const = 0;
		virtual void SetPosition(int32_t nX, int32_t nZ, bool bDoRearrange) = 0;

		virtual void GetCitySize(int32_t& nX, int32_t& nZ) const = 0;
		virtual void SetCitySize(int32_t nX, int32_t nZ) = 0;

		virtual int32_t GetPopulation(void) const = 0;
		virtual int32_t GetCommercialJobs(void) const = 0;
		virtual int32_t GetIndustrialJobs(void) const = 0;
		virtual float GetWorkforcePercentage(void) const = 0;

		virtual int32_t GetMayorRating(void) const = 0;
		virtual int32_t GetDifficultyLevel(void) const = 0;
		virtual float GetTaxRate(uint32_t dwTaxType) const = 0;

		virtual int32_t GetPopulation(uint32_t dwPopulationType) const = 0;
		virtual int32_t GetExtrapolatedPopulation(uint32_t dwPopulationType) const = 0;
		virtual int32_t GetAllowableExtrapolation(uint32_t dwPopulationType) const = 0;
		virtual void ExtrapolateGrowth(uint32_t dwPopulationType, float fAddedPop) = 0;

		virtual cISC4RegionalCity* FindConnection(int32_t nUnknown1, int32_t nUnknown2, int32_t nUnknown3) const = 0;
		virtual void GetAllConnections(SC4List<cISC4NeighborConnection*>& sList) const = 0;
		virtual void ChangeSymmetricConnection(cISC4NeighborConnection* pConnection, bool bUnknown) = 0;

		virtual void SetupPreferences(SC4NewCityPreferences* pPreferences) = 0;
		virtual void UpdateCityCache(SC4NewCityPreferences* pPreferences) = 0;

		virtual void SetupCity(cISC4City* pCity) = 0;
		virtual void UpdateCityCache(cISC4City* pCity) = 0;

		virtual uint32_t GetCitySerialNumber(void) const = 0;
		virtual void SetCitySerialNumber(uint32_t dwSerialNumber) = 0;

		virtual bool GetOriginalLanguageAndCountry(int32_t& nLanguage, int32_t& nCountry) const = 0;
		virtual bool GetLastLanguageAndCountry(int32_t& nLanguage, int32_t& nCountry) = 0;

		virtual void GetCitySaveFilePath(cIGZString& sPath) const = 0;
		virtual void SetCitySaveFilePath(cIGZString const& sPath) = 0;

		virtual void GetCityName(cIGZString& sName) const = 0;
		virtual void SetCityName(cIGZString const& sName) = 0;

		virtual void GetMayorName(cIGZString& sName) const = 0;
		virtual void SetMayorName(cIGZString const& sName) = 0;

		virtual void GetUtilityAdvisorName(cIGZString& sName) const = 0;
		virtual void SetUtilityAdvisorName(cIGZString const& sName) = 0;

		virtual void GetCityDescription(cIGZString& sDescription) const = 0;
		virtual void SetCityDescription(cIGZString const& sDescription) = 0;

		virtual uint32_t GetBirthDate(void) const = 0;
		virtual void SetBirthDate(uint32_t dwBirthDate) = 0;

		virtual bool GetEstablished(void) const = 0;
		virtual void SetEstablished(bool bEstablished) = 0;

		virtual void GetWorldPosition(float& fLongitude, float& fLatitude) const = 0;
		virtual void SetWorldPosition(float fLongitude, float fLatitude) = 0;

		virtual float GetWorldBaseElevation(void) const = 0;
		virtual void GetWorldBaseElevation(float fElevation) = 0;

		virtual int32_t GetWorldHemisphere(void) const = 0;

		virtual float GetBudget(void) const = 0;
		virtual void SetBudget(float fBudget) = 0;

		virtual float GetIncome(void) const = 0;
		virtual void SetIncome(float fIncome) = 0;

		virtual float GetExported(int32_t nCommodity) const = 0;
		virtual void SetExported(int32_t nCommodity, float fExports) = 0;

		virtual float GetImported(int32_t nCommodity) const = 0;
		virtual void SetImported(int32_t nCommodity, float fImports) = 0;

		virtual float GetProduced(int32_t nCommodity) const = 0;
		virtual void SetProduced(int32_t nCommodity, float fProduced) = 0;

		virtual float GetDemanded(int32_t nCommodity) const = 0;
		virtual void SetDemanded(int32_t nCommodity, float fDemanded) = 0;

		virtual float GetCostPerUnit(int32_t nCommodity) const = 0;
		virtual void SetCostPerUnit(int32_t nCommodity, float fCostPerUnit) = 0;

		virtual float GetCommodityBalance(int32_t nCommodity) const = 0;

		virtual uint32_t GetTutorialGUID(void) const = 0;
		virtual void SetTutorialGUID(uint32_t dwGUID) = 0;
		virtual bool IsTutorial(void) const = 0;

		virtual bool UpdateLocalDeals(void) = 0;
		virtual bool SetLocalDeals(SC4List<cISC4NeighborDeal*>& sList) = 0;
		virtual bool GetLocalDeals(SC4List<cISC4NeighborDeal*>& sList) = 0;

		virtual bool UpdateImportExport(void) = 0;

		virtual void GetPointsOfInterest(uint32_t dwPointOfInterestType, SC4Vector<uint32_t>& sList) = 0;
};