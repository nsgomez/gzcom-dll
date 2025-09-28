/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cSC4BaseOccupantFilter.h
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

#pragma once
#include "cISC4OccupantFilter.h"
#include "cRZBaseUnknown.h"

class cSC4BaseOccupantFilter : public cRZBaseUnknown, public cISC4OccupantFilter
{
public:
	// cIGZUnknown

	bool QueryInterface(uint32_t riid, void** ppvObj) override;
	uint32_t AddRef() override;
	uint32_t Release() override;

	// cISC4OccupantFilter

	bool IsOccupantIncluded(cISC4Occupant* pOccupant) override;
	bool IsOccupantTypeIncluded(uint32_t dwType) override;
	bool IsPropertyHolderIncluded(cISCPropertyHolder* pProperties) override;
};