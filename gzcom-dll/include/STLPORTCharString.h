/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * STLPORTCharString.h
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

#pragma once
#include <cstdint>
#include <string_view>

// This type is a binary compatible re-implementation of the STLPORT 4.6
// std::string type that the Windows version of SC4 uses.
// It uses the game's cIGZAllocatorService for memory management and
// only implements a very limited subset of the std::string API.
// 
// If you need a std::string type for use outside of interacting with
// with the SC4 APIs that require this type, use the std::string type
// provided by your C++ compiler.

namespace STLPORT
{
	class CharString
	{
	public:
		CharString();
		CharString(CharString const& other);
		CharString(CharString&& other) noexcept;
		CharString(std::string_view const& view);
		CharString(char const* pszSource);
		CharString(char const* pszSource, size_t length);

		~CharString();

		CharString& operator=(CharString const& other);
		CharString& operator=(CharString&& other) noexcept;

		char* data() const;

		size_t length() const;

		void assign(const char* pszSource);
		void assign(const char* pszSource, size_t length);

		int compare(char const* pszOther, size_t length) const;

		void append(char const* pszOther, size_t length);
		void insert(size_t pos, char const* pszOther, size_t length);
		void replace(size_t pos, char const* pszOther, size_t length);
		void erase(size_t startPos, size_t length);

		void resize(size_t newSize);
	private:
		void allocate_string_buffer(size_t stringLength);
		size_t capacity();
		void construct_empty_string();

		char* mpStart;
		char* mpEnd;
		char* mpCapacity;
	};
}
