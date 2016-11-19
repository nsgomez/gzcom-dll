#pragma once
#include "cIGZUnknown.h"

class cISC4Occupant;

class cISC4LandfillOccupant : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual cISC4Occupant* AsOccupant(void) = 0;

		virtual bool SetTileID(uint32_t) = 0;

		virtual int32_t GetOrientation(void) = 0;
		virtual bool SetOrientation(int32_t) = 0;

		virtual bool IsEmptyLandfillTile(void) = 0;
};