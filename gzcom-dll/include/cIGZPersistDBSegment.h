/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZPersistDBSegment.h
 *
 * Copyright (C) 2024, 2025 Nicholas Hayes
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
#include "cIGZFile.h"

class cGZPersistResourceKey;
class cIGZPersistDBRecord;
class cIGZPersistResourceKeyFilter;
class cIGZPersistResourceKeyList;
class cIGZString;

static const uint32_t GZIID_cIGZPersistDBSegment = 0x656B8F0C;

class cIGZPersistDBSegment : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool Open(bool openRead, bool openWrite) = 0;
	virtual bool IsOpen() const = 0;
	virtual bool Close() = 0;
	virtual bool Flush() = 0;

	virtual void GetPath(cIGZString& path) const = 0;
	virtual bool SetPath(cIGZString const& path) = 0;

	virtual bool Lock() = 0;
	virtual bool Unlock() = 0;

	virtual uint32_t GetSegmentID() const = 0;
	virtual bool SetSegmentID(uint32_t const& segmentID) = 0;

	virtual uint32_t GetRecordCount(cIGZPersistResourceKeyFilter* filter) = 0;

	virtual uint32_t GetResourceKeyList(cIGZPersistResourceKeyList* list, cIGZPersistResourceKeyFilter* filter) = 0;
	virtual bool GetResourceKeyList(cIGZPersistResourceKeyList& list) = 0;

	virtual bool TestForRecord(cGZPersistResourceKey const& key) = 0;
	virtual uint32_t GetRecordSize(cGZPersistResourceKey const& key) = 0;
	virtual bool OpenRecord(cGZPersistResourceKey const& key, cIGZPersistDBRecord** record, cIGZFile::AccessMode accessMode) = 0;
	virtual bool CreateNewRecord(cGZPersistResourceKey const& key, cIGZPersistDBRecord** record) = 0;

	virtual bool CloseRecord(cIGZPersistDBRecord* record) = 0;
	virtual bool CloseRecord(cIGZPersistDBRecord** record) = 0;

	virtual bool AbortRecord(cIGZPersistDBRecord* record) = 0;
	virtual bool AbortRecord(cIGZPersistDBRecord** record) = 0;

	virtual bool DeleteRecord(cGZPersistResourceKey const& key) = 0;
	virtual uint32_t ReadRecord(cGZPersistResourceKey const& key, void* buffer, uint32_t& recordSize) = 0;
	virtual bool WriteRecord(cGZPersistResourceKey const& key, void* buffer, uint32_t recordSize) = 0;

	virtual bool Init(uint32_t segmentID, cIGZString const& path, bool unknown2) = 0;
};
