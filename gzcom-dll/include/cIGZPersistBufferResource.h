/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZPersistBufferResource.h
 *
 * Copyright (C) 2026 Nicholas Hayes
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

class cGZBufferColorType;
class cIGZBuffer;

static const uint32_t GZIID_cIGZPersistBufferResource = 0x6f1568e;

class cIGZPersistBufferResource : public cIGZUnknown
{
public:
	virtual cIGZBuffer* GetBuffer() const = 0;

	// Renamed the GetBuffer(uint32_t, void**) overload to GetBufferAs to avoid ambiguity with
	// the overload order on Windows.
	// MSVC puts every virtual overload of a name at the vtable slot of the first one declared,
	// in REVERSE declaration order.

	virtual bool GetBufferAs(uint32_t riid, void** ppvObj) = 0;

	// On Windows, SetBuffer is below the GetBuffer methods.

	virtual bool SetBuffer(cIGZBuffer* pBuffer) = 0;
};
