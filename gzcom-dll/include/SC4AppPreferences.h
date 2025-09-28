/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4AppPreferences.h
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

class SC4AppPreferences
{
public:
    uint32_t enableFullGamePauseOnAppFocusLoss;
    uint32_t languageID;
    int8_t languageName[64];
    uint8_t field3_0x48;
    uint8_t field4_0x49;
    uint8_t field5_0x4a;
    uint8_t bIME;
    uint8_t field7_0x4c[2400];
};

