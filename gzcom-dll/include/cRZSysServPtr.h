/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZServPtr.h
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
#include "cIGZFrameWork.h"
#include "cRZCOMDllDirector.h"

template<class T, uint32_t riid, uint32_t srvid>
class cRZSysServPtr
{
	static_assert(std::is_base_of<cIGZUnknown, T>::value, "T must extend cIGZUnknown");
	public:
		cRZSysServPtr() {
			pService = nullptr;

			cIGZFrameWork* pFrameWork = RZGetFrameWork();
			if (pFrameWork) {
				pFrameWork->GetSystemService(srvid, riid, (void**)&pService);
			}
		}

		virtual ~cRZSysServPtr() {
			if (pService) {
				pService->Release();
			}
		}

		T* operator->() const { return pService; }
		T& operator*() const { return *pService; }
		operator T*() const { return pService; }

	protected:
		T* pService;
};