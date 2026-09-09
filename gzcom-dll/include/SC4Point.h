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

template<typename T>
class SC4Point
{
	public:
		SC4Point() : x(0), y(0)
		{
		}

		SC4Point(T x, T y) : x(x), y(y)
		{
		}

		SC4Point(SC4Point const& other)
		{
			this->x = other.x;
			this->y = other.y;
		}

		SC4Point(SC4Point&& other) noexcept
		{
			this->x = other.x;
			this->y = other.y;
			other.x = 0;
			other.y = 0;
		}

		SC4Point& operator=(SC4Point const& other)
		{
			this->x = other.x;
			this->y = other.y;

			return *this;
		}

		SC4Point& operator=(SC4Point&& other)
		{
			this->x = other.x;
			this->y = other.y;
			other.x = 0;
			other.y = 0;

			return *this;
		}

		T x;
		T y;
};