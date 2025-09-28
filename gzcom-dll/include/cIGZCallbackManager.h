/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZCallbackManager.h
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

class cIGZCallbackManager : public cIGZUnknown
{
public:
	typedef void(*CallbackFn)(void* state);

	virtual uint32_t Register(CallbackFn callback, void* state, uint32_t intervalInMilliseconds, bool oneShot, bool unknown) = 0;
	virtual bool Unregister(uint32_t id) = 0;

	virtual bool SetCallbackThreadPriority(int32_t priority) = 0;
	virtual int32_t GetCallbackThreadPriority() = 0;
	virtual uint32_t GetCallbackThreadID() = 0;
};