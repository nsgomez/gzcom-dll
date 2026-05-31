/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cSC4LotConfigurationObject.h
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
#include "SC4Vector.h"
#include <cstddef>
#include <cstdint>

class cSC4LotConfigurationObject
{
public:
	// Types of LotConfigurationObjects
	enum class Type : uint8_t
	{
		Building = 0,
		Prop = 1,
		Texture = 2,
		Foundation = 3,
		Flora = 4,
		WaterConstraint = 5,
		TerrainConstraint = 6,
		Network = 7,
	};

	// City detail level at which the object is shown
	enum class DetailLevel : uint8_t
	{
		Low = 0x00,
		Medium = 0x10,
		High = 0x20,
	};

	// Orientation in 90-degree steps
	enum class Rotation : uint8_t
	{
		R0 = 0,
		R90 = 1,
		R180 = 2,
		R270 = 3,
	};

	// Type of the LotConfigurationObject
	Type type;
	// Bit flags, meaning depends on `type` (see isOptional()/detailLevel()):
	//   0x01 - Prop: optional (set) vs mandatory (clear)
	//   0x30 - Prop/Texture/Flora: city detail level
	uint8_t flags;
	Rotation rotation;
	// Only meaningful for type == Texture
	bool mirrored;
	// Object center in lot space (y is elevation).
	float x;
	float y;
	float z;
	// Bounding rectangle in the X/Z plane.
	float rectMaxX;
	float rectMaxZ;
	float rectMinX;
	float rectMinZ;
	// Only meaningful for type == Building
	uint32_t foundationIID;
	// Unique ID of the LotConfigurationObject within the LotConfiguration
	uint32_t objectID;
	// Type-dependent payload
	//   Building   - building family OR instance IIDs
	//   Prop       - prop family OR instance IIDs
	//   Flora      - flora family OR instance IIDs
	//   Texture    - base/overlay texture IIDs
	//   WaterConstraint - data[0] toggled 0/1 (1 = 2 tile open water besides lot required)
	//   Network    - positional fields, not a list:
	//                data[0] = network type, data[1] = min edges,
	//                data[2] = max edges data[3] = SC4Path instance id
	SC4Vector<uint32_t> data;

	// Prop only: object is optional rather than mandatory (flags & 0x01 set).
	[[nodiscard]] bool isOptional() const { return (flags & 0x01) != 0; }

	// Prop/Texture/Flora: city detail level for display (flags & 0x30).
	[[nodiscard]] DetailLevel detailLevel() const { return static_cast<DetailLevel>(flags & 0x30); }
};

static_assert(sizeof(cSC4LotConfigurationObject) == 0x34);
static_assert(offsetof(cSC4LotConfigurationObject, type) == 0x00);
static_assert(offsetof(cSC4LotConfigurationObject, flags) == 0x01);
static_assert(offsetof(cSC4LotConfigurationObject, rotation) == 0x02);
static_assert(offsetof(cSC4LotConfigurationObject, mirrored) == 0x03);
static_assert(offsetof(cSC4LotConfigurationObject, x) == 0x04);
static_assert(offsetof(cSC4LotConfigurationObject, y) == 0x08);
static_assert(offsetof(cSC4LotConfigurationObject, z) == 0x0c);
static_assert(offsetof(cSC4LotConfigurationObject, rectMaxX) == 0x10);
static_assert(offsetof(cSC4LotConfigurationObject, rectMaxZ) == 0x14);
static_assert(offsetof(cSC4LotConfigurationObject, rectMinX) == 0x18);
static_assert(offsetof(cSC4LotConfigurationObject, rectMinZ) == 0x1c);
static_assert(offsetof(cSC4LotConfigurationObject, foundationIID) == 0x20);
static_assert(offsetof(cSC4LotConfigurationObject, objectID) == 0x24);
static_assert(offsetof(cSC4LotConfigurationObject, data) == 0x28);
