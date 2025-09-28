/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZPersistDBRecord.h
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

class cGZPersistResourceKey;

static const uint32_t GZIID_cIGZPersistDBRecord = 0xE56B8F03;

class cIGZPersistDBRecord : public cIGZUnknown
{
public:
	virtual void GetKey(cGZPersistResourceKey& key) const = 0;

	virtual uint16_t GetAccessFlags() const = 0;
	virtual bool Close() = 0;

	virtual bool GetFieldVoid(void*, uint32_t) = 0;
	virtual bool SetFieldVoid(const void*, uint32_t) = 0;

	virtual uint32_t GetSize() = 0;
	virtual bool SetSize(uint32_t) = 0;

	virtual uint32_t GetPosition() = 0;
	virtual uint32_t SeekAbsolute(uint32_t) = 0;
	virtual uint32_t SeekRelative(int32_t) = 0;
};
