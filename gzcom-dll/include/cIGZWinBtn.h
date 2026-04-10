/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZWinBtn.h
 *
 * Copyright (C) 2024, 2026 Nicholas Hayes
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
class cIGZFont;
class cIGZString;
class cIGZWin;
class cRZColor;
class cRZRect;

static const uint32_t GZIID_cIGZWinBtn = 0x8810;

class cIGZWinBtn : public cIGZUnknown
{
public:
	enum BtnFlag : int32_t
	{
		BtnFlagToggle = 0x1,
		BtnFlagTriggerOnDown = 0x2,
		BtnFlagShowCaption = 0x4,
		BtnFlagFill = 0x10,
		BtnFlagAutoSize = 0x20,
		BtnFlagWrapCaption = 0x40,
		BtnFlagShiftCaption = 0x80,
		BtnFlagTips = 0x100,
		BtnFlagTipsDelay = 0x200,
		BtnFlagTipsTimeOut = 0x400,
	};

	enum class CaptionStyle : int32_t
	{
		AlignCenter = 0,
		AlignLeft = 1,
		AlignRight = 2
	};

	enum class Style : int32_t
	{
		Label = 1,
		Standard = 2,
		Toggle = 3,
		RadioCheck = 4
	};

	virtual cIGZWin* AsIGZWin() = 0;

	virtual bool GetBtnFlag(BtnFlag flag) const = 0;
	virtual bool SetBtnFlag(BtnFlag flag, bool value) = 0;

	virtual bool ToggleOn() = 0;
	virtual bool ToggleOff() = 0;
	virtual bool IsOn() const = 0;

	virtual bool SetChecked(bool unknown1) = 0;
	virtual bool IsChecked() const = 0;

	virtual Style GetStyle() = 0;
	virtual bool SetStyle(Style style, cIGZBuffer* imageBuffer, cRZRect const* imageArea) = 0;
	virtual bool SetButtonStyle(Style style) = 0;

	virtual int32_t GetImageW() const = 0;
	virtual int32_t GetImageH() const = 0;
	virtual bool GetImageArea(cRZRect& unknown1) const = 0;

	virtual bool SetBuffer(cIGZBuffer* unknown1) = 0;
	virtual bool GetBuffer(cIGZBuffer*& unknown1) const = 0;

	virtual bool SetFont(cIGZFont* font) = 0;
	virtual bool SetFontStyle(uint32_t style) = 0;
	virtual bool GetFontStyle(uint32_t& style) = 0;

	virtual bool SetFontColor(int32_t unknown1, uint32_t unknown2) = 0;
	virtual bool GetFontColor(int32_t unknown1, uint32_t& unknown2) const = 0;
	virtual bool SetFontColor(int32_t unknown1, cRZColor& unknown2) = 0;
	virtual bool GetFontColor(int32_t unknown1, cRZColor& unknown2) const = 0;
	virtual bool ClearFontColor(int32_t unknown1) = 0;

	virtual bool SetCaptionStyle(CaptionStyle style) = 0;
	virtual bool GetCaptionStyle(CaptionStyle& style) const = 0;

	virtual bool SetGutters(uint8_t unknown1, uint8_t unknown2) = 0;
	virtual bool GetGutters(int32_t& unknown1, int32_t& unknown2) const = 0;
	virtual bool SetGutters(uint8_t unknown1, uint8_t unknown2, uint8_t unknown3, uint8_t unknown4) = 0;
	virtual bool GetGutters(int32_t& unknown1, int32_t& unknown2, int32_t& unknown3, int32_t& unknown4) const = 0;

	virtual bool FitSizeToContent() = 0;
	virtual bool GetMinMaxInfo(cRZRect& info) const = 0;

	virtual bool SetTipText(const cIGZString& tipText) = 0;
	virtual bool GetTipText(cIGZString& tipText) const = 0;
	virtual bool ClearTipText() = 0;

	virtual bool SetTipPlacementType(int32_t unknown1) = 0;
	virtual bool GetTipPlacementType(int32_t& unknown1) const = 0;

	virtual bool SetTipPlacementOffsets(int32_t unknown1, int32_t unknown2) = 0;
	virtual bool GetTipPlacementOffsets(int32_t& unknown1, int32_t& unknown2) const = 0;

	virtual bool SetTipColor(int32_t unknown1, uint8_t unknown2, uint8_t unknown3, uint8_t unknown4) = 0;
	virtual bool GetTipColor(int32_t unknown1, uint8_t& unknown2, uint8_t& unknown3, uint8_t& unknown4) const = 0;

	virtual void Flash(uint32_t unknown1, uint32_t unknown2) = 0;
	virtual bool SetSoundID(int32_t unknown1, uint32_t unknown2) = 0;
	virtual uint32_t GetSoundID(int32_t unknown1) const = 0;

	virtual bool SetID(uint32_t unknown1) = 0;
	virtual uint32_t GetID() const = 0;

	virtual bool SetCaption(const cIGZString& caption) = 0;
	virtual cIGZString* GetCaption() = 0;
};
