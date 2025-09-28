/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cSC4BaseViewInputControl.h
 *
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
#include "cRZBaseUnknown.h"
#include "cIGZCursor.h"
#include "cIGZWin.h"
#include "cIGZWinMgr.h"
#include "cISC4View3DWin.h"
#include "cISC4ViewInputControl.h"
#include "cRZAutoRefCount.h"

class cSC4BaseViewInputControl : public cRZBaseUnknown, public cISC4ViewInputControl
{
protected:
	/**
	 * @brief Constructs the cSC4BaseViewInputControl
	 * @param controlCLSID The unique id that identifies this view input control.
	 * It should be a randomly generated unsigned 32-bit integer.
	 */
	cSC4BaseViewInputControl(uint32_t controlID);

public:
	// cIGZUnknown

	bool QueryInterface(uint32_t riid, void** ppvObj) override;
	uint32_t AddRef() override;
	uint32_t Release() override;

	// cISC4ViewInputControl

	/**
	 * @brief Initializes the control.
	 * @return True if successful; otherwise, false.
	 * @remarks Make sure you call the base class implementation first if you override this.
	 */
	bool Init() override;

	/**
	 * @brief Shuts down the control.
	 * @return True if successful; otherwise, false.
	 * @remarks Make sure you call the base class implementation first if you override this.
	 */
	bool Shutdown() override;

	/**
	 * @brief Gets the control id.
	 * @return The control id.
	 */
	uint32_t GetID() override;

	/**
	 * @brief Sets the control id.
	 * @param id The control id.
	 */
	void SetID(uint32_t id) override;

	/**
	 * @brief Gets the cursor used by this view input control.
	 * @return The cursor used by this view input control.
	 */
	cIGZCursor* GetCursor() override;

	/**
	 * @brief Sets the cursor used by this view input control.
	 * @param pIGZCursor The cursor to use for this view input control.
	 */
	void SetCursor(cIGZCursor* pIGZCursor) override;

	/**
	 * @brief Sets the cursor used by this view input control.
	 * @param cursorID The cursor to use for this view input control.
	 */
	void SetCursor(uint32_t cursorID) override;

	/**
	 * @brief Sets the parent window for this view input control.
	 * @param pWin The parent window for this view input control.
	 */
	void SetWindow(cIGZWin* pWin) override;

	/**
	 * @brief Weather the control handles its own scrolling.
	 * @return True if the control handles its own scrolling; otherwise, false.
	 * @remarks Defaults to false.
	 */
	bool IsSelfScrollingView() override;

	/**
	 * @brief Weather the control should stack with previously active controls.
	 * @return True if the control should stack with previously active
	 * controls; otherwise, false.
	 * @remarks Most tools leave this at the default of true, but the query tool, torch,
	 * dispatch tool, and a few others override it and return false.
	 */
	bool ShouldStack() override;

	/**
	 * @brief Notifies the view input control that a character was entered on the keyboard.
	 * @param value The character.
	 * @return True if the control handled the event; otherwise, false.
	 */
	bool OnCharacter(char value) override;

	/**
	 * @brief Notifies the view input control that a keyboard key is down.
	 * @param vkCode The Windows virtual key code.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	bool OnKeyDown(int32_t vkCode, uint32_t modifiers) override;

	/**
	 * @brief Notifies the view input control that a keyboard key is up.
	 * @param vkCode The Windows virtual key code.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	bool OnKeyUp(int32_t vkCode, uint32_t modifiers) override;

	/**
	 * @brief Notifies the view input control that the left mouse button is down.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	bool OnMouseDownL(int32_t x, int32_t z, uint32_t modifiers) override;

	/**
	 * @brief Notifies the view input control that the right mouse button is down.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	bool OnMouseDownR(int32_t x, int32_t z, uint32_t modifiers) override;

	/**
	 * @brief Notifies the view input control that the left mouse button is up.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	bool OnMouseUpL(int32_t x, int32_t z, uint32_t modifiers) override;

	/**
	 * @brief Notifies the view input control that the right mouse button is up.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	bool OnMouseUpR(int32_t x, int32_t z, uint32_t modifiers) override;

	/**
	 * @brief Notifies the view input control that the mouse has moved.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	bool OnMouseMove(int32_t x, int32_t z, uint32_t modifiers) override;

	/**
	 * @brief Notifies the view input control that the mouse wheel has moved.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @param wheelDelta The wheel scroll delta. Positive for scroll wheel up (e.g. zoom in),
	 * negative for scroll wheel down (e.g. zoom out).
	 * @return True if the control handled the event; otherwise, false.
	 */
	bool OnMouseWheel(int32_t x, int32_t z, uint32_t modifiers, int32_t wheelDelta) override;

	/**
	 * @brief Notifies the view input control that the mouse has exited the control.
	 * @return True if the control handled the event; otherwise, false.
	 */
	bool OnMouseExit() override;

	/**
	 * @brief Called when the control is activated.
	 */
	void Activate() override;

	/**
	 * @brief Called when the control is deactivated.
	 */
	void Deactivate() override;

	/**
	 * @brief Indicates if the control is capturing input.
	 * @return True if the control is capturing input; otherwise, false.
	 */
	bool AmCapturing() override;

protected:
	/**
	 * @brief Removes the control from the game's UI.
	 */
	virtual void EndInput();

	/**
	 * @brief Gets a value indicating if this control is
	 * at the top of the view input control stack.
	 * @return True if this control is at the top of the
	 * view input control stack; otherwise, false.
	 */
	bool IsOnTop();

	/**
	 * @brief Releases the control from capturing input.
	 * @return True if successful; otherwise, false.
	 */
	bool ReleaseCapture();

	/**
	 * @brief Set the control to capture input.
	 * @return True if successful; otherwise, false.
	 */
	bool SetCapture();

	bool initialized;
	uint32_t id;
	uint32_t cursorID;
	cRZAutoRefCount<cIGZCursor> cursor;
	cRZAutoRefCount<cIGZWin> window;
	cRZAutoRefCount<cIGZWinMgr> windowManager;
	cRZAutoRefCount<cISC4View3DWin> view3D;
};