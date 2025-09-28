/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SCPropertyUtil.h
 *
 * Copyright (C) 2024, 2025 Nicholas Hayes
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
#include "cISCPropertyHolder.h"

class cIGZString;
struct StringResourceKey;

namespace SCPropertyUtil
{
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, bool& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int8_t& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint8_t& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int16_t& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint16_t& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int32_t& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint32_t& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int64_t& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint64_t& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, float& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, double& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, cIGZString& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, StringResourceKey& value);
}