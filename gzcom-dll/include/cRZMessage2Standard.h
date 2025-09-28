/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZMessage2Standard.h
 *
 * Copyright (C) 2016, 2017 Nelson Gomez
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
#include "cIGZMessage2Standard.h"
#include "cIGZSerializable.h"
#include "cRZAutoRefCount.h"
#include "cRZBaseString.h"
#include "cRZMessage2.h"
#include <stdint.h>

class cRZMessage2Standard : public cIGZMessage2Standard, public cRZMessage2
{
	public:
		bool QueryInterface(uint32_t riid, void** ppvObj) {
			return cRZUnknown::QueryInterface(riid, ppvObj);
		}
		uint32_t AddRef(void) { return cRZUnknown::AddRef(); }
		uint32_t Release(void) { return cRZUnknown::Release(); }

		bool Create(uint32_t dwType, void** ppUnknown) const {
			return cRZMessage2::Create(dwType, ppUnknown);
		}

		uint32_t GetType(void) const { return cRZMessage2::GetType(); }
		uint32_t SetType(uint32_t dwType) { return cRZMessage2::SetType(dwType); }

		bool operator==(cIGZMessage2 const& msgOther) const {
			return cRZMessage2::operator==(msgOther);
		}
		bool operator<(cIGZMessage2 const& msgOther) const {
			return cRZMessage2::operator<(msgOther);
		}

	public:
		cRZMessage2Standard();

		bool GetHasData1(void) const;
		intptr_t GetData1(void) const;
		void* GetVoid1(void) const;

		cIGZMessage2Standard* SetData1(intptr_t ulData);
		cIGZMessage2Standard* SetVoid1(void* pData);

		bool GetHasData2(void) const;
		intptr_t GetData2(void) const;
		void* GetVoid2(void) const;

		cIGZMessage2Standard* SetData2(intptr_t ulData);
		cIGZMessage2Standard* SetVoid2(void* pData);

		bool GetHasData3(void) const;
		intptr_t GetData3(void) const;
		void* GetVoid3(void) const;

		cIGZMessage2Standard* SetData3(intptr_t ulData);
		cIGZMessage2Standard* SetVoid3(void* pData);

		bool GetHasData4(void) const;
		intptr_t GetData4(void) const;
		void* GetVoid4(void) const;

		cIGZMessage2Standard* SetData4(intptr_t ulData);
		cIGZMessage2Standard* SetVoid4(void* pData);

		bool GetHasString(void) const;
		bool GetString(uint32_t dwMaxLen, void** ppStringOut) const;
		cIGZMessage2Standard* SetString(cIGZString* pString);

		bool GetHasIGZUnknown(void) const;
		cIGZUnknown* GetIGZUnknown(void) const;
		cIGZMessage2Standard* SetIGZUnknown(cIGZUnknown* pObj);

		bool GetHasExtra(void) const;
		uint32_t GetExtra(uint32_t dwLen, void** ppOut) const;
		bool SetExtra(cIGZSerializable* pSerializable);

	protected:
		inline bool IsDataFieldSet(uint8_t uFlag) const {
			return (m_uDataFlags & uFlag) == 1;
		}

		uint8_t m_uDataFlags;
		intptr_t m_dwData[4];
		cRZBaseString m_szDataString;
		cRZAutoRefCount<cIGZUnknown> m_pUnknown;
};