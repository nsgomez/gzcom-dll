#pragma once
#include "cIGZUnknown.h"

class cIGZString;
class cISC4Occupant;
class SC4Percentage;

class cISC4BuildingOccupant : public cIGZUnknown
{
	public:
		virtual cISC4Occupant* AsOccupant(void) = 0;

		virtual uint32_t GetBuildingType(void) = 0;
		virtual cISC4BuildingOccupant* SetBuildingType(uint32_t) = 0;

		virtual int32_t GetBuildingAge(void) = 0;
		virtual void SetBuildingAge(int32_t) = 0;

		virtual bool SetBoundingBox(float const* fTopLeft, float const* fBottomRight) = 0;

		virtual SC4Percentage* GetCompletionPercent(void) = 0;
		virtual bool SetCompletionPercent(SC4Percentage const&) = 0;

		virtual intptr_t GetBuildingProfile(void) = 0;
		virtual intptr_t GetBuildingName(void) = 0;
		virtual intptr_t GetExemplarName(void) = 0;
		
		virtual int32_t GetOrientation(void) = 0;
		virtual bool SetOrientation(int32_t) = 0;

		virtual bool IsLit(void) = 0;
		virtual bool SetLit(bool) = 0;

		virtual bool SetName(cIGZString&) = 0;
		virtual bool GetName(cIGZString&) = 0;
};