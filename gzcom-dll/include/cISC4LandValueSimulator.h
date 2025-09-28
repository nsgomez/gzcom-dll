/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4LandValueSimulator.h
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

template<typename T> class cISC4SimGrid;

class cISC4LandValueSimulator : public cIGZUnknown
{
public:
	enum class LandValueType : uint32_t
	{
		Low = 1,
		Medium = 2,
		High = 3
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual LandValueType GetLandValueType(int32_t x, int32_t z) = 0;
	virtual uint8_t GetLandValue(int32_t x, int32_t z) = 0;

	virtual cISC4SimGrid<uint8_t>* GetIntrinsicLandValueMap() = 0;
	virtual cISC4SimGrid<uint8_t>* GetTotalLandValueMap() = 0;
	virtual cISC4SimGrid<float>* GetSlopeMap() = 0;
	virtual uint8_t GetAverageLandValue() = 0;

	virtual float GetModeAltitude() = 0;
};
