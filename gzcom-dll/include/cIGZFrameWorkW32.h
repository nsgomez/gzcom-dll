/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZFrameWorkW32.h
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
#include <Windows.h>

class cIGZFrameWork;

static const uint32_t GZIID_cIGZFrameWorkW32 = 0x23ea70a1;

class cIGZFrameWorkW32 : public cIGZUnknown
{
public:

	virtual cIGZFrameWork* AsIGZFrameWork() = 0;

	virtual HINSTANCE GetWindowsInstance() = 0;

	virtual HWND GetMainHWND() = 0;

	virtual bool SetMainHWND(HWND) = 0;
};