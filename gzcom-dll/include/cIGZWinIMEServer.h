/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZWinIMEServer.h
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

static const uint32_t GZIID_cIGZWinIMEServer = 0x2ac44ae7;

class cIGZWinIMEServer : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;
	virtual bool IsIMEAvailable() const = 0;
	virtual bool GetEnabled() const = 0;
	virtual void SetEnabled(bool enabled) = 0;
	virtual bool GetCompositionEnabled() const = 0;
	virtual bool SetCompositionEnabled(bool enabled) = 0;
	virtual bool GetCompositionActive() const = 0;
	virtual bool SetCompositionActive(bool active) const = 0;
	// Points at the server's own composition string state. Its layout is not
	// declared in the SDK yet.
	virtual void* GetCompositionStringData() = 0;
	virtual bool SetCompositionString(uint16_t* text, uint32_t length) = 0;
	virtual bool GetCandidateListActive() const = 0;
	virtual bool SetCandidateListActive(bool active) const = 0;
	// Points at the server's own candidate list state. Its layout is not
	// declared in the SDK yet.
	virtual void* GetCandidateListData() = 0;
	// Fails when the index is past the end of the candidate list.
	virtual bool SetCandidateListSelection(uint32_t index) = 0;
};
