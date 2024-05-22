#pragma once
#include "cIGZUnknown.h"

template <typename T> class cISC4SimGrid;
template <typename T> class SC4Point;

class cISC4AuraSimulator : public cIGZUnknown
{
public:
	enum eStrikeBuster : uint32_t
	{
		StrikeBusterAll = 0,
		StrikeBusterPolice = 1,
		StrikeBusterFire = 2,
		StrikeBusterHealth = 3,
		StrikeBusterSchool = 4,
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual int8_t GetAuraValue(int32_t x, int32_t z) = 0;

	virtual void AddTransientEffect(float unknown1, float param_2, float param_3, float param_4) = 0;
	virtual void AddTransientEffect(float param_1, float param_2, uint32_t transientAuraEffect) = 0;

	virtual int8_t GetMayorRating() const = 0;
	virtual int8_t GetMaxMayorRating(SC4Point<long>& location) const = 0;
	virtual int8_t GetMinMayorRating(SC4Point<long>& location) const = 0;

	virtual void BustStrike(eStrikeBuster type) = 0;

	virtual cISC4SimGrid<int8_t>* GetAuraGrid() = 0;
	virtual cISC4SimGrid<int8_t>* GetTransientAuraGrid() = 0;

	virtual cISC4SimGrid<int16_t>* GetParkMap() const = 0;
	virtual cISC4SimGrid<int16_t>* GetLandmarkMap() const = 0;
};
