/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISCExemplarPropertyHolder.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2025 Nicholas Hayes
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

class cISCResExemplar;

static const uint32_t GZIID_cISCExemplarPropertyHolder = 0x0ac2b5f7;

class cISCExemplarPropertyHolder : public cIGZUnknown
{
	public:
		virtual bool SetDefaultExemplar(cISCResExemplar* pExemplar) = 0;
		virtual cISCResExemplar* GetDefaultExemplar(void) = 0;
};