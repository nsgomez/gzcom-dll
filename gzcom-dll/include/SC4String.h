/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4String.h
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

class cIGZString;

/**
 * @brief A class that recreates the layout of SC4's internal cRZString class.
 * It is used for structures that have cRZString fields and API methods that return it.
 *
 * Use cRZBaseString if you need a type that implements cIGZString.
 */
class SC4String
{
public:
	cIGZString* AsIGZString()
	{
		return reinterpret_cast<cIGZString*>(this);
	}

	const cIGZString* AsIGZString() const
	{
		return reinterpret_cast<const cIGZString*>(this);
	}

private:
	void* vtable;
	intptr_t stringFields[3];
	uint32_t refCount;
};