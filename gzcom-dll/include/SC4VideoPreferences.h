/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4VideoPreferences.h
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

class SC4VideoPreferences
{
public:
	uint8_t field0_0x0;                // 0x0
	uint8_t visualEffects;             // 0x1
	uint8_t carsAnsSims;               // 0x2
	uint8_t shadows;                   // 0x3
	uint8_t textureQuality;            // 0x4
	uint8_t bAtmosphericEffects;       // 0x5
	uint8_t bWaterEffects;             // 0x6
	uint8_t driverType;                // 0x7
	uint8_t cursorType;                // 0x8
	uint8_t bTranslucency;             // 0x9
	uint8_t cityDetail;                // 0xa
	uint8_t bFullScreen;               // 0xb
	uint32_t variableSpeedAutomata;    // 0xc
	uint32_t width;                    // 0x10
	uint32_t height;                   // 0x14
	uint32_t bitDepth;                 // 0x18
	uint32_t buildingLoaderSpeedGroup; // 0x1c
	uint32_t field17_0x20;             // 0x20
	uint32_t field18_0x24;             // 0x24
};