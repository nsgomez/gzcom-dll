#pragma once
#include "cIGZUnknown.h"
#include "cRZAutoRefCount.h"
#include <map>

class cIGZString;
class cISC4Advice;
class cISC4AdviceSubject;
class cISC4Advisor;
class cISCLua; // TODO: Implement me (it's long!)

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