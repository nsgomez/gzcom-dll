/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISCPropertyHolder.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2023, 2024 Nicholas Hayes
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
class cIGZUnknownList;
class cIGZVariant;
class cISCProperty;

static const uint32_t GZIID_cISCPropertyHolder = 0x25216283;

class cISCPropertyHolder : public cIGZUnknown
{
	public:
		virtual bool HasProperty(uint32_t dwProperty) const = 0;

		virtual bool GetPropertyList(cIGZUnknownList** ppList) const = 0;
		virtual cISCProperty* GetProperty(uint32_t dwProperty) const = 0;
		virtual bool GetProperty(uint32_t dwProperty, uint32_t& dwValueOut) const = 0;
		virtual bool GetProperty(uint32_t dwProperty, cIGZString& szValueOut) const = 0;
		virtual bool GetProperty(uint32_t dwProperty, uint32_t riid, void** ppvObj) const = 0;
		virtual bool GetProperty(uint32_t dwProperty, void* pUnknown, uint32_t& dwUnknownOut) const = 0;

		virtual bool AddProperty(cISCProperty* pProperty, bool bUnknown) = 0;
		virtual bool AddProperty(uint32_t dwProperty, cIGZVariant const* pVariant, bool bUnknown) = 0;
		virtual bool AddProperty(uint32_t dwProperty, uint32_t dwValue, bool bUnknown) = 0;
		virtual bool AddProperty(uint32_t dwProperty, cIGZString const& szValue) = 0;
		virtual bool AddProperty(uint32_t dwProperty, int32_t lValue, bool bUnknown) = 0;
		virtual bool AddProperty(uint32_t dwProperty, void* pUnknown, uint32_t dwUnknown, bool bUnknown) = 0;

		virtual bool CopyAddProperty(cISCProperty* pProperty, bool bUnknown) = 0;

		virtual bool RemoveProperty(uint32_t dwProperty) = 0;
		virtual bool RemoveAllProperties(void) = 0;

		typedef void (*FunctionPtr1)(cISCProperty*, void*);
		typedef bool (*FunctionPtr2)(cISCProperty*, void*);

		virtual bool EnumProperties(FunctionPtr1 pFunction1, void* pData) const = 0;
		virtual bool EnumProperties(FunctionPtr2 pFunction2, FunctionPtr1 pFunctionPipe) const = 0;

		virtual bool CompactProperties(void) = 0;
};