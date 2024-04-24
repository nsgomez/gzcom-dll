#pragma once
#include "cIGZUnknown.h"

class cIGZString;

class cISC4CivicBuildingSimulator : public cIGZUnknown
{
public:
	class ConditionalBuildingStatus
	{
	public:
		int8_t status;
		int8_t statusPadding; // Padding for alignment.
		uint16_t buildingCount;
		intptr_t unknown1; // Possibly a pointer to a cIGZString, but it crashes when accessing any method
		intptr_t unknown2; // std::string, null/0 if status == -4
		intptr_t unknown3;
		intptr_t unknown4;
		intptr_t unknown5;
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool IsBuildingExcluded(uint32_t buildingID) = 0;

	virtual ConditionalBuildingStatus* GetConditionalBuildingStatus(uint32_t buildingID) = 0;
	virtual bool UpdateConditionalBuildingStatus(uint32_t buildingID, ConditionalBuildingStatus* status) = 0;

	virtual uint32_t GetLandmarkCount() = 0;
};

