#pragma once
#include "cIGZUnknown.h"

// Mostly guessed as to what this interface includes. Not tested or reliable.
class cIGZSystemService : public cIGZUnknown
{
	public:
		virtual uint32_t GetServiceID(void) = 0;
		virtual cIGZSystemService* SetServiceID(uint32_t dwServiceId) = 0;

		virtual int32_t GetServicePriority(void) = 0;
		virtual bool IsServiceRunning(void) = 0;
		virtual cIGZSystemService* SetServiceRunning(bool bRunning) = 0;

		virtual bool OnIdle(void) = 0;
		virtual bool OnTick(void) = 0;
		virtual int32_t GetServiceTickPriority(void) = 0;
};