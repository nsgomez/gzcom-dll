/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZBaseUnknown.h
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

/**
 * @brief A base class for types that implement cIGZUnknown and delete
 * themselves when their reference count drops to zero.
 */
class cRZBaseUnknown : public cIGZUnknown
{
public:
	virtual ~cRZBaseUnknown();

	/**
	* @brief Casts the object to the interface specified by riid. Override
	* this method to respond to queries for any additional interfaces that
	* you implement.
	* @param riid The GUID for the interface type to cast to.
	* @param ppvObj A pointer to a void pointer to store the result in.
	* @return Whether the object could be successfully cast or not.
	*/
	virtual bool QueryInterface(uint32_t riid, void** ppvObj);

	/**
	* @brief Adds a reference to this object.
	* @return The new reference count for this object.
	*/
	uint32_t AddRef();

	/**
	 * @brief Removes a reference to this object. When the reference
	 * count drops to zero the object will delete itself.
	* @return The new reference count for this object.
	 */
	uint32_t Release();

protected:
	cRZBaseUnknown();

private:
	uint32_t refCount;
};
