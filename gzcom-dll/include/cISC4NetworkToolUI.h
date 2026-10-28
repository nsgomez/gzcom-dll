/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4NetworkToolUI.h
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
#include "cIGZUnknown.h"

class cISC4View3DWin;

static const uint32_t GZIID_cISC4NetworkToolUI = 0x8b54be51;

// The mouse-driven front end of a network tool, handed out by
// cISC4NetworkTool::GetUITool. It handles view input while the tool is in
// use, and the ID and pen getters forward to the tool it is bound to.
class cISC4NetworkToolUI : public cIGZUnknown
{
public:
	virtual bool Shutdown() = 0;

	virtual uint32_t ViewInputControlId() = 0;
	virtual uint32_t CursorId() = 0;
	virtual void PenWidth(int32_t& widthX, int32_t& widthZ) = 0;

	virtual void EnterUI() = 0;
	virtual void LeaveUI() = 0;

	// Mouse handlers in the same form as cISC4ViewInputControl.
	virtual bool OnMouseDownL(int32_t x, int32_t z, uint32_t modifiers) = 0;
	virtual bool OnMouseUpL(int32_t x, int32_t z, uint32_t modifiers) = 0;
	virtual bool OnMouseMove(int32_t x, int32_t z, uint32_t modifiers) = 0;
	virtual void CancelInput() = 0;

	virtual bool IsActive() = 0;
	virtual uint32_t DirectionalCursorBase() = 0;

	// Direction of the last drag segment as a value from 0 to 7, or -1 when
	// the drag is too short to have one.
	virtual int32_t LastDragDirection() = 0;

	virtual void AttachToView(cISC4View3DWin* view) = 0;
};
