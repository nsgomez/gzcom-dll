/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4AudioPreferences.h
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

class SC4AudioPreferences
{
public:
    uint32_t field0_0x0;       // 0x0
    uint32_t field1_0x4;       // 0x4
    uint32_t field2_0x8;       // 0x8
    uint32_t musicEnabled;     // 0xc
    uint32_t field4_0x10;      // 0x10
    uint32_t field5_0x14;      // 0x14
    uint32_t field6_0x18;      // 0x18
    uint32_t field7_0x1c;      // 0x1c
    uint32_t field8_0x20;      // 0x20
    uint32_t field9_0x24;      // 0x24
    uint8_t field10_0x28[30];  // 0x28
    uint8_t field11_0x46[30];  // 0x46
    uint8_t field12_0x64;      // 0x64
    uint8_t audioEnabled;      // 0x65
    uint8_t field14_0x66;      // 0x66
    uint8_t field15_0x67;      // 0x67
};

