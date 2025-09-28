/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4UI.cpp
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

#include "SC4UI.h"
#include "cIGZUIScriptService.h"
#include "cIGZWin.h"
#include "cISC4App.h"
#include "GZServPtrs.h"

cIGZWin* SC4UI::CreateWindowFromScript(const cGZPersistResourceKey& key, cIGZWin* parent, uint32_t windowClsid)
{
	cIGZUIScriptServicePtr pUIScriptService;

	if (pUIScriptService)
	{
		return pUIScriptService->CreateWindowFromScript(key, parent, windowClsid);
	}

	return nullptr;
}

bool SC4UI::CreateWindowFromScript(
	const cGZPersistResourceKey& key,
	cIGZWin* parent,
	uint32_t windowClsid,
	uint32_t riid,
	void** ppvObj)
{
	cIGZUIScriptServicePtr pUIScriptService;

	if (pUIScriptService)
	{
		return pUIScriptService->CreateWindowFromScript(key, parent, windowClsid, riid, ppvObj);
	}

	return false;
}

cRZAutoRefCount<cISC4View3DWin> SC4UI::GetView3DWin()
{
	cRZAutoRefCount<cISC4View3DWin> view3D;

	cISC4AppPtr sc4App;

	if (sc4App)
	{
		cIGZWin* mainWindow = sc4App->GetMainWindow();

		if (mainWindow)
		{
			const uint32_t kGZWin_WinSC4App = 0x6104489a;
			const uint32_t kGZWin_SC4View3DWin = 0x9a47b417;

			cIGZWin* pParentWin = mainWindow->GetChildWindowFromID(kGZWin_WinSC4App);

			if (pParentWin)
			{
				cRZAutoRefCount<cISC4View3DWin> temp;

				if (pParentWin->GetChildAs(
					kGZWin_SC4View3DWin,
					kGZIID_cISC4View3DWin,
					temp.AsPPVoid()))
				{
					view3D = std::move(temp);
				}
			}
		}
	}

	return view3D;
}
