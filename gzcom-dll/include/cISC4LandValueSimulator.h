#pragma once
#include "cIGZUnknown.h"

template<typename T> class cISC4SimGrid;

class cISC4LandValueSimulator : public cIGZUnknown
{
public:
	enum class LandValueType : uint32_t
	{
		Low = 1,
		Medium = 2,
		High = 3
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual LandValueType GetLandValueType(int32_t x, int32_t z) = 0;
	virtual uint8_t GetLandValue(int32_t x, int32_t z) = 0;

	virtual cISC4SimGrid<uint8_t>* GetIntrinsicLandValueMap() = 0;
	virtual cISC4SimGrid<uint8_t>* GetTotalLandValueMap() = 0;
	virtual cISC4SimGrid<float>* GetSlopeMap() = 0;
	virtual uint8_t GetAverageLandValue() = 0;

	virtual float GetModeAltitude() = 0;
};
