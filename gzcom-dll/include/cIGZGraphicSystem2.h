/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZGraphicSystem2.h
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

class cGZDisplayMetrics;
class cGZGPixelFormatDesc;
class cIGZGDriver;
class cIGZBuffer;
class cIGZString;
class cRZRect;

static const uint32_t GZIID_cIGZGraphicSystem2 = 0xC47B747C;

class cIGZGraphicSystem2 : public cIGZUnknown
{
public:
	virtual cIGZGDriver* GetGDriver() = 0;
	virtual uint32_t GetGDriverCount() const = 0;
	virtual cIGZGDriver* GetGDriverByIndex(uint32_t) const = 0;
	virtual cIGZGDriver* GetGDriverByID(uint32_t) const = 0;
	virtual void SetGDriver(cIGZGDriver*) = 0;

	virtual void SetDefaultDriverClassID(uint32_t) = 0;
	virtual void SetDriverSettingsIniFilePath(cIGZString const&) = 0;

	virtual bool IsScreenSettingAvailable(cGZDisplayMetrics const&, uint32_t) = 0;
	virtual bool DowngradeToAvailableScreenSetting(cGZDisplayMetrics&, uint32_t) = 0;
	virtual void SetUIRenderingMode() = 0;
	virtual bool RenderBufferToScreen(cIGZBuffer*, cRZRect const&, cRZRect const&) = 0;
	virtual void DisableScreenBuffer() = 0;

	virtual void GetScreenPixelFormat(cGZGPixelFormatDesc&) = 0;

	virtual void LazyFlush() = 0;

	virtual void SetEnableRenderToScreen(bool) = 0;

	virtual void SetForceNoTranslucency(bool, float) = 0;
	virtual bool IsTranslucencyEnabled() = 0;
	virtual float GetTranslucencyThreshold() = 0;

	virtual void EnableCursorEmulation(bool) = 0;

	virtual void EnablePageFlipping(bool) = 0;
	virtual bool IsPageFlippingEnabled() = 0;
};