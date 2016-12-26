#include "../include/cIGZApp.h"
#include "../include/cIGZCheatCodeManager.h"
#include "../include/cIGZFrameWork.h"
#include "../include/cIGZMessage2.h"
#include "../include/cIGZMessageServer2.h"
#include "../include/cIGZMessage2Standard.h"
#include "../include/cIGZMessageTarget2.h"
#include "../include/cIGZMouseMessage.h"
#include "../include/cIGZWin.h"
#include "../include/cIGZWinMgr.h"
#include "../include/cISC4App.h"
#include "../include/cISC4City.h"
#include "../include/cISC4DisasterLayer.h"
#include "../include/cISC4DisasterManager.h"
#include "../include/cISC4Lot.h"
#include "../include/cISC4LotManager.h"
#include "../include/cISC4Occupant.h"
#include "../include/cISC4PollutionSimulator.h"
#include "../include/cISC4SimGrid.h"
#include "../include/cISC4View3DWin.h"
#include "../include/cRZAutoRefCount.h"
#include "../include/cRZBaseString.h"
#include "../include/cRZCOMDllDirector.h"
#include "../include/cRZPoint.h"
#include "../include/cS3DCamera.h"
#include "../include/cS3DVector3.h"
#include "../include/GZCLSIDDefs.h"
#include "../include/GZServPtrs.h"
#include <random>
#include <Windows.h>

static const uint32_t kExtraExtraCheatsPluginCOMDirectorID = 0x5b76862b;

static const uint32_t kDisasterID_Riot = 0xca380b06;
static const uint32_t kDisasterID_ToxicSpill = 0xebfb0404;
static const uint32_t kGZIID_cIGZCheatCodeManager = 0xa1085722;
static const uint32_t kGZIID_cIGZMouseMessage = 0x1a0c615f;
static const uint32_t kGZIID_cISC4App = 0x26ce01c0;
static const uint32_t kGZIID_cISC4DisasterInstance = 0x49b43f58;
static const uint32_t kGZIID_cISC4LotManager = 0x681905bd;
static const uint32_t kGZIID_cISC4View3DWin = -95964167;
static const uint32_t kGZIID_cS3DCamera = 0xe9c6262a;

static const uint32_t kGZWin_WinSC4App = 0x6104489a;
static const uint32_t kGZWin_SC4View3DWin = 0x9a47b417;

static const uint32_t kGZMSG_CheatIssued = 0x230e27ac;
static const uint32_t kGZMSG_MouseMessage = 0xfa0c6390;

static const uint32_t kCheatSievertBeGone = 0x9e0c0b4d;
static const uint32_t kCheatChernobyl = 0x606a36f7;
static const uint32_t kCheatUncivilDisobediece = 0x1bb93583;
static const uint32_t kCheatHazmat = 0x3749433c;

static const char* kszCheatSievertBeGone = "SievertBeGone";
static const char* kszCheatChernobyl = "Chernobyl";
static const char* kszCheatUncivilDisobedience = "UncivilDisobedience";
static const char* kszCheatHazmat = "hazmat";

class cGZExtraExtraCheatsPluginCOMDirector : public cRZCOMDllDirector, public cIGZMessageTarget2
{
	public:
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
			return kExtraExtraCheatsPluginCOMDirectorID;
		}

		bool DoMessage(cIGZMessage2* pMessage) {
			if (pMessage->GetType() == kGZMSG_CheatIssued) {
				cIGZMessage2Standard* pStandardMsg = static_cast<cIGZMessage2Standard*>(pMessage);

				uint32_t dwCheatID = pStandardMsg->GetData1();
				cIGZString* pszCheatData = static_cast<cIGZString*>(pStandardMsg->GetVoid2());

				ProcessCheat(dwCheatID, pszCheatData);
			}
			else if (pMessage->GetType() == kGZMSG_MouseMessage) {
				cIGZMouseMessage* pMouseMsg;
				if (pMessage->QueryInterface(kGZIID_cIGZMouseMessage, (void**)&pMouseMsg)) {
					m_sMousePos = pMouseMsg->Position();
					pMouseMsg->Release();
				}
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
				pMsgServ->AddNotification(this, kGZMSG_MouseMessage);
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
		bool ProcessCheat(uint32_t dwCheatID, cIGZString const* szCheatText) {
			switch (dwCheatID) {
				case kCheatSievertBeGone: return SetAllRadiation(false);
				case kCheatChernobyl: return SetAllRadiation(true);
				case kCheatUncivilDisobediece: return TryToStartDisasterAtMouseLocation(kDisasterID_Riot);
				case kCheatHazmat: return TryToStartDisasterAtMouseLocation(kDisasterID_ToxicSpill);
				default: return false;
			}
		}

		void RegisterCheats(cIGZCheatCodeManager* pCheatMgr) {
			// The message ID parameter has no effect, so just pass zero like
			// the rest of the game does.
			pCheatMgr->AddNotification2(this, 0);
			pCheatMgr->RegisterCheatCode(kCheatSievertBeGone, cRZBaseString(kszCheatSievertBeGone));
			pCheatMgr->RegisterCheatCode(kCheatChernobyl, cRZBaseString(kszCheatChernobyl));
			pCheatMgr->RegisterCheatCode(kCheatUncivilDisobediece, cRZBaseString(kszCheatUncivilDisobedience));
			pCheatMgr->RegisterCheatCode(kCheatHazmat, cRZBaseString(kszCheatHazmat));
		}

	protected:
		bool SetAllRadiation(bool bSetRadioactive) {
			cISC4AppPtr pApp;
			if (!pApp) return false;

			cISC4City* pCity = pApp->GetCity();
			if (!pCity) return false;

			cISC4PollutionSimulator* pPollution = pCity->GetPollutionSimulator();
			if (!pPollution) return false;

			cISC4SimGrid<short>* pGrid = pPollution->GetPollutionGrid(3);
			if (!pGrid) return false;

			for (uint32_t i = 0; i < pCity->CellCountX(); i++) {
				for (uint32_t j = 0; j < pCity->CellCountZ(); j++) {
					pPollution->SetIsRadioactive(i, j, bSetRadioactive);
				}
			}

			return true;
		}

		bool TryToStartDisasterAtMouseLocation(uint32_t dwDisasterType) {
			cISC4AppPtr pApp;
			if (!pApp) return false;

			cISC4City* pCity = pApp->GetCity();
			if (!pCity) return false;

			cIGZWin* pParentWin = pApp->GetMainWindow();
			if (!pParentWin) return false;

			pParentWin = pParentWin->GetChildWindowFromID(kGZWin_WinSC4App);
			if (!pParentWin) return false;

			cISC4View3DWin* pWin = NULL;
			if (!pParentWin->GetChildAs(kGZWin_SC4View3DWin, kGZIID_cISC4View3DWin, (void**)&pWin)) return false;

			cISC4DisasterLayer* pDisasterLayer = pCity->GetDisasterLayer();
			if (!pDisasterLayer) return false;

			cISC4DisasterManager* pDisasterManager = pDisasterLayer->GetDisasterManager(dwDisasterType);
			if (!pDisasterManager) return false;

			float fPosition[3];
			int32_t nX, nZ;

			pWin->PickTerrain(m_sMousePos.nX, m_sMousePos.nY, fPosition, false);
			pCity->PositionToCell(fPosition[0], fPosition[2], nX, nZ);

			pDisasterManager->AttemptDisasterStart(nX, nZ);
			return true;
		}

		bool GetRandomLotLocation(cISC4City* pCity, int32_t& nX, int32_t& nZ) {
			cISC4LotManager* pLotManager = pCity->GetZoneDeveloper();
			if (!pLotManager) return false;
			if (!pLotManager->QueryInterface(kGZIID_cISC4LotManager, (void**)&pLotManager)) return false;

			cISC4Lot* pLot = pLotManager->GetRandomLot();
			if (!pLot) { pLotManager->Release(); return false; }
			if (!pLot->GetLocation(nX, nZ)) { pLotManager->Release(); return false; }

			pLotManager->Release();
			return true;
		}

	protected:
		cRZPoint m_sMousePos;
};

// You need to replace the director returned here for the game and this DLL
// to use the right director. This is the only place that it's necessary to
// do so.
/*cRZCOMDllDirector* RZGetCOMDllDirector() {
	static cGZExtraExtraCheatsPluginCOMDirector sDirector;
	return &sDirector;
}*/