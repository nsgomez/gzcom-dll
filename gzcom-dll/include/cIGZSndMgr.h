/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZSndMgr.h
 *
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
#include "cIGZUnknown.h"

class cGZPersistResourceKey;
class cIGZSnd;
class cIGZSoundCreator;
class cIGZSndDataSource;
class cIGZSndDataSourceCreator;
class cIGZString;
class cIGZVariant;

class cIGZSndMgr : public cIGZUnknown
{
public:
	virtual bool GetResource(cGZPersistResourceKey const& key, uint32_t riid, void** ppvObj) = 0;

	virtual void SetSystemSndVol(int32_t volume) = 0;
	virtual int32_t GetSystemSndVol() = 0;
	virtual uint32_t SystemSndID(int32_t key) = 0;
	virtual void SetSystemSndID(int32_t key, uint32_t soundID) = 0;
	virtual bool SetDefaultSndDataSourcePlayer2DClassId(uint32_t classId) = 0;
	virtual bool GetDefaultSndDataSourcePlayer2DClassId(uint32_t& classId) = 0;
	virtual bool SetDefaultSndDataSourcePlayer3DClassId(uint32_t classId) = 0;
	virtual bool GetDefaultSndDataSourcePlayer3DClassId(uint32_t& classId) = 0;

	virtual void RegisterSnd(cIGZSnd* pSnd, uint32_t id) = 0;
	virtual void UnregisterSnd(uint32_t id) = 0;
	virtual void UnregisterSnd(cIGZSnd* pSnd) = 0;
	virtual bool RegisterSndCreator(cIGZSoundCreator* pCreator) = 0;
	virtual bool RemoveSndCreator(cIGZSoundCreator* pCreator) = 0;

	virtual bool GetSound(cIGZString& fileName, uint32_t unknown2, cIGZVariant* unknown3, uint32_t riid, void** ppvObj) = 0;
	virtual bool GetSound(uint32_t id, uint32_t unknown2, cIGZVariant* unknown3, uint32_t riid, void** ppvObj) = 0;
	virtual bool SndAutoPlay(uint32_t unknown1) = 0;
	virtual bool SndAutoPlay(uint32_t unknown1, int32_t volume) = 0;
	virtual bool SystemSndAutoPlay(uint32_t unknown1) = 0;
	virtual bool SystemSndAutoPlay(uint32_t unknown1, int32_t volume) = 0;
	virtual bool AddSndToAutoPlayList(cIGZSnd* unknown1) = 0;

	virtual bool GetSndDataSource(uint32_t unknown1, uint32_t unknown2, cIGZVariant* unknown3, uint32_t riid, void** ppvObj) = 0;
	virtual bool RegisterSndDataSourceCreator(cIGZSndDataSourceCreator* pCreator, uint32_t id) = 0;
	virtual bool RemoveSndDataSourceCreator(uint32_t id) = 0;
	virtual bool RemoveSndDataSourceCreator(cIGZSndDataSourceCreator* pCreator) = 0;
	virtual bool GetSndDataSourceCreator(uint32_t id, uint32_t riid, void** ppvObj) = 0;

	virtual void RegisterSndDataSource(cIGZSndDataSource* pSndDataSource, uint32_t id) = 0;
	virtual void UnregisterSndDataSource(uint32_t id) = 0;
	virtual void UnregisterSndDataSource(cIGZSndDataSource* pSndDataSource) = 0;
};