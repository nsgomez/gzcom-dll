#pragma once
#include "cIGZUnknown.h"

class cIGZString;
class cISC4AdviceSubject;

class cISC4Advice : public cIGZUnknown
{
	public:
		virtual bool Init(int32_t dwUnknown) = 0;
		virtual bool Shutdown(void) = 0;
		virtual bool Clone(cISC4Advice** ppAdvice) = 0;
		
		virtual int32_t GetMood(void) = 0;
		virtual int32_t GetPriority(void) = 0;
		virtual intptr_t GetTrigger(void) = 0;
		virtual char* GetTriggerString(void) = 0;
		virtual uint32_t GetGUID(void) = 0;
		
		virtual int32_t GetAdvisorID(void) = 0;
		virtual cISC4Advice* SetAdvisorID(int32_t dwAdvisorID) = 0;

		virtual int32_t GetSessionID(void) = 0;
		
		virtual bool SetFlags(int32_t dwFlags, bool bStatus) = 0;
		virtual bool CheckFlags(int32_t dwFlags) = 0;
		
		virtual int32_t GetFrequencyInDays(void) = 0;
		virtual int32_t GetTimeOutInDays(void) = 0;
		
		virtual char* GetTextTitle(void) = 0;
		virtual int32_t GetTextTitleGUID(void) = 0;
		
		virtual char* GetTextMessage(void) = 0;
		virtual int32_t GetTextMessageGUID(void) = 0;

		virtual bool DoLink(cIGZString const& szLinkName) = 0;
		
		virtual intptr_t NotifyGlobalEffectTriggerChanged(void) = 0;

		virtual bool SetEventSubject(cISC4AdviceSubject* pSubject) = 0;
		virtual cISC4AdviceSubject* GetEventSubject(void) = 0;

		virtual int32_t GetEventID(void) = 0;
		virtual int32_t GetCommandID(void) = 0;
		
		virtual bool UpdateText(void) = 0;
};