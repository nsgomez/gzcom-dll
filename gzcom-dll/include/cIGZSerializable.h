/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZSerializable.h
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
#include "cIGZUnknown.h"

class cIGZIStream;
class cIGZOStream;

static const uint32_t GZIID_cIGZSerializable = 0xe4fda3d4;

/**
 * @brief An interface for objects that can be saved to and read from disk
 * 
 * Serializable objects must have a class ID registered with a COM director in
 * order to be instantiated when reading from disk. A serializable object is
 * something that could, for instance, be written to the savegame, and can use
 * the streams given to read and write data for that object in the format it
 * desires.
 */
class cIGZSerializable : public cIGZUnknown
{
	public:
		/**
		 * @brief Writes data to the stream provided
		 * @param gzOut The stream to write to
		 * @return Whether the stream encountered an error
		 * @see cIGZOStream::GetError(void)
		 */
		virtual bool Write(cIGZOStream& gzOut) = 0;

		/**
		 * @brief Reads data from the stream provided
		 * @param gzIn The stream to read from
		 * @return Whether the stream encountered an error
		 * @see cIGZIStream::GetError(void)
		 *
		 * You can assume that when reading from the stream, it starts in a
		 * position for your class object and you can read in the same order
		 * as you wrote.
		 */
		virtual bool Read(cIGZIStream& gzIn) = 0;

		/**
		 * @return The clsid associated with this serializable object
		 */
		virtual uint32_t GetGZCLSID(void) = 0;
};