#pragma once
#include "cIGZUnknown.h"
#include <vector>

class cIGZDate;
class cIGZMessageTarget2;
class cIGZString;
class SC4String;

class cISC4Simulator : public cIGZUnknown
{
	public:
		// These values correspond to the kSC4MessageSim* messages starting with
		// kSC4MessageSimBegin/OneShot and ending with kSC4MessageSimIdle.
		enum eAgentType : uint32_t
		{
			AgentTypeSimBegin = 0,
			AgentTypeSimEmergencyTime = 1,
			AgentTypeSimNewMinute = 2,
			AgentTypeSimNewHour = 3,
			AgentTypeSimNewDay = 4,
			AgentTypeSimNewWeek = 5,
			AgentTypeSimNewMonth = 6,
			AgentTypeSimNewYear = 7,
			AgentTypeSimSpecificDay = 8,
			AgentTypeSimSpecificTime = 9,
			AgentTypeSimIdle = 10,
		};

		enum eAgentFlags : uint32_t
		{
			AgentFlagNone = 0,
			AgentFlagEnabledForUnestablishedCities = 1,
			AgentFlagEnabledForEstablishedCities = 2
		};

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool GetSimStartDate(cIGZDate& sDate) = 0;

		virtual cIGZDate* GetSimDate(void) = 0;
		virtual void GetSimDate(long& year, long& month, long& day, long& dayOfYear, long& weekDay) = 0;
		virtual int32_t GetSimDateNumber(void) = 0;

		virtual bool Pause(void) = 0;
		virtual bool HiddenPause(void) = 0;
		virtual bool EmergencyPause(void) = 0;

		virtual bool Resume(void) = 0;
		virtual bool HiddenResume(void) = 0;
		virtual bool EmergencyResume(void) = 0;

		virtual bool IsPaused(void) = 0;
		virtual bool IsHiddenPaused(void) = 0;
		virtual bool IsEmergencyPaused(void) = 0;
		virtual bool IsAnyPaused(void) = 0;

		virtual bool AddAgent(cIGZMessageTarget2* pAgent, eAgentType agentType, cIGZString const& szAgentName, eAgentFlags flags) = 0;
		virtual bool RemoveAgent(cIGZMessageTarget2* pAgent, eAgentType agentType) = 0;
		virtual bool RemoveAgent(cIGZMessageTarget2* pAgent) = 0;
		virtual bool RemoveAllAgents(void) = 0;
		virtual bool RemoveAllAgents(eAgentType agentType) = 0;
		virtual bool EnumerateAgentsByName(std::vector<SC4String>& sAgents) = 0;
		virtual bool GetAgentEnabled(cIGZString const& szAgentName) = 0;
		virtual bool SetAgentEnabled(cIGZString const& szAgentName, bool bEnabled) = 0;

		virtual int32_t GetSimSpeed(void) = 0;
		virtual bool SetSimSpeed(int32_t lSpeed) = 0;

		virtual int32_t GetSimTime(void) = 0;
		virtual bool SetSimTime(int32_t lTime) = 0;

		virtual bool SetMaxMillisecondsPerTick(uint32_t dwTime) = 0;

		virtual float GetAnimationTimeDilation(void) = 0;

		virtual bool SetCityEstablished(bool bEstablished) = 0;
};