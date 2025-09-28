/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZPersistResourceKeyList.h
 *
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
#include "cIGZUnknown.h"

class cGZPersistResourceKey;

static const uint32_t GZCLSID_cIGZPersistResourceKeyList = 0x656B8F2D;
static const uint32_t GZIID_cIGZPersistResourceKeyList = 0x656B8F12;

class cIGZPersistResourceKeyList : public cIGZUnknown
{
	public:
		virtual bool Insert(cGZPersistResourceKey const& key) = 0;
		virtual bool Insert(cIGZPersistResourceKeyList const& list) = 0;

		virtual bool Erase(cGZPersistResourceKey const& key) = 0;
		virtual bool EraseAll() = 0;

		typedef void (*EnumKeysFunctionPtr)(cGZPersistResourceKey const& key, void* pContext);

		virtual void EnumKeys(EnumKeysFunctionPtr pCallback, void* pContext) const = 0;

		virtual bool IsPresent(cGZPersistResourceKey const& key) const = 0;
		virtual uint32_t Size() const = 0;
		virtual const cGZPersistResourceKey& GetKey(uint32_t index) const = 0;
};
