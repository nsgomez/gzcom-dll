/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4CellRegion.h
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
#include "cRZCellMap.h"
#include "SC4Rect.h"
#include <utility>

template<typename T>
class SC4CellRegion
{
public:
	SC4CellRegion(T x1, T y1, T x2, T y2, bool initialValue)
		: bounds(x1, y1, x2, y2),
		  cellMap(x2 - x1 + 1, y2 - y1 + 1, initialValue)
	{
	}

	SC4CellRegion(T width, T height, bool initialValue)
		: bounds(0, 0, width, height),
		  cellMap(width, height, initialValue)
	{
	}

	SC4CellRegion(SC4CellRegion const& other)
		: bounds(other.bounds),
		  cellMap(other.cellMap)
	{
	}

	SC4CellRegion(SC4CellRegion&& other) noexcept
		: bounds(std::move(other.bounds)),
		  cellMap(std::move(other.cellMap))
	{
	}

	SC4CellRegion& operator=(SC4CellRegion const& other)
	{
		this->bounds = other.bounds;
		this->cellMap = other.cellMap;

		return *this;
	}

	SC4CellRegion& operator=(SC4CellRegion&& other) noexcept
	{
		this->bounds = std::move(other.bounds);
		this->cellMap = std::move(other.cellMap);

		return *this;
	}

	SC4Rect<T> bounds;
	cRZCellMap cellMap;
};

static_assert(sizeof(SC4CellRegion<long>) == 0x24);