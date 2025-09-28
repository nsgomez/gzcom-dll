/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4CrimeSimulator.h
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

class cS3DVector3;
class cISC4Automaton;
class cISC4PropOccupant;

template <typename T> class cISC4SimGrid;
template <typename T> class SC4Vector;

class cISC4CrimeSimulator : public cIGZUnknown
{
public:
	class tCrimeEvent
	{
	public:
		uint32_t cellX;
		uint32_t cellZ;
		uint32_t id;
		uint8_t unknown1;
		cGZPersistResourceKey nameKey;
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual cISC4SimGrid<uint8_t>* GetCrimeGrid() = 0;

	virtual uint32_t GetAverageCrime() = 0;
	virtual uint32_t GetMonthlyCrimeCount() = 0;

	virtual bool GetCrimeHotspot(uint8_t* unknown1, int32_t* unknown2, int32_t* unknown3) = 0;
	virtual cISC4Automaton* GetNearestCrimeSim(cS3DVector3 const& unknown1, float unknown2) = 0;
	virtual cISC4PropOccupant* GetNearestCrimeProp(cS3DVector3 const& unknown1, float unknown2) = 0;
	virtual bool GetCrimeIncidentArray(SC4Vector<tCrimeEvent>& vector) = 0;

	virtual bool SetVisualsCreated(uint32_t unknown1, bool unknown2) = 0;
	virtual bool GetVisualsCreated(uint32_t unknown1) = 0;
};