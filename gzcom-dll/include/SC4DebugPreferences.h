/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4DebugPreferences.h
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

class SC4DebugPreferences
{
public:
    uint32_t field0_0x0;     // 0x0
    uint8_t field1_0x4[16];  // 0x4
    uint8_t field2_0x14[16]; // 0x14
    uint32_t xddDebug;       // 0x24
};

