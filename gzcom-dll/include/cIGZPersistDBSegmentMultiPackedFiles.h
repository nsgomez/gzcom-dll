/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZPersistDBSegmentMultiPackedFiles.h
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
class cIGZPersistResourceKeyFilter;
class cIGZString;

static const uint32_t GZCLSID_cGZPersistDBSegmentMultiPackedFiles = 0x90F8619;
static const uint32_t GZIID_cIGZPersistDBSegmentMultiPackedFiles = 0xE90F85F3;

class cIGZPersistDBSegmentMultiPackedFiles : public cIGZUnknown
{
public:
	virtual void SetPathFilter(cIGZString const&) = 0;

	virtual int32_t ConsolidateDatabaseRecords(cIGZPersistDBSegment*, cIGZPersistResourceKeyFilter*) = 0;
	virtual int32_t ConsolidateDatabaseRecords(cIGZString const&, cIGZPersistResourceKeyFilter*) = 0;

	virtual bool FindDBSegment(cGZPersistResourceKey const&, cIGZPersistDBSegment**) = 0;
	virtual uint32_t GetSegmentCount() = 0;
	virtual cIGZPersistDBSegment* GetSegmentByIndex(uint32_t) = 0;

	virtual void AddedResource(cGZPersistResourceKey const&, cIGZPersistDBSegment*) = 0;
	virtual void RemovedResource(cGZPersistResourceKey const&, cIGZPersistDBSegment*) = 0;
};
