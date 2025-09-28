/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZMessage2.h
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
#include "cIGZMessage2.h"
#include "cRZUnknown.h"

class cRZMessage2 : public cIGZMessage2, public cRZUnknown
{
	public:
		bool QueryInterface(uint32_t riid, void** ppvObj);
		uint32_t AddRef(void) { return cRZUnknown::AddRef(); }
		uint32_t Release(void) { return cRZUnknown::Release(); }

	public:
		cRZMessage2();

		bool Create(uint32_t dwType, void** ppUnknown) const override;

		uint32_t GetType(void) const override;
		uint32_t SetType(uint32_t dwType) override;

		bool operator==(cIGZMessage2 const& msgOther) const override;
		bool operator<(cIGZMessage2 const& msgOther) const override;

	protected:
		uint32_t m_dwType;
};