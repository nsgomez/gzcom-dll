/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cGZDisplayMetrics.h
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

class cGZDisplayMetrics
{
public:
	uint32_t width;        // 0x0
	uint32_t height;       // 0x4
	uint32_t bitDepth;     // 0x8
	uint32_t field3_0xc;   // 0xc
	uint32_t field4_0x10;  // 0x10
	uint32_t field5_0x14;  // 0x14
	uint32_t field6_0x18;  // 0x18
};