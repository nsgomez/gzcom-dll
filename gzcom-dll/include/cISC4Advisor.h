/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4Advisor.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2024, 2025 Nicholas Hayes
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
#include "cRZAutoRefCount.h"
#include <utility>

class cIGZString;
class cISC4Advice;
class cISC4AdviceSubject;
class SC4String;

template <typename T> class SC4List;

class cISC4Advisor : public cIGZUnknown
{
	public:
		virtual bool Init(int32_t dwUnknown) = 0;
		virtual bool Shutdown(void) = 0;

		virtual int32_t GetID(void) const = 0;

		virtual SC4String* GetName(void) const = 0;
		virtual bool SetName(cIGZString const& szName) = 0;

		virtual SC4String* GetPersonalName(void) const = 0;
		virtual bool SetPersonalName(cIGZString const& szName) = 0;

		virtual SC4List<std::pair<int32_t, cRZAutoRefCount<cISC4Advice>>>& GetCurrentAdvices(void) const = 0;
		virtual SC4List<std::pair<int32_t, cRZAutoRefCount<cISC4Advice>>>& GetCurrentAdvices(void) = 0;

		virtual cISC4Advice* GetAdviceByGUID(int32_t dwGUID) = 0;
		virtual cISC4Advice* GetAdviceBySessionID(int32_t dwSessionID) const = 0;

		virtual bool Simulate(int32_t dwUnknown) = 0;

		virtual int32_t GetHeadAnimCount(bool bUnknown) = 0;

		virtual bool SetHeadAnim(bool bUnknown, int32_t dwAnimID) = 0;
		virtual int32_t GetHeadAnimID(int32_t dwUnknown) = 0;

		virtual bool PushEvent(int32_t dwGUID, cISC4AdviceSubject* pSubject) = 0;

		virtual bool CommandWouldTrigger(uint32_t dwCommandID) = 0;

		virtual bool RetireAdvice(cISC4Advice* pAdvice) = 0;
};