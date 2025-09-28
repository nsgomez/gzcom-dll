/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4EffectsManager.h
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

class cIGZString;
class cISC4EffectMaps;
class cISC4VisualEffect;

class cISC4EffectsManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool HasVisualEffect(char const* name) = 0;
	virtual bool CreateVisualEffect(char const* name, cISC4VisualEffect** ppEffect) = 0;
	virtual bool CreateVisualEffect(uint32_t unknown1, uint32_t unknown2, cISC4VisualEffect** ppEffect) = 0;

	virtual void GetStatsString(cIGZString& stats) = 0;
	virtual cISC4EffectMaps* GetEffectMaps() = 0;
	virtual float GetTallestBuildingAltitude() = 0;
};
