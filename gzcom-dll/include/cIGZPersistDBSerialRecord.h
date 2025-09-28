/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZPersistDBSerialRecord.h
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

class cGZPersistResourceKey;
class cIGZPersistDBRecord;
class cIGZString;
class cIGZVariant;

static const uint32_t GZIID_cIGZPersistDBSerialRecord = 0xc56b8f08;

class cIGZPersistDBSerialRecord : public cIGZUnknown
{
public:
	virtual cIGZPersistDBRecord* AsIGZPersistDBRecord() = 0;

	virtual bool GetFieldUint8(uint8_t& value) = 0;
	virtual bool GetFieldUint8(uint8_t* ptr, uint32_t count) = 0;
	virtual bool GetFieldSint8(int8_t& value) = 0;
	virtual bool GetFieldSint8(int8_t* ptr, uint32_t count) = 0;
	virtual bool GetFieldUint16(uint16_t& value) = 0;
	virtual bool GetFieldUint16(uint16_t* ptr, uint32_t count) = 0;
	virtual bool GetFieldSint16(int16_t& value) = 0;
	virtual bool GetFieldSint16(int16_t* ptr, uint32_t count) = 0;
	virtual bool GetFieldUint32(uint32_t& value) = 0;
	virtual bool GetFieldUint32(uint32_t* ptr, uint32_t count) = 0;
	virtual bool GetFieldSint32(int32_t& value) = 0;
	virtual bool GetFieldSint32(int32_t* ptr, uint32_t count) = 0;
	virtual bool GetFieldUint64(uint64_t& value) = 0;
	virtual bool GetFieldUint64(uint64_t* ptr, uint32_t count) = 0;
	virtual bool GetFieldSint64(int64_t& value) = 0;
	virtual bool GetFieldSint64(int64_t* ptr, uint32_t count) = 0;
	virtual bool GetFieldFloat32(float& value) = 0;
	virtual bool GetFieldFloat32(float* ptr, uint32_t count) = 0;
	virtual bool GetFieldFloat64(double& value) = 0;
	virtual bool GetFieldFloat64(double* ptr, uint32_t count) = 0;
	virtual bool GetFieldString(cIGZString& value) = 0;
	virtual bool GetFieldResKey(cGZPersistResourceKey& value) = 0;
	virtual bool GetFieldVariant(cIGZVariant** ppVariant) = 0;
	virtual bool GetFieldVoid(void* ptr, uint32_t count) = 0;

	virtual bool SetFieldUint8(uint8_t value) = 0;
	virtual bool SetFieldUint8(uint8_t* ptr, uint32_t count) = 0;
	virtual bool SetFieldSint8(int8_t value) = 0;
	virtual bool SetFieldSint8(int8_t* ptr, uint32_t count) = 0;
	virtual bool SetFieldUint16(uint16_t value) = 0;
	virtual bool SetFieldUint16(uint16_t* ptr, uint32_t count) = 0;
	virtual bool SetFieldSint16(short value) = 0;
	virtual bool SetFieldSint16(short* ptr, uint32_t count) = 0;
	virtual bool SetFieldUint32(uint32_t value) = 0;
	virtual bool SetFieldUint32(uint32_t* ptr, uint32_t count) = 0;
	virtual bool SetFieldSint32(int32_t value) = 0;
	virtual bool SetFieldSint32(int32_t* ptr, uint32_t count) = 0;
	virtual bool SetFieldUint64(uint64_t value) = 0;
	virtual bool SetFieldUint64(uint64_t* ptr, uint32_t count) = 0;
	virtual bool SetFieldSint64(int64_t value) = 0;
	virtual bool SetFieldSint64(int64_t* ptr, uint32_t count) = 0;
	virtual bool SetFieldFloat32(float value) = 0;
	virtual bool SetFieldFloat32(float* ptr, uint32_t count) = 0;
	virtual bool SetFieldFloat64(double value) = 0;
	virtual bool SetFieldFloat64(double* ptr, uint32_t count) = 0;
	virtual bool SetFieldString(cIGZString const& value) = 0;
	virtual bool SetFieldResKey(cGZPersistResourceKey const& value) = 0;
	virtual bool SetFieldVariant(cIGZVariant const* value) = 0;
	virtual bool SetFieldVoid(void* ptr, uint32_t count) = 0;

	virtual uint32_t GetSize() = 0;
	virtual bool SetSize(uint32_t size) = 0;

	virtual uint32_t GetPosition() = 0;
	virtual bool SeekAbsolute(uint32_t position) = 0;
	virtual bool SeekRelative(int32_t position) = 0;
};