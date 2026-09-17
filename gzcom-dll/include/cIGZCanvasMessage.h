/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZCanvasMessage.h
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

static const uint32_t GZIID_cIGZCanvasMessage = 0xda1062fa;
static const uint32_t kCanvasMessageType = 0x1a10630a;

class cIGZCanvasMessage : public cIGZMessage2
{
	public:
		enum class CanvasEvent : uint32_t
		{
			CanvasInit = 0,
			CanvasShutdown = 1,
			WindowActivate = 2,
			WindowDeactivate = 3,
			WindowPaint = 4,
			WindowMove = 5,
			CanvasUninitialize = 6,
			CanvasReinitialize = 7,
			WindowInit = 8,
			WindowShutdown = 9,
			WindowEnableDisable = 10
		};

		virtual void Initialize(CanvasEvent dwCanvasEventID) = 0;
		virtual CanvasEvent EventType(void) const = 0;
};