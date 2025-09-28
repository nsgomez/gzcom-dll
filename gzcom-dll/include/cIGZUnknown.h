/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZUnknown.h
 *
 * Copyright (C) 2016 Nelson Gomez
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
#include <stdint.h>

static const uint32_t GZIID_cIGZUnknown = 1;

/**
 * @brief The fundamental COM object that all others inherit from
 *
 * Any COM object that interacts with the game or will be used by directors
 * should inherit from this object and implement refcounting as specified.
 */
class cIGZUnknown
{
	public:
		/**
		 * @brief Casts the object to the interface specified by riid
		 * @param riid The GUID for the interface type to cast to
		 * @param ppvObj A pointer to a void pointer to store the result in
		 * @return Whether the object could be successfully cast or not
		 */
		virtual bool QueryInterface(uint32_t riid, void** ppvObj) = 0;

		/**
		 * @brief Adds a reference to this object
		 * @return The new reference count for this object
		 */
		virtual uint32_t AddRef(void) = 0;

		/**
		 * @brief Removes a reference to this object
		 * @return The new reference count for this object
		 *
		 * If the reference count is zero, the object should delete itself and
		 * return zero unless it has pretty good reason not to, such as
		 * refcounting for the object being handled by some other service.
		 */
		virtual uint32_t Release(void) = 0;
};