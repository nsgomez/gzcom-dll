/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4AutomataTemplates.h
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
#include "SC4List.h"
#include "SC4String.h"
#include "SC4Vector.h"
#include <cstddef>
#include <cstdint>

// Data layouts of the automata controller templates, recovered from SimCity 4.exe 1.1.641.
//
// The game builds these from the automata Lua scripts (the "generator" and "attractor"
// tables) and owns them for its whole lifetime. Read them through the pointers that
// cISC4AutomataController, cISC4AutomataControllerManager and cISC4Automaton hand out.
// Don't construct, copy or free them yourself. The containers inside are allocated by
// the game.

// A time of day plus a day counter, used by the automata controller manager clock.
// cISC4AutomataControllerManager::GetControllerTime returns the current one.
struct tControllerTime
{
	float hour;      // +0x00 hours in [0, 24) once normalized
	int16_t day;     // +0x04 day counter, the game wraps it to a weekday (0 to 6) when it normalizes
	uint8_t unknown_0x06[2]; // +0x06 alignment padding
};

static_assert(sizeof(tControllerTime) == 0x8);
static_assert(offsetof(tControllerTime, hour) == 0x0);
static_assert(offsetof(tControllerTime, day) == 0x4);

// One entry of a controller template's "behavior" table.
// It tells an automaton what to do when it is within radius of the controller.
// The game keeps a template's behaviors sorted by radius and then by priority, and
// cISC4AutomataController::GetBehaviorTemplate returns the first one whose radius
// covers the distance.
struct tBehaviorTemplate
{
	tBehaviorTemplate() = delete;
	tBehaviorTemplate(tBehaviorTemplate const&) = delete;
	tBehaviorTemplate& operator=(tBehaviorTemplate const&) = delete;

	uint32_t state;                // +0x00 "state", the automaton state ID to enter
	float radius;                  // +0x04 "radius", defaults to FLT_MAX
	float percentage;              // +0x08 "percentage", defaults to 1.0
	uint32_t priority;             // +0x0c "priority", defaults to 1
	SC4Vector<SC4String> anims;    // +0x10 "anims", animation names
	SC4Vector<uint32_t> sfx;       // +0x1c "sfx", sound IDs parsed from hex strings
	float timeout;                 // +0x28 "timeout" in seconds, 0 or less means none
	bool isFinal;                  // +0x2c "final"
	uint8_t unknown_0x2d[3];       // +0x2d alignment padding
	float kphMultiply[2];          // +0x30 "kph_multiply" min and max, defaults to 1.0
	int32_t kph[2];                // +0x38 "kph" min and max, defaults to -1
	float acceleration;            // +0x40 "acceleration", defaults to 0.5
	bool ignorePaths;              // +0x44 "ignore_paths"
	bool ignoreRoads;              // +0x45 "ignore_roads"
	bool ignoreTerrain;            // +0x46 "ignore_terrain"
	bool ignoreAttractors;         // +0x47 "ignore_attractors"
	bool avoidLots;                // +0x48 "avoid_lots"
	bool avoidRoads;               // +0x49 "avoid_roads"
	uint8_t unknown_0x4a[2];       // +0x4a alignment padding
	float pathOffset;              // +0x4c "path_offset"

	// The fields below come from the nested "random_walk" table.
	float randomWalkDelay[2];      // +0x50 "delay" min and max, defaults to 10 and 15
	float randomWalkTurn[2];       // +0x58 "turn", defaults to 0.1 and 0.2
	float randomWalkStrength[2];   // +0x60 "strength" min and max, defaults to 1.0
	float randomWalkIdleDelay[2];  // +0x68 "idle_delay" min and max, defaults to 0
	float randomWalkIdleTime[2];   // +0x70 "idle_time" min and max, defaults to 5 and 10
	float randomWalkDeceleration;  // +0x78 "deceleration", defaults to 0.5
};

static_assert(sizeof(tBehaviorTemplate) == 0x7c);
static_assert(offsetof(tBehaviorTemplate, state) == 0x00);
static_assert(offsetof(tBehaviorTemplate, radius) == 0x04);
static_assert(offsetof(tBehaviorTemplate, percentage) == 0x08);
static_assert(offsetof(tBehaviorTemplate, priority) == 0x0c);
static_assert(offsetof(tBehaviorTemplate, anims) == 0x10);
static_assert(offsetof(tBehaviorTemplate, sfx) == 0x1c);
static_assert(offsetof(tBehaviorTemplate, timeout) == 0x28);
static_assert(offsetof(tBehaviorTemplate, isFinal) == 0x2c);
static_assert(offsetof(tBehaviorTemplate, kphMultiply) == 0x30);
static_assert(offsetof(tBehaviorTemplate, kph) == 0x38);
static_assert(offsetof(tBehaviorTemplate, acceleration) == 0x40);
static_assert(offsetof(tBehaviorTemplate, ignorePaths) == 0x44);
static_assert(offsetof(tBehaviorTemplate, avoidRoads) == 0x49);
static_assert(offsetof(tBehaviorTemplate, pathOffset) == 0x4c);
static_assert(offsetof(tBehaviorTemplate, randomWalkDelay) == 0x50);
static_assert(offsetof(tBehaviorTemplate, randomWalkTurn) == 0x58);
static_assert(offsetof(tBehaviorTemplate, randomWalkStrength) == 0x60);
static_assert(offsetof(tBehaviorTemplate, randomWalkIdleDelay) == 0x68);
static_assert(offsetof(tBehaviorTemplate, randomWalkIdleTime) == 0x70);
static_assert(offsetof(tBehaviorTemplate, randomWalkDeceleration) == 0x78);

// The shared part of an automata generator or attractor template.
// The game allocates a bigger derived object (generator or attractor data follows
// at +0x78), so never assume the size of the whole allocation from this struct.
struct tControllerTemplate
{
	tControllerTemplate() = delete;
	tControllerTemplate(tControllerTemplate const&) = delete;
	tControllerTemplate& operator=(tControllerTemplate const&) = delete;

	// The game's lot flag bits in lotFlags, named after the Lua keys that set them.
	// The default value is 2, which has no Lua key.
	enum LotFlags : uint32_t
	{
		LotFlagTransient = 0x8,
		LotFlagUseLotFacing = 0x10,
		LotFlagUseLotCenter = 0x20,
		LotFlagIgnoreLot = 0x40,
		LotFlagFollowRoads = 0x80,
		LotFlagDestroyAutomata = 0x100,
		LotFlagPersistOffscreen = 0x200,
		LotFlagFollowRail = 0x800,
		LotFlagGroundOnly = 0x1000,
	};

	void* vtable;                           // +0x00 the game's vtable, it only holds the virtual destructor
	SC4String name;                         // +0x04 the template name from the script
	uint32_t controllerType;                // +0x18 0x4a1628c5 for generators, 0x6a1628ba for attractors
	uint32_t controllerClassID;             // +0x1c GZCOM class ID used to create the controller, same value as the type
	float radius;                           // +0x20 "radius"
	uint8_t timeOfDayCurve[0x10];           // +0x24 "time_of_day", an opaque cSC4ResponseCurve (point vector plus one dword)
	uint32_t calendarMask;                  // +0x34 "calendar", one bit per listed value, 0xFFFFFFFF when absent
	SC4Vector<tBehaviorTemplate> behaviors; // +0x38 "behavior", sorted by radius and then priority
	SC4List<uint32_t> effectTriggers;       // +0x44 "effect_trigger"
	SC4List<uint32_t> deactivateTriggers;   // +0x48 "deactivate_trigger"
	float lifetime;                         // +0x4c "lifetime"
	float delay;                            // +0x50 "delay"
	uint32_t maxCount;                      // +0x54 "max_count"
	uint32_t lotFlags;                      // +0x58 see LotFlags
	float exclusiveRadius;                  // +0x5c "exclusive_radius"
	SC4Vector<uint32_t> sfx;                // +0x60 "sfx", sound IDs parsed from hex strings
	SC4Vector<uint32_t> ignoreStates;       // +0x6c "ignore_states"
};

static_assert(sizeof(tControllerTemplate) == 0x78);
static_assert(offsetof(tControllerTemplate, name) == 0x04);
static_assert(offsetof(tControllerTemplate, controllerType) == 0x18);
static_assert(offsetof(tControllerTemplate, controllerClassID) == 0x1c);
static_assert(offsetof(tControllerTemplate, radius) == 0x20);
static_assert(offsetof(tControllerTemplate, timeOfDayCurve) == 0x24);
static_assert(offsetof(tControllerTemplate, calendarMask) == 0x34);
static_assert(offsetof(tControllerTemplate, behaviors) == 0x38);
static_assert(offsetof(tControllerTemplate, effectTriggers) == 0x44);
static_assert(offsetof(tControllerTemplate, deactivateTriggers) == 0x48);
static_assert(offsetof(tControllerTemplate, lifetime) == 0x4c);
static_assert(offsetof(tControllerTemplate, delay) == 0x50);
static_assert(offsetof(tControllerTemplate, maxCount) == 0x54);
static_assert(offsetof(tControllerTemplate, lotFlags) == 0x58);
static_assert(offsetof(tControllerTemplate, exclusiveRadius) == 0x5c);
static_assert(offsetof(tControllerTemplate, sfx) == 0x60);
static_assert(offsetof(tControllerTemplate, ignoreStates) == 0x6c);
