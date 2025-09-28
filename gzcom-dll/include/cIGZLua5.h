/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZLua5.h
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

class cIGZLua5Thread;

static const uint32_t GZIID_cIGZLua5 = 0x6B2811A6;

class cIGZLua5 : public cIGZUnknown
{
public:
	enum OpenFlags : int32_t
	{
		OpenFlagNone = 0,
		OpenFlagIO = 2,
		OpenFlagString = 4,
		OpenFlagMath = 8,
		OpenFlagDebug = 16,
		OpenFlagTable = 32,
		OpenFlagLua4Compat = 64,
		OpenFlagDefault = OpenFlagIO | OpenFlagString | OpenFlagMath | OpenFlagDebug | OpenFlagTable | OpenFlagLua4Compat
	};

	virtual cIGZLua5Thread* AsIGZLua5Thread() = 0;

	virtual bool Open(OpenFlags) = 0;
	virtual void Close() = 0;

	virtual int32_t CreateThread(cIGZLua5Thread**, int32_t, uint32_t) = 0;
	virtual void DestroyThread(int32_t) = 0;
	virtual bool ResumeThread(int32_t, int32_t, int32_t*) = 0;
	virtual cIGZLua5Thread* GetThread(int32_t) = 0;

	virtual int32_t GetGCCount() = 0;
	virtual int32_t GetGCThreshold() = 0;
	virtual void SetGCThreshold(int32_t) = 0;

	typedef void (*ErrorReporterCallback)(cIGZLua5Thread*, int32_t, char const*);

	virtual void SetErrorReporter(ErrorReporterCallback, bool) = 0;
	virtual ErrorReporterCallback GetErrorReporter() = 0;
};