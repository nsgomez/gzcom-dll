/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4DBSegmentOStream.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2023 Nicholas Hayes
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
#include "cIGZOStream.h"

class cGZPersistResourceKey;
class cIGZSerializable;
class cIGZVariant;
class cISC4DBSegment;

static const uint32_t GZIID_cISC4DBSegmentOStream = 0x6999a8fb;

class cISC4DBSegmentOStream : public cIGZOStream
{
	public:
		virtual bool Open(cISC4DBSegment* pSegment, cGZPersistResourceKey const& sKey, bool bUnknown) = 0;
		virtual bool Close(void) = 0;

		virtual bool IsOpen(void) = 0;

		virtual int32_t GetRecord(void) = 0;
		virtual int32_t GetSegment(void) = 0;

		virtual bool WriteGZSerializable(cIGZSerializable const* pSegment) = 0;
		virtual bool WriteResKey(cGZPersistResourceKey const& sKey) = 0;
		virtual bool WriteVariant(cIGZVariant const& sVariant) = 0;
};