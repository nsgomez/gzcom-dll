/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cGZBufferType.h
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

enum class cGZBufferType : uint32_t
{
	Unknown0 = 0,
	Unknown1 = 1,
	Unknown2 = 2,
	Unknown3 = 3,
	Unknown4 = 4,
	Unknown5 = 5,
	Unknown6 = 6,
	Unknown7 = 7,
	Unknown8 = 8,
	Bgra32 = 9,
};