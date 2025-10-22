/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZGimexFactory.h
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
#include "cIGZBuffer.h"

class cGZPersistResourceKey;
class cIGZFile;
class cIGZPersistDBSegment;
class cIGZPersistDBSerialRecord;
class cIGZString;
template<typename T> class SC4Rect;

static const uint32_t GZCLSID_cIGZGimexFactory = 0xa2ffb5d3;
static const uint32_t GZIID_cIGZGimexFactory = 0x02ffbb60;

class cIGZGimexFactory : public cIGZUnknown
{
public:
	virtual bool LoadFromFile(cIGZString const& path, cIGZBuffer* pBuffer, cGZBufferColorType::eColorType bufferType) = 0;
	virtual bool LoadFromFile(cIGZString const& path, cIGZBuffer** outBuffer, cGZBufferColorType::eColorType bufferType) = 0;

	virtual bool SaveToFile(cIGZString const& path, cIGZBuffer* pBuffer, SC4Rect<int32_t>& area, uint32_t quality) = 0;
	virtual bool SaveToFile(cIGZString const& path, cIGZBuffer* pBuffer, uint32_t quality) = 0;
	virtual bool LoadFromFile(cIGZFile* pFile, uint32_t gimexIndex, cIGZBuffer* pBuffer, cGZBufferColorType::eColorType bufferType) = 0;
	virtual bool CreateFromFile(cIGZFile* pFile, uint32_t gimexIndex, cIGZBuffer** outBuffer, cGZBufferColorType::eColorType bufferType) = 0;

	virtual bool LoadFromResource(cGZPersistResourceKey& key, uint32_t gimexIndex, cIGZBuffer* pBuffer, cGZBufferColorType::eColorType bufferType) = 0;
	virtual bool CreateFromResource(cGZPersistResourceKey& key, uint32_t gimexIndex, cIGZBuffer** outBuffer, cGZBufferColorType::eColorType bufferType) = 0;
	virtual bool LoadFromSerialRecord(cIGZPersistDBSerialRecord* pRecord, uint32_t gimexIndex, cIGZBuffer* pBuffer, cGZBufferColorType::eColorType bufferType) = 0;
	virtual bool CreateFromSerialRecord(cIGZPersistDBSerialRecord* pRecord, uint32_t gimexIndex, cIGZBuffer** outBuffer, cGZBufferColorType::eColorType bufferType) = 0;

	virtual bool SaveToFile(cIGZFile* pFile, uint32_t gimexIndex, cIGZBuffer* pBuffer, SC4Rect<int32_t>& area, uint32_t quality) = 0;
	virtual bool SaveToFile(cIGZFile* pFile, uint32_t gimexIndex, cIGZBuffer* pBuffer, uint32_t quality) = 0;
	virtual bool SaveToResource(cGZPersistResourceKey& key, cIGZPersistDBSegment* pSegment, uint32_t gimexIndex, cIGZBuffer* pBuffer, SC4Rect<int32_t>& area, uint32_t quality) = 0;
	virtual bool SaveToResource(cGZPersistResourceKey& key, cIGZPersistDBSegment* pSegment, uint32_t gimexIndex, cIGZBuffer* pBuffer, uint32_t quality) = 0;
	virtual bool SaveToSerialRecord(cIGZPersistDBSerialRecord* pRecord, uint32_t gimexIndex, cIGZBuffer* pBuffer, SC4Rect<int32_t>& area, uint32_t quality) = 0;
	virtual bool SaveToSerialRecord(cIGZPersistDBSerialRecord* pRecord, uint32_t gimexIndex, cIGZBuffer* pBuffer, uint32_t quality) = 0;
};