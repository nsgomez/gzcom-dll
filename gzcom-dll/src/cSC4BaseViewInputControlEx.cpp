/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cSC4BaseViewInputControlEx.cpp
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

#include "cSC4BaseViewInputControlEx.h"
#include "cIGZCanvas.h"
#include "cIGZKeyboard.h"
#include <windowsx.h>

namespace
{
	uint32_t XButtonToKeyState(uint32_t xButton)
	{
		switch (xButton)
		{
		case XBUTTON1:
			return MK_XBUTTON1;
		case XBUTTON2:
			return MK_XBUTTON2;
		default:
			return 0;
		}
	}
}

cSC4BaseViewInputControlEx::cSC4BaseViewInputControlEx(uint32_t controlID)
	: cSC4BaseViewInputControl(controlID),
	  buttonsDown(0)
{
}

bool cSC4BaseViewInputControlEx::QueryInterface(uint32_t riid, void** ppvObj)
{
	return cSC4BaseViewInputControl::QueryInterface(riid, ppvObj);
}

uint32_t cSC4BaseViewInputControlEx::AddRef()
{
	return cSC4BaseViewInputControl::AddRef();
}

uint32_t cSC4BaseViewInputControlEx::Release()
{
	return cSC4BaseViewInputControl::Release();
}

bool cSC4BaseViewInputControlEx::Init()
{
	if (cSC4BaseViewInputControl::Init() && !canvasW32)
	{
		cIGZCanvas* canvas = windowManager->GetCanvas();
		cRZAutoRefCount<cIGZCanvasW32> localCanvasW32;

		if (canvas
			&& canvas->QueryInterface(GZIID_cIGZCanvasW32, localCanvasW32.AsPPVoid())
			&& localCanvasW32->AddWinProcFilter(this, true))
		{
			canvasW32 = localCanvasW32;
		}
	}

	return initialized;
}

bool cSC4BaseViewInputControlEx::Shutdown()
{
	if (canvasW32)
	{
		canvasW32->AddWinProcFilter(this, false);
		canvasW32.Reset();
	}

	buttonsDown = 0;

	return cSC4BaseViewInputControl::Shutdown();
}

void cSC4BaseViewInputControlEx::Deactivate()
{
	buttonsDown = 0;
	cSC4BaseViewInputControl::Deactivate();
}

bool cSC4BaseViewInputControlEx::OnMouseDownM(int32_t x, int32_t z, uint32_t modifiers)
{
	return false;
}

bool cSC4BaseViewInputControlEx::OnMouseUpM(int32_t x, int32_t z, uint32_t modifiers)
{
	return false;
}

bool cSC4BaseViewInputControlEx::OnMouseDownX(int32_t x, int32_t z, uint32_t modifiers, uint32_t button)
{
	return false;
}

bool cSC4BaseViewInputControlEx::OnMouseUpX(int32_t x, int32_t z, uint32_t modifiers, uint32_t button)
{
	return false;
}

bool cSC4BaseViewInputControlEx::IsMiddleMouseDown() const
{
	return (buttonsDown & MK_MBUTTON) != 0;
}

bool cSC4BaseViewInputControlEx::IsXMouseDown(uint32_t button) const
{
	return (buttonsDown & XButtonToKeyState(button)) != 0;
}

LRESULT cSC4BaseViewInputControlEx::FilterMessage(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam,
	bool& handled)
{
	// When handled is set, the canvas window procedure returns our result
	// right away, skipping its own processing and any later filters.
	switch (uMsg)
	{
	case WM_MBUTTONDOWN:
	case WM_MBUTTONDBLCLK:
		handled = ButtonDown(MK_MBUTTON, lParam);
		break;
	case WM_MBUTTONUP:
		handled = ButtonUp(MK_MBUTTON, lParam);
		break;
	case WM_XBUTTONDOWN:
	case WM_XBUTTONDBLCLK:
		handled = ButtonDown(XButtonToKeyState(GET_XBUTTON_WPARAM(wParam)), lParam);
		// Win32 expects TRUE for a handled X button message, this also
		// stops DefWindowProc from sending a WM_APPCOMMAND for it.
		return handled ? TRUE : 0;
	case WM_XBUTTONUP:
		handled = ButtonUp(XButtonToKeyState(GET_XBUTTON_WPARAM(wParam)), lParam);
		return handled ? TRUE : 0;
	case WM_MOUSEMOVE:
		// The button-up message is lost when a button is released outside of
		// the game window, the next mouse move tells us it is no longer down.
		ReleaseButtons(buttonsDown & ~GET_KEYSTATE_WPARAM(wParam), lParam);
		break;
	case WM_CANCELMODE:
	case WM_KILLFOCUS:
		if (buttonsDown)
		{
			POINT point{};

			if (GetCursorPos(&point) && ScreenToClient(hWnd, &point))
			{
				ReleaseButtons(buttonsDown, MAKELPARAM(point.x, point.y));
			}
			else
			{
				ReleaseButtons(buttonsDown, 0);
			}
		}
		break;
	}

	return 0;
}

bool cSC4BaseViewInputControlEx::ButtonDown(uint32_t button, LPARAM lParam)
{
	int32_t x = 0;
	int32_t z = 0;

	if (button == 0
		|| (buttonsDown & button) != 0
		|| !initialized
		|| !IsOnTop()
		|| !IsOverView(lParam))
	{
		return false;
	}

	ToWindowCoordinates(lParam, x, z);
	buttonsDown |= button;

	return DispatchButton(button, true, x, z);
}

bool cSC4BaseViewInputControlEx::ButtonUp(uint32_t button, LPARAM lParam)
{
	if (button == 0 || (buttonsDown & button) == 0)
	{
		return false;
	}

	buttonsDown &= ~button;

	int32_t x = 0;
	int32_t z = 0;
	ToWindowCoordinates(lParam, x, z);

	return DispatchButton(button, false, x, z);
}

void cSC4BaseViewInputControlEx::ReleaseButtons(uint32_t buttons, LPARAM lParam)
{
	static constexpr uint32_t allButtons[] = { MK_MBUTTON, MK_XBUTTON1, MK_XBUTTON2 };

	for (uint32_t button : allButtons)
	{
		if ((buttons & button) != 0)
		{
			ButtonUp(button, lParam);
		}
	}
}

bool cSC4BaseViewInputControlEx::DispatchButton(uint32_t button, bool down, int32_t x, int32_t z)
{
	const uint32_t modifiers = GetModifiers();

	if (button == MK_MBUTTON)
	{
		return down ? OnMouseDownM(x, z, modifiers) : OnMouseUpM(x, z, modifiers);
	}

	const uint32_t xButton = button == MK_XBUTTON1 ? XBUTTON1 : XBUTTON2;

	return down ? OnMouseDownX(x, z, modifiers, xButton) : OnMouseUpX(x, z, modifiers, xButton);
}

bool cSC4BaseViewInputControlEx::IsOverView(LPARAM lParam) const
{
	// Mirrors how cGZWinMgrBase::ProcessMouseMessage routes mouse buttons: everything goes to
	// the capture window if there is one, and nothing reaches the view while a modal window is
	// open. Otherwise the click goes to the deepest visible window under the cursor that does
	// not have WinFlag_IgnoreMouse set, which skips the overlays on top of the city view.
	cIGZWin* capture = windowManager->GZGetCapture();

	if (capture)
	{
		return capture == window;
	}

	if (windowManager->IsModal())
	{
		return false;
	}

	cIGZWin* mainWindow = windowManager->GetMainWindow();

	return mainWindow
		&& mainWindow->GetChildWindowFromCursorPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)) == window;
}

void cSC4BaseViewInputControlEx::ToWindowCoordinates(LPARAM lParam, int32_t& x, int32_t& z) const
{
	// GZ screen coordinates are relative to the canvas, which is the window
	// that receives the messages, so the client coordinates can be used as-is.
	x = GET_X_LPARAM(lParam);
	z = GET_Y_LPARAM(lParam);

	// The game's ScreenToWindowCoordinates returns nothing, despite the bool in
	// cIGZWin.h, so its result is not checked.
	if (window)
	{
		window->ScreenToWindowCoordinates(x, z);
	}
}

uint32_t cSC4BaseViewInputControlEx::GetModifiers() const
{
	cIGZKeyboard* keyboard = windowManager ? windowManager->GetKeyboard() : nullptr;

	return keyboard ? keyboard->GetCurrentModifierState() : 0;
}
