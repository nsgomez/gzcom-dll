/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4Point.h
 *
 * Copyright (C) 2016 Nelson Gomez
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
#include <type_traits>

template<typename T>
class SC4Point
{
	public:
		SC4Point() = default;

		SC4Point(T x, T y) : x(x), y(y)
		{
		}

		T x{};
		T y{};
};
static_assert(std::is_trivially_copyable_v<SC4Point<float>>);
static_assert(!std::is_trivially_default_constructible_v<SC4Point<float>>);  // x and y are initialized to 0
static_assert(std::is_standard_layout_v<SC4Point<float>>);