/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4Rect.h
 *
 * Copyright (C) 2016 Nelson Gomez
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

template<typename T>
class SC4Rect
{
	public:
		SC4Rect()
			: topLeftX(0),
			  topLeftY(0),
			  bottomRightX(0),
			  bottomRightY(0)
		{
		}

		SC4Rect(T topLeftX, T topLeftY, T bottomRightX, T bottomRightY)
			: topLeftX(topLeftX),
			  topLeftY(topLeftY),
			  bottomRightX(bottomRightX),
			  bottomRightY(bottomRightY)
		{
		}

		SC4Rect(SC4Rect const& other)
		{
			this->topLeftX = other.topLeftX;
			this->topLeftY = other.topLeftY;
			this->bottomRightX = other.bottomRightX;
			this->bottomRightY = other.bottomRightY;
		}

		SC4Rect(SC4Rect&& other) noexcept
		{
			this->topLeftX = other.topLeftX;
			this->topLeftY = other.topLeftY;
			this->bottomRightX = other.bottomRightX;
			this->bottomRightY = other.bottomRightY;

			other.topLeftX = 0;
			other.topLeftY = 0;
			other.bottomRightX = 0;
			other.bottomRightY = 0;
		}


		SC4Rect& operator=(SC4Rect const& other)
		{
			this->topLeftX = other.topLeftX;
			this->topLeftY = other.topLeftY;
			this->bottomRightX = other.bottomRightX;
			this->bottomRightY = other.bottomRightY;

			return *this;
		}

		SC4Rect& operator=(SC4Rect&& other) noexcept
		{
			this->topLeftX = other.topLeftX;
			this->topLeftY = other.topLeftY;
			this->bottomRightX = other.bottomRightX;
			this->bottomRightY = other.bottomRightY;

			other.topLeftX = 0;
			other.topLeftY = 0;
			other.bottomRightX = 0;
			other.bottomRightY = 0;

			return *this;
		}

		T topLeftX;
		T topLeftY;
		T bottomRightX;
		T bottomRightY;
};