/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZPersistDBSegmentDirectoryFiles.h
 *
 * Copyright (C) 2026 Casper Van Gheluwe
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
class cIGZPersistRESIDtoExtensionMap;
class cIGZString;

static const uint32_t GZCLSID_cGZDBSegmentDirectoryFiles = 0xa079ce1b;
static const uint32_t GZIID_cIGZPersistDBSegmentDirectoryFiles = 0x856c8cf7;

class cIGZPersistDBSegmentDirectoryFiles : public cIGZUnknown
{
public:
	virtual cIGZPersistDBSegment* AsIGZPersistDBSegment() = 0;

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool Init(uint32_t segmentID, cIGZString const& path, bool unknown) = 0;

	virtual bool IsOpen() const = 0;

	virtual void GetDirectory(cIGZString& path) const = 0;
	virtual bool SetDirectory(cIGZString const& path) = 0;

	virtual void SetDefaultGroupId(uint32_t groupId) = 0;
	virtual uint32_t GroupId() const = 0;

	virtual void* ExtensionMap() = 0;
	virtual bool GetRESIDtoExtensionMap(cIGZPersistRESIDtoExtensionMap** ppMap) = 0;
	virtual bool AddExtensionAssociation(uint32_t typeId, cIGZString const& extension) = 0;

	virtual void SetAllowedIDPositions(bool prefix, bool suffix) = 0;
	virtual void SetAllowTextAsKey(bool allow) = 0;

	virtual bool GetFileNameFromKey(cGZPersistResourceKey const& key, cIGZString& outFileName) = 0;
	virtual bool GetFilePathFromKey(cGZPersistResourceKey const& key, cIGZString& outFilePath) = 0;
	virtual bool GetKeyFromFileName(cIGZString const& stem, cIGZString const& ext, cGZPersistResourceKey& outKey) = 0;

	virtual bool IsFileNameValid(cIGZString const& fileName) = 0;
	virtual bool GenerateNewKey(uint32_t typeId, cGZPersistResourceKey& outKey) = 0;
	virtual uint32_t EnumerateRecordFiles(cIGZString** outFileNames, uint32_t maxCount) = 0;

	virtual bool GetFileChangeDetection() const = 0;
	virtual bool SetFileChangeDetection(bool enable, uint32_t intervalSeconds) = 0;
};
