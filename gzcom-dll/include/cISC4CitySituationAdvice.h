/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4CitySituationAdvice.h
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
#include "cISC4ZoneManager.h"

class cIGZString;
class cISC4Advice;
class cISC4Automaton;
class SC4String;

template <typename T> class SC4List;
template <typename T> class SC4Point;
template <typename T> class SC4Rect;
template <typename T> class SC4Vector;

static const uint32_t GZIID_cISC4CitySituationAdvice = 0x6beb1e8a;

class cISC4CitySituationAdvice : public cIGZUnknown
{
public:
	enum SituationFlags : uint32_t
	{
		SituationFlag_None = 0x0,
		SituationFlag_CreateTarget = 0x1,
		SituationFlag_Unknown1 = 0x2,
		SituationFlag_HasTargetSequence = 0x4,
		SituationFlag_ServiceMission = 0x8,
		SituationFlag_UseLotBoundry = 0x10,
		SituationFlag_MySimMission = 0x20,
		SituationFlag_TrainingMission = 0x40,
		SituationFlag_PursuitMission = 0x80,
		SituationFlag_AlwaysCreateTarget = 0x100,
	};

	enum CoverageType : uint32_t
	{
		CoverageType_Zone = 1,
		// building occupant group
		CoverageType_Lot = 2,
		CoverageType_Network = 3,
		CoverageType_Rect = 4,
		// only use coverage_cells_min and coverage_cells_max
		CoverageType_UnzonedLand = 5,
		// only use coverage_cells_min and coverage_cells_max
		CoverageType_UnzonedWater = 6,
		// list of individual cells
		CoverageType_Cells = 7,
	};

	virtual cISC4Advice* AsAdvice() = 0;

	virtual uint32_t GetSuccessCondition() const = 0;
	virtual bool GetSuccessConditionText(cIGZString& text) const = 0;

	virtual float GetTimeLimit() const = 0;
	virtual float GetSuccessDistance() const = 0;
	virtual float GetMinTargetDistance() const = 0;
	virtual float GetMaxTargetDistance() const = 0;
	virtual float GetSuccessTimeout() const = 0;
	virtual float GetDelayAfterDisabled() const = 0;

	virtual SC4Vector<uint32_t>* GetAutomataGroups() const = 0;
	virtual SC4Vector<uint32_t>* GetTargetGroups() const = 0;

	virtual SituationFlags GetSituationFlags() const = 0;
	virtual bool CheckSituationFlag(SituationFlags flags) const = 0;

	virtual SC4Vector<uint32_t>* GetTargetSequence() const = 0;
	virtual bool HasTargetSequence() const = 0;

	virtual SC4Vector<uint32_t>* GetEvadeList() const = 0;
	virtual bool HasEvadeList() const = 0;
	virtual float GetEvadeDistance() const = 0;
	virtual float GetEvadeTimeout() const = 0;

	virtual cIGZString* GetSuccessText() const = 0;
	virtual cIGZString* GetFailureText() const = 0;
	virtual cIGZString* GetProgressText(uint16_t unknown1) const = 0;

	virtual uint32_t GetSituationImageId() const = 0;
	virtual uint32_t GetSuccessImageId() const = 0;
	virtual uint32_t GetSuccessMood() const const = 0;
	virtual uint32_t GetFailureImageId() const = 0;
	virtual uint32_t GetFailureMood() const = 0;

	virtual int32_t GetScriptTableRef() const = 0;
	virtual uint32_t GetEvilTwinGuid() const = 0;

	virtual uint32_t GetRewardGuid() const = 0;
	virtual cIGZString* GetRewardProgressText() const = 0;
	virtual cIGZString* GetRewardUnlockedText() const = 0;
	virtual uint32_t GetRewardUnlockedImageId() const = 0;

	virtual CoverageType GetCoverageType() const = 0;
	virtual cISC4ZoneManager::ZoneType GetCoverageZone() const = 0;
	virtual uint32_t GetCoverageOccupantGroup() const = 0;
	// Returns a bit wise combination of network flags
	virtual uint32_t GetCoverageNetworkType() = 0;
	virtual SC4Rect<int16_t>* GetCoverageRect() const = 0;
	virtual SC4List<SC4Point<uint16_t>>* GetCellCoverageList() const = 0;
	virtual uint32_t GetCoverageCellsMin() const = 0;
	virtual uint32_t GetCoverageCellsMax() const = 0;
	virtual uint32_t GetCoverageSuccessCount() = 0;
	virtual float GetCoverageSuccessPct() const = 0;

	virtual bool GetSuccessAura(float& radius, float& magnitude) const = 0;
	virtual bool GetSuccessEffectName(SC4String& text) const = 0;
	virtual bool GetSuccessMoney(int64_t& value) const = 0;
	virtual bool GetFailureAura(float& radius, float& magnitude) = 0;
	virtual bool GetFailureEffectName(SC4String& text) = 0;
	virtual bool GetFailureMoney(int64_t& value) const = 0;
	virtual float GetActiveRadius() const = 0;

	virtual bool IsAutomatonRelevant(cISC4Automaton* pAutomaton) const = 0;
	virtual bool IsGroupRelevant(SC4Vector<uint32_t> const& groups) const = 0;

	virtual void UpdateSituationFields() = 0;
};