/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4City.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2023, 2024, 2025, 2026 Nicholas Hayes
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

class cIGZPersistDBSegment;
class cIGZString;
class cISC424HourClock;
class cISC4AdvisorSystem;
class cISC4AirportDeveloper;
class cISC4AuraSimulator;
class cISC4AutomataManager;
class cISC4AutomataControllerManager;
class cISC4AutomataScriptSystem;
class cISC4BudgetSimulator;
class cISC4BuildingDevelopmentSimulator;
class cISC4CitySituationManager;
class cISC4CivicBuildingSimulator;
class cISC4CommercialSimulator;
class cISC4CrimeSimulator;
class cISC4DemandSimulator;
class cISC4Demolition;
class cISC4DisasterLayer;
class cISC4DispatchManager;
class cISC4EffectsManager;
class cISC4FireProtectionSimulator;
class cISC4FlammabilitySimulator;
class cISC4FloraSimulator;
class cISC4HistoryWarehouse;
class cISC4IndustrialSimulator;
class cISC4LandfillDeveloper;
class cISC4LandValueSimulator;
class cISC4LotConfigurationManager;
class cISC4LotDeveloper;
class cISC4LotManager;
class cISC4MySimAgentSimulator;
class cISC4NeighborsSimulator;
class cISC4NetworkManager;
class cISC4NetworkLotManager;
class cISC4OccupantManager;
class cISC4OrdinanceSimulator;
class cISC4ParkManager;
class cISC4PlumbingSimulator;
class cISC4PoliceSimulator;
class cISC4PollutionSimulator;
class cISC4PowerSimulator;
class cISC4PropDeveloper;
class cISC4PropManager;
class cISC4ResidentialSimulator;
class cISC4SeaportDeveloper;
class cISC4Simulator;
class cISC4TractDeveloper;
class cISC4TrafficSimulator;
class cISC4TutorialSystem;
class cISC4WeatherSimulator;
class cISC4ZoneDeveloper;
class cISC4ZoneManager;
class cISTETerrain;
class cISTESurfaceWater;

class cISC4City : public cIGZUnknown
{
	public:
		enum class CitySizeType : int32_t
		{
			Small = 0,
			Medium = 1,
			Large = 2
		};

		enum class DifficultyLevel : int32_t
		{
			Easy = 0,
			Medium = 1,
			Hard = 2
		};

		enum class WorldHemisphere : int32_t
		{
			Northern = 1,
			Southern = 2
		};

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual uint32_t GetCitySerialNumber(void) const = 0;
		virtual void SetCitySerialNumber(uint32_t dwSerial) = 0;
		virtual uint32_t GetNewOccupantSerialNumber(void) = 0;

		virtual bool GetOriginalLanguageAndCountry(uint32_t& dwLanguage, uint32_t& dwCountry) const = 0;
		virtual bool GetLastLanguageAndCountry(uint32_t& dwLanguage, uint32_t& dwCountry) = 0;

		virtual void GetCitySaveFilePath(cIGZString& szPath) const = 0;
		virtual void SetCitySaveFilePath(cIGZString const& szPath) = 0;

		virtual void GetCityName(cIGZString& szName) const = 0;
		virtual void SetCityName(cIGZString const& szName) = 0;

		virtual bool GetCityNameChanged(void) const = 0;
		virtual void SetCityNameChanged(bool bToggle) = 0;

		virtual void GetMayorName(cIGZString& szName) const = 0;
		virtual void SetMayorName(cIGZString const& szName) = 0;

		virtual void GetCityDescription(cIGZString& szDescription) const = 0;
		virtual void SetCityDescription(cIGZString const& szDescription) = 0;

		virtual uint32_t GetBirthDate(void) const = 0;
		virtual void SetBirthDate(uint32_t dwDate) = 0;

		virtual bool GetEstablished(void) const = 0;
		virtual void SetEstablished(bool bEstablished) = 0;

		virtual DifficultyLevel GetDifficultyLevel(void) const = 0;
		virtual void SetDifficultyLevel(DifficultyLevel dwLevel) = 0;

		virtual void GetWorldPosition(float& fLongitude, float& fLatitude) = 0;
		virtual void SetWorldPosition(float fLongitude, float fLatitude) = 0;

		virtual float GetWorldBaseElevation(void) = 0;
		virtual void SetWorldBaseElevation(float fElevation) = 0;

		virtual WorldHemisphere GetWorldHemisphere(void) = 0;

		// intptr_t's are class instances that have yet to be discerned
		virtual cISC4Demolition* GetDemolitionUtility(void) const = 0;
		virtual cISC4HistoryWarehouse* GetHistoryWarehouse(void) const = 0;
		virtual cISC4LotManager* GetLotManager(void) const = 0;
		virtual cISC4OccupantManager* GetOccupantManager(void) const = 0;
		virtual cISC4PropManager* GetPropManager(void) const = 0;
		virtual cISC4ZoneManager* GetZoneManager(void) const = 0;
		virtual cISC4LotConfigurationManager* GetLotConfigurationManager(void) const = 0;
		virtual cISC4NetworkManager* GetNetworkManager(void) const = 0;
		virtual cISC4DispatchManager* GetDispatchManager(void) const = 0;
		virtual intptr_t GetTrafficNetwork(void) const = 0;
		virtual cISC4PropDeveloper* GetPropDeveloper(void) const = 0;
		virtual cISC4NetworkLotManager* GetNetworkLotManager(void) const = 0;
		virtual cISC4AutomataManager* GetVehicleManager(void) const = 0;
		virtual cISC4AutomataManager* GetPedestrianManager(void) const = 0;
		virtual cISC4AutomataManager* GetAircraftManager(void) const = 0;
		virtual cISC4AutomataManager* GetWatercraftManager(void) const = 0;
		virtual cISC4AutomataControllerManager* GetAutomataControllerManager(void) const = 0;
		virtual cISC4AutomataScriptSystem* GetAutomataScriptSystem(void) const = 0;
		virtual cISC4CitySituationManager* GetCitySituationManager(void) const = 0;

		virtual cISC4Simulator* GetSimulator(void) const = 0;
		virtual cISC4AuraSimulator* GetAuraSimulator(void) const = 0;
		virtual cISC4BudgetSimulator* GetBudgetSimulator(void) const = 0;
		virtual cISC4BuildingDevelopmentSimulator* GetBuildingDevelopmentSimulator(void) const = 0;
		virtual cISC4CommercialSimulator* GetCommercialSimulator(void) const = 0;
		virtual cISC4CrimeSimulator* GetCrimeSimulator(void) const = 0;
		virtual cISC4DemandSimulator* GetDemandSimulator(void) const = 0;
		virtual cISC4FireProtectionSimulator* GetFireProtectionSimulator(void) const = 0;
		virtual cISC4FlammabilitySimulator* GetFlammabilitySimulator(void) const = 0;
		virtual cISC4FloraSimulator* GetFloraSimulator(void) const = 0;
		virtual cISC4IndustrialSimulator* GetIndustrialSimulator(void) const = 0;
		virtual cISC4LandValueSimulator* GetLandValueSimulator(void) const = 0;
		virtual cISC4NeighborsSimulator* GetNeighborsSimulator(void) const = 0;
		virtual cISC4OrdinanceSimulator* GetOrdinanceSimulator(void) const = 0;
		virtual cISC4PlumbingSimulator* GetPlumbingSimulator(void) const = 0;
		virtual cISC4PoliceSimulator* GetPoliceSimulator(void) const = 0;
		virtual cISC4PollutionSimulator* GetPollutionSimulator(void) const = 0;
		virtual cISC4PowerSimulator* GetPowerSimulator(void) const = 0;
		virtual cISC4ResidentialSimulator* GetResidentialSimulator(void) const = 0;
		virtual cISC4TrafficSimulator* GetTrafficSimulator(void) const = 0;
		virtual cISC4WeatherSimulator* GetWeatherSimulator(void) const = 0;
		virtual cISC4MySimAgentSimulator* GetMySimAgentSimulator(void) const = 0;

		virtual cISC4DisasterLayer* GetDisasterLayer(void) const = 0;
		virtual cISC4CivicBuildingSimulator* GetCivicBuildingSimulator(void) const = 0;
		virtual cISC4ParkManager* GetParkManager(void) const = 0;
		virtual cISC4ZoneDeveloper* GetZoneDeveloper(void) const = 0;
		virtual cISC4SeaportDeveloper* GetSeaportDeveloper(void) const = 0;
		virtual cISC4AirportDeveloper* GetAirportDeveloper(void) const = 0;
		virtual cISC4LandfillDeveloper* GetLandfillDeveloper(void) const = 0;
		virtual cISC4LotDeveloper* GetLotDeveloper(void) const = 0;
		virtual cISC4TractDeveloper* GetTractDeveloper(void) const = 0;

		virtual cISC4AdvisorSystem* GetAdvisorSystem(void) const = 0;
		virtual cISC4TutorialSystem* GetTutorialSystem(void) const = 0;

		virtual cISTESurfaceWater* GetSurfaceWater(void) const = 0;
		virtual cISTETerrain* GetTerrain(void) const = 0;

		virtual cISC4EffectsManager* GetEffectsManager(void) const = 0;

		virtual cISC424HourClock* Get24HourClock(void) const = 0;

		virtual CitySizeType GetCitySizeType(void) const = 0;
		virtual bool SetSize(float fX, float fZ) = 0;
		virtual float SizeX(void) const = 0;
		virtual float SizeZ(void) const = 0;

		virtual float CellWidthX(void) const = 0;
		virtual float CellWidthZ(void) const = 0;

		virtual uint32_t CellCountX(void) const = 0;
		virtual uint32_t CellCountZ(void) const = 0;

		virtual void PositionToCell(float fX, float fZ, int& cX, int& cZ) const = 0;
		virtual void CellCornerToPosition(int cX, int cZ, float& fX, float& fZ) const = 0;
		virtual void CellCenterToPosition(int cX, int cZ, float& fX, float& fZ) const = 0;

		virtual bool LocationIsInBounds(float fX, float fZ) const = 0;
		virtual bool CellIsInBounds(int cX, int cZ) const = 0;
		virtual bool CellCornerIsInBounds(int cX, int cZ) const = 0;

		virtual void ToggleSimulationMode(void) = 0;
		virtual bool IsInCityTimeSimulationMode(void) = 0;

		virtual void EnableSave(void) = 0;
		virtual void DisableSave(void) = 0;
		virtual bool IsSaveDisabled(void) = 0;

		virtual void UIIncreaseLockCount(void) = 0;
		virtual void UIDecreaseLockCount(void) = 0;
		virtual int32_t UIGetLockCount(void) = 0;

		virtual bool SaveObliterated(cIGZPersistDBSegment* pSegment) = 0;
};