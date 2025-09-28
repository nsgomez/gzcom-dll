/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cSC4BaseOccupantFilter.cpp
 *
 * Copyright (C) 2025 Nicholas Hayes
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

#include "cSC4BaseOccupantFilter.h"
#include "cISC4Occupant.h"

bool cSC4BaseOccupantFilter::QueryInterface(uint32_t riid, void** ppvObj)
{
	if (riid == GZIID_cISC4OccupantFilter)
	{
		*ppvObj = static_cast<cISC4OccupantFilter*>(this);
		AddRef();

		return true;
	}

	return cRZBaseUnknown::QueryInterface(riid, ppvObj);
}

uint32_t cSC4BaseOccupantFilter::AddRef()
{
	return cRZBaseUnknown::AddRef();
}

uint32_t cSC4BaseOccupantFilter::Release()
{
	return cRZBaseUnknown::Release();
}

bool cSC4BaseOccupantFilter::IsOccupantIncluded(cISC4Occupant* pOccupant)
{
	return IsOccupantTypeIncluded(pOccupant->GetType());
}

bool cSC4BaseOccupantFilter::IsOccupantTypeIncluded(uint32_t dwType)
{
	return true;
}

bool cSC4BaseOccupantFilter::IsPropertyHolderIncluded(cISCPropertyHolder* pProperties)
{
	return true;
}
