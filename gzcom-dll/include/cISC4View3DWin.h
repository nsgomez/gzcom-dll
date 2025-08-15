#pragma once
#include "cIGZUnknown.h"

class cIGZCommandParameterSet;
class cIGZString;
class cIGZWin;
class cIGZWinKeyAccelerator;
class cISC43DRender;
class cISC4Occupant;
class cISC4ViewInputControl;
class cISC4ViewManager;
class cS3DVector3;
class cSC4ViewFilterInformation;
class cSC4ViewLevelInformation;

static const uint32_t kGZIID_cISC4View3DWin = 0xFA47B3F9;

class cISC4View3DWin : public cIGZUnknown
{
	public:
		virtual cIGZWin* AsIGZWin(void) = 0;

		virtual cISC43DRender* GetRenderer(void) = 0;
		virtual cIGZUnknown* GetModelMaker(void) = 0;
		virtual cISC4ViewManager* GetViewManager(void) = 0;

		virtual bool ProcessCommand(uint32_t dwCommandID, cIGZCommandParameterSet&, cIGZCommandParameterSet&) = 0;

		virtual int32_t SetZoom(int32_t nZoomLevel) = 0;
		virtual int32_t ZoomIn(void) = 0;
		virtual int32_t ZoomOut(void) = 0;
		virtual bool SetZoomLimits(int32_t nLower, int32_t nUpper) = 0;
		virtual bool CanZoomIn(void) = 0;
		virtual bool CanZoomOut(void) = 0;

		virtual int32_t SetRotation(int32_t nOrientation) = 0;
		virtual int32_t RotateLeft(void) = 0;
		virtual int32_t RotateRight(void) = 0;
		virtual int32_t SetZoomAndRotation(int32_t nZoom, int32_t nRotation) = 0;

		virtual bool GetCurrentViewFilterInfo(cSC4ViewFilterInformation& sInfo) = 0;
		virtual bool SetCurrentViewFilterInfo(cSC4ViewFilterInformation& sInfo) = 0;

		virtual bool GetCurrentViewLevelInfo(cSC4ViewLevelInformation& sInfo) = 0;
		virtual bool SetCurrentViewLevelInfo(cSC4ViewLevelInformation& sInfo) = 0;

		virtual int32_t GetCurrentViewLevel(void) = 0;
		virtual bool SetCurrentViewLevel(uint32_t nLevel) = 0;

		virtual cISC4ViewInputControl* GetCurrentViewInputControl(void) = 0;
		virtual bool SetCurrentViewInputControl(cISC4ViewInputControl* pControl, int32_t sOperation) = 0;
		virtual bool RemoveCurrentViewInputControl(bool) = 0;
		virtual bool RemoveAllViewInputControls(bool) = 0;

		virtual bool AddPersistentViewInputControl(cISC4ViewInputControl* pControl) = 0;
		virtual bool RemovePersistentViewInputControl(cISC4ViewInputControl* pControl) = 0;
		virtual bool RemoveAllPersistentViewInputControls(void) = 0;

		virtual cIGZWinKeyAccelerator* GetKeyAccelerator(void) = 0;
		virtual bool SetKeyAccelerator(cIGZWinKeyAccelerator* pAccelerator) = 0;

		virtual bool SetScrolling(bool bScrolling, float fX, float fZ) = 0;
		virtual bool ScrollStop(void) = 0;
		virtual bool KillKeyboardScrolling(void) = 0;

		/// <summary>
		/// Converts screen coordinates to 3D world coordinates by intersecting with terrain.
		/// </summary>
		/// <param name="screenX">Screen X coordinate</param>
		/// <param name="screenZ">Screen Z coordinate</param>
		/// <param name="pWorldCoordsOut">Output array of 3 floats for world coordinates [x,y,z]</param>
		/// <param name="bUnknownFlag">Purpose unclear - likely controls picking precision/quality.
		/// Passed as second bool to underlying cSC43DRender::PickTerrain method.</param>
		/// <returns>true if terrain was successfully picked, false otherwise</returns>
		virtual bool PickTerrain(int32_t screenX, int32_t screenZ, float* pWorldCoordsOut, bool bUnknownFlag) = 0;

		/// <summary>
		/// Converts screen coordinates to a cISC4Occupant at that location.
		/// </summary>
		/// <param name="screenX">Screen X coordinate</param>
		/// <param name="screenZ">Screen Z coordinate</param>
		/// <param name="pOccupantOut">Output reference to occupant pointer (set to found occupant or null)</param>
		/// <returns>true if an occupant was found, false otherwise</returns>
		virtual bool PickOccupant(int32_t screenX, int32_t screenZ, cISC4Occupant*& pOccupantOut) = 0;

		virtual void DisplayTerrainPickDebugString(int32_t, int32_t) = 0; // no-op
		virtual bool GetTerrainQueryEnabled(void) = 0;
		virtual bool SetCursorText(uint32_t, uint32_t, cIGZString const*, cIGZString const*, int32_t) = 0;
		virtual bool ClearCursorText(uint32_t) = 0;
		virtual bool SetCostIndicator(uint32_t) = 0;
		virtual bool SetCostIndicator(uint32_t, uint32_t) = 0;
		virtual bool ClearCostIndicator(bool) = 0;

		virtual bool SetErrorReportString(char const*) = 0;
		virtual int32_t GetGlobalEffectTriggerState(uint32_t) = 0;
		virtual int32_t AssertGlobalEffectTrigger(uint32_t) = 0;
		virtual int32_t RetractGlobalEffectTrigger(uint32_t) = 0;

		virtual int32_t GetCoverageHelper(void) = 0;
		virtual bool SetCursorTextPosition3D(cS3DVector3 const&) = 0;

		virtual uint32_t GetLastSelectedBuilding(void) = 0;
		virtual uint32_t GetLastSelectedLot(void) = 0;

		virtual bool SetLastSelectedBuilding(uint32_t) = 0;
		virtual bool SetLastSelectedLot(uint32_t) = 0;

		virtual bool MinimizeUI(bool) = 0;

		virtual bool ShowMissionStatusPanel(uint32_t) = 0;
		virtual bool HideMissionStatusPanel(void) = 0;
		virtual bool UpdateMissionStatusPanel(void) = 0;

		virtual bool CloseSecondaryMenu(void) = 0;
		virtual void CloseTertiaryMenu(void) = 0;
};
