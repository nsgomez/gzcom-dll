/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4COMSerializer.h
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

class cIGZIStream;
class cIGZOStream;
class cIGZSerializable;
class cISC4DBSegment;

static const uint32_t GZIID_cISC4COMSerializer = 0x699899ea;

/**
 * @brief Saves and loads cIGZSerializable objects that are shared between records of a city file.
 *
 * Get it from cISC4DBSegment::GetCOMSerializer(). Writing an object only stores a
 * reference to it (an object ID plus its class ID) in your stream. The object data
 * itself goes into one shared record (type 0x499b23fe, group 0x299b2d1b) when the
 * segment is closed. Every reference to the same object reads back as the same
 * instance, which the game creates from the class ID through the COM director.
 *
 * Most code uses this through cISC4DBSegmentOStream::WriteGZSerializable and
 * cISC4DBSegmentIStream::ReadGZSerializable, which forward here.
 */
class cISC4COMSerializer : public cIGZUnknown
{
public:
	enum Mode : int32_t
	{
		kModeClosed = 0,
		kModeLoad = 1,
		kModeSave = 2,
	};

	/**
	 * @brief Binds the serializer to a segment.
	 * @param pSegment The segment that holds the shared object record.
	 * @param mode 1 to load or 2 to save. 0 fails.
	 * @return False if the segment could not be used or the mode is 0.
	 *
	 * An already open serializer is closed first.
	 */
	virtual bool Open(cISC4DBSegment* pSegment, int32_t mode) = 0;

	/**
	 * @brief Unbinds the serializer and resets its object tables.
	 * @return The result of SaveClassObjects in save mode, otherwise true.
	 */
	virtual bool Close() = 0;

	/**
	 * @return The mode passed to Open, or 0 when closed.
	 */
	virtual int32_t GetMode() = 0;

	/**
	 * @brief Reads the shared object record and calls cIGZSerializable::Read on
	 * every object that was not loaded yet.
	 *
	 * Only works in load mode and only runs once per Open.
	 */
	virtual bool LoadClassObjects() = 0;

	/**
	 * @brief Writes every object passed to WriteGZSerializable into the shared
	 * object record, using cIGZSerializable::Write.
	 *
	 * Only works in save mode. Close calls this for you.
	 */
	virtual bool SaveClassObjects() = 0;

	/**
	 * @brief Writes a reference to an object and queues the object to be saved.
	 * @param stream The stream of the record that refers to the object.
	 * @param pSerializable The object, or nullptr to write a null reference.
	 * @return True if the reference was written and the stream has no error.
	 */
	virtual bool WriteGZSerializable(cIGZOStream& stream, cIGZSerializable const* pSerializable) = 0;

	/**
	 * @brief Reads a reference written by WriteGZSerializable.
	 * @param stream The stream of the record that refers to the object.
	 * @param ppSerializableOut Receives the object, or nullptr for a null reference.
	 * @param bLoadNow True reads the object data right away. Otherwise it is
	 *                 read later by LoadClassObjects.
	 * @return True if the reference was read and the stream has no error.
	 */
	virtual bool ReadGZSerializable(cIGZIStream& stream, cIGZSerializable** ppSerializableOut, bool bLoadNow) = 0;
};
