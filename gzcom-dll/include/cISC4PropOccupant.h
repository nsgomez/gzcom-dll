#pragma once
#include "cIGZUnknown.h"
#include "cS3DVector3.h"

class cIGZDate;
class cISC4Occupant;
class cSC4PropPlacementProperties;

static const uint32_t GZIID_cISC4PropOccupant = 0xe9793a65;

class cISC4PropOccupant : public cIGZUnknown
{
public:
	class PropProfile
	{
		uint32_t occupantClassID;
		cS3DVector3 occupantSize;
		uint32_t requesterSatisfaction;
		uint8_t wealth;
		uint32_t crimeIncidentID;
	};

	typedef uint8_t tPropTimerMask;

	virtual cISC4Occupant* AsOccupant() = 0;

	// Both floats are an array of 3 values.
	virtual void SetBoundingBox(float const* unknown1, float const* unknown2) = 0;

	virtual cSC4PropPlacementProperties* GetPropPlacementProperties() = 0;
	virtual void SetPropPlacementProperties(cSC4PropPlacementProperties*) = 0;

	virtual uint32_t GetPropType() const = 0;
	virtual void SetPropType(uint32_t type) = 0;

	virtual int32_t GetOrientation() const = 0;
	virtual bool SetOrientation(int32_t unknown1) = 0;

	virtual void SetState(uint32_t unknown1) = 0;
	virtual uint8_t GetState() const = 0;

	virtual void SetTimeOfDayRange(float unknown1, float unknown2) = 0;
	virtual void GetTimeOfDayRange(float& unknown1, float& unknown2) const = 0;
	virtual void SetSimulatorDateRange(uint32_t unknown1, uint32_t unknown2, uint8_t unknown3, uint8_t unknown4) = 0;
	virtual void TickSimulatorDate(cIGZDate const& unknown1) = 0;

	virtual void SetRandomChance(uint8_t unknown1) = 0;
	virtual uint8_t GetRandomChance() const = 0;

	virtual uint8_t GetPropTimerBitfield() const = 0;
	virtual bool GetPropTimerState(tPropTimerMask mask) const = 0;
	virtual void SetPropTimerState(tPropTimerMask mask, bool unknown2) = 0;

	virtual uint8_t GetPropUsage() const = 0;
	virtual void SetPropUsage(uint8_t usage) = 0;
};