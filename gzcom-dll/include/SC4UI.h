/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4UI.h
 *
 * Copyright (C) 2024, 2025 Nicholas Hayes
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
#include "cISC4View3DWin.h"
#include "cRZAutoRefCount.h"
#include <cstdint>

class cGZPersistResourceKey;
class cIGZWin;

namespace SC4UI
{
	cIGZWin* CreateWindowFromScript(const cGZPersistResourceKey& key, cIGZWin* parent, uint32_t windowClsid);

	bool CreateWindowFromScript(
		const cGZPersistResourceKey& key,
		cIGZWin* parent,
		uint32_t windowClsid,
		uint32_t riid,
		void** ppvObj);

	cRZAutoRefCount<cISC4View3DWin> GetView3DWin();
}