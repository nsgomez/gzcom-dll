/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4DBSegment.h
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
class cIGZPersistDBSegment;
class cISC4COMSerializer;
class cISC4DBSegmentIStream;
class cISC4DBSegmentOStream;

static const uint32_t GZIID_cISC4DBSegment = 0x499899da;

class cISC4DBSegment : public cIGZUnknown
{
public:
	virtual cIGZPersistDBSegment* AsIGZPersistDBSegment() = 0;

	virtual cISC4COMSerializer* GetCOMSerializer() = 0;

	virtual bool OpenIStream(cGZPersistResourceKey const& key, cISC4DBSegmentIStream** ppStream) = 0;
	virtual void CloseIStream(cISC4DBSegmentIStream* pStream) = 0;

	virtual bool LoadClassObjects() = 0;

	virtual bool OpenOStream(cGZPersistResourceKey const& key, cISC4DBSegmentOStream** ppStream, bool bUnknown) = 0;
	virtual void CloseOStream(cISC4DBSegmentOStream* pStream) = 0;

	virtual bool SaveClassObjects() = 0;

	virtual uint32_t GetLastError() = 0;

	virtual float GetPercentageCompletion() = 0;
	virtual void SetPercentageCompletion(float percentage) = 0;
};