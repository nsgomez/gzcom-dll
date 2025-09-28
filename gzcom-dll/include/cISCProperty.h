/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISCProperty.h
 *
 * Copyright (C) 2023 Nicholas Hayes
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

class cIGZVariant;
class cIGZOStream;
class cIGZIStream;

static const uint32_t GZIID_cISCProperty = 0x452160ec;

class cISCProperty : public cIGZUnknown
{
public:

	virtual uint32_t GetPropertyID() const = 0;
	virtual void SetPropertyID(uint32_t value) = 0;

	virtual cIGZVariant* GetPropertyValue() = 0;
	virtual const cIGZVariant* GetPropertyValue() const = 0;

	virtual bool SetPropertyValue(const cIGZVariant& value) = 0;
	virtual bool Write(cIGZOStream& stream) const = 0;
	virtual bool Read(cIGZIStream& stream) = 0;
};