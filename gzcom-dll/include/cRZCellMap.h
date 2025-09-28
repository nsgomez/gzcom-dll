/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZCellMap.h
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

class cRZCellMap
{
public:
	cRZCellMap(uint32_t rows, uint32_t columns, bool initialValue);
	cRZCellMap(cRZCellMap const& other);
	cRZCellMap(cRZCellMap&& other) noexcept;

	cRZCellMap& operator=(cRZCellMap const& other);
	cRZCellMap& operator=(cRZCellMap&& other) noexcept;

	virtual ~cRZCellMap();

	bool GetValue(uint32_t column, uint32_t row) const;
	void SetValue(uint32_t column, uint32_t row, bool value);

private:
	void DestroyData();

	uint32_t rows;
	uint32_t columns;
	uint32_t columnIntegerCount;
	uint32_t** data;
};

static_assert(sizeof(cRZCellMap) == 0x14);