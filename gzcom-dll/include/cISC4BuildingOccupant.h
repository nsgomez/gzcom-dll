#pragma once
#include "cIGZUnknown.h"

class cIGZString;
class cISC4Occupant;
class SC4Percentage;

class cISC4BuildingOccupant : public cIGZUnknown
{
	public:
		enum class PurposeType : uint32_t
		{
			None = 0,
			Residence = 1,
			Services = 2,
			Office = 3,
			Tourism = 4,
			Agriculture = 5,
			Processing = 6,
			Manufacturing = 7,
			HighTech = 8,
			Other = 9
		};

		enum class WealthType : uint32_t
		{
			None = 0,
			Low = 1,
			Medium = 2,
			High = 3
		};

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