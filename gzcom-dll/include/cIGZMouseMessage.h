/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZMouseMessage.h
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

class cRZPoint;

static const uint32_t GZIID_cIGZMouseMessage = 0x1a0c615f;
static const uint32_t kMouseMessageType = 0xfa0c6390;

/**
 * @brief A type of message sent upon mouse events (i.e. movement)
 */
class cIGZMouseMessage : public cIGZMessage2
{
	public:
		enum class MouseEvent : uint32_t
		{
			Invalid = 0,
			LeftButtonDown = 7,
			RightButtonDown = 8,
			MiddleButtonDown = 9,
			LeftButtonUp = 10,
			RightButtonUp = 11,
			MiddleButtonUp = 12,
			Move = 13,
			Wheel = 14
		};

		virtual uint32_t Initialize(MouseEvent dwMouseEventID, cRZPoint const& sPosition, uint32_t dwKeyFlags, int32_t lWheelDelta) = 0;

		virtual MouseEvent EventType(void) const = 0;
		virtual cRZPoint Position(void) const = 0;
		virtual int32_t WheelDelta(void) const = 0;
		virtual uint32_t KeyFlags(void) const = 0;
};