/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cSC4OccupantTypeFilter.h
 *
 * Copyright (C) 2016 Nelson Gomez
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
#include "cISC4OccupantFilter.h"
#include "cRZUnknown.h"
#include <unordered_set>

class cISC4Occupant;
class cISCPropertyHolder;

class cSC4OccupantTypeFilter : public cISC4OccupantFilter, public cRZUnknown
{
	public:
		bool QueryInterface(uint32_t riid, void** ppvObj) {
			return cRZUnknown::QueryInterface(riid, ppvObj);
		}

		uint32_t AddRef(void) { return cRZUnknown::AddRef(); }
		uint32_t Release(void) { return cRZUnknown::Release(); }

	public:
		virtual bool IsOccupantIncluded(cISC4Occupant* pOccupant) {
			return true;
		}

		virtual bool IsPropertyHolderIncluded(cISCPropertyHolder* pProperties) {
			return true;
		}

		virtual bool IsOccupantTypeIncluded(uint32_t dwType) {
			return (m_sOccupantTypes.find(dwType) != m_sOccupantTypes.end());
		}

	public:
		void AddOccupantType(uint32_t dwType) {
			m_sOccupantTypes.insert(dwType);
		}

	protected:
		std::unordered_set<uint32_t> m_sOccupantTypes;
};