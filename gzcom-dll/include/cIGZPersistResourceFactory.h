/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZPersistResourceFactory.h
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

class cIGZPersistDBRecord;
class cIGZPersistResource;

static const uint32_t GZIID_cIGZPersistResourceFactory = 0xA56B8F17;

class cIGZPersistResourceFactory : public cIGZUnknown
{
public:
	virtual bool CreateInstance(uint32_t type, uint32_t riid, void** ppvObj, uint32_t unknown1, cIGZUnknown* unknown2) = 0;
	virtual bool CreateInstance(cIGZPersistDBRecord& record, uint32_t riid, void** ppvObj, uint32_t unknown1, cIGZUnknown* unknown2) = 0;

	virtual bool Read(cIGZPersistResource& resource, cIGZPersistDBRecord& record) = 0;
	virtual bool Write(cIGZPersistResource const& resource, cIGZPersistDBRecord& record) = 0;
};