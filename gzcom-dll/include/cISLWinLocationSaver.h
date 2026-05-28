/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISLWinLocationSaver.h
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

class cIGZWin;

class cISLWinLocationSaver : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool SaveWindowLocation(uint32_t id, int32_t left, int32_t top) = 0;
	virtual bool SaveWindowLocation(cIGZWin* pWin) = 0;
	virtual bool GetWindowRestoreLocation(uint32_t& id, int32_t& left, int32_t& top, bool unknown4) = 0;
	virtual bool GetWindowRestoreLocation(cIGZWin* pWin, int32_t& left, int32_t& top, bool unknown4) = 0;
	virtual bool RestoreWindowLocation(uint32_t id, bool unknown2) = 0;
	virtual bool RestoreWindowLocation(cIGZWin* pWin, bool unknown2) = 0;
};