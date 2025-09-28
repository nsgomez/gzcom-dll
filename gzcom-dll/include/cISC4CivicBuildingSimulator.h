/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4CivicBuildingSimulator.h
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
#include "cIGZUnknown.h"
#include "SC4String.h"

class cIGZString;

class cISC4CivicBuildingSimulator : public cIGZUnknown
{
public:
	enum eConditionalBuildingStatus : uint8_t
	{
		ConditionalBuildingStatusNone = 0,
		ConditionalBuildingStatusHidden = 1,
		ConditionalBuildingStatusAvailable = 2,
		ConditionalBuildingStatusAdvisorEventDataSet = 4
	};

	class ConditionalBuildingStatus
	{
	public:
		eConditionalBuildingStatus status;
		uint16_t buildingCount;
		SC4String itemToolTip;
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool IsBuildingExcluded(uint32_t buildingID) = 0;

	virtual ConditionalBuildingStatus* GetConditionalBuildingStatus(uint32_t buildingID) const = 0;
	virtual bool UpdateConditionalBuildingStatus(uint32_t buildingID, ConditionalBuildingStatus* status) = 0;

	virtual uint32_t GetLandmarkCount() = 0;
};

