/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZMessage2.h
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
#include "cIGZUnknown.h"

/**
 * @brief A preferred interface for interclass communication
 *
 * Unlike cGZMessage, this interface provides a more preferred method of
 * communicating between classes and directors that, as an Unknown-based
 * interface, can be cast to different subclasses.
 */
class cIGZMessage2 : public cIGZUnknown
{
	public:
		virtual bool Create(uint32_t dwTypeIID, void** ppUnknown) const = 0;

		virtual uint32_t GetType(void) const = 0;
		virtual uint32_t SetType(uint32_t dwType) = 0;

		/**
		 * @brief Compares messages by their assigned type
		 */
		virtual bool operator==(cIGZMessage2 const& msgOther) const = 0;

		/**
		 * @see operator==(cIGZMessage2 const& msgOther) const
		 */
		virtual bool operator<(cIGZMessage2 const& msgOther) const = 0;
};