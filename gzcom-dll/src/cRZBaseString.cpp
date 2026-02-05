/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZBaseString.cpp
 *
 * Copyright (C) 2016, 2017 Nelson Gomez
 * Copyright (C) 2023, 2025 Nicholas Hayes
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

#include "../include/cRZBaseString.h"
#include <algorithm>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const uint32_t kRZBaseStringIID = 0xab13a836;

cRZBaseString::cRZBaseString(cIGZString const& szSource)
	: szData(szSource.ToChar()), mnRefCount(0) {
	// Empty
}

cRZBaseString::cRZBaseString(cIGZString const& szSource, size_t dwStart, size_t dwEnd)
	: mnRefCount(0) {
	std::string szNewSource = std::string(szSource.ToChar());
	szData = std::string(szNewSource, dwStart, dwEnd);
}

cRZBaseString::cRZBaseString(char const* pszSource)
	: szData(pszSource), mnRefCount(0) {
	// Empty
}

cRZBaseString::cRZBaseString(char const* pszSource, size_t dwLen)
	: szData(pszSource, dwLen), mnRefCount(0) {
	// Empty
}

cRZBaseString::cRZBaseString(char cChar, size_t dwRepetitions)
	: szData(dwRepetitions, cChar), mnRefCount(0) {
	// Empty
}

cRZBaseString::cRZBaseString(std::string const& szSource)
	: szData(szSource), mnRefCount(0) {
	// Empty
}

cRZBaseString::cRZBaseString(size_t dwStartSize)
	: szData(dwStartSize, '\0'), mnRefCount(0) {
	// Empty
}

cRZBaseString::cRZBaseString(void)
	: szData(), mnRefCount(0) {
	// Empty
}

cRZBaseString::cRZBaseString(const cRZBaseString& other)
	: szData(other.szData), mnRefCount(0) {
}

cRZBaseString::cRZBaseString(cRZBaseString&& other) noexcept
	: szData(std::move(other.szData)), mnRefCount(other.mnRefCount) {
}

cRZBaseString& cRZBaseString::operator=(const cRZBaseString& other) {
	if (this == &other)	{
		return *this;
	}

	szData = other.szData;

	return *this;
}

cRZBaseString& cRZBaseString::operator=(cRZBaseString&& other) noexcept {
	if (this == &other)	{
		return *this;
	}

	mnRefCount = other.mnRefCount;
	szData = std::move(other.szData);

	return *this;
}

cRZBaseString& cRZBaseString::operator=(const std::string_view& view) {
	szData = view;

	return *this;
}

bool cRZBaseString::QueryInterface(uint32_t riid, void** ppvObj) {
	switch (riid) {
		case kRZBaseStringIID:
			*ppvObj = static_cast<cRZBaseString*>(this);
			break;

		case GZIID_cIGZString:
			*ppvObj = static_cast<cIGZString*>(this);
			break;

		case GZIID_cIGZUnknown:
			*ppvObj = static_cast<cIGZUnknown*>(static_cast<cRZBaseString*>(this));
			break;

		default:
			return false;
	}

	AddRef();
	return true;
}

uint32_t cRZBaseString::AddRef(void) {
	return ++mnRefCount;
}

uint32_t cRZBaseString::Release(void) {
	if (mnRefCount > 0) {
		--mnRefCount;
	}

	return mnRefCount;
}

uint32_t cRZBaseString::FromChar(char const* pszSource) {
	if (pszSource == nullptr) {
		szData.erase();
	}
	else {
		szData.assign(pszSource);
	}

	return true;
}

uint32_t cRZBaseString::FromChar(char const* pszSource, uint32_t dwLength) {
	if (pszSource == nullptr) {
		szData.erase();
	}
	else {
		szData.assign(pszSource, dwLength);
	}

	return true;
}

char const* cRZBaseString::ToChar(void) const {
	return szData.c_str();
}

char const* cRZBaseString::Data(void) const {
	return szData.c_str();
}

char* cRZBaseString::Data(void) {
	return szData.data();
}

uint32_t cRZBaseString::Strlen(void) const {
	return (uint32_t)szData.length();
}

bool cRZBaseString::IsEqual(cIGZString const* szOther, bool bCaseSensitive) const {
	if (szOther == NULL) {
		return this->Strlen() == 0;
	}

	return CompareTo(cRZBaseString(szOther->ToChar()), bCaseSensitive) == 0;
}

bool cRZBaseString::IsEqual(cIGZString const& szOther, bool bCaseSensitive) const {
	return CompareTo(szOther, bCaseSensitive) == 0;
}

bool cRZBaseString::IsEqual(char const* pszOther, uint32_t dwLength, bool bCaseSensitive) const {
	if (pszOther == NULL) {
		return this->Strlen() == 0;
	}

	return CompareTo(pszOther, dwLength, bCaseSensitive) == 0;
}

int32_t cRZBaseString::CompareTo(cIGZString const& szOther, bool bCaseSensitive) const {
	if (!bCaseSensitive) {
		cRZBaseString szThis = cRZBaseString(this->ToChar());
		cRZBaseString szDupOther = cRZBaseString(szOther);

		szThis.MakeUpper();
		szDupOther.MakeUpper();

		return szThis.CompareTo(szDupOther, true);
	}
	else {
		return szData.compare(szOther.ToChar());
	}
}

int32_t cRZBaseString::CompareTo(char const* pszOther, uint32_t dwLength, bool bCaseSensitive) const {
	cRZBaseString szOther = cRZBaseString(pszOther, dwLength);
	return CompareTo(szOther, bCaseSensitive);
}

cIGZString& cRZBaseString::operator=(cIGZString const& szOther) {
	char const* pszSource = szOther.ToChar();
	szData = std::string(pszSource);

	return *this;
}

int32_t cRZBaseString::Copy(cIGZString const& szOther) {
	szData = std::string(szOther.ToChar());
	return true;
}

int32_t cRZBaseString::Resize(uint32_t dwNewSize) {
	szData.resize(dwNewSize);
	return true;
}

cIGZString* cRZBaseString::Append(char const* pszOther, uint32_t dwLength) {
	szData.append(pszOther, dwLength);
	return this;
}

cIGZString* cRZBaseString::Append(cIGZString const& szOther) {
	szData.append(szOther.ToChar());
	return this;
}

cIGZString* cRZBaseString::Insert(uint32_t dwPos, char const* pszOther, uint32_t dwLength) {
	szData.insert(dwPos, pszOther, dwLength);
	return this;
}

cIGZString* cRZBaseString::Insert(uint32_t dwPos, cIGZString const& szOther) {
	szData.insert(dwPos, szOther.ToChar());
	return this;
}

cIGZString* cRZBaseString::Replace(uint32_t dwStartPos, char const* pszOther, uint32_t dwLength) {
	szData.replace(dwStartPos, dwLength, pszOther);
	return this;
}

cIGZString* cRZBaseString::Replace(uint32_t dwStartPos, cIGZString const& szOther) {
	szData.replace(dwStartPos, szOther.Strlen(), szOther.ToChar());
	return this;
}

cIGZString* cRZBaseString::Erase(uint32_t dwStartPos, uint32_t dwEndPos) {
	szData.erase(dwStartPos, dwEndPos);
	return this;
}

int32_t cRZBaseString::Find(char const* pszOther, uint32_t dwPos, bool bCaseSensitive) const {
	cRZBaseString szOther = cRZBaseString(pszOther);
	return Find(szOther, dwPos, bCaseSensitive);
}

int32_t cRZBaseString::Find(cIGZString const& szOther, uint32_t dwPos, bool bCaseSensitive) const {
	if (!bCaseSensitive) {
		cRZBaseString szThis = cRZBaseString(this->ToChar());
		cRZBaseString szDupOther = cRZBaseString(szOther);

		szThis.MakeUpper();
		szDupOther.MakeUpper();

		return szThis.Find(szDupOther, dwPos, true);
	}
	else {
		return (int32_t)szData.find(szOther.ToChar(), dwPos);
	}
}

int32_t cRZBaseString::RFind(char const* pszOther, uint32_t dwPos, bool bCaseSensitive) const {
	cRZBaseString szOther = cRZBaseString(pszOther);
	return RFind(szOther, dwPos, bCaseSensitive);
}

int32_t cRZBaseString::RFind(cIGZString const& szOther, uint32_t dwPos, bool bCaseSensitive) const {
	if (!bCaseSensitive) {
		cRZBaseString szThis = cRZBaseString(this->ToChar());
		cRZBaseString szDupOther = cRZBaseString(szOther);

		szThis.MakeUpper();
		szDupOther.MakeUpper();

		return szThis.RFind(szDupOther, dwPos, true);
	}
	else {
		return (int32_t)szData.rfind(szOther.ToChar(), dwPos);
	}
}

cIGZString* cRZBaseString::Sprintf(char const* pszFormat, ...) {
	va_list args;
	va_start(args, pszFormat);

	va_list argsCopy;
	va_copy(argsCopy, args);

	int nBufferSize = vsnprintf(NULL, 0, pszFormat, argsCopy);

	va_end(argsCopy);

	if (nBufferSize > 0)
	{
		char* pszResult = (char*)malloc(nBufferSize + 1);

		if (pszResult)
		{
			if (vsnprintf(pszResult, nBufferSize, pszFormat, args) > 0)
			{
				szData.assign(pszResult);
			}

			free(pszResult);
		}
	}

	va_end(args);

	return this;
}

cRZBaseString* cRZBaseString::MakeUpper(void) {
	std::transform(szData.begin(), szData.end(), szData.begin(), ::toupper);
	return this;
}

cRZBaseString* cRZBaseString::MakeLower(void) {
	std::transform(szData.begin(), szData.end(), szData.begin(), ::tolower);
	return this;
}
