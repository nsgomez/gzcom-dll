#pragma once
#include "cIGZUnknown.h"

class cISC4Occupant;

class cISC4FoundationOccupant : public cIGZUnknown
{
	public:
		virtual cISC4Occupant* AsOccupant(void) = 0;

		virtual uint32_t GetFoundationType(void) = 0;
		virtual bool SetFoundationType(uint32_t) = 0;

		virtual float GetMaxHeight(void) = 0;
		virtual bool SetMaxHeight(float) = 0;

		virtual bool SetSize(float const*) = 0;

		virtual int32_t GetUsage(void) = 0;
		virtual bool SetUsage(int32_t) = 0;

		virtual int32_t GetOrientation(void) = 0;
		virtual bool SetOrientation(int32_t) = 0;
};