/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZOStream.h
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

class cIGZSerializable;
class cIGZString;

/**
 * @brief An output type of generic I/O stream
 * @see cIGZSerializable
 */
class cIGZOStream : public cIGZUnknown
{
	public:
		virtual void Flush(void) = 0;

		virtual bool SetSint8(int8_t cValue) = 0;
		virtual bool SetUint8(uint8_t ucValue) = 0;
		virtual bool SetSint16(int16_t sValue) = 0;
		virtual bool SetUint16(uint16_t usValue) = 0;
		virtual bool SetSint32(int32_t lValue) = 0;
		virtual bool SetUint32(uint32_t ulValue) = 0;
		virtual bool SetSint64(int64_t llValue) = 0;
		virtual bool SetUint64(uint64_t ullValue) = 0;
		virtual bool SetFloat32(float fValue) = 0;
		virtual bool SetFloat64(double dValue) = 0;
		virtual bool SetRZCharStr(char const* pszData) = 0;
		virtual bool SetGZStr(cIGZString const& szData) = 0;
		virtual bool SetGZSerializable(cIGZSerializable const& sData) = 0;
		virtual bool SetVoid(void const* pData, uint32_t dwSize) = 0;

		/**
		 * @brief Returns the current error code for the stream
		 * @return Zero if no error encountered, non-zero value otherwise
		 */
		virtual int32_t GetError(void) = 0;
		virtual int32_t SetUserData(cIGZVariant* pData) = 0;
		virtual int32_t GetUserData(void) = 0;
};