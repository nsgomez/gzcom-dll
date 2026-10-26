/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZWinGen.h
 *
 * Copyright (C) 2025, 2026 Nicholas Hayes
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

static const uint32_t GZCLSID_cGZWinGen = 0x4386d516;
static const uint32_t GZIID_cIGZWinGen = 0x5386D516;

class cIGZWinGen : public cIGZUnknown
{
public:
	enum WinGenFlags : int32_t
	{
		WinGenFlag_Movable = 0x1,
		WinGenFlag_Sizable = 0x2,
		WinGenFlag_DefaultKeys = 0x4,
		WinGenFlag_CloseVisible = 0x10,
		WinGenFlag_GoBackVisible = 0x20,
		WinGenFlag_MinMaxVisible = 0x40,
		WinGenFlag_CloseDisabled = 0x100,
		WinGenFlag_GoBackDisabled = 0x200,
		WinGenFlag_MinMaxDisabled = 0x400,
		WinGenFlag_TitleBar = 0x1000,
		WinGenFlag_Fill = 0x2000,
		WinGenFlag_Outline = 0x4000,
		WinGenFlag_Paint = 0x8000,
		WinGenFlag_Sidebar = 0x10000,
	};

	struct tWinProcMessageTypes
	{
		enum eWinProcMessageTypes : uint32_t
		{
			// unusable for scripted windows because the game calls cIGZWin::Init before user code can set the WinProc.
			GZWinInit = 0xa2bf8ad0, 
			GZWinShutdown = 0xa2bf8ad1,
			// data1 = adjusted rect pointer, data2 = user area rect pointer.
			LayoutAdjustUserRect = 0xa2bf8ad2,
			// data1 = user area rect pointer, data2 = window bounds rect pointer.
			Layout = 0xa2bf8ad3,
			// data1 = packed mouse position with x in high 16 bits and y in low 16 bits,
			// data2 = pointer to a one - byte Boolean result.
			PointInWindowCoordinates = 0xa2bf8ad4,
			// fires when the winproc is set to non - null and can be used for initialization.
			Attach = 0xa2bf8ad5,
			// fires when the winproc is set to null and can be used for shutdown.
			Detach = 0xa2bf8ad6,
			// fires when the winproc is set to non - null and can be used for initialization.
			PostAttach = 0xa2bf8ad8,
			// data1 = draw area rect pointer
			BeginPaint = 0xa2bf8acd,
			// data1 = draw area rect pointer
			Paint = 0xa2bf8ace,
			// data1 = draw area rect pointer
			EndPaint = 0xa2bf8acf,
		};
	};

	virtual cIGZWin* AsIGZWin() = 0;

	virtual uint32_t GetCLSID() = 0;

	virtual bool GetWinGenFlag(WinGenFlags flag) const = 0;
	virtual bool SetWinGenFlag(WinGenFlags flag, bool value) = 0;

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
	virtual bool RemoveColorBar(int32_t unknown1) = 0;
};
