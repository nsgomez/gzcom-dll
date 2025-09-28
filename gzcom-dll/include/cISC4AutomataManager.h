/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4AutomataManager.h
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
#include "cGZPersistResourceKey.h"
#include "SC4String.h"
#include "cISCResExemplar.h"

class cIGZMessageTarget2;
class cISC4Automaton;
class cS3DVector3;

template <typename T> class SC4Rect;
template <typename T> class SC4Vector;

class cISC4AutomataManager : public cIGZUnknown
{
public:
	class tExemplarData
	{
	public:
		uint32_t zoneFilter;
		uint32_t wealthFilter;
		uint32_t zonePurposeFilter;
		uint32_t layerFilter;
		cGZPersistResourceKey modelResourceKey;
		SC4String exemplarName;
		cISCResExemplar* resExemplar;
		bool ignoreLighting;
		uint32_t crimeType;
		uint32_t occupantGroups[10];
		uint8_t occupantGroupCount;
		uint32_t finalOccupantGroup;
	};

	class tDispatchLocation;

	enum class PopulateLayer : int32_t
	{
		None = 0,
		Commute = 1,
		Bus = 2,
		FreightTruck = 3,
		CommuteTrain = 4,
		FreightTrain = 5,
		Subway = 6,
		OccupantTrip = 7,
		Crime = 8,
		ElevatedTrain = 9,
		Monorail = 10
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool Activate(bool unknown1) = 0;
	virtual bool IsActive() const = 0;

	virtual bool AddAutomaton(cISC4Automaton* unknown1) = 0;
	virtual bool RemoveAutomaton(cISC4Automaton* unknown1, bool unknown2) = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;
	virtual bool IsPaused() const = 0;

	virtual uint32_t GetAutomataCount() const = 0;
	virtual bool IsDrivingMode() const = 0;
	virtual uint8_t GetMinZoom() const = 0;
	virtual cISC4Automaton* CreateAutomaton(uint32_t unknown1, cS3DVector3 const& unknown2, uint32_t unknown3, cGZPersistResourceKey const& unknown4, cIGZMessageTarget2* unknown5, uint8_t unknown6, cS3DVector3 const* unknown7) = 0;
	virtual bool GetRandomCreationPoint(uint32_t unknown1, cS3DVector3 const& unknown2, float unknown3, float unknown4, cS3DVector3& unknown5, uint32_t unknown6, cS3DVector3* unknown7) = 0;

	virtual bool Dispatch(cISC4Automaton* unknown1, tDispatchLocation const& unknown2, tDispatchLocation* unknown3, uint32_t unknown4, uint8_t unknown5, cGZPersistResourceKey const& unknown6, uint8_t unknown7) = 0;
	virtual bool Dispatch(cISC4Automaton* unknown1, tDispatchLocation const& unknown2, tDispatchLocation* unknown3, uint32_t unknown4, uint8_t unknown5) = 0;
	virtual bool TranslateDispatchLocation(tDispatchLocation const& unknown1, SC4Rect<int32_t>& unknown2) = 0;
	virtual bool TranslateDispatchLocation(tDispatchLocation const& unknown1, cS3DVector3& unknown2) = 0;
	virtual bool ChaseAutomaton(cISC4Automaton* unknown1, cISC4Automaton* unknown2) = 0;
	virtual bool ChaseAutomaton(uint32_t unknown1, float unknown2, cISC4Automaton* unknown3, bool unknown4) = 0;

	virtual void SetMaxCount(int count) = 0;
	virtual bool HandleTuningParametersChanged() = 0;

	virtual tExemplarData* ChooseRandomExemplar(uint32_t unknown1, PopulateLayer unknown2, int unknown3, int unknown4) = 0;
	virtual tExemplarData* ChooseRandomExemplarByFilter(uint32_t unknown1, uint32_t unknown2, uint32_t unknown3, uint32_t unknown4, uint32_t unknown5) = 0;
	virtual tExemplarData* ChooseExemplarByCrimeType(uint32_t unknown1, uint32_t unknown2, PopulateLayer unknown3) = 0;
	virtual SC4Vector<tExemplarData>& GetExemplarData() = 0;
	virtual intptr_t GetExemplarDataMap() = 0; // std::map<uint32_t, std::vector<uint32_t>>

	virtual bool CanCreateGroup(uint32_t id) const = 0;
	virtual bool TrackAutomataGroupInstances(uint32_t unknown1, bool unknown2) = 0;
	virtual bool GetInstancesOfGroup(uint32_t unknown1, intptr_t& hash_set) const = 0;
	virtual void ReleaseAutomatonSet(intptr_t hash_set) = 0;
	virtual void SetCameraFollow(cISC4Automaton* unknown1) = 0;
	virtual bool IsCameraFollowUpdating() const = 0;
	virtual uint32_t GetSourceBuildingCount(uint32_t unknown1) const = 0;
	virtual uint32_t GetSourceBuildingCountForAutomataGroup(uint32_t unknown1) const = 0;
};