/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4View3DWin.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2025 Nicholas Hayes
 * Copyright (C) 2026 Casper Van Gheluwe
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

		/**
		 * @brief Sets the zoom level.
		 * @remarks The level is clamped to the limits set with SetZoomLimits.
		 */
		virtual int32_t SetZoom(int32_t nZoomLevel) = 0;

		/**
		 * @brief Zooms in one level, unless the view is already at the upper zoom limit.
		 * @remarks The city view calls this when the mouse wheel is scrolled up and no view
		 * input control on the stack handled it.
		 */
		virtual int32_t ZoomIn(void) = 0;

		/**
		 * @brief Zooms out one level, unless the view is already at the lower zoom limit.
		 * @remarks The city view calls this when the mouse wheel is scrolled down and no view
		 * input control on the stack handled it.
		 */
		virtual int32_t ZoomOut(void) = 0;

		/**
		 * @brief Sets the zoom levels that SetZoom, ZoomIn and ZoomOut stay within.
		 * @param nLower The lowest allowed zoom level.
		 * @param nUpper The highest allowed zoom level. Values above 4 are lowered to 4 or 5,
		 * depending on the game settings.
		 * @return Always true.
		 * @remarks The current zoom level is moved inside the new limits if needed. Setting
		 * both limits to the current level stops the player from zooming the view, while
		 * the renderer's own zoom functions keep working.
		 */
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

		/**
		 * @brief Puts a view input control on top of the control stack.
		 * @param pControl The control.
		 * @param sOperation What to do with the controls that are already on the stack.
		 * @return True if successful, or false if it failed.
		 * @remarks The game calls SetWindow and then Init on the control. See
		 * cISC4ViewInputControl for how input is passed to the controls.
		 */
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

		/**
		 * @brief Adds a view input control that stays active when the player switches tools.
		 * @param pControl The control.
		 * @return Always true.
		 * @remarks The game calls Init, SetWindow and Activate on the control, and keeps a
		 * reference to it. Persistent controls get some events before the control stack and
		 * others after it, see cISC4ViewInputControl.
		 */
		virtual bool AddPersistentViewInputControl(cISC4ViewInputControl* pControl) = 0;
		virtual bool RemovePersistentViewInputControl(cISC4ViewInputControl* pControl) = 0;
		virtual bool RemoveAllPersistentViewInputControls(void) = 0;

		virtual cIGZWinKeyAccelerator* GetKeyAccelerator(void) = 0;
		virtual bool SetKeyAccelerator(cIGZWinKeyAccelerator* pAccelerator) = 0;

		/**
		 * @brief Starts or stops scrolling the view in a direction.
		 * @param bScrolling True to start scrolling, false to stop.
		 * @param angle The scroll direction, as an angle in radians.
		 * @param speed The scroll speed.
		 */
		virtual bool SetScrolling(bool bScrolling, float angle, float speed) = 0;
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
		/**
		 * Sets or updates cursor text.
		 *
		 * If an entry with the given ID already exists, its text and icon are updated in place.
		 * If not, a new entry is inserted into a priority-sorted list. Only the highest-priority
		 * entry is displayed. Passing null or empty strings for both text parameters clears the
		 * entry.
		 *
		 * @param cursorId Unique identifier for this cursor text entry. Use a consistent ID
		 *                 per tool, so repeated calls update rather than duplicate.
		 * @param priority Display priority. Higher values take precedence; the entry with the
		 *                 highest priority in the list is the one shown.
		 * @param title Primary text line, or null to clear it.
		 * @param body Secondary text line, or null to clear it.
		 * @param icon Cursor text icon mode. 0 for default (text follows mouse), 1 to
		 *             anchor the icon at the 3D position set via SetCursorTextPosition3D. Other modes may exist.
		 */
		virtual bool SetCursorText(uint32_t cursorId, uint32_t priority, cIGZString const* title, cIGZString const* body, int32_t icon) = 0;
		/**
		 * Removes a cursor text entry by ID.
		 *
		 * If no entry with the given ID exists, this is a no-op. After removal, the display
		 * updates to show the next highest-priority entry or hides the cursor text UI if
		 * the list is empty.
		 *
		 * @param cursorId  The identifier of the cursor text entry to remove.
		 */
		virtual bool ClearCursorText(uint32_t cursorId) = 0;
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
