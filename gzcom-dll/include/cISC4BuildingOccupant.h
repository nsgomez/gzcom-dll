#pragma once
#include "cIGZUnknown.h"
#include "cS3DVector3.h"

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

		class BuildingProfile
		{
			// These flags are probably intended as a quick way for the game to
			// identify buildings that are part of the specified occupant groups.
			enum BuildingCategoryFlags : uint32_t
			{
				BuildingCategoryFlagNone                  = 0,
				BuildingCategoryFlagResidential           = 0x00000001, // 0x1000
				BuildingCategoryFlagCommercial            = 0x00000002, // 0x1001
				BuildingCategoryFlagIndustrial            = 0x00000004, // 0x1002
				BuildingCategoryFlagTransportation        = 0x00000008, // 0x1003
				BuildingCategoryFlagUtility               = 0x00000010, // 0x1004
				BuildingCategoryFlagCivic                 = 0x00000020, // 0x1005
				BuildingCategoryFlagPark                  = 0x00000040, // 0x1006
				BuildingCategoryFlagRail                  = 0x00000080, // 0x1300
				BuildingCategoryFlagBus                   = 0x00000100, // 0x1301
				BuildingCategoryFlagSubway                = 0x00000200, // 0x1302
				BuildingCategoryFlagPower                 = 0x00000400, // 0x1400
				BuildingCategoryFlagWater                 = 0x00000800, // 0x1401
				BuildingCategoryFlagLandfill              = 0x00001000, // 0x1402
				BuildingCategoryFlagPolice                = 0x00002000, // 0x1500
				BuildingCategoryFlagJail                  = 0x00004000, // 0x1501
				BuildingCategoryFlagFire                  = 0x00008000, // 0x1502
				BuildingCategoryFlagSchool                = 0x00010000, // 0x1503
				BuildingCategoryFlagCollege               = 0x00020000, // 0x1504
				BuildingCategoryFlagLibrary               = 0x00040000, // 0x1505
				BuildingCategoryFlagMuseum                = 0x00080000, // 0x1506
				BuildingCategoryFlagHealth                = 0x00100000, // 0x1507
				BuildingCategoryFlagAirport               = 0x00200000, // 0x1508
				BuildingCategoryFlagSeaport               = 0x00400000, // 0x1509
				BuildingCategoryFlagLandmark              = 0x00800000, // 0x150A
				BuildingCategoryFlagReward                = 0x01000000, // 0x150B
				BuildingCategoryFlagStyleChicago          = 0x02000000, // 0x2000
				BuildingCategoryFlagStyleNewYork          = 0x04000000, // 0x2001
				BuildingCategoryFlagStyleHouston          = 0x08000000, // 0x2002
				BuildingCategoryFlagIndustryAgriculture   = 0x10000000, // 0x3000
				BuildingCategoryFlagIndustryDirty         = 0x20000000, // 0x3001
				BuildingCategoryFlagIndustryManufacturing = 0x40000000, // 0x3002
			};

			PurposeType           purpose;
			WealthType            wealth;
			uint16_t              currentOccupantCapacity;
			intptr_t              capacitiesSatisfied[4]; // A vector<map<uint32_t, uint16_t>>
			BuildingCategoryFlags buildingCategoryFlags;
			cS3DVector3           occupantSize;
			int64_t               plopCost;
			int64_t               budgetItemCost;
		};

		virtual cISC4Occupant* AsOccupant(void) = 0;

		virtual uint32_t GetBuildingType(void) = 0;
		virtual cISC4BuildingOccupant* SetBuildingType(uint32_t) = 0;

		virtual int32_t GetBuildingAge(void) = 0;
		virtual void SetBuildingAge(int32_t) = 0;

		virtual bool SetBoundingBox(float const* fTopLeft, float const* fBottomRight) = 0;

		virtual SC4Percentage* GetCompletionPercent(void) = 0;
		virtual bool SetCompletionPercent(SC4Percentage const&) = 0;

		virtual BuildingProfile& GetBuildingProfile(void) const = 0;
		virtual cIGZString* GetBuildingName(void) = 0;
		virtual cIGZString* GetExemplarName(void) = 0;

		virtual int32_t GetOrientation(void) = 0;
		virtual bool SetOrientation(int32_t) = 0;

		virtual bool IsLit(void) = 0;
		virtual bool SetLit(bool) = 0;

		virtual bool SetName(cIGZString&) = 0;
		virtual bool GetName(cIGZString&) = 0;
};