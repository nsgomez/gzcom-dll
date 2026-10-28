/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZRegistry.h
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

static const uint32_t GZIID_cIGZRegistry = 0xa237613c;

class cIGZRegistry : public cIGZUnknown
{
public:
	typedef void (*EnumCallback)(cIGZString const& key, cIGZString const& value, void* pContext);

	virtual bool Register(cIGZString const& name) = 0;
	virtual bool Unregister(cIGZString const& name) = 0;

	// Reads the value stored under key in the given root into valueOut.
	virtual bool Lookup(char* root, cIGZString const& key, cIGZString& valueOut) = 0;

	// Joins the root, category and key into a full registry name. Fails when
	// root is null.
	virtual bool MakeRegistryName(char* root, cIGZString const& category, cIGZString const& key, cIGZString& nameOut) = 0;

	// Calls the callback once per key and value pair under the root, passing
	// pContext through unchanged.
	virtual bool EnumCategory(char* root, EnumCallback pCallback, void* pContext) = 0;
};
