/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4View3DWin.h
 *
 * Copyright (C) 2016 Nelson Gomez
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
		enum ViewInputControlStackOperation : int32_t
		{
			ViewInputControlStackOperation_None = 0,
			ViewInputControlStackOperation_RemoveCurrentControl = 1,
			ViewInputControlStackOperation_RemoveAllControls = 2,
		};

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
		virtual bool SetCurrentViewInputControl(cISC4ViewInputControl* pControl, ViewInputControlStackOperation sOperation) = 0;

		/**
		 * @brief Removes the current view input control.
		 * @param suppressPreviousControlRestore Weather the game should be prevented from
		 * returning to the user's previously selected control.
		 * @return True if successful; otherwise, false.
		 */
		virtual bool RemoveCurrentViewInputControl(bool suppressPreviousControlRestore) = 0;


		/**
		 * @brief Removes all view input controls.
		 * @param suppressPreviousControlRestore Weather the game should be prevented from
		 * returning to the user's previously selected control.
		 * @return Always false.
		 */
		virtual bool RemoveAllViewInputControls(bool suppressPreviousControlRestore) = 0;

		virtual bool AddPersistentViewInputControl(cISC4ViewInputControl* pControl) = 0;
		virtual bool RemovePersistentViewInputControl(cISC4ViewInputControl* pControl) = 0;
		virtual bool RemoveAllPersistentViewInputControls(void) = 0;

		virtual cIGZWinKeyAccelerator* GetKeyAccelerator(void) = 0;
		virtual bool SetKeyAccelerator(cIGZWinKeyAccelerator* pAccelerator) = 0;

		virtual bool SetScrolling(bool bScrolling, float fX, float fZ) = 0;
		virtual bool ScrollStop(void) = 0;
		virtual bool KillKeyboardScrolling(void) = 0;

		/**
		 * @brief Converts screen coordinates to 3D world coordinates by intersecting with terrain.
		 * @param screenX Screen X coordinate.
		 * @param screenZ Screen Z coordinate.
		 * @param pWorldCoordsOut Output array of 3 floats for world coordinates [x,y,z].
		 * @param bUnknownFlag Purpose unclear - likely controls picking precision/quality.
		 * Passed as second bool to underlying cSC43DRender::PickTerrain method.
		 * @return True if terrain was successfully picked, false otherwise.
		 */
		virtual bool PickTerrain(int32_t screenX, int32_t screenZ, float* pWorldCoordsOut, bool bUnknownFlag) = 0;

		/**
		 * @brief Converts screen coordinates to a cISC4Occupant at that location.
		 * @param screenX Screen X coordinate.
		 * @param screenZ Screen Z coordinate.
		 * @param pOccupantOut Output reference to occupant pointer (set to found occupant or null.
		 * @return True if an occupant was found, false otherwise.
		 */
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
