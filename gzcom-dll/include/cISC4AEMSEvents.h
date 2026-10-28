/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4AEMSEvents.h
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
#include "SC4Percentage.h"

class cISCPropertyHolder;

static const uint32_t GZIID_cISC4AEMSEvents = 0x8c1faeb7;

class cISC4AEMSEvents : public cIGZUnknown
{
public:
	// Index into the event system's handle table. The game's vehicle code
	// passes small values such as 8 to 13, but their names are not known.
	enum AEMSEventType : uint32_t {};

	virtual bool LoadSoundBank(cISCPropertyHolder const* propertyHolder, uint32_t propertyID) = 0;
	virtual bool UnloadSoundBank(cISCPropertyHolder const* propertyHolder, uint32_t propertyID) = 0;
	// Returns true when the event was not already running.
	virtual bool StartSound(AEMSEventType type) = 0;
	virtual bool EndSound(AEMSEventType type) = 0;
	// The parameter setters clamp the percentage to [0, 1] and scale it to 0-127.
	virtual bool SetParamVelocity(SC4Percentage velocity) = 0;
	virtual bool SetParamThrottle(SC4Percentage throttle) = 0;
	virtual bool SetParamWobble(SC4Percentage wobble) = 0;
};
