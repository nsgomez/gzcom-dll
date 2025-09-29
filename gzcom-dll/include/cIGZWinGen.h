/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZWinGen.h
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
class cIGZWin;
class cIGZWinProc;
class cRZRect;

static const uint32_t GZIID_cIGZWinGen = 0x5386D516;

class cIGZWinGen : public cIGZUnknown
{
public:
	virtual cIGZWin* AsIGZWin() = 0;

	virtual uint32_t GetCLSID() = 0;

	virtual bool GetWinGenFlag(int32_t flag) = 0;
	virtual bool SetWinGenFlag(int32_t flag, bool value) = 0;

	virtual cIGZWinGen* SetWinProc(cIGZWinProc* proc) = 0;
	virtual cIGZWinProc* GetWinProc() = 0;
	virtual bool GetWinProcAs(uint32_t riid, void** ppvObj) = 0;

	virtual bool GetUserArea(cRZRect* unknown1) = 0;
	virtual bool SetUserArea(cRZRect* unknown1) = 0;

	virtual bool SetBackgroundBitmap(uint32_t blitType, cIGZBuffer* param_2) = 0;
	virtual bool GetBackgroundBitmap(uint32_t& blitType, cIGZBuffer** param_2) = 0;
	virtual bool SetBackgroundBitmap(cIGZBuffer* param_1) = 0;
	virtual bool GetBackgroundBitmap(cIGZBuffer** param_1) = 0;
	virtual bool SetBackgroundBlitType(uint32_t blitType) = 0;
	virtual bool GetBackgroundBlitType(uint32_t& blitType) = 0;

	virtual bool SetUserData(uint32_t key, uint32_t value) = 0;
	virtual bool GetUserData(uint32_t key, uint32_t& value) = 0;

	virtual bool SetUserData(uint32_t value) = 0;
	virtual uint32_t GetUserData() = 0;

	virtual bool SetUserData(uint32_t key, cIGZUnknown* unknown2) = 0;
	virtual bool GetUserData(uint32_t key, uint32_t riid, void** ppvObj) = 0;

	virtual bool RemoveUserData(uint32_t key) = 0;

	virtual bool SetGutters(uint8_t unknown1, uint8_t unknown2) = 0;
	virtual bool GetGutters(int32_t& unknown1, int32_t& unknown2) = 0;

	virtual bool SetGutters(int8_t unknown1, int8_t unknown2, int8_t unknown3, int8_t unknown4) = 0;
	virtual bool GetGutters(int32_t& unknown1, int32_t& unknown2, uint32_t& unknown3, uint32_t& unknown4) = 0;

	// TODO: Check that these methods have the correct parameters
	virtual bool AddColorBar(int32_t unknown1, int32_t unknown2, int32_t unknown3, cRZRect const& unknown4) = 0;
	virtual bool AddDividerH(int32_t unknown1, int32_t unknown2) = 0;
	virtual bool RemoveColorBar() = 0;
};
