/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cSC4EdgeConnectionStore.h
 *
 * Copyright (C) 2024 Nicholas Hayes
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
#include <cstdint>

struct EdgeConnection
{
	uint32_t networkType;
	// The game stores the edge data in a uint32_t using the order 0xWWNNEESS. We
	// place the uint32_t in a union to allow the individual byte fields to be
	// accessed without bit-shifting.
	union
	{
		uint32_t packedEdgeData;
		struct
		{
			uint8_t west;
			uint8_t north;
			uint8_t east;
			uint8_t south;
		} directions;
	} edgeData;
};

static_assert(sizeof(EdgeConnection) == 8, "sizeof(EdgeConnection) != 8");

class cSC4EdgeConnectionStore
{
public:
	uint32_t additionalNetworkCount;        // 0
	EdgeConnection firstNetwork;            // 4
	EdgeConnection* additionalNetworkArray; // 12
};

static_assert(sizeof(cSC4EdgeConnectionStore) == 16, "sizeof(EdgeConnection) != 16");
