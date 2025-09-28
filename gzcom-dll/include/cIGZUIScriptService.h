/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZUIScriptService.h
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

#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;
class cIGZScriptableControlSet;
class cIGZUIScriptServiceResourceFactory;
class cIGZScriptTerp;
class cIGZString;
class cIGZWin;

class cIGZUIScriptService : public cIGZUnknown
{
public:
	virtual cIGZWin* CreateWindowFromScript(cGZPersistResourceKey const& key, cIGZWin* parent, uint32_t windowClsid) = 0;
	virtual bool CreateWindowFromScript(cGZPersistResourceKey const& key, cIGZWin* parent, uint32_t windowClsid, uint32_t riid, void** ppvObj) = 0;

	virtual cIGZScriptableControlSet* ExecuteScriptString(cIGZString const& data) = 0;
	virtual cIGZScriptableControlSet* ExecuteScriptFile(cIGZString const& file) = 0;
	virtual cIGZScriptableControlSet* ExecuteScriptResource(const cGZPersistResourceKey& key) = 0;

	virtual cIGZScriptTerp* GetScriptInterpreter() = 0;

	virtual cIGZUIScriptServiceResourceFactory* GetResourceFactory() = 0;
	virtual bool SetResourceFactory(cIGZUIScriptServiceResourceFactory* pFactory) = 0;
};