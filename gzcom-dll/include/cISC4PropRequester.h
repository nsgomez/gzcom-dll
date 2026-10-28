/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4PropRequester.h
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
#include "SC4Rect.h"
#include "SC4Vector.h"

static const uint32_t GZIID_cISC4PropRequester = 0x89c498be;

// Asks the prop developer to place props around the city. The pollution and
// crime simulators and the wealth requester implement it. Register one with
// cISC4PropDeveloper::AddPropRequester.
class cISC4PropRequester : public cIGZUnknown
{
public:
	// The share of props this requester asks for in the given cell area.
	virtual int32_t GetRequestedShare(SC4Rect<int32_t> const& area) const = 0;
	virtual uint32_t GetRequesterSatisfactionId() const = 0;

	// Requesters that return true pick their own prop through SelectProp.
	virtual bool UsesCustomPropSelector() const = 0;

	// Picks one prop ID out of the candidates for the cell at (x, z).
	virtual uint32_t SelectProp(SC4Vector<uint32_t> const& candidates, int32_t x, int32_t z) const = 0;
};
