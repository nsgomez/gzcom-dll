/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4RegionPreferences.h
 *
 * Copyright (C) 2024, 2026 Nicholas Hayes
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
#include "SC4Point.h"

class SC4RegionPreferences
{
public:
	char regionName[64];			// 0x0
	SC4Point<int32_t> viewPosttion;	// 0x40
	bool showCityBoundaryGrid;		// 0x48
	bool showCityNames;				// 0x49
	uint8_t mapModeIndex;			// 0x4a
	uint8_t field6_0x4b;			// 0x4b
};

