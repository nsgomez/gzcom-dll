/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZCursorManager.h
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

class cIGZCursor;
class cIGZString;

class cIGZCursorManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool AddCursor(cIGZCursor* cursor, uint32_t id) = 0;
	virtual bool RemoveCursor(uint32_t id) = 0;

	virtual cIGZCursor* GetCursor(uint32_t id) = 0;
	virtual cIGZCursor* GetCursor() = 0;
	virtual bool SetCursor(uint32_t id) = 0;
	virtual bool SetCursor(cIGZCursor* cursor) = 0;

	virtual bool PushAutoCursor(uint32_t id) = 0;
	virtual bool PopAutoCursor() = 0;

	virtual bool AddCursor(cIGZString const& path, uint32_t id) = 0;
	virtual void ShowCursor() = 0;
	virtual void HideCursor() = 0;
};