/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZCursor.h
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

class cIGZBuffer;
class cIGZString;

class cIGZCursor : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void SetCursor(bool set) = 0;
	virtual void ShowCursor(bool show) = 0;

	virtual void GetCursorHotSpot(int32_t& x, int32_t& z) = 0;
	virtual void SetCursorHotSpot(int32_t x, int32_t z) = 0;

	virtual bool LoadCursorA(cIGZString const& path) = 0;
	virtual void SetCursorHandle(void* handle) = 0;
	virtual void SetCursorBuffer(cIGZBuffer* buffer) = 0;
	virtual bool SystemHasCursorSupport() = 0;
	virtual cIGZBuffer* GetCursorBuffer() = 0;
	virtual bool IsLoaded() = 0;
};