/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4WeatherSimulator.h
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

class cS3DVector2;
template <typename T> class SC4Rect;
template <typename T> class SC4Vector;

class cISC4WeatherSimulator : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool DoPostCityInit() = 0;

	virtual float CellWidthX() = 0;
	virtual float CellWidthZ() = 0;
	virtual uint32_t CellCountX() = 0;
	virtual uint32_t CellCountZ() = 0;

	virtual int32_t PositionToCell(float fX, float fZ, int& cX, int& cZ) = 0;
	virtual void CellToPosition(int32_t cX, int32_t cZ, float& fX, float& fZ) = 0;
	virtual void CellToStandardCityCell(int32_t unknown1, int32_t unknown2, int32_t& unknown3, int32_t& unknown4) = 0;
	virtual void StandardCityCellToCell(int32_t unknown1, int32_t unknown2, int32_t& unknown3, int32_t& unknown4) = 0;

	virtual int32_t GetCurrentSeason() = 0;
	virtual int32_t GetCurrentSeasonMonth() = 0;

	virtual void UpdateMoisture(SC4Rect<int32_t> const& rect) = 0;
	virtual uint8_t GetMoistureValue(float x, float z) = 0;
	virtual void GetMoistureValueMapPtr(SC4Vector<SC4Vector<uint8_t>>& vector) = 0;
	virtual uint8_t GetMoistureType(float x, float z) = 0;
	virtual void SetManualMoistureAddition(float unknown1, float unknown2, float unknown3, float unknown4, float unknown5) = 0;

	virtual float GetHumidity(float x, float z) = 0;
	virtual float GetAmbientWind(cS3DVector2& ambientWind) = 0;
	virtual float GetWindAtCell(int x, int z, cS3DVector2& ambientWind) = 0; // Calls GetAmbientWind, x and z parameters are unused.
};