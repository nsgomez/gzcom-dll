#include "../include/cIGZApp.h"
#include "../include/cIGZCheatCodeManager.h"
#include "../include/cIGZFrameWork.h"
#include "../include/cIGZMessage2.h"
#include "../include/cIGZMessageServer2.h"
#include "../include/cIGZMessage2Standard.h"
#include "../include/cIGZMessageTarget2.h"
#include "../include/cISC4App.h"
#include "../include/cISC4City.h"
#include "../include/cISC4Occupant.h"
#include "../include/cISC4RegionalCity.h"
#include "../include/cISCPropertyHolder.h"
#include "../include/cRZAutoRefCount.h"
#include "../include/cRZCOMDllDirector.h"
#include "../include/GZCLSIDDefs.h"
#include "../include/GZServPtrs.h"
#include <Windows.h>

static const uint32_t kGZIID_cIGZCheatCodeManager = 0xa1085722;
static const uint32_t kGZIID_cISC4App = 0x26ce01c0;

static const uint32_t kGZMSG_CheatIssued = 0x230e27ac;
static const uint32_t kGZMSG_MonthPassed = 0x66956816;
static const uint32_t kGZMSG_OccupantInserted = 0x99ef1142;
static const uint32_t kGZMSG_OccupantRemoved = 0x99ef1143;

static const uint32_t kSCPROP_ExemplarID = 0x21;
static const uint32_t kSCPROP_CityExclusionGroup = 0xea2e078b;
static const uint32_t kOccupantGroup_Courthouse = 0x1511;
static const uint32_t kOccupantType_Building = 0x278128a0;

static const uint32_t kCityHallGroup_Stage1 = 0x4a9ae483;
static const uint32_t kCityHallGroup_Stage2 = 0xaa9ae4ac;
static const uint32_t kCityHallGroup_Stage3 = 0x4a9ae4d0;

static const uint32_t kCityHallUpgradePluginCOMDirectorID = 0xb673bd5b;
static const uint32_t kCheatUpgradeCityHall = 0xb546bad0;
static const char* kszCheatUpgradeCityHall = "UpgradeCityHall";

class cGZCityHallUpgradePluginCOMDirector : public cRZCOMDllDirector, public cIGZMessageTarget2
{
	public:
		cGZCityHallUpgradePluginCOMDirector() {
			pCityHall = NULL;
		}

		/* Failing to explicitly delegate these methods results in some
		   ambiguity when resolving which virtual methods to use: those
		   from cIGZMessageTarget (which are pure abstract) or those from
		   cRZCOMDllDirector, and the compiler will complain. */
		bool QueryInterface(uint32_t riid, void** ppvObj) {
			if (riid == GZCLSID::kcIGZMessageTarget2) {
				*ppvObj = static_cast<cIGZMessageTarget2*>(this);
				AddRef();
				return true;
			}
			else {
				return cRZCOMDllDirector::QueryInterface(riid, ppvObj);
			}
		}

		uint32_t AddRef(void) {
			return cRZCOMDllDirector::AddRef();
		}

		uint32_t Release(void) {
			return cRZCOMDllDirector::Release();
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
			else if (dwType == kGZMSG_MonthPassed) {
				DoMonthlyTick();
			}
			else if (dwType == kGZMSG_OccupantInserted) {
				cISC4Occupant* pOccupant = (cISC4Occupant*)pStandardMsg->GetVoid1();
				DoOccupantInserted(pOccupant);
			}
			else if (dwType == kGZMSG_OccupantRemoved) {
				cISC4Occupant* pOccupant = (cISC4Occupant*)pStandardMsg->GetVoid1();
				DoOccupantRemoved(pOccupant);
			}

			return true;
		}

		bool PreAppInit() {
			return true;
		}

		bool PostAppInit() {
			cIGZFrameWork* const pFramework = RZGetFrameWork();
			if (pFramework) {
				cIGZApp* const pApp = pFramework->Application();
				if (pApp) {
					cISC4App* pISC4App;
					if (pApp->QueryInterface(kGZIID_cISC4App, (void**)&pISC4App)) {
						cIGZCheatCodeManager* pCheatMgr = pISC4App->GetCheatCodeManager();
						if (pCheatMgr && pCheatMgr->QueryInterface(kGZIID_cIGZCheatCodeManager, (void**)&pCheatMgr)) {
							RegisterCheats(pCheatMgr);
						}
					}
				}
			}

			cIGZMessageServer2Ptr pMsgServ;
			if (pMsgServ) {
				pMsgServ->AddNotification(this, kGZMSG_MonthPassed);
				pMsgServ->AddNotification(this, kGZMSG_OccupantInserted);
				pMsgServ->AddNotification(this, kGZMSG_OccupantRemoved);
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

		bool AbortiveQuit() {
			return true;
		}

	protected:
		int GetCityHallType(cISC4Occupant* pOccupant) {
			if (pOccupant->GetType() != kOccupantType_Building) {
				return 0;
			}
			else if (!pOccupant->IsOccupantGroup(kOccupantGroup_Courthouse)) {
				return 0;
			}

			cISCPropertyHolder* pProperties = pOccupant->AsPropertyHolder();
			uint32_t dwProp = 0;

			if (!pProperties || !pProperties->GetProperty(kSCPROP_CityExclusionGroup, dwProp))
				return 0;

			switch (dwProp) {
				case kCityHallGroup_Stage1: return 1;
				case kCityHallGroup_Stage2: return 2;
				case kCityHallGroup_Stage3: return 3;
				default: return 0;
			}
		}

		void DoOccupantInserted(cISC4Occupant* pOccupant) {
			int nCityHallType = GetCityHallType(pOccupant);
			if (nCityHallType == 0) {
				return;
			}

			pCityHall = pOccupant;
			
			char buf[24];
			sprintf(buf, "spawn %08x", pCityHall);
			MessageBoxA(NULL, buf, NULL, NULL);
		}

		void DoOccupantRemoved(cISC4Occupant* pOccupant) {
			if (pOccupant == pCityHall) {
				pCityHall = NULL;
				MessageBoxA(NULL, "Removed city hall!", NULL, NULL);
			}
		}

		void DoMonthlyTick(void) {
			cISC4App* pISC4App;
			if (RZGetFrameWork()->Application()->QueryInterface(kGZIID_cISC4App, (void**)&pISC4App)) {
				cISC4RegionalCity* pCity = pISC4App->GetRegionalCity();
				if (pCity) {
					// ;
				}
			}
		}

		bool ProcessCheat(uint32_t dwCheatID, cIGZString const* szCheatText) {
			switch (dwCheatID) {
				case kCheatUpgradeCityHall: return true;
				default: return false;
			}
		}

		void RegisterCheats(cIGZCheatCodeManager* pCheatMgr) {
			// The message ID parameter has no effect, so just pass zero like
			// the rest of the game does.
			pCheatMgr->AddNotification2(this, 0);

			cRZBaseString szCheatName(kszCheatUpgradeCityHall);
			pCheatMgr->RegisterCheatCode(kCheatUpgradeCityHall, szCheatName);
		}

	protected:
		cRZAutoRefCount<cISC4Occupant> pCityHall;
};

// You need to replace the director returned here for the game and this DLL
// to use the right director. This is the only place that it's necessary to
// do so.
cRZCOMDllDirector* RZGetCOMDllDirector() {
	static cGZCityHallUpgradePluginCOMDirector sDirector;
	return &sDirector;
}