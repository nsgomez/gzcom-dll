/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4NetworkLotConfiguration.h
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
#include "cIGZUnknown.h"

class cIGZString;
class cSC4LotConfigurationObject;
template <typename T> class SC4Vector;

class cISC4NetworkLotConfiguration : public cIGZUnknown
{
public:
	virtual SC4Vector<cSC4LotConfigurationObject>* GetObjectArray() const = 0;
	virtual uint32_t GetID() const = 0;
	virtual void GetName(cIGZString& name) const = 0;
	virtual uint32_t GetNetworkPieceId() const = 0;
};