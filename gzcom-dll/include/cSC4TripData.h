/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cSC4TripData.h
 *
 * Copyright (C) 2026 Nicholas Hayes
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
#include "SC4Vector.h"

class cSC4TripData
{
public:
	// The path data is in a compressed format, see:
	// https://wiki.sc4devotion.com/index.php?title=Lot_Subfile#Appendix_6_-_Structure_of_Commute_Paths

	SC4Vector<uint8_t> pathData1;	// 0x0
	SC4Vector<uint8_t> pathData2;	// 0xc
	uint32_t commuterCount;			// 0x18
	uint8_t unknown4;				// 0x1c
	uint8_t transitType;			// 0x1d
	uint8_t flags1;					// 0x1e
	uint8_t unknown5;				// 0x1f

	// The game uses a few special values for the destination tile fields, this description is based on
	// https://wiki.sc4devotion.com/index.php?title=Lot_Subfile#Appendix_7_-_Destination_Tile:
	//
	// A job located in the western neighbor has an X coordinate of -1.
	// A job located in the northern neighbor has a Z coordinate of -1.
	// A job located in the eastern neighbor has an X coordinate of the city X cell count (64, 128, or 256).
	// A job located in the southern neighbor has a Z coordinate of the city Z cell count (64, 128, or 256).
	//
	// If the commute path has disappeared (e.g. work demolished or redeveloping),
	// the X coordinate becomes 0xDFA8 (-8,280).

	int16_t destinationTileX;		// 0x20
	int16_t destinationTileZ;		// 0x22
	float tripLength;				// 0x24
	uint8_t unknown6;				// 0x28
	uint8_t unknown7;				// 0x29
	uint8_t unknown8;				// 0x2a
	uint8_t unknown9;				// 0x2b
};

static_assert(sizeof(cSC4TripData) == 0x2c);
static_assert(offsetof(cSC4TripData, commuterCount) == 0x18);
static_assert(offsetof(cSC4TripData, flags1) == 0x1e);
static_assert(offsetof(cSC4TripData, destinationTileX) == 0x20);
static_assert(offsetof(cSC4TripData, tripLength) == 0x24);
static_assert(offsetof(cSC4TripData, unknown6) == 0x28);