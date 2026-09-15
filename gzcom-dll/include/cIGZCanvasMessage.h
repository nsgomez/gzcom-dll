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

class cIGZCanvasMessage : public cIGZMessage2
{
	public:
		virtual cIGZCanvasMessage* Initialize(uint32_t dwCanvasEventID) = 0;
		virtual uint32_t EventType(void) = 0;
};