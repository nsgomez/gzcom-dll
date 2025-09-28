/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4CitySituationManager.h
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

class cIGZMessageTarget2;
class cIGZString;
class cISC4Automaton;
class cISC4CitySituationAdvice;
class cISC4Occupant;

class cISC4CitySituationManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual uint32_t GetMissionSuccessCount(uint32_t) const = 0;
	virtual cISC4CitySituationAdvice* GetActiveSituation() const = 0;
	virtual uint32_t GetCurrentStatus() const = 0;
	virtual cISC4Automaton* GetActiveAuto() = 0;

	virtual cISC4Occupant* GetCurrentTarget() const = 0;
	virtual uint32_t GetCurrentTargetIndex() const = 0;
	virtual uint32_t GetNumTargets() const = 0;
	virtual uint32_t GetNumTargetsRemaining() const = 0;
	virtual float GetCurrentTimeLimitSeconds() const = 0;
	virtual float GetCurrentSituationTime() const = 0;
	virtual float GetCurrentTimeRemainingSeconds() const = 0;
	virtual void GetCurrentTargetName(cIGZString& name) const = 0;

	virtual bool GetSituationAura(float& unknown1, float& unknown2) = 0;
	virtual bool GetSituationMoney(int64_t& value) = 0;

	virtual bool IsSituationAvailable(cISC4Occupant* pOccupant) const = 0;
	virtual bool IsSituationAvailable(uint32_t guid) const = 0;
	virtual bool InitiateSituationByGuid(uint32_t sessionID, bool unknown2, uint32_t unknown3) = 0;
	virtual bool InitiateSituationForOccupant(cISC4Occupant* unknown1, cISC4CitySituationAdvice* unknown2) = 0;
	virtual bool InitiateSituationByAutomataGroup(uint32_t unknown1, bool unknown2, bool unknown3) = 0;
	virtual void StartJoyride(cISC4Automaton* unknown1, bool unknown2, cIGZMessageTarget2* unknown3) = 0;

	virtual void TreatAutomatonAsGroup(cISC4Automaton* pAutomaton, uint32_t occupantGroup) = 0;
	virtual void SetMaxCSI(uint8_t value) = 0;
	virtual uint8_t GetMaxCSI() const = 0;
	virtual uint32_t GetTrackedAutomataCount() = 0;
	virtual void SetCSIVisible(bool visible) = 0;
	virtual bool GetCSIVisible() const = 0;

	virtual bool HandleTuningParametersChanged() = 0;
	virtual bool CountdownIsInProgress() const = 0;
	virtual void ResetTutorials() = 0;
};