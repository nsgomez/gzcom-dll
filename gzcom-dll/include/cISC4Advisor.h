#pragma once
#include "cIGZUnknown.h"
#include "cRZAutoRefCount.h"
#include <list>

class cIGZString;
class cISC4Advice;
class cISC4AdviceSubject;

class cISC4Advisor : public cIGZUnknown
{
	public:
		virtual bool Init(int32_t dwUnknown) = 0;
		virtual bool Shutdown(void) = 0;

		virtual int32_t GetID(void) const = 0;
		
		virtual char* GetName(void) const = 0;
		virtual bool SetName(cIGZString const& szName) = 0;

		virtual char* GetPersonalName(void) const = 0;
		virtual bool SetPersonalName(cIGZString const& szName) = 0;

		virtual std::list<std::pair<int32_t, cRZAutoRefCount<cISC4Advice>>>& GetCurrentAdvices(void) const = 0;
		virtual std::list<std::pair<int32_t, cRZAutoRefCount<cISC4Advice>>>& GetCurrentAdvices(void) = 0;

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