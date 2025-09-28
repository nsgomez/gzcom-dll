/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZBaseUnknown.cpp
 *
 * Copyright (C) 2024 Nicholas Hayes
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

#include "cRZBaseUnknown.h"

cRZBaseUnknown::cRZBaseUnknown()
	: refCount(0)
{
}

cRZBaseUnknown::~cRZBaseUnknown()
{
}

bool cRZBaseUnknown::QueryInterface(uint32_t riid, void** ppvObj)
{
	if (riid == GZIID_cIGZUnknown)
	{
		*ppvObj = static_cast<cIGZUnknown*>(this);
		AddRef();

		return true;
	}

	*ppvObj = nullptr;
	return false;
}

uint32_t cRZBaseUnknown::AddRef()
{
	uint32_t localRefCount = refCount + 1;
	refCount = localRefCount;

	return localRefCount;
}

uint32_t cRZBaseUnknown::Release()
{
	uint32_t localRefCount = 0;

	if (refCount > 0)
	{
		localRefCount = refCount - 1;
		refCount = localRefCount;

		if (localRefCount == 0)
		{
			delete this;
		}
	}

	return localRefCount;
}

