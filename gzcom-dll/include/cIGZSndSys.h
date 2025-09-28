/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZSndSys.h
 *
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

class cIGZSndEventHandler;
class cIGZSndEventStd;
class cIGZSndInstanceCache;
class cIGZSndRenderer;
class cIGZSndPropertyCache;
class cIGZSndUpdateTarget;
class cIGZSnd3DListener;
class cIGZSnd3DListenerEx;
class cIGZString;
class SndCallbackInterval;

class cIGZSndSys : public cIGZUnknown
{
public:
	virtual cIGZSnd3DListener* AsIGZSnd3DListener() = 0;
	virtual cIGZSnd3DListenerEx* AsIGZSnd3DListenerEx() = 0;

	virtual bool DoEvent(cIGZSndEventStd* pEvent) = 0;
	virtual bool DoEvent(uint32_t unknown1, uint32_t unknown2, uint32_t unknown3, uint32_t unknown4, uint32_t unknown5) = 0;
	virtual bool DoEvent(uint32_t unknown1, cIGZUnknown* unknown2, uint32_t unknown3, uint32_t unknown4, uint32_t unknown5, uint32_t unknown6) = 0;
	virtual bool DoEvent(cIGZString* unknown2, uint32_t unknown3, uint32_t unknown4, uint32_t unknown5, uint32_t unknown6) = 0;

	virtual bool PostEvent(cIGZSndEventStd* pEvent) = 0;
	virtual bool PostEvent(uint32_t unknown1, uint32_t unknown2, uint32_t unknown3, uint32_t unknown4, uint32_t unknown5) = 0;
	virtual bool PostEvent(uint32_t unknown1, cIGZUnknown* unknown2, uint32_t unknown3, uint32_t unknown4, uint32_t unknown5, uint32_t unknown6) = 0;
	virtual bool PostEvent(cIGZString* unknown2, uint32_t unknown3, uint32_t unknown4, uint32_t unknown5, uint32_t unknown6) = 0;

	virtual bool EventCreate(uint32_t riid, void** ppvObj) = 0;
	virtual bool EventCreate(uint32_t eventID, uint32_t riid, void** ppvObj, uint32_t data1, uint32_t data2, uint32_t data3, uint32_t data4) = 0;

	virtual bool RegisterEventHandler(cIGZSndEventHandler* pEventHandler) = 0;
	virtual bool UnregisterEventHandler(cIGZSndEventHandler* pEventHandler) = 0;
	virtual bool Update(uint32_t unknown1) = 0;

	virtual bool GetInitFlag() const = 0;

	virtual void SetDataDirectory(cIGZString const& path) = 0;
	virtual cIGZString* DataDirectory() = 0;

	virtual bool GetEnabledFlag() const = 0;
	virtual void SetEnabledFlag(bool enabled) = 0;

	virtual bool SetExtensionDefaultDataSourceClassId(cIGZString* unknown1, uint32_t unknown2) = 0;
	virtual bool GetExtensionDefaultDataSourceClassId(cIGZString* unknown1, uint32_t& unknown2) = 0;

	virtual uint32_t GetNumExtensionDefaultDataSourceClassIdMappings() = 0;
	virtual bool GetExtensionDefaultDataSourceClassIdMappingClassId(uint32_t unknown1, uint32_t& unknown2) = 0;
	virtual bool GetExtensionDefaultDataSourceClassIdMappingExtension(uint32_t unknown1, cIGZString& unknown2) = 0;

	virtual int32_t GetMasterVolume() = 0;
	virtual bool SetMasterVolume(int32_t masterVolume) = 0;

	virtual bool RegisterTarget(cIGZSndUpdateTarget* unknown1, SndCallbackInterval* unknown2) = 0;
	virtual bool UnregisterTarget(cIGZSndUpdateTarget* unknown1) = 0;

	typedef bool(*EnumerateTargetsCallback)(cIGZSndUpdateTarget*, uint32_t, void*);

	virtual bool EnumerateTargets(EnumerateTargetsCallback pCallback, uint32_t unknown2, void* pContext) = 0;

	virtual bool EnableUpdates() = 0;
	virtual bool DisableUpdates() = 0;

	virtual bool RegisterRenderer(cIGZSndRenderer* pRenderer) = 0;
	virtual bool UnregisterRenderer(cIGZSndRenderer* pRenderer) = 0;
	virtual bool IsRegisteredRenderer(cIGZSndRenderer* pRenderer) = 0;

	virtual uint32_t NumRenderers() = 0;

	virtual bool FindPlayingGZSnd(uint32_t unknown1, uint32_t riid, void** ppvObj) = 0;
	virtual bool IsSndPlaying(uint32_t unknown1) = 0;

	virtual intptr_t GetCriticalSection() = 0;

	virtual bool GetSndPropertyCache(cIGZSndPropertyCache** ppCache) = 0;
	virtual cIGZSndPropertyCache* GetSndPropertyCache() = 0;
	virtual bool GetSndInstanceCache(cIGZSndInstanceCache** ppCache) = 0;
	virtual cIGZSndInstanceCache* GetSndInstanceCache() = 0;

	virtual bool AddToMainlineReleaseList(cIGZUnknown* unknown1) = 0;
	virtual void Panic() = 0;

	virtual void SetTestMode(bool enabled) = 0;
	virtual bool GetTestMode() = 0;

	virtual uint32_t GetSoundSystemThreadId() = 0;
};