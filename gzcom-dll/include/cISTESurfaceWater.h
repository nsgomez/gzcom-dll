/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISTESurfaceWater.h
 *
 * Copyright (C) 2025 Nicholas Hayes
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

class cISC4Lot;
template<typename T> class cISC4SimGrid;
class cS3DVector3;

class cISTESurfaceWater : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual float GetWaterDepthAtVertex(int32_t index) const = 0;
	virtual float GetWaterDepthForCell(int32_t x, int32_t z) const = 0;

	virtual bool IsNavigable(int32_t param_1, int32_t param_2, int32_t param_3, cISC4Lot* param_4) const = 0;
	virtual bool IsNavigable(cS3DVector3 param_1, int32_t param_2, cISC4Lot* param_3) const = 0;

	virtual cISC4SimGrid<uint16_t>* GetBodyOfWaterMap() const = 0;
	virtual float AltitudeAtWhichFloodingWillOccur(int32_t x, int32_t z) = 0;
	virtual float GetWaterVelocity(int32_t x, int32_t z) = 0;
	virtual int32_t GetWaterType(int32_t x, int32_t z) = 0;
	virtual bool HasDraftClearance(int32_t x, int32_t z) = 0;
};