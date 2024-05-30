#pragma once
#include "cIGZUnknown.h"
#include "SC4String.h"

class cIGZString;

class cISC4CivicBuildingSimulator : public cIGZUnknown
{
public:
	enum eConditionalBuildingStatus : uint8_t
	{
		ConditionalBuildingStatusNone = 0,
		ConditionalBuildingStatusHidden = 1,
		ConditionalBuildingStatusAvailable = 2,
		ConditionalBuildingStatusAdvisorEventDataSet = 4
	};

	class ConditionalBuildingStatus
	{
	public:
		eConditionalBuildingStatus status;
		uint16_t buildingCount;
		SC4String itemToolTip;
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool IsBuildingExcluded(uint32_t buildingID) = 0;

	virtual ConditionalBuildingStatus* GetConditionalBuildingStatus(uint32_t buildingID) const = 0;
	virtual bool UpdateConditionalBuildingStatus(uint32_t buildingID, ConditionalBuildingStatus* status) = 0;

	virtual uint32_t GetLandmarkCount() = 0;
};

