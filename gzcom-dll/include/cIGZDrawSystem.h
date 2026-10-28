/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZDrawSystem.h
 *
 * Copyright (C) 2026 Casper Van Gheluwe
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
#include "cIGZBuffer.h"
#include "cIGZUnknown.h"

class cIGZBufferHardwareCache;
class cIGZDrawContextEngine;
class cIGZDrawContextEngineFactory;

static const uint32_t GZIID_cIGZDrawSystem = 0x4b2ea3b3;

class cIGZDrawSystem : public cIGZUnknown
{
public:
	virtual void AddEngine(cIGZDrawContextEngineFactory* pFactory) = 0;
	virtual bool CreateEngine(cIGZUnknown* pUnknown, cIGZDrawContextEngine** ppEngine) = 0;
	virtual bool CreatePrivateBuffer(cIGZBuffer** ppBuffer, int32_t width, int32_t height, cGZBufferColorType::eColorType colorType) = 0;

	virtual void RegisterBufferCache(cIGZBufferHardwareCache* pCache) = 0;
	virtual void UnregisterBufferCache(cIGZBufferHardwareCache* pCache) = 0;
	// Flushes the caches that went unused for more than four clock ticks.
	// The Mac build ignores the argument.
	virtual void FlushOldBufferCaches(uint32_t unknown) = 0;
	virtual void FlushBufferCaches() = 0;

	// The clock the buffer caches are aged against.
	virtual uint32_t GetBufferCacheClock() = 0;
};
