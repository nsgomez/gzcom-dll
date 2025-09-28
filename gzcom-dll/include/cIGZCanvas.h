/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZCanvas.h
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

class cIGZString;
class cIGZVariant;
template <typename T> class SC4Rect;

static const uint32_t GZIID_cIGZCanvas = 0x66b217a1;

class cIGZCanvas : public cIGZUnknown
{
public:
	virtual bool Init(uint32_t unknown1, uint32_t width, uint32_t height) = 0;
	virtual bool Init(SC4Rect<int32_t> const& area) = 0;

	virtual bool IsInitialized() = 0;
	virtual bool Shutdown() = 0;

	virtual bool Uninitialize() = 0;
	virtual bool Restore() = 0;

	virtual void SetArea(int32_t left, int32_t top, int32_t right, int32_t bottom) = 0;
	virtual SC4Rect<int32_t>* GetArea() = 0;

	virtual void ShowWindow() = 0;
	virtual void HideWindow() = 0;

	virtual void SetCaption(cIGZString const& caption) = 0;

	virtual void Paint() = 0;
	virtual void ForceFullSystemRedraw() = 0;

	virtual int32_t LastCursorPositionX() = 0;
	virtual int32_t LastCursorPositionY() = 0;

	virtual bool FlushInputMessageQueue() = 0;
	virtual bool PostSystemMessage(cIGZVariant* pVariant) = 0;

	virtual intptr_t GetSystemCanvasIdentifier() = 0; // A HWND* on Windows
};
