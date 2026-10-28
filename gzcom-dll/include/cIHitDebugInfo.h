/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIHitDebugInfo.h
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

class cIGZString;

static const uint32_t GZIID_cIHitDebugInfo = 0x7bba0cbd;

// Maps compiled Hit audio script data back to source files and line numbers.
class cIHitDebugInfo : public cIGZUnknown
{
public:
	virtual bool Shutdown() = 0;

	virtual void AddSourceFile(cIGZString const& filename, uint8_t* pData, int32_t dataSize) = 0;

	virtual bool GetDataAddressFromFilenameAndLineNum(cIGZString const& filename, int32_t lineNum, uint8_t** ppAddressOut) = 0;
	virtual bool GetFilenameAndLineNumFromDataAddress(uint8_t* pAddress, cIGZString& filenameOut, int32_t& lineNumOut) = 0;

	// Looks up a track entry point through cIHitMan.
	virtual bool GetDataAddressFromEntryPoint(uint32_t entryPoint, uint8_t** ppAddressOut) = 0;
	virtual bool GetHitFilenameFromEntryPoint(uint32_t entryPoint, cIGZString& filenameOut) = 0;

	virtual bool LoadDebugInfo(cIGZString const& filename, uint8_t* pData, int32_t dataSize) = 0;
	virtual bool LoadSymbolFile(cIGZString const& filename) = 0;
};
