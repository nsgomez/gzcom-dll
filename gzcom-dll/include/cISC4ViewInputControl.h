/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4ViewInputControl.h
 *
 * Copyright (C) 2024, 2025 Nicholas Hayes
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

class cIGZCursor;
class cIGZWin;

static const uint32_t GZIID_cISC4ViewInputControl = 0xC6BB8345;

class cISC4ViewInputControl : public cIGZUnknown
{
public:
	/**
	 * @brief Initializes the control.
	 * @return True if successful; otherwise, false.
	 */
	virtual bool Init() = 0;

	/**
	 * @brief Shuts down the control.
	 * @return True if successful; otherwise, false.
	 * @remarks Make sure you call the base class implementation first if you override this.
	 */
	virtual bool Shutdown() = 0;

	/**
	 * @brief Gets the control id.
	 * @return The control id.
	 */
	virtual uint32_t GetID() = 0;

	/**
	 * @brief Sets the control id.
	 * @param id The control id.
	 */
	virtual void SetID(uint32_t id) = 0;

	/**
	 * @brief Gets the cursor used by this view input control.
	 * @return The cursor used by this view input control.
	 */
	virtual cIGZCursor* GetCursor() = 0;

	/**
	 * @brief Sets the cursor used by this view input control.
	 * @param pIGZCursor The cursor to use for this view input control.
	 */
	virtual void SetCursor(cIGZCursor* pIGZCursor) = 0;

	/**
	 * @brief Sets the cursor used by this view input control.
	 * @param pIGZCursor The cursor to use for this view input control.
	 */
	virtual void SetCursor(uint32_t cursorID) = 0;

	/**
	 * @brief Sets the parent window for this view input control.
	 * @param pWin The parent window for this view input control.
	 */
	virtual void SetWindow(cIGZWin* pWin) = 0;

	/**
	 * @brief Weather the control handles its own scrolling.
	 * @return True if the control handles its own scrolling; otherwise, false.
	 */
	virtual bool IsSelfScrollingView() = 0;

	/**
	 * @brief Weather the control should stack with previously active controls.
	 * @return True if the control should stack with previously active
	 * controls; otherwise, false.
	 * @remarks Most tools leave this at the default of true, but the query tool, torch,
	 * set it to false.
	 */
	virtual bool ShouldStack() = 0;

	/**
	 * @brief Notifies the view input control that a character was entered on the keyboard.
	 * @param value The character.
	 * @return True if the control handled the event; otherwise, false.
	 */
	virtual bool OnCharacter(char value) = 0;

	/**
	 * @brief Notifies the view input control that a keyboard key is down.
	 * @param vkCode The Windows virtual key code.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	virtual bool OnKeyDown(int32_t vkCode, uint32_t modifiers) = 0;

	/**
	 * @brief Notifies the view input control that a keyboard key is up.
	 * @param vkCode The Windows virtual key code.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	virtual bool OnKeyUp(int32_t vkCode, uint32_t modifiers) = 0;

	/**
	 * @brief Notifies the view input control that the left mouse button is down.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	virtual bool OnMouseDownL(int32_t x, int32_t z, uint32_t modifiers) = 0;

	/**
	 * @brief Notifies the view input control that the right mouse button is down.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	virtual bool OnMouseDownR(int32_t x, int32_t z, uint32_t modifiers) = 0;

	/**
	 * @brief Notifies the view input control that the left mouse button is up.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	virtual bool OnMouseUpL(int32_t x, int32_t z, uint32_t modifiers) = 0;

	/**
	 * @brief Notifies the view input control that the right mouse button is up.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	virtual bool OnMouseUpR(int32_t x, int32_t z, uint32_t modifiers) = 0;

	/**
	 * @brief Notifies the view input control that the mouse has moved.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 */
	virtual bool OnMouseMove(int32_t x, int32_t z, uint32_t modifiers) = 0;

	/**
	 * @brief Notifies the view input control that the mouse wheel has moved.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @param wheelDelta The wheel scroll delta. Positive for scroll wheel up (e.g. zoom in),
	 * negative for scroll wheel down (e.g. zoom out).
	 * @return True if the control handled the event; otherwise, false.
	 */
	virtual bool OnMouseWheel(int32_t x, int32_t z, uint32_t modifiers, int32_t wheelDelta) = 0;

	/**
	 * @brief Notifies the view input control that the mouse has exited the control.
	 * @return True if the control handled the event; otherwise, false.
	 */
	virtual bool OnMouseExit() = 0;

	/**
	 * @brief Called when the control is activated.
	 */
	virtual void Activate() = 0;

	/**
	 * @brief Called when the control is deactivated.
	 */
	virtual void Deactivate() = 0;

	/**
	 * @brief Indicates if the control is capturing input.
	 * @return True if the control is capturing input; otherwise, false.
	 */
	virtual bool AmCapturing() = 0;
};
