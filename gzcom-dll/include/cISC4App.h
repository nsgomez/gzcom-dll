#pragma once
#include "cIGZUnknown.h"

class cGZMessage;
class cIGZMessage;
class cIGZString;
class cIGZWin;
class cISC4RegionalCity;
class SC4VideoPreferences;

// Taken from the Mac vtable
class cISC4App : public cIGZUnknown
{
	public:
		virtual bool EnableFullGamePauseOnAppFocusLoss(bool bEnable) = 0;
		virtual bool FullGamePause(bool bPause) = 0;
		virtual bool GainLoseFocus(bool bFocus) = 0;
		
		virtual bool RequestNewCity(cISC4RegionalCity* pCity) = 0; // Actually an AutoRefCount
		virtual bool RequestLoadCity(void) = 0;
		virtual bool RequestCloseCity(bool bShowConfirmPrompt) = 0;
		virtual bool RequestSaveCity(bool bShowNotif, bool bUnknown) = 0;
		virtual bool RequestQuit(bool bShowDialog, bool bSaveFirst) = 0;
		virtual bool RequestQuitFromRegion(bool bShowDialog) = 0;
		virtual bool RequestGoToRegionView(bool bShowDialog) = 0;
		
		virtual bool NewCity(void) = 0;
		virtual bool LoadCity(cIGZString& szString, cISC4RegionalCity* pCityOut) = 0; // Actually an AutoRefCount
		virtual bool CloseCity(void) = 0;
		virtual bool SaveCity(bool bUnknown) = 0;
		virtual bool SaveCity(cIGZString const& szName, bool bUnknown) = 0;
		virtual bool Quit(void) = 0;

		virtual bool ApplyVideoPreferences(SC4VideoPreferences const& sPreferences) = 0;
		virtual bool GetAutoVideoPreferences(SC4VideoPreferences* pPreferencesOut) = 0;

		virtual bool GetDebugFunctionalityEnabled(void) = 0;
		virtual cISC4App* SetDebugFunctionalityEnabled(bool bEnabled) = 0;

		virtual bool GetPopupDialogsEnabled(void) = 0;
		virtual cISC4App* SetPopupDialogsEnabled(bool bEnabled) = 0;

		// All intptr_t types here are actually unspecified class types that have
		// been omitted for simplicity's sake.
		virtual int32_t GetAppState(void) = 0;
		virtual bool GetAppName(cIGZString& szNameOut) = 0;
		virtual intptr_t GetMainWindow(void) = 0;
		virtual intptr_t GetFeatureManager(void) = 0;
		virtual intptr_t GetCheatCodeManager(void) = 0;
		virtual intptr_t GetNation(void) = 0;
		virtual intptr_t GetRegion(void) = 0;
		virtual intptr_t GetRegionalCity(void) = 0;
		virtual intptr_t GetCity(void) = 0;
		virtual intptr_t GetPreferences(void) = 0;
		virtual intptr_t GetNewCitySpecification(void) = 0;
		virtual intptr_t GetDebugConsole(void) = 0;
		virtual intptr_t GetGimexFactory(void) = 0;
		virtual intptr_t GetStringDetokenizer(void) = 0;
		virtual intptr_t GetWinLocationSaver(void) = 0;
		virtual intptr_t GetRenderProperties(void) = 0;
		virtual intptr_t GetGlyphTextureManager(void) = 0;
		virtual intptr_t GetLuaInterpreter(void) = 0;
		virtual intptr_t GetTutorialRegistry(void) = 0;

		virtual bool IsRunFirstTimeAfterInstall(void) = 0;
		virtual bool GetAppDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetCDAppDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetDataDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetCDDataDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetPluginDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetCDPluginDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetSkuSpecificDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetUserDataDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetUserPluginDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetRegionsDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetMySimDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetAlbumDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetHTTPCacheDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetTempDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetExceptionReportsDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetTestScriptDirectory(cIGZString& szPathOut) = 0;
		virtual bool GetAppIniFileName(cIGZString& szPathOut) = 0;
		virtual bool GetAppIniFilePath(cIGZString& szPathOut) = 0;
		virtual bool GetAppPreferencesFileName(cIGZString& szPathOut) = 0;
		virtual bool GetAppPreferencesFilePath(cIGZString& szPathOut) = 0;

		typedef bool (*ShutdownCallback)(void*);
		virtual bool RegisterShutdownCallbackFunction(ShutdownCallback pfCallback, void* pUnknown) = 0;
		virtual bool UnregisterShutdownCallbackFunction(ShutdownCallback pfCallback, void* pUnknown) = 0;
		
		virtual bool LoadRegistry(void) = 0;
};