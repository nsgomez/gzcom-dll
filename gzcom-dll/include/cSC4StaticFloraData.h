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

#pragma once
#include "cISCResExemplar.h"
#include "cRZAutoRefCount.h"
#include "SC4Vector.h"
#include <cstddef>

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

	// Indices into parameters. The game reads the 14 floats in this order from
	// exemplar property 0x083DC35B. Ages use the flora simulator's date counter.
	struct tParameters
	{
		enum eParameters : uint32_t
		{
			MaturityAge = 0,         // Growth state 2 from this age, state 1 from half of it.
			SeedingAge = 1,          // The plant drops seeds from this age.
			SeedingInterval = 2,     // Time between two seed drops.
			SeedsPerDrop = 3,        // Rounded to the nearest integer.
			SeedScatterRadius = 4,
			LifeSpan = 5,            // At this age (growth state 3) the plant restarts as a sapling.
			MinPropagationScore = 8, // Below this propagation score the plant is removed.
			SeedSuccessFactor = 9,
			FootprintRadius = 11,    // Read by the lot editor.
		};
	};

	// floraPreferences is indexed [elevation][moisture]. The elevation row is the
	// height above sea level (the depth below it for bWaterFlora) times the
	// simulator's elevation scale, clamped to 0-15. The moisture column is
	// cISC4WeatherSimulator::GetMoistureType. Each value is coverage * 255, read
	// from the 256 floats of exemplar property 0x083DC487; the propagation score
	// is value / 255.
	struct FloraPreferencesEntry
	{
		uint8_t values[16];
	};

	// Note: the game does not check the lengths of properties 0x083DC35B (14 floats)
	// and 0x083DC487 (256 floats). A shorter array makes it read past the end.

	uint32_t type;                              // 0x0, the flora type (property 0x21)
	uint32_t clusterType;                       // 0x4, the next flora type in the cluster chain (property 0x2A0348BA)
	uint32_t seedType;                          // 0x8, the flora type the seeds grow as: the start of the cluster chain
	bool bWaterFlora;                           // 0xc
	float parameters[14];                       // 0x10, see tParameters
	float clusterMaxRadius;                     // 0x48
	float clusterMaxHeight;	                    // 0x4c 
	FloraPreferencesEntry floraPreferences[16]; // 0x50
	uint32_t cursorID;                          // 0x150
	SC4Vector<uint32_t> families;               // 0x154
	int64_t plopCost;                           // 0x160
	cRZAutoRefCount<cISCResExemplar> exemplar;	// 0x168
	// 0x16c, tFloraFlags. Bit 0 is property 0xE9D117C3. Bits 1 and 2 default to set;
	// property 0x6A37EBB6 clears bit 2 when true and bit 1 when false.
	uint8_t flags;
	uint32_t refCount;                          // 0x170
};

static_assert(offsetof(cSC4StaticFloraData, type) == 0x0);
static_assert(offsetof(cSC4StaticFloraData, seedType) == 0x8);
static_assert(offsetof(cSC4StaticFloraData, parameters) == 0x10);
static_assert(offsetof(cSC4StaticFloraData, floraPreferences) == 0x50);
static_assert(offsetof(cSC4StaticFloraData, families) == 0x154);
static_assert(offsetof(cSC4StaticFloraData, plopCost) == 0x160);
static_assert(offsetof(cSC4StaticFloraData, flags) == 0x16c);
static_assert(offsetof(cSC4StaticFloraData, refCount) == 0x170);
static_assert(sizeof(cSC4StaticFloraData) == 0x178);
