#pragma once
#include "cIGZUnknown.h"

class cISC4Lot;
class cISC4Occupant;

class cISC4LotRetainingWallOccupant : public cIGZUnknown
{
	public:
		virtual cISC4Occupant* AsOccupant(void) = 0;

		virtual bool SetSize(float const*) = 0;
		
		virtual cISC4Lot* GetLot(void) = 0;
		virtual bool SetLot(cISC4Lot*) = 0;

		virtual int32_t GetEdgeFlags(void) = 0;
		virtual bool SetEdgeFlags(int32_t) = 0;

		virtual bool GetEdgeHashArray(int32_t*) = 0;
		virtual bool SetEdgeHashArray(int32_t const*) = 0;

		virtual uint32_t GetRetainingWallType(void) = 0;
		virtual bool SetRetainingWallType(uint32_t) = 0;
};