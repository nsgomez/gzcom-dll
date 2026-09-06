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
#include "cIGZAllocatorService.h"
#include "GZServPtrs.h"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <stdarg.h>

namespace
{
	char* allocate(size_t length)
	{
		cIGZAllocatorServicePtr pAllocator;

		char* ptr = static_cast<char*>(pAllocator->Allocate(length));

		if (!ptr)
		{
			throw std::bad_alloc();
		}

		return ptr;
	}

	void deallocate(char* ptr)
	{
		cIGZAllocatorServicePtr pAllocator;

		pAllocator->Deallocate(ptr);
	}

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

SC4String::SC4String() : mpStart(nullptr), mpEnd(nullptr), mpCapacity(nullptr), mnRefCount(0)
{
	construct_empty_string();
}

SC4String::SC4String(SC4String const& other) : mpStart(nullptr), mpEnd(nullptr), mpCapacity(nullptr), mnRefCount(0)
{
	operator=(other);
}

SC4String::SC4String(SC4String&& other) noexcept : mpStart(nullptr), mpEnd(nullptr), mpCapacity(nullptr), mnRefCount(0)
{
	operator=(std::move(other));
}

SC4String::SC4String(cIGZString const& other) : mpStart(nullptr), mpEnd(nullptr), mpCapacity(nullptr), mnRefCount(0)
{
	Copy(other);
}

SC4String::SC4String(std::string_view const& view) : mpStart(nullptr), mpEnd(nullptr), mpCapacity(nullptr), mnRefCount(0)
{
	FromChar(view.data(), view.size());
}

SC4String::SC4String(char const* pszSource) : mpStart(nullptr), mpEnd(nullptr), mpCapacity(nullptr), mnRefCount(0)
{
	FromChar(pszSource);
}

SC4String::SC4String(char const* pszSource, uint32_t dwLength) : mpStart(nullptr), mpEnd(nullptr), mpCapacity(nullptr), mnRefCount(0)
{
	FromChar(pszSource, dwLength);
}

SC4String::~SC4String()
{
	if (mpStart)
	{
		deallocate(mpStart);
	}

	mpStart = nullptr;
	mpEnd = nullptr;
	mpCapacity = nullptr;
	mnRefCount = 0;
}

SC4String& SC4String::operator=(SC4String const& other)
{
	if (this != &other)
	{
		FromChar(other.ToChar(), other.Strlen());
	}
	return *this;
}

SC4String& SC4String::operator=(SC4String&& other) noexcept
{
	if (this != &other)
	{
		mpStart = std::exchange(other.mpStart, nullptr);
		mpEnd = std::exchange(other.mpEnd, nullptr);
		mpCapacity = std::exchange(other.mpCapacity, nullptr);
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
	if (!pszSource || *pszSource == 0)
	{
		this->construct_empty_string();
	}
	else
	{
		const size_t dwLength = std::char_traits<char>::length(pszSource);

		allocate_string_buffer(dwLength);

		std::char_traits<char>::move(mpStart, pszSource, dwLength);
	}
}

void SC4String::FromChar(char const* pszSource, uint32_t dwLength)
{
	if (!pszSource || dwLength == 0)
	{
		this->construct_empty_string();
	}
	else
	{
		allocate_string_buffer(dwLength);

		std::char_traits<char>::move(mpStart, pszSource, dwLength);
	}
}

char const* SC4String::ToChar(void) const
{
	return mpStart;
}

char const* SC4String::Data(void) const
{
	return mpStart;
}

uint32_t SC4String::Strlen(void) const
{
	return mpEnd - mpStart;
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

	const uint32_t thisStringLength = this->Strlen();
	int32_t result = 0;

	if (bCaseSensitive)
	{	
		result = memcmp(this->ToChar(), pszOther, (std::min)(thisStringLength, dwLength));

		if (result == 0)
		{
			if (thisStringLength < dwLength)
			{
				result = -1;
			}
			else if (thisStringLength > dwLength)
			{
				result = 1;
			}
		}
	}
	else
	{
		std::string thisLowerCase = MakeLowerCase(this->ToChar(), thisStringLength);
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
	if (dwNewSize == 0)
	{
		this->construct_empty_string();
	}
	else if (this->Strlen() == 0)
	{
		this->allocate_string_buffer(dwNewSize);
		std::char_traits<char>::assign(mpStart, dwNewSize, '\0');
	}
	else
	{
		std::string temp(this->ToChar(), this->Strlen());
		temp.resize(dwNewSize);

		this->FromChar(temp.c_str(), temp.size());
	}
}

cIGZString* SC4String::Append(char const* pszOther, uint32_t dwLength)
{
	if (dwLength != 0)
	{
		if (this->Strlen() == 0)
		{
			this->FromChar(pszOther, dwLength);
		}
		else
		{
			std::string temp(this->ToChar(), this->Strlen());
			temp.append(pszOther, dwLength);

			this->FromChar(temp.c_str(), temp.size());
		}
	}
	return this;
}

cIGZString* SC4String::Append(cIGZString const& szOther)
{
	return this->Append(szOther.ToChar(), szOther.Strlen());
}

cIGZString* SC4String::Insert(uint32_t dwPos, char const* pszOther, uint32_t dwLength)
{
	std::string temp(this->ToChar(), this->Strlen());
	temp.insert(dwPos, pszOther, dwLength);

	this->FromChar(temp.c_str(), temp.size());
	return this;
}

cIGZString* SC4String::Insert(uint32_t dwPos, cIGZString const& szOther)
{
	return this->Insert(dwPos, szOther.ToChar(), szOther.Strlen());
}

cIGZString* SC4String::Replace(uint32_t dwStartPos, char const* pszOther, uint32_t dwLength)
{
	std::string temp(this->ToChar(), this->Strlen());
	temp.replace(dwStartPos, dwLength, pszOther);

	this->FromChar(temp.c_str(), temp.size());
	return this;
}

cIGZString* SC4String::Replace(uint32_t dwStartPos, cIGZString const& szOther)
{
	return this->Replace(dwStartPos, szOther.ToChar(), szOther.Strlen());
}

cIGZString* SC4String::Erase(uint32_t dwStartPos, uint32_t dwEndPos)
{
	std::string temp(this->ToChar(), this->Strlen());
	temp.erase(dwStartPos, dwEndPos);

	this->FromChar(temp.c_str(), temp.size());
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
		allocate_string_buffer(nBufferSize);

		vsnprintf(mpStart, nBufferSize, pszFormat, args);
	}

	va_end(args);

	return this;
}

void SC4String::allocate_string_buffer(size_t stringLength)
{
	if (stringLength == UINT_MAX)
	{
		throw std::out_of_range("SC4String");
	}

	const size_t lengthWithTerminator = stringLength + 1;

	if (lengthWithTerminator < capacity())
	{
		mpEnd = mpStart + stringLength;
		*mpEnd = 0;
	}
	else
	{
		if (mpStart)
		{
			deallocate(mpStart);
			mpStart = nullptr;
			mpEnd = nullptr;
			mpCapacity = nullptr;
		}

		char* newStart = allocate(lengthWithTerminator);

		mpStart = newStart;
		mpEnd = newStart + stringLength;
		mpCapacity = mpEnd;
		*mpEnd = 0;
	}
}

size_t SC4String::capacity()
{
	return mpCapacity - mpStart;
}

void SC4String::construct_empty_string()
{
	if (mpStart)
	{
		if (mpStart != mpEnd)
		{
			*mpStart = 0;
			mpEnd = mpStart;
		}
	}
	else
	{
		constexpr size_t emptyStringSize = 1;

		mpStart = allocate(emptyStringSize);
		mpEnd = mpStart;
		mpCapacity = mpStart + emptyStringSize;
		*mpStart = 0;
	}
}
