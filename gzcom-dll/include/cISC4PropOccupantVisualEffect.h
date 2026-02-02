/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4PropOccupantVisualEffect.h
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

class cISC4Occupant;
class cISC4PropOccupant;

static const uint32_t GZCLSID_cISC4PropOccupantVisualEffect = 0x2977aa49;
static const uint32_t GZIID_cISC4PropOccupantVisualEffect = 0x2977aa49;

class cISC4PropOccupantVisualEffect : public cIGZUnknown
{
public:
	virtual cISC4Occupant* AsOccupant() = 0;
	virtual cISC4PropOccupant* AsPropOccupant() = 0;

	virtual void SetEffectType(char const* effectName) = 0;
	virtual void SetEffectType(uint32_t effectType) = 0;
	virtual bool StartEffect(bool unknown1) = 0;
	virtual bool StopEffect(bool unknown1) = 0;
};