#pragma once
#include "cIGZUnknown.h"

class cISC4Occupant;
class cSC4StaticFloraData;

class cISC4FloraOccupant : public cIGZUnknown
{
	public:
		virtual cISC4Occupant* AsOccupant(void) = 0;

		virtual uint32_t GetFloraType(void) = 0;
		virtual bool SetFloraType(uint32_t) = 0;

		virtual uint32_t GetBirthDate(void) = 0;
		virtual bool SetBirthDate(uint32_t) = 0;

		virtual uint32_t GetLastSeedingDate(void) = 0;
		virtual bool SetLastSeedingDate(uint32_t) = 0;

		virtual int32_t GetState(void) = 0;
		virtual bool SetState(int32_t) = 0;

		virtual uint32_t GetOrientation(void) = 0;
		virtual bool SetOrientation(uint32_t) = 0;

		virtual bool SetStaticFloraData(cSC4StaticFloraData*) = 0;
};