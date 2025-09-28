/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cGZGPixelFormatDesc.h
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

class cGZGPixelFormatDesc
{
public:
    uint32_t field0_0x0;
    uint32_t alphaColorMask;
    uint32_t redColorMask;
    uint32_t greenColorMask;
    uint32_t blueColorMask;
    uint32_t field5_0x14;
    uint32_t field6_0x18;
    uint32_t field7_0x1c;
};
