/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cSC4StaticFloraData.h
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

#include "cISCResExemplar.h"
#include "cRZAutoRefCount.h"
#include "SC4Vector.h"

class cSC4StaticFloraData
{    
public:
	struct tFloraFlags
	{
		enum eFloraFlags : uint8_t
		{
			// The item will appear in menus, but is ignored by the simulation.
			SpecialCaseOnly = 0x1,
			ShowInGodModeFloraMenu = 0x2,
			ShowInMayorModeFloraMenu = 0x4
		};
	};

	struct FloraPreferencesEntry
	{
		uint8_t values[16];
	};

	uint32_t unknown1;                        	// 0x0
	uint32_t clusterType;                       // 0x4
	uint32_t type;                              // 0x8
	bool bWaterFlora;                           // 0xc
	float parameters[14];                       // 0x10
	float clusterMaxRadius;                     // 0x48
	float clusterMaxHeight;	                    // 0x4c 
	FloraPreferencesEntry floraPreferences[16]; // 0x50
	uint32_t cursorID;                          // 0x150
	SC4Vector<uint32_t> families;               // 0x154
	int64_t plopCost;                           // 0x160
	cRZAutoRefCount<cISCResExemplar> exemplar;	// 0x168
	uint8_t flags;								// 0x16c
	uint32_t refCount;                          // 0x170
};

static_assert(offsetof(cSC4StaticFloraData, type) == 0x8);
static_assert(offsetof(cSC4StaticFloraData, parameters) == 0x10);
static_assert(offsetof(cSC4StaticFloraData, floraPreferences) == 0x50);
static_assert(offsetof(cSC4StaticFloraData, families) == 0x154);
static_assert(offsetof(cSC4StaticFloraData, plopCost) == 0x160);
static_assert(offsetof(cSC4StaticFloraData, flags) == 0x16c);
static_assert(offsetof(cSC4StaticFloraData, refCount) == 0x170);
static_assert(sizeof(cSC4StaticFloraData) == 0x178);
