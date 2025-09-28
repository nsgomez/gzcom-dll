/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZCanvasW32.h
 *
 * Copyright (C) 2024 Nicholas Hayes
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

class cIGZCanvas;
class cIGZWinProcFilterW32;

static const uint32_t GZIID_cIGZCanvasW32 = 0xe46397db;

class cIGZCanvasW32 : public cIGZUnknown
{
public:
	virtual cIGZCanvas* AsIGZCanvas() = 0;

	virtual intptr_t Handle() = 0; // The registered mouse wheel message
	virtual intptr_t Class() = 0; // Always returns 0

	virtual bool AddWinProcFilter(cIGZWinProcFilterW32*, bool add) = 0;
};