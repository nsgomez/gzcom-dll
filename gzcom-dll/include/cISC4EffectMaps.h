/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4EffectMaps.h
 *
 * Copyright (C) 2025 Nicholas Hayes
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
#include "cIGZUnknown.h"

template <typename T> class SC4Rect;

class cISC4EffectMaps : public cIGZUnknown
{
public:
	virtual uint32_t MapCount() = 0;
	virtual uint32_t MapVertsX() = 0;
	virtual uint32_t MapVertsZ() = 0;

	virtual float MapLerpedHeight(uint32_t unknown1, float unknown2, float unknown3) = 0;
	virtual float MapVertexHeight(uint32_t unknown1, uint32_t unknown2, uint32_t unknown3) = 0;
	virtual uint32_t MapLerpedNormal(float unknown2, float unknown3) = 0;

	virtual void AddRectToMap(uint32_t unknown1, SC4Rect<int32_t> const& unknown2, float unknown3, uint32_t unknown4) = 0;
};