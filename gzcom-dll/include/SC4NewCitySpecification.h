/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4NewCitySpecification.h
 *
 * Copyright (C) 2026 Nicholas Hayes
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

#include "cIGZBuffer.h"
#include "cRZAutoRefCount.h"

class cIGZPersistDBSegment;

class SC4NewCitySpecification
{
public:
    char terrainImagePath[512];
    cRZAutoRefCount<cIGZBuffer> terrainImageBuffer;
    cIGZPersistDBSegment* obliteratedCityDBSegment;
};

static_assert(sizeof(SC4NewCitySpecification) == 0x208);
static_assert(offsetof(SC4NewCitySpecification, terrainImageBuffer) == 0x200);
static_assert(offsetof(SC4NewCitySpecification, obliteratedCityDBSegment) == 0x204);

