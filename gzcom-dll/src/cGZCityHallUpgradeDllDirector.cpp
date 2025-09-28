/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cGZCityHallUpgradeDllDirector.cpp
 *
 * Copyright (C) 2016 Nelson Gomez
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

#include "../include/cIGZApp.h"
#include "../include/cIGZCheatCodeManager.h"
#include "../include/cIGZFrameWork.h"
#include "../include/cIGZMessage2.h"
#include "../include/cIGZMessageServer2.h"
#include "../include/cIGZMessage2Standard.h"
#include "../include/cISC4AdvisorSystem.h"
#include "../include/cISC4App.h"
#include "../include/cISC4BuildingDevelopmentSimulator.h"
#include "../include/cISC4City.h"
#include "../include/cISC4Lot.h"
#include "../include/cISC4LotConfiguration.h"
#include "../include/cISC4LotConfigurationManager.h"
#include "../include/cISC4LotDeveloper.h"
#include "../include/cISC4LotManager.h"
#include "../include/cISC4Occupant.h"
#include "../include/cISC4OccupantManager.h"
#include "../include/cISC4RegionalCity.h"
#include "../include/cISCPropertyHolder.h"
#include "../include/cRZMessage2COMDirector.h"
#include "../include/cRZMessage2Standard.h"
#include "../include/cRZBaseString.h"
#include "../include/GZServPtrs.h"
#include "../include/SC4Rect.h"
#include <list>

static const uint32_t kCityHall_PopThreshold2 = 45000;
static const uint32_t kCityHall_PopThreshold3 = 95000;

static const uint32_t kGZIID_cIGZCheatCodeManager = 0xa1085722;
static const uint32_t kGZIID_cISC4App = 0x26ce01c0;
static const uint32_t kGZIID_cISC4Occupant = 649819774;
static const uint32_t kGZIID_cISCExemplarPropertyHolder = 180532727;
static const uint32_t kGZIID_cISCPropertyHolder = 622944899;

static const uint32_t kGZMSG_CheatIssued = 0x230e27ac;
static const uint32_t kGZMSG_CityInited = 0x26d31ec1;
static const uint32_t kGZMSG_MonthPassed = 0x66956816;
static const uint32_t kGZMSG_OccupantInserted = 0x99ef1142;
static const uint32_t kGZMSG_OccupantRemoved = 0x99ef1143;
static const uint32_t kGZMSG_UpgradeCityHall2 = 0xd888e355;
static const uint32_t kGZMSG_UpgradeCityHall3 = 0xd788e345;

static const uint32_t kSCPROP_ExemplarID = 0x21;
static const uint32_t kSCPROP_CityExclusionGroup = 0xea2e078b;
static const uint32_t kOccupantGroup_Reward = 0x150B;
static const uint32_t kOccupantGroup_Courthouse = 0x1511;
static const uint32_t kOccupantType_Building = 0x278128a0;
static const uint32_t kOccupantType_Default = 0x74758925;

static const uint32_t kCityHallGroup_Stage1 = 0x4a9ae483;
static const uint32_t kCityHallGroup_Stage2 = 0xaa9ae4ac;
static const uint32_t kCityHallGroup_Stage3 = 0x4a9ae4d0;

static const uint32_t kCityHallUpgradePluginCOMDirectorID = 0xb673bd5b;

static const uint32_t kCheatUpgradeCityHall = 0xb546bad0;
static const uint32_t kCheatForceCityHallSearch = 0xb546bad1;
static const char* kszCheatUpgradeCityHall = "UpgradeCityHall";
static const char* kszCheatForceCityHallSearch = "ForceCityHallSearch";

class cGZCityHallUpgradePluginCOMDirector : public cRZMessage2COMDirector
{
	public:
		cGZCityHallUpgradePluginCOMDirector() {
			pCityHall = NULL;
			uCityHallStage = 0;
		}

		uint32_t GetDirectorID() const {
			return kCityHallUpgradePluginCOMDirectorID;
		}

		bool DoMessage(cIGZMessage2* pMessage) {
			cIGZMessage2Standard* pStandardMsg = static_cast<cIGZMessage2Standard*>(pMessage);
			uint32_t dwType = pMessage->GetType();

			if (dwType == kGZMSG_CheatIssued) {
				uint32_t dwCheatID = pStandardMsg->GetData1();
				cIGZString* pszCheatData = static_cast<cIGZString*>(pStandardMsg->GetVoid2());

				ProcessCheat(dwCheatID, pszCheatData);
			}
			else if (dwType == kGZMSG_CityInited) {
				SearchForExistingCityHall();
			}
			else if (dwType == kGZMSG_MonthPassed) {
				DoMonthlyTick();
			}
			else if (dwType == kGZMSG_OccupantInserted || dwType == kGZMSG_OccupantRemoved) {
				cISC4Occupant* pOccupant = (cISC4Occupant*)pStandardMsg->GetVoid1();
				if (!pOccupant)
					return true;
				else if (dwType == kGZMSG_OccupantInserted)
					DoOccupantInserted(pOccupant);
				else
					DoOccupantRemoved(pOccupant);
			}
			else if (dwType == kGZMSG_UpgradeCityHall2)
				UpgradeCityHall(2);
			else if (dwType == kGZMSG_UpgradeCityHall3)
				UpgradeCityHall(3);

			return true;
		}

		bool PostAppInit() {
			cIGZFrameWork* const pFramework = RZGetFrameWork();
			if (!pFramework)
				return false;

			cIGZApp* const pApp = pFramework->Application();
			if (!pApp)
				return false;

			cISC4App* pISC4App;
			if (!pApp->QueryInterface(kGZIID_cISC4App, (void**)&pISC4App))
				return false;

			cIGZCheatCodeManager* pCheatMgr = pISC4App->GetCheatCodeManager();
			if (pCheatMgr && pCheatMgr->QueryInterface(kGZIID_cIGZCheatCodeManager, (void**)&pCheatMgr)) {
				RegisterCheats(pCheatMgr);
			}

			cIGZMessageServer2Ptr pMsgServ;
			if (pMsgServ) {
				pMsgServ->AddNotification(this, kGZMSG_CityInited);
				pMsgServ->AddNotification(this, kGZMSG_MonthPassed);
				pMsgServ->AddNotification(this, kGZMSG_OccupantInserted);
				pMsgServ->AddNotification(this, kGZMSG_OccupantRemoved);
				pMsgServ->AddNotification(this, kGZMSG_UpgradeCityHall2);
				pMsgServ->AddNotification(this, kGZMSG_UpgradeCityHall3);
			}

			return true;
		}

		bool OnStart(cIGZCOM* pCOM) {
			cIGZFrameWork* const pFramework = RZGetFrameWork();
			if (pFramework) {
				if (pFramework->GetState() < cIGZFrameWork::kStatePreAppInit) {
					pFramework->AddHook(this);
				}
				else {
					PreAppInit();
				}
			}

			return true;
		}

	protected:
		uint8_t GetCityHallType(cISC4Occupant* pOccupant) {
			if (pOccupant->GetType() != kOccupantType_Building) {
				return 0;
			}
			else if (!pOccupant->IsOccupantGroup(kOccupantGroup_Reward)) {
				return 0;
			}

			cISCPropertyHolder* pProperties = pOccupant->AsPropertyHolder();
			uint32_t dwProp = 0;

			if (!pProperties || !pProperties->GetProperty(kSCPROP_CityExclusionGroup, dwProp)) {
				return 0;
			}

			switch (dwProp) {
				case kCityHallGroup_Stage1: return 1;
				case kCityHallGroup_Stage2: return 2;
				case kCityHallGroup_Stage3: return 3;
				default: return 0;
			}
		}

		bool DoOccupantInserted(cISC4Occupant* pOccupant) {
			uint8_t uCityHallType = GetCityHallType(pOccupant);
			if (uCityHallType == 0) {
				return false;
			}

			pCityHall = pOccupant;
			uCityHallStage = uCityHallType;
			return true;
		}

		void DoOccupantRemoved(cISC4Occupant* pOccupant) {
			if (pOccupant == pCityHall) {
				pCityHall = NULL;
				uCityHallStage = 0;
			}
		}

		static bool CityHallIterator(cISC4Occupant* pOccupant, void* pData) {
			cGZCityHallUpgradePluginCOMDirector* inst;
			inst = reinterpret_cast<cGZCityHallUpgradePluginCOMDirector*>(pData);

			return (inst->DoOccupantInserted(pOccupant) == false);
		}

		void SearchForExistingCityHall(void) {
			cISC4App* pISC4App;
			if (!RZGetFrameWork()->Application()->QueryInterface(kGZIID_cISC4App, (void**)&pISC4App))
				return;

			cISC4City* pCity = pISC4App->GetCity();
			if (!pCity)
				return;

			cISC4OccupantManager* pManager = pCity->GetOccupantManager();
			if (!pManager)
				return;

			pManager->IterateOccupants(CityHallIterator, this, NULL, NULL, kOccupantType_Building);
		}

		void DoMonthlyTick(void) {
			if (uCityHallStage == 0)
				return;

			cISC4App* pISC4App;
			if (!RZGetFrameWork()->Application()->QueryInterface(kGZIID_cISC4App, (void**)&pISC4App))
				return;

			cISC4RegionalCity* pCity = pISC4App->GetRegionalCity();
			if (!pCity)
				return;

			int32_t nPopulation = pCity->GetPopulation();
			if (nPopulation >= kCityHall_PopThreshold3 && uCityHallStage < 3) {
				SendUpgradeMessage(kGZMSG_UpgradeCityHall3);
			}
			else if (nPopulation >= kCityHall_PopThreshold2 && uCityHallStage < 2) {
				SendUpgradeMessage(kGZMSG_UpgradeCityHall2);
			}
		}

		void SendUpgradeMessage(uint32_t dwMessageID) {
			cISC4App* pISC4App;
			if (!RZGetFrameWork()->Application()->QueryInterface(kGZIID_cISC4App, (void**)&pISC4App))
				return;

			cISC4City* pCity = pISC4App->GetCity();
			if (!pCity)
				return;

			cISC4AdvisorSystem* pAdvisory = pCity->GetAdvisorSystem();
			if (!pAdvisory)
				return;

			pAdvisory->AddRef();
			pAdvisory->PushEvent(dwMessageID, NULL);
			pAdvisory->Release();
		}

		void UpgradeCityHall(uint8_t uNewStage) {
			if (uCityHallStage >= uNewStage)
				return;

			uint32_t dwLotID = 0;
			switch (uNewStage) {
				case 1:
					dwLotID = 0x6a4bd588;
					break;

				case 2:
					dwLotID = 0x6a4bd539;
					break;

				case 3:
					dwLotID = 0x4a4bd4fc;
					break;

				default:
					return;
			}

			cISC4App* pISC4App;
			if (!RZGetFrameWork()->Application()->QueryInterface(kGZIID_cISC4App, (void**)&pISC4App)) return;

			cISC4City* pCity = pISC4App->GetCity();
			if (!pCity) return;

			cISC4LotManager* pLotManager = pCity->GetLotManager();
			if (!pLotManager) return;

			cISC4LotConfigurationManager* pConfigManager = pCity->GetLotConfigurationManager();
			if (!pConfigManager) return;

			cISC4Lot* pLot = pLotManager->GetOccupantLot(pCityHall);
			if (!pLot) return;

			cISC4BuildingDevelopmentSimulator* pBDevSim = pCity->GetBuildingDevelopmentSimulator();
			if (!pBDevSim) return;

			cISC4LotDeveloper* pDeveloper = pBDevSim->GetLotDeveloper();
			if (!pDeveloper) return;

			cISC4LotConfiguration* pConfig = pConfigManager->GetLotConfiguration(dwLotID);
			if (!pConfig) return;

			SC4Rect<int32_t> sBounds;

			pDeveloper->AddRef();

			int nLotFacing = pLot->GetFacing();
			pLot->GetBoundingRect(sBounds);

			int x1 = sBounds.topLeftX;
			int y1 = sBounds.topLeftY;
			int x2 = sBounds.bottomRightX - x1 + 1;
			int y2 = sBounds.bottomRightY - y1 + 1;

			pDeveloper->StartDemolishLot(pLot);
			pDeveloper->EndDemolishLot(pLot);

			pLot = NULL;
			pCityHall = NULL;

			/**
			 * When creating the lot and spawning its occupants, the game will
			 * handle the creation of the new city hall stage automatically.
			 */
			if (pLotManager->CreateLot(x1, y1, x2, y2, nLotFacing, pLot)) {
				pLot->SetLotConfiguration(pConfig);
				pLot->UpdateZoneType();
				pDeveloper->ConstructDefaultLot(pLot, pConfig, 0, true);
			}

			pDeveloper->Release();
		}

		bool ProcessCheat(uint32_t dwCheatID, cIGZString const* szCheatText) {
			switch (dwCheatID) {
				case kCheatUpgradeCityHall:
					if (uCityHallStage == 1) {
						SendUpgradeMessage(kGZMSG_UpgradeCityHall2);
					}
					else if (uCityHallStage == 2) {
						SendUpgradeMessage(kGZMSG_UpgradeCityHall3);
					}

					return true;

				case kCheatForceCityHallSearch:
					SearchForExistingCityHall();

				default:
					return false;
			}
		}

		void RegisterCheats(cIGZCheatCodeManager* pCheatMgr) {
			// The message ID parameter has no effect, so just pass zero like
			// the rest of the game does.
			pCheatMgr->AddNotification2(this, 0);

			cRZBaseString szCheatName(kszCheatUpgradeCityHall);
			pCheatMgr->RegisterCheatCode(kCheatUpgradeCityHall, szCheatName);

			szCheatName.FromChar(kszCheatForceCityHallSearch);
			pCheatMgr->RegisterCheatCode(kCheatForceCityHallSearch, szCheatName);
		}

	protected:
		cISC4Occupant* pCityHall;
		uint8_t uCityHallStage;
};

// You need to replace the director returned here for the game and this DLL
// to use the right director. This is the only place that it's necessary to
// do so.
/*cRZCOMDllDirector* RZGetCOMDllDirector() {
	static cGZCityHallUpgradePluginCOMDirector sDirector;
	return &sDirector;
}*/