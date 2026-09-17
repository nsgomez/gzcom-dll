/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZKeyMessage.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2026 Nicholas Hayes
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

static const uint32_t GZIID_cIGZKeyMessage = 0x1a104742;
static const uint32_t kKeyMessageType = 0x7a104750;

/**
 * @brief A type of message sent upon a keyboard event (i.e. typing)
 */
class cIGZKeyMessage : public cIGZMessage2
{
	public:
		enum class KeyEvent : uint32_t
		{
			Invalid = 0,
			Char = 4,
			Down = 5,
			Up = 6
		};

		virtual uint32_t Initialize(KeyEvent dwKeyEventID, uint32_t dwKey, uint32_t dwKeyFlags, uint32_t dwRepeatCount) = 0;

		virtual KeyEvent EventType(void) = 0;
		virtual uint32_t Key(void) = 0;
		virtual uint32_t KeyFlags(void) = 0;
		virtual uint32_t RepeatCount(void) = 0;
};