/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4PropOccupantTerrainDecal.h
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

#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;

static const uint32_t GZCLSID_cISC4PropOccupantTerrainDecal = 0x2977aa48;
static const uint32_t GZIID_cISC4PropOccupantTerrainDecal = 0x2977aa48;

class cISC4PropOccupantTerrainDecal : public cIGZUnknown
{
public:
	enum class tCompletionAction : uint32_t
	{
		None = 0,
		RemoveOverlay = 1,
		InsertOccupant = 2
	};

	virtual void SetDecalTexture(cGZPersistResourceKey const& textureKey, float scale) = 0;
	virtual void SetOpacity(float opacity) = 0;
	virtual void SetOpacityFade(float time, tCompletionAction action, float minOpacity, float maxOpacity) = 0;
	virtual void SetDecalSize(float scale) = 0;
};