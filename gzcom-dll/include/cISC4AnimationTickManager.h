/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4AnimationTickManager.h
 *
 * Copyright (C) 2026 Casper Van Gheluwe
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

class cIGZMessageTarget2;

static const uint32_t GZIID_cISC4AnimationTickManager = 0x86ad10ed;

class cISC4AnimationTickManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;
	virtual bool AddTickableObject(cIGZMessageTarget2*, uint32_t) = 0;
	virtual bool RemoveTickableObject(cIGZMessageTarget2*, uint32_t) = 0;
	virtual bool FindTickableObject(cIGZMessageTarget2*, uint32_t) = 0;
	virtual void SetNewPriority(cIGZMessageTarget2*, uint32_t) = 0;
	virtual uint32_t DoAnimationTick() = 0;
	virtual uint32_t GetCurrentTickTime() const = 0;
	virtual void SetMinAndMaxTickTimeDeltas(uint32_t, uint32_t) = 0;
	virtual void PauseAnimationSystem(bool) = 0;
	virtual bool IsAnimationSystemPaused() const = 0;
	virtual void EnableAutoStep(bool, uint32_t) = 0;
	virtual void SetStepTickTimeDelta(uint32_t) = 0;
	virtual void StepAnimationSystem() = 0;
};
