/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZKeyMessage.h
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
#include "cIGZMessage2.h"

/**
 * @brief A type of message sent upon a keyboard event (i.e. typing)
 */
class cIGZKeyMessage : public cIGZMessage2
{
	public:
		virtual uint32_t Initialize(uint32_t dwKeyEventID, uint32_t dwKey, uint32_t dwKeyFlags, uint32_t dwRepeatCount) = 0;

		virtual uint32_t EventType(void) = 0;
		virtual uint32_t Key(void) = 0;
		virtual uint32_t KeyFlags(void) = 0;
		virtual uint32_t RepeatCount(void) = 0;
};