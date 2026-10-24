/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISTESurfaceWater.h
 *
 * Copyright (C) 2025 Nicholas Hayes
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
#include "cS3DVector3.h"

class cISC4Lot;
template<typename T> class cISC4SimGrid;

class cISTESurfaceWater : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual float GetWaterDepthAtVertex(int32_t index) const = 0;
	virtual float GetWaterDepthForCell(int32_t x, int32_t z) const = 0;

	// MSVC puts every virtual overload of a name at the vtable slot of the first
	// one declared, in REVERSE declaration order. So the pair is declared in the
	// reverse of the game's order: 7 IsNavigable(cS3DVector3, ...), 8 IsNavigable(cellX, cellZ, ...).

	/**
	 * @param cellX Terrain cell X coordinate
	 * @param cellZ Terrain cell Z coordinate
	 * @param radius Search radius in cells
	 * @param lot Lot to exclude from conflict checks (nullptr = no lot excluded)
	 * @return true if the area is navigable. In other words, there are no obstructions
	 *		   within the radius around the position
	 */
	virtual bool IsNavigable(int32_t cellX, int32_t cellZ, int32_t radius, cISC4Lot* lot) const = 0;

	/**
	 * @param position World-space 3D position, uses the X and Z position, ignoring Y
	 * @param radius Search radius around the position, in cells
	 * @param lot Lot to exclude from conflict checks (nullptr = no lot excluded)
	 * @return true if the area is navigable. In other words, there are no obstructions
	 *		   within the radius around the position
	 */
	virtual bool IsNavigable(cS3DVector3 position, int32_t radius, cISC4Lot* lot) const = 0;

	virtual cISC4SimGrid<uint16_t>* GetBodyOfWaterMap() const = 0;
	virtual float AltitudeAtWhichFloodingWillOccur(int32_t x, int32_t z) = 0;
	virtual float GetWaterVelocity(int32_t x, int32_t z) = 0;
	virtual int32_t GetWaterType(int32_t x, int32_t z) = 0;
	virtual bool HasDraftClearance(int32_t x, int32_t z) = 0;
};