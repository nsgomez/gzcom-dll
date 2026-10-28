/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4String.cpp
 *
 * Copyright (C) 2026 Nicholas Hayes
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

#include "SC4String.h"
#include <algorithm>
#include <string>
#include <stdarg.h>

namespace
{
	void MakeLowerCase(std::string& asLowerCase)
	{
		std::transform(
			asLowerCase.begin(),
			asLowerCase.end(),
			asLowerCase.begin(),
			[](unsigned char c) { return std::tolower(c); });
	}

	std::string MakeLowerCase(const char* const szData, size_t count)
	{
		std::string asLowerCase(szData, count);

		MakeLowerCase(asLowerCase);

		return asLowerCase;
	}

	int32_t FindImpl(
		const char* const szData1,
		size_t data1Length,
		const char* const szData2,
		size_t data2Length,
		size_t offset,
		bool bCaseSensitive)
	{
		std::string data1(szData1, data1Length);
		std::string data2(szData2, data2Length);

		if (!bCaseSensitive)
		{
			MakeLowerCase(data1);
			MakeLowerCase(data2);
		}

		return data1.find(data2, offset);
	}

	int32_t RFindImpl(
		const char* const szData1,
		size_t data1Length,
		const char* const szData2,
		size_t data2Length,
		size_t offset,
		bool bCaseSensitive)
	{
		std::string data1(szData1, data1Length);
		std::string data2(szData2, data2Length);

		if (!bCaseSensitive)
		{
			MakeLowerCase(data1);
			MakeLowerCase(data2);
		}

		return data1.rfind(data2, offset);
	}
}

SC4String::SC4String() : mString(), mnRefCount(0)
{
}

SC4String::SC4String(SC4String const& other) : mString(other.mString), mnRefCount(0)
{
}

SC4String::SC4String(SC4String&& other) noexcept : mString(std::move(other.mString)), mnRefCount(other.mnRefCount)
{
	other.mnRefCount = 0;
}

SC4String::SC4String(cIGZString const& other) : mString(other.ToChar(), other.Strlen()), mnRefCount(0)
{
}

SC4String::SC4String(std::string_view const& view) : mString(view), mnRefCount(0)
{
}

SC4String::SC4String(char const* pszSource) : mString(pszSource), mnRefCount(0)
{
}

SC4String::SC4String(char const* pszSource, uint32_t dwLength) : mString(pszSource, dwLength), mnRefCount(0)
{
}

SC4String& SC4String::operator=(SC4String const& other)
{
	if (this != &other)
	{
		mString = other.mString;
	}
	return *this;
}

SC4String& SC4String::operator=(SC4String&& other) noexcept
{
	if (this != &other)
	{
		mString = std::move(other.mString);
		mnRefCount = std::exchange(other.mnRefCount, 0);
	}
	return *this;
}

bool SC4String::QueryInterface(uint32_t riid, void** ppvObj)
{
	if (riid == GZIID_cIGZString)
	{
		*ppvObj = static_cast<cIGZString*>(this);
		AddRef();

		return true;
	}
	else if (riid == GZIID_cIGZUnknown)
	{
		*ppvObj = static_cast<cIGZUnknown*>(this);
		AddRef();

		return true;
	}

	*ppvObj = nullptr;
	return false;
}

uint32_t SC4String::AddRef()
{
	uint32_t localRefCount = mnRefCount + 1;
	mnRefCount = localRefCount;

	return localRefCount;
}

uint32_t SC4String::Release()
{
	uint32_t localRefCount = 0;

	if (mnRefCount > 0)
	{
		localRefCount = mnRefCount - 1;
		mnRefCount = localRefCount;

		if (localRefCount == 0)
		{
			delete this;
		}
	}

	return localRefCount;
}

void SC4String::FromChar(char const* pszSource)
{
	mString.assign(pszSource);
}

void SC4String::FromChar(char const* pszSource, uint32_t dwLength)
{
	mString.assign(pszSource, dwLength);
}

char const* SC4String::ToChar(void) const
{
	return mString.data();
}

char const* SC4String::Data(void) const
{
	return mString.data();
}

uint32_t SC4String::Strlen(void) const
{
	return mString.length();
}

bool SC4String::IsEqual(cIGZString const* szOther, bool bCaseSensitive) const
{
	if (szOther)
	{
		return this->IsEqual(szOther->ToChar(), szOther->Strlen(), bCaseSensitive);
	}

	return this->Strlen() == 0;
}

bool SC4String::IsEqual(cIGZString const& szOther, bool bCaseSensitive) const
{
	return this->IsEqual(szOther.ToChar(), szOther.Strlen(), bCaseSensitive);
}

bool SC4String::IsEqual(char const* pszOther, uint32_t dwLength, bool bCaseSensitive) const
{
	if (dwLength == UINT_MAX)
	{
		dwLength = std::char_traits<char>::length(pszOther);
	}

	if (this->Strlen() == dwLength)
	{
		if (bCaseSensitive)
		{
			return memcmp(this->ToChar(), pszOther, dwLength) == 0;
		}
		else
		{
			std::string thisLowerCase = MakeLowerCase(this->ToChar(), dwLength);
			std::string otherLowerCase = MakeLowerCase(pszOther, dwLength);

			return memcmp(thisLowerCase.c_str(), otherLowerCase.c_str(), dwLength) == 0;
		}
	}

	return false;
}

int32_t SC4String::CompareTo(cIGZString const& szOther, bool bCaseSensitive) const
{
	return this->CompareTo(szOther.ToChar(), szOther.Strlen(), bCaseSensitive);
}

int32_t SC4String::CompareTo(char const* pszOther, uint32_t dwLength, bool bCaseSensitive) const
{
	if (dwLength == UINT_MAX)
	{
		dwLength = std::char_traits<char>::length(pszOther);
	}

	int32_t result = 0;

	if (bCaseSensitive)
	{	
		result = mString.compare(pszOther, dwLength);
	}
	else
	{
		std::string thisLowerCase = MakeLowerCase(this->ToChar(), this->Strlen());
		std::string otherLowerCase = MakeLowerCase(pszOther, dwLength);

		result = thisLowerCase.compare(otherLowerCase);
	}

	return result;
}

cIGZString& SC4String::operator=(cIGZString const& szOther)
{
	FromChar(szOther.ToChar(), szOther.Strlen());
	return *this;
}

void SC4String::Copy(cIGZString const& szOther)
{
	FromChar(szOther.ToChar(), szOther.Strlen());
}

void SC4String::Resize(uint32_t dwNewSize)
{
	mString.resize(dwNewSize);
}

cIGZString* SC4String::Append(char const* pszOther, uint32_t dwLength)
{
	mString.append(pszOther, dwLength);
	return this;
}

cIGZString* SC4String::Append(cIGZString const& szOther)
{
	return this->Append(szOther.ToChar(), szOther.Strlen());
}

cIGZString* SC4String::Insert(uint32_t dwPos, char const* pszOther, uint32_t dwLength)
{
	mString.insert(dwPos, pszOther, dwLength);
	return this;
}

cIGZString* SC4String::Insert(uint32_t dwPos, cIGZString const& szOther)
{
	return this->Insert(dwPos, szOther.ToChar(), szOther.Strlen());
}

cIGZString* SC4String::Replace(uint32_t dwStartPos, char const* pszOther, uint32_t dwLength)
{
	mString.replace(dwStartPos, pszOther, dwLength);
	return this;
}

cIGZString* SC4String::Replace(uint32_t dwStartPos, cIGZString const& szOther)
{
	return this->Replace(dwStartPos, szOther.ToChar(), szOther.Strlen());
}

cIGZString* SC4String::Erase(uint32_t dwStartPos, uint32_t dwEndPos)
{
	mString.erase(dwStartPos, dwEndPos);
	return this;
}

int32_t SC4String::Find(char const* pszOther, uint32_t dwPos, bool bCaseSensitive) const
{
	return FindImpl(
		this->ToChar(),
		this->Strlen(),
		pszOther,
		std::char_traits<char>::length(pszOther),
		dwPos,
		bCaseSensitive);
}

int32_t SC4String::Find(cIGZString const& szOther, uint32_t dwPos, bool bCaseSensitive) const
{
	return FindImpl(
		this->ToChar(),
		this->Strlen(),
		szOther.ToChar(),
		szOther.Strlen(),
		dwPos,
		bCaseSensitive);
}

int32_t SC4String::RFind(char const* pszOther, uint32_t dwPos, bool bCaseSensitive) const
{
	return RFindImpl(
		this->ToChar(),
		this->Strlen(),
		pszOther,
		std::char_traits<char>::length(pszOther),
		dwPos,
		bCaseSensitive);
}

int32_t SC4String::RFind(cIGZString const& szOther, uint32_t dwPos, bool bCaseSensitive) const
{
	return RFindImpl(
		this->ToChar(),
		this->Strlen(),
		szOther.ToChar(),
		szOther.Strlen(),
		dwPos,
		bCaseSensitive);
}

cIGZString* SC4String::Sprintf(char const* pszFormat, ...)
{
	va_list args;
	va_start(args, pszFormat);

	va_list argsCopy;
	va_copy(argsCopy, args);

	int nBufferSize = vsnprintf(NULL, 0, pszFormat, argsCopy);

	va_end(argsCopy);

	if (nBufferSize > 0)
	{
		mString.resize(nBufferSize);

		vsnprintf(mString.data(), nBufferSize, pszFormat, args);
	}

	va_end(args);

	return this;
}

