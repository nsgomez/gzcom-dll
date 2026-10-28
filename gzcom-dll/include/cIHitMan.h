/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIHitMan.h
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
#include "cIGZUnknown.h"

class cIGZPersistDBSegment;
class cIGZSnd;
class cIGZString;
class cIHitAppDataRequestHandler;
class cIHitSem;
class cIHitTrackDataBlock;
class cIHitTrackPlayer;

static const uint32_t GZIID_cIHitMan = 0xbb1bd9a8;

class cIHitMan : public cIGZUnknown
{
public:
	typedef void (*TrackFlowErrorHandler)(cIHitTrackPlayer* pPlayer, char* szMessage);

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;
	virtual void UpdateView() = 0;

	virtual bool Pause() = 0;
	virtual bool Unpause() = 0;
	virtual bool IsPaused() const = 0;

	virtual bool LoadHitFile(cIGZString const& path) = 0;
	virtual bool UnloadHitFile(cIGZString const& path) = 0;

	virtual bool RegisterTrackDataBlock(cIHitTrackDataBlock* pBlock) = 0;
	virtual bool RemoveTrackDataBlock(cIHitTrackDataBlock* pBlock) = 0;
	virtual bool GetTrackDataBlockAndOffset(uint32_t id, cIHitTrackDataBlock** ppBlock, uint32_t& offsetOut) = 0;
	virtual int32_t TrackDataEntryPoint(uint32_t id) const = 0;

	// Creates a new track player and queries it for riid.
	virtual bool CreateTrackPlayer(uint32_t riid, void** ppvObj) = 0;
	virtual bool GetHitList(uint32_t group, uint32_t unused, void** ppHitList) = 0;

	virtual bool AllocChannel(uint32_t unused, void** ppChannel) = 0;
	virtual void FreeChannel(cIGZSnd* pChannel) = 0;

	virtual bool RegisterSem(cIHitSem* pSem) = 0;
	virtual bool RemoveSem(uint32_t id) = 0;
	virtual bool RemoveAllSems() = 0;
	virtual bool GetSem(uint32_t id, uint32_t riid, void** ppvObj) const = 0;
	virtual cIHitSem* GetSem(uint32_t id) = 0;
	virtual uint32_t NumSems() = 0;
	virtual cIHitSem* GetSemAt(uint32_t index) = 0;

	// Returns a uniform value from min up to but not including max.
	virtual int32_t Random(int32_t max, int32_t min) = 0;
	virtual int32_t Callback(int32_t arg1, int32_t arg2) = 0;

	virtual void SetTrackFlowErrorHandler(TrackFlowErrorHandler pHandler) = 0;
	virtual void HandleTrackFlowError(cIHitTrackPlayer* pPlayer, char* szMessage) = 0;

	virtual bool SetRegisterVal(int32_t reg, int32_t value) = 0;
	virtual int32_t GetRegisterVal(int32_t reg) const = 0;

	// Forwards to the registered cIHitAppDataRequestHandler.
	virtual bool GetSourceDataField(int32_t source, int32_t field, int32_t* pValueOut) const = 0;
	virtual bool RegisterSourceDataRequestHandler(cIHitAppDataRequestHandler* pHandler) = 0;
	virtual cIHitAppDataRequestHandler* GetSourceDataRequestHandler() = 0;

	virtual int32_t ControlGroup(int32_t type) = 0;
	virtual bool AddToControlGroup(int32_t type, int32_t group) = 0;

	virtual void SetSequenceGroupSnd(uint32_t group, cIGZSnd* pSnd) = 0;
	virtual bool GetSequenceGroupSnd(uint32_t group, cIGZSnd** ppSnd) = 0;

	virtual void DuckMapSetSndobPri(cIGZSnd const* pSnd, int32_t priority) = 0;
	virtual int32_t DuckMapSndobPri(cIGZSnd const* pSnd) = 0;
	virtual int32_t DuckMapMaxPri() = 0;
	virtual void DuckMapRemoveAll() = 0;

	virtual void AddDBSegment(uint32_t id, cIGZPersistDBSegment* pSegment) = 0;
	virtual bool FindDBSegment(uint32_t id, uint32_t riid, void** ppvObj) = 0;
	virtual void RemoveDBSegment(uint32_t id) = 0;

	virtual bool AddTypeToGroupAssociation(uint32_t type, uint32_t group) = 0;
};
