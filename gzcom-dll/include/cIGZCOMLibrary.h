/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZCOMLibrary.h
 *
 * Copyright (C) 2016 Nelson Gomez
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

class cIGZCOMDirector;
class cIGZString;

/**
 * @brief The public interface for internally represented COM libraries
 * @see cGZCOMLibrary
 *
 * Unlike cGZCOMLibrary, this virtual interface is supposed to represent the
 * methods that other directors are allowed to access.
 */
class cIGZCOMLibrary : public cIGZUnknown
{
	public:
		virtual bool GetPath(cIGZString& szCopyTo) = 0;
		virtual cIGZCOMDirector* GetDirector(void) = 0;

		virtual uintptr_t GetHandle(void) = 0;
		virtual bool IsLoaded(void) const = 0;
};