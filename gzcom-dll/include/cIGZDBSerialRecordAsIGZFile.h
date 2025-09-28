/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZDBSerialRecordAsIGZFile.h
 *
 * Copyright (C) 2025 Nicholas Hayes
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

class cIGZPersistDBSerialRecord;
class cIGZFile;

static const uint32_t GZCLSID_cIGZDBSerialRecordAsIGZFile = 0xa32c0da;
static const uint32_t GZIID_cIGZDBSerialRecordAsIGZFile = 0x8a32c0ac;

class cIGZDBSerialRecordAsIGZFile : public cIGZUnknown
{
public:
	virtual bool SetDBSerialRecord(cIGZPersistDBSerialRecord* pRecord) = 0;
	virtual cIGZPersistDBSerialRecord* GetDBSerialRecord() = 0;

	virtual cIGZFile* AsIGZFile() = 0;
};