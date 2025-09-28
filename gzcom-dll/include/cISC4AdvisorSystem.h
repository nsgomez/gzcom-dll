/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4AdvisorSystem.h
 *
 * Copyright (C) 2016 Nelson Gomez
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
#include "cRZAutoRefCount.h"
#include <map>

class cIGZString;
class cISC4Advice;
class cISC4AdviceSubject;
class cISC4Advisor;
class cISCLua;

class cISC4AdvisorSystem : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool AddAdvisor(cISC4Advisor* pAdvisor) = 0;
		virtual bool RemoveAdivsor(int32_t dwAdvisorID) = 0;
		virtual cISC4Advisor* GetAdvisor(int32_t dwAdvisorID) = 0;
		virtual std::map<int32_t, cRZAutoRefCount<cISC4Advisor>>& GetAdvisors(void) = 0;

		virtual intptr_t GetRandom(void) = 0; // This points to an RZRandom that we can't recreate yet
		virtual cISCLua* GetScriptingContext(void) = 0;

		virtual bool DoLink(cIGZString const& szUnknown) = 0;

		virtual bool SetGlobalValue(char const* pszTuningVar, double dValue) = 0;
		virtual bool SetGlobalValue(char const* pszTuningVar, cIGZString* pszValue) = 0;
		virtual bool SetLocalValue(char const* pszTuningVar, double dValue, cISC4AdviceSubject* pSubject) = 0;

		virtual bool PushEvent(int32_t dwEventId, cISC4AdviceSubject* pSubject) = 0;
		virtual bool SubscribeToEvent(int32_t dwEventId, cISC4Advisor* pAdvisor) = 0;
		virtual bool UnsubscribeFromEvent(int32_t dwEventId, cISC4Advisor* pAdvisor) = 0;

		virtual bool PushContextAdvice(cISC4Advice* pAdvice) = 0;
		virtual cISC4Advice* PopContextAdvice(void) = 0;
		virtual cISC4Advice* GetContextAdvice(void) = 0;

		virtual int32_t GetAdvicePopupPriorityThreshold(void) = 0;
		virtual int32_t GetDataTag(int32_t dwUnknown) = 0;
};