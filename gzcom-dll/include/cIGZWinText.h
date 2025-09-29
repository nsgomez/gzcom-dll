/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZWinText.h
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

class cIGZFont;
class cIGZString;
class cIGZWin;

class cRZColor;

static const uint32_t GZIID_cIGZWinText = 0x212CDC1F;

class cIGZWinText : public cIGZUnknown
{
public:

	virtual cIGZWin* AsIGZWin() = 0;

	virtual bool SetCaption(cIGZString const& caption) = 0;

	virtual bool FitWindowToText(bool unknown1, bool unknown2) = 0;

	virtual bool GetWinTextFlag(long flag) = 0;
	virtual bool SetWinTextFlag(long flag, bool value) = 0;

	virtual bool SetTextColor(uint32_t color) = 0;
	virtual bool GetTextColor(uint32_t& color) = 0;
	virtual bool ClearTextColor() = 0;

	virtual bool SetTextColor(uint32_t index, uint32_t color) = 0;
	virtual bool GetTextColor(uint32_t index, uint32_t& color) = 0;
	virtual bool SetTextColor(uint32_t index, cRZColor color) = 0;
	virtual bool GetTextColor(uint32_t index, cRZColor& color) = 0;
	virtual bool ClearTextColor(uint32_t index) = 0;

	virtual bool SetBackgroundOpaque(bool value) = 0;
	virtual bool IsBackgroundOpaque() = 0;

	virtual bool SetFont(cIGZFont* unknown1) = 0;
	virtual bool SetFontStyle(uint32_t style) = 0;
	virtual bool GetFontStyle(uint32_t& style) = 0;

	virtual bool SetAlignment(uint32_t alignment) = 0;
	virtual bool GetAlignment(uint32_t& alignment) = 0;

	virtual bool SetGutters(int8_t unknown1, int8_t unknown2) = 0;
	virtual bool GetGutters(int8_t& unknown1, int8_t& unknown2) = 0;

	virtual bool SetTextOffsets(int8_t unknown1, int8_t unknown2) = 0;
	virtual bool GetTextOffsets(int8_t& unknown1, int8_t& unknown2) = 0;

	virtual bool SetOutlineUse(bool unknown1, uint32_t unknown2) = 0;
	virtual bool GetOutlineUse(bool& unknown1, uint32_t& unknown2) = 0;
};