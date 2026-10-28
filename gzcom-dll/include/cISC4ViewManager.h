/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4ViewManager.h
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

static const uint32_t GZIID_cISC4ViewManager = 0x67c5bede;

// Selects the data view (overlay) shown by the map view. The map view
// (cSC4WinMapView) implements this interface itself, and
// cISC4View3DWin::GetViewManager hands it out.
class cISC4ViewManager : public cIGZUnknown
{
public:
	// Sets the data view that is shown when no temporary view is pushed.
	virtual void SetBaseView(uint32_t viewId) = 0;

	// Pushes a temporary data view on top of the base view.
	// PopView removes that ID from the stack again.
	virtual void PushView(uint32_t viewId) = 0;
	virtual void PopView(uint32_t viewId) = 0;
};
