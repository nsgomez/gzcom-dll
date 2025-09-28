/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZUnknownList.h
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
#include "cIGZUnknown.h"

class cIGZUnknownEnumerator;

/**
 * @brief An interface for lists of cIGZUnknown and unknown-derived objects
 */
class cIGZUnknownList : public cIGZUnknown
{
	public:
		virtual size_t GetSize(void) = 0;
		
		virtual bool GetElement(uint32_t dwOffset, uint32_t riid, void** ppvObj) = 0;
		virtual bool EnumElements(cIGZUnknown& sEnum, cIGZUnknown* pUnknown, uint32_t riid) = 0;

		virtual bool Push_Front(cIGZUnknown* pElem) = 0;
		virtual bool Push_Front(cIGZUnknownList const& sList) = 0;

		virtual bool Push_Back(cIGZUnknown* pElem) = 0;
		virtual bool Push_Back(cIGZUnknownList const& sList) = 0;

		virtual bool Peek_Front(uint32_t riid, void** ppvObj) = 0;
		virtual bool Peek_Back(uint32_t riid, void** ppvObj) = 0;
		virtual bool Pop_Front(uint32_t riid, void** ppvObj) = 0;
		virtual bool Pop_Back(uint32_t riid, void** ppvObj) = 0;

		virtual bool Clear(void) = 0;
		virtual bool CopyFrom(cIGZUnknownList const& sList) = 0;
		virtual bool CreateClone(cIGZUnknownList** ppList) = 0;

		virtual bool ConstEnumElements(cIGZUnknownEnumerator& sEnum, cIGZUnknown* pUnknown, uint32_t riid) = 0;

};