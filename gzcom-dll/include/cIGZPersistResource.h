/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZPersistResource.h
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

class cGZPersistResourceKey;

static const uint32_t GZIID_cIGZPersistResource = 0x456b8f1d;

class cIGZPersistResource : public cIGZUnknown
{
public:
	virtual void GetKey(cGZPersistResourceKey& key) const = 0;
	virtual bool SetKey(cGZPersistResourceKey const& key) = 0;

	virtual uint32_t GetType() const = 0;
	virtual uint32_t GetGroup() const = 0;
	virtual uint32_t GetInstance() const = 0;

	virtual bool SetType(uint32_t type) = 0;
	virtual bool SetGroup(uint32_t group) = 0;
	virtual bool SetInstance(uint32_t instance) = 0;

	virtual uint32_t GetRefCount() const = 0;
};
