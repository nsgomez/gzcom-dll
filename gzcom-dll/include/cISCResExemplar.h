/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISCResExemplar.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2024 memo
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
#include "cIGZSerializable.h"

class cGZPersistResourceKey;
class cISCPropertyHolder;
class cISCResExemplarCohort;

static const uint32_t GZIID_cISCResExemplar = 0xA52160F5;

class cISCResExemplar : public cIGZSerializable
{
	public:
		virtual cISCPropertyHolder* AsISCPropertyHolder(void) = 0;
		virtual cISCPropertyHolder* AsISCPropertyHolder(void) const = 0;

		virtual bool IsPropertyLocal(uint32_t dwProperty) = 0;

		virtual cISCResExemplarCohort* GetCohort(void) = 0;
		virtual bool SetCohort(cISCResExemplarCohort* pCohort, bool bSendMsg) = 0;

		virtual bool GetKey(cGZPersistResourceKey& sKey) = 0;
		virtual bool SetKey(cGZPersistResourceKey const& sKey) = 0;

		virtual bool CompactProperties(void) = 0;
};