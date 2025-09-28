/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZString.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2023 Nicholas Hayes
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

static const uint32_t GZIID_cIGZString = 0x89b7dc8;

/**
 * @brief An interface for string objects, similar to std::string
 */
class cIGZString : public cIGZUnknown
{
	public:
		virtual uint32_t FromChar(char const* pszSource) = 0;
		virtual uint32_t FromChar(char const* pszSource, uint32_t dwLength) = 0;
		virtual char const* ToChar(void) const = 0;
		virtual char const* Data(void) const = 0;

		virtual uint32_t Strlen(void) const = 0;
		virtual bool IsEqual(cIGZString const* szOther, bool bCaseSensitive) const = 0;
		virtual bool IsEqual(cIGZString const& szOther, bool bCaseSensitive) const = 0;
		virtual bool IsEqual(char const* pszOther, uint32_t dwLength, bool bCaseSensitive) const = 0;

		virtual int32_t CompareTo(cIGZString const& szOther, bool bCaseSensitive) const = 0;
		virtual int32_t CompareTo(char const* pszOther, uint32_t dwLength, bool bCaseSensitive) const = 0;

		virtual cIGZString& operator=(cIGZString const& szOther) = 0;
		
		virtual int32_t Copy(cIGZString const& szOther) = 0;
		virtual int32_t Resize(uint32_t dwNewSize) = 0;
		
		virtual cIGZString* Append(char const* pszOther, uint32_t dwLength) = 0;
		virtual cIGZString* Append(cIGZString const& szOther) = 0;
		virtual cIGZString* Insert(uint32_t dwPos, char const* pszOther, uint32_t dwLength) = 0;
		virtual cIGZString* Insert(uint32_t dwPos, cIGZString const& szOther) = 0;
		virtual cIGZString* Replace(uint32_t dwStartPos, char const* pszOther, uint32_t dwLength) = 0;
		virtual cIGZString* Replace(uint32_t dwStartPos, cIGZString const& szOther) = 0;
		virtual cIGZString* Erase(uint32_t dwStartPos, uint32_t dwEndPos) = 0;

		virtual int32_t Find(char const* pszOther, uint32_t dwPos, bool bCaseSensitive) const = 0;
		virtual int32_t Find(cIGZString const& szOther, uint32_t dwPos, bool bCaseSensitive) const = 0;
		
		virtual int32_t RFind(char const* pszOther, uint32_t dwPos, bool bCaseSensitive) const = 0;
		virtual int32_t RFind(cIGZString const& szOther, uint32_t dwPos, bool bCaseSensitive) const = 0;

		virtual cIGZString* Sprintf(char const* pszFormat, ...) = 0;
};