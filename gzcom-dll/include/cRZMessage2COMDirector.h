/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZMessage2COMDirector.h
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
#include "cIGZMessageTarget2.h"
#include "cRZCOMDllDirector.h"
#include "GZCLSIDDefs.h"

class cRZMessage2COMDirector : public cRZCOMDllDirector, public cIGZMessageTarget2
{
	public:
		bool QueryInterface(uint32_t riid, void** ppvObj) {
			if (riid == GZCLSID::kcIGZMessageTarget2) {
				*ppvObj = static_cast<cIGZMessageTarget2*>(this);
				AddRef();
				return true;
			}
			else {
				return cRZMessage2COMDirector::QueryInterface(riid, ppvObj);
			}
		}

		uint32_t AddRef(void) {
			return cRZCOMDllDirector::AddRef();
		}

		uint32_t Release(void) {
			return cRZCOMDllDirector::Release();
		}
};