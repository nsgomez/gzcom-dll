/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cSC4BaseViewInputControlEx.h
 *
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
#include "cSC4BaseViewInputControl.h"
#include "cIGZCanvasW32.h"
#include "cIGZWinProcFilterW32.h"

/**
 * @brief A view input control base class with functionality that SC4 itself does not provide.
 *
 * The game never delivers middle or X (back/forward) mouse button events to view input
 * controls. This class intercepts the Win32 messages for those buttons using a
 * cIGZWinProcFilterW32 on the game canvas, and forwards them to OnMouseDownM/OnMouseUpM
 * and OnMouseDownX/OnMouseUpX.
 *
 * Use cSC4BaseViewInputControl instead if you only need the base game functionality,
 * this class registers a window procedure filter for every initialized control.
 */
class cSC4BaseViewInputControlEx : public cSC4BaseViewInputControl, public cIGZWinProcFilterW32
{
protected:
	/**
	 * @brief Constructs the cSC4BaseViewInputControlEx
	 * @param controlCLSID The unique id that identifies this view input control.
	 * It should be a randomly generated unsigned 32-bit integer.
	 */
	cSC4BaseViewInputControlEx(uint32_t controlID);

public:
	// cIGZUnknown

	bool QueryInterface(uint32_t riid, void** ppvObj) override;
	uint32_t AddRef() override;
	uint32_t Release() override;

	// cISC4ViewInputControl

	/**
	 * @brief Initializes the control and starts listening for extra mouse button messages.
	 * @return True if successful; otherwise, false.
	 * @remarks Make sure you call the base class implementation first if you override this.
	 */
	bool Init() override;

	/**
	 * @brief Shuts down the control and stops listening for extra mouse button messages.
	 * @return True if successful; otherwise, false.
	 * @remarks Make sure you call the base class implementation first if you override this.
	 * The up event is not sent for buttons that are still down.
	 */
	bool Shutdown() override;

	/**
	 * @brief Called when the control is deactivated.
	 * @remarks Make sure you call the base class implementation if you override this.
	 * The up event is not sent for buttons that are still down.
	 */
	void Deactivate() override;

	// cSC4BaseViewInputControlEx

	/**
	 * @brief Notifies the view input control that the middle mouse button is down.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 * @remarks Only called when the control is at the top of the view input control stack,
	 * and the cursor is over the view (not over a UI window covering it).
	 */
	virtual bool OnMouseDownM(int32_t x, int32_t z, uint32_t modifiers);

	/**
	 * @brief Notifies the view input control that the middle mouse button is up.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @return True if the control handled the event; otherwise, false.
	 * @remarks Called exactly once for every OnMouseDownM call, unless the control
	 * is deactivated or shut down first. This includes the cases where the button
	 * was released outside of the game window, or the game window lost focus.
	 */
	virtual bool OnMouseUpM(int32_t x, int32_t z, uint32_t modifiers);

	/**
	 * @brief Notifies the view input control that an X mouse button is down.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @param button XBUTTON1 (usually back) or XBUTTON2 (usually forward).
	 * @return True if the control handled the event; otherwise, false.
	 * @remarks Same delivery rules as OnMouseDownM. Returning true also stops Windows
	 * from turning the click into a browser back/forward command.
	 */
	virtual bool OnMouseDownX(int32_t x, int32_t z, uint32_t modifiers, uint32_t button);

	/**
	 * @brief Notifies the view input control that an X mouse button is up.
	 * @param x The mouse x position.
	 * @param z The mouse z position.
	 * @param modifiers The framework modifier flags.
	 * @param button XBUTTON1 (usually back) or XBUTTON2 (usually forward).
	 * @return True if the control handled the event; otherwise, false.
	 * @remarks Same delivery rules as OnMouseUpM.
	 */
	virtual bool OnMouseUpX(int32_t x, int32_t z, uint32_t modifiers, uint32_t button);

protected:
	/**
	 * @brief Gets a value indicating if the middle mouse button is down.
	 * @return True if the control received OnMouseDownM and the matching
	 * OnMouseUpM has not happened yet; otherwise, false.
	 * @remarks Useful for implementing middle mouse dragging in OnMouseMove.
	 */
	bool IsMiddleMouseDown() const;

	/**
	 * @brief Gets a value indicating if an X mouse button is down.
	 * @param button XBUTTON1 or XBUTTON2.
	 * @return True if the control received OnMouseDownX for that button and the
	 * matching OnMouseUpX has not happened yet; otherwise, false.
	 */
	bool IsXMouseDown(uint32_t button) const;

private:
	// cIGZWinProcFilterW32

	LRESULT FilterMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool& handled) override;

	// The button parameters below are Win32 key state flags (MK_MBUTTON, MK_XBUTTON1, MK_XBUTTON2).
	bool ButtonDown(uint32_t button, LPARAM lParam);
	bool ButtonUp(uint32_t button, LPARAM lParam);
	void ReleaseButtons(uint32_t buttons, LPARAM lParam);
	bool DispatchButton(uint32_t button, bool down, int32_t x, int32_t z);
	bool IsOverView(LPARAM lParam) const;
	void ToWindowCoordinates(LPARAM lParam, int32_t& x, int32_t& z) const;
	uint32_t GetModifiers() const;

	uint32_t buttonsDown;
	cRZAutoRefCount<cIGZCanvasW32> canvasW32;
};
