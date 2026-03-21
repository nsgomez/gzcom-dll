/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4TractDeveloper.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2025, 2026 Nicholas Hayes
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
#include "cISC4BuildingDevelopmentSimulator.h"

template<typename T> class SC4List;
template <typename T> class SC4Vector;

class cISC4TractDeveloper : public cIGZUnknown
{
	public:
		enum class Outcome : int32_t
		{
			UnknownFailure = 0,
			NothingToReoccupy = 1,
			MonopolyPiece = 2,
			NoLot = 3,
			LotNotReady = 4,
			NoLotConfiguration = 5,
			WrongZone = 6,
			WrongPurpose = 7,
			WrongWealth = 8,
			WrongStyle = 9,
			TooSteep = 10,
			BuildingTooSmall = 11,
			GrowthStageTooSmall = 12,
			BuildingTooBig = 13,
			GrowthStageTooBig = 14,
			ResidentHasDifferentPurpose = 15,
			ResidentHasDifferentWealth = 16,
			NotBiggerThanExistingGrowthStage = 17,
			Historical = 18,
			JustBuiltRecently = 19,
			InsufficentConstructionResources = 20,
			PoorRoads = 21,
			WrongLandValue = 22,
			NoFireCoverage = 23,
			NoPark = 24,
			NoWater = 25,
			NoPower = 26,
			Success = 27
		};

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool Grow(cISC4BuildingDevelopmentSimulator::GrowthProfile const& sProfile, SC4List<Outcome>& sOutcomes, bool& bUnknown) = 0;
		virtual bool Decline(cISC4BuildingDevelopmentSimulator::GrowthProfile const& sProfile) = 0;
		virtual bool UpdatePopulation(cISC4BuildingDevelopmentSimulator::GrowthProfile const& sProfile) = 0;

		virtual int32_t GetCurrentStyle(void) const = 0;
		virtual SC4Vector<uint32_t>& GetActiveStyles(void) const = 0;
		virtual bool SetActiveStyles(SC4Vector<uint32_t> const& sStyles) = 0;

		virtual bool IsUsingAllStylesAtOnce(void) const = 0;
		virtual cISC4TractDeveloper* UseAllStylesAtOnce(bool bFlag) = 0;

		virtual int32_t GetYearsBetweenStyleChanges(void) const = 0;
		virtual cISC4TractDeveloper* SetYearsBetweenStyleChanges(int32_t nYears) = 0;
};