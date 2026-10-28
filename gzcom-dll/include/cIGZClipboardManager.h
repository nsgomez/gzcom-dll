/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZClipboardManager.h
 *
 * Copyright (C) 2026 Casper Van Gheluwe
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

class cIGZClipboard;
class cIGZClipboardData;
class cIGZString;

static const uint32_t GZIID_cIGZClipboardManager = 0x07ec0010;

//
// The manager keeps its clipboards in a map keyed by clipboard ID. Methods that
// take a trailing clipboard ID forward to that clipboard. The setters and
// ClearClipboard accept 0xFFFFFFFF to act on every clipboard, and the getters
// accept 0xFFFFFFFE to use the first clipboard that has the data type.
class cIGZClipboardManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;
	virtual uint32_t GetClipboardCount() = 0;
	virtual cIGZClipboard* GetClipboard(uint32_t clipboardID) = 0;
	// Fills the array with up to count clipboards and returns how many there are.
	virtual uint32_t GetClipboards(cIGZClipboard** clipboards, uint32_t& count) = 0;
	virtual bool AddClipboard(cIGZClipboard* clipboard) = 0;
	virtual bool RemoveClipboard(cIGZClipboard* clipboard) = 0;
	// Pass 0xFFFFFFFF to remove every clipboard.
	virtual bool RemoveClipboard(uint32_t clipboardID) = 0;
	virtual bool IsClipboardDataTypeAvailable(uint32_t dataType, uint32_t clipboardID) = 0;
	virtual uint32_t GetAvailableClipboardDataTypes(uint32_t* dataTypes, uint32_t& count, uint32_t clipboardID) = 0;
	// Returns the ID of the first clipboard that has the data type, or 0xFFFFFFFD.
	virtual uint32_t GetClipboardWithDataTypeAvailable(uint32_t dataType) = 0;
	virtual bool GetClipboardData(uint32_t dataType, uint32_t, void** data, uint32_t clipboardID) = 0;
	virtual bool SetClipboardData(cIGZClipboardData* data, uint8_t, uint32_t clipboardID) = 0;
	virtual bool ClearClipboard(uint32_t dataType, uint32_t clipboardID) = 0;
	virtual bool GetClipboardText(cIGZString& text, uint32_t clipboardID) = 0;
	virtual bool GetClipboardText(void* buffer, uint32_t& length, uint32_t, uint32_t clipboardID) = 0;
	virtual bool SetClipboardText(cIGZString const& text, uint8_t, uint32_t clipboardID) = 0;
	virtual bool SetClipboardText(void* buffer, uint32_t length, uint32_t, uint8_t, uint32_t clipboardID) = 0;
};
