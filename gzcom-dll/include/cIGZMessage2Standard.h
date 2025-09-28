/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZMessage2Standard.h
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
#include "cIGZMessage2.h"

class cIGZSerializable;
class cIGZString;

/**
 * @brief A standardized interface for simple messages
 *
 * This interface extends cIGZMessage2 by providing fields for four different
 * data fields that can be references as integers or void pointers, as well
 * as for a string, an arbitrary cIGZUnknown implementation, and arbitrary
 * "extra" data.
 */
class cIGZMessage2Standard : public cIGZMessage2
{
	public:
		virtual bool GetHasData1(void) const = 0;
		virtual intptr_t GetData1(void) const = 0;
		virtual void* GetVoid1(void) const = 0;

		virtual cIGZMessage2Standard* SetData1(intptr_t ulData) = 0;
		virtual cIGZMessage2Standard* SetVoid1(void* pData) = 0;

		virtual bool GetHasData2(void) const = 0;
		virtual intptr_t GetData2(void) const = 0;
		virtual void* GetVoid2(void) const = 0;

		virtual cIGZMessage2Standard* SetData2(intptr_t ulData) = 0;
		virtual cIGZMessage2Standard* SetVoid2(void* pData) = 0;

		virtual bool GetHasData3(void) const = 0;
		virtual intptr_t GetData3(void) const = 0;
		virtual void* GetVoid3(void) const = 0;

		virtual cIGZMessage2Standard* SetData3(intptr_t ulData) = 0;
		virtual cIGZMessage2Standard* SetVoid3(void* pData) = 0;

		virtual bool GetHasData4(void) const = 0;
		virtual intptr_t GetData4(void) const = 0;
		virtual void* GetVoid4(void) const = 0;

		virtual cIGZMessage2Standard* SetData4(intptr_t ulData) = 0;
		virtual cIGZMessage2Standard* SetVoid4(void* pData) = 0;

		virtual bool GetHasString(void) const = 0;
		virtual bool GetString(uint32_t dwMaxLen, void** ppStringOut) const = 0;
		virtual cIGZMessage2Standard* SetString(cIGZString* pString) = 0;

		virtual bool GetHasIGZUnknown(void) const = 0;
		virtual cIGZUnknown* GetIGZUnknown(void) const = 0;
		virtual cIGZMessage2Standard* SetIGZUnknown(cIGZUnknown* pObj) = 0;

		virtual bool GetHasExtra(void) const = 0;
		virtual uint32_t GetExtra(uint32_t dwLen, void** ppOut) const = 0;
		virtual bool SetExtra(cIGZSerializable* pSerializable) = 0;
};