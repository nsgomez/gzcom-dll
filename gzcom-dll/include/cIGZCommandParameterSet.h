/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZCommandParameterSet.h
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

class cIGZVariant;

class cIGZCommandParameterSet : public cIGZUnknown
{
public:
	static const uint32_t kStatusParameterID = 0x2b999d2b;

	virtual uint32_t GetParameterCount() const = 0;
	virtual void SetParameterCount(uint32_t count) = 0;

	virtual cIGZVariant* operator[](uint32_t id) = 0;

	virtual cIGZVariant* GetParameter(uint32_t id) = 0;
	virtual void SetParameter(uint32_t id, cIGZVariant const& variant) = 0;
	virtual void AppendParameter(cIGZVariant const& variant) = 0;
	virtual void RemoveParameter(uint32_t id) = 0;

	virtual void SetStatusParameterValue(int32_t status) = 0;
	virtual bool CompareParameterString(uint32_t id, const char* other, bool caseSensitive) = 0;
	virtual bool ValidateParameter(uint32_t unknown1, uint32_t unknown2) = 0;

	virtual uint32_t GetFirstParameterID() const = 0;
	virtual uint32_t GetNextParameterID(uint32_t previousID) const = 0;
};