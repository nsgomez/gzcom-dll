/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cGZPersistResourceKey.h
 *
 * Copyright (C) 2023, 2025 Nicholas Hayes
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
#include "stdint.h"

class cGZPersistResourceKey
{
public:
	constexpr cGZPersistResourceKey()
		: type(0), group(0), instance(0)
	{
	}

	constexpr cGZPersistResourceKey(uint32_t type, uint32_t group, uint32_t instance)
		: type(type), group(group), instance(instance)
	{
	}


	uint32_t type;
	uint32_t group;
	uint32_t instance;
};
