/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4String.h
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
#include "cIGZString.h"
#include <string_view>

/**
 * @brief A class that provides binary compatibility with internal cRZString class used by
 * the 32-bit Windows digital version of SC4.
 * It is used for structures that have cRZString fields and API methods that use cRZString.
 *
 * Use cRZBaseString if you need a general string type that implements cIGZString.
 * cRZBaseString can provide better performance as its implementation is not subject to
 * the same compatibility restrictions as this class.
 */
class SC4String : public cIGZString
{
public:
	SC4String();
	SC4String(SC4String const& other);
	SC4String(SC4String&& other) noexcept;
	SC4String(cIGZString const& other);
	SC4String(std::string_view const& view);
	SC4String(char const* pszSource);
	SC4String(char const* pszSource, uint32_t dwLength);

	~SC4String();

	SC4String& operator=(SC4String const& other);
	SC4String& operator=(SC4String&& other) noexcept;

	// cIGZUnknown

	bool QueryInterface(uint32_t riid, void** ppvObj) override;
	uint32_t AddRef() override;
	uint32_t Release() override;

	// cIGZString
	
	void FromChar(char const* pszSource) override;
	void FromChar(char const* pszSource, uint32_t dwLength) override;
	char const* ToChar(void) const override;
	char const* Data(void) const override;

	uint32_t Strlen(void) const override;
	bool IsEqual(cIGZString const* szOther, bool bCaseSensitive) const override;
	bool IsEqual(cIGZString const& szOther, bool bCaseSensitive) const override;
	bool IsEqual(char const* pszOther, uint32_t dwLength, bool bCaseSensitive) const override;

	int32_t CompareTo(cIGZString const& szOther, bool bCaseSensitive) const override;
	int32_t CompareTo(char const* pszOther, uint32_t dwLength, bool bCaseSensitive) const override;

	cIGZString& operator=(cIGZString const& szOther) override;

	void Copy(cIGZString const& szOther) override;
	void Resize(uint32_t dwNewSize) override;

	cIGZString* Append(char const* pszOther, uint32_t dwLength) override;
	cIGZString* Append(cIGZString const& szOther) override;	
	cIGZString* Insert(uint32_t dwPos, char const* pszOther, uint32_t dwLength) override;
	cIGZString* Insert(uint32_t dwPos, cIGZString const& szOther) override;
	cIGZString* Replace(uint32_t dwStartPos, char const* pszOther, uint32_t dwLength) override;
	cIGZString* Replace(uint32_t dwStartPos, cIGZString const& szOther) override;
	cIGZString* Erase(uint32_t dwStartPos, uint32_t dwEndPos) override;

	int32_t Find(char const* pszOther, uint32_t dwPos, bool bCaseSensitive) const override;
	int32_t Find(cIGZString const& szOther, uint32_t dwPos, bool bCaseSensitive) const override;

	int32_t RFind(char const* pszOther, uint32_t dwPos, bool bCaseSensitive) const override;
	int32_t RFind(cIGZString const& szOther, uint32_t dwPos, bool bCaseSensitive) const override;

	cIGZString* Sprintf(char const* pszFormat, ...) override;

private:
	void allocate_string_buffer(size_t stringLength);
	size_t capacity();
	void construct_empty_string();

	// The 3 pointer fields are from the STLPORT 4.6 std::string class.
	// The mnRefCount field is from cRZString.

	char* mpStart;
	char* mpEnd;
	char* mpCapacity;
	uint32_t mnRefCount;
};

static_assert(sizeof(SC4String) == 0x14);
