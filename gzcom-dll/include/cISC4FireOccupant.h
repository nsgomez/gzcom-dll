#pragma once
#include "cIGZUnknown.h"

class cISC4Occupant;

class cISC4FireOccupant : public cIGZUnknown
{
	public:
		virtual cISC4Occupant* AsOccupant(void) = 0;

		virtual bool SetTarget(cISC4Occupant*) = 0;
		virtual cISC4Occupant* GetTarget(void) = 0;

		virtual uint32_t GetStage(void) = 0;
		virtual uint32_t GetMaxStage(void) = 0;
		virtual bool SetStage(uint32_t) = 0;

		virtual uint32_t GetCounter(void) = 0;
		virtual bool SetCounter(uint32_t) = 0;

		virtual bool GetHosed(void) = 0;
		virtual bool SetHosed(int32_t) = 0;
		
		virtual uint32_t GetFamily(void) = 0;
		virtual bool SetFamily(uint32_t) = 0;

};