#pragma once
#include "cIGZUnknown.h"

class cISC4PowerPoleOccupant;

class cISC4PowerLineOccupant : public cIGZUnknown
{
	public:
		virtual bool GetConnectedPoles(cISC4PowerLineOccupant*&, cISC4PowerPoleOccupant*&, bool&) = 0;
		virtual bool SetConnectedPoles(cISC4PowerPoleOccupant*, cISC4PowerPoleOccupant*, bool) = 0;

		virtual bool GetCell(uint32_t&, uint32_t&) = 0;

		virtual bool IsPreview(void) = 0;
		virtual bool SetPreview(bool) = 0;
};