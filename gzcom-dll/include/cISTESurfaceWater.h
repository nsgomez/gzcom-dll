#pragma once
#include "cIGZUnknown.h"

class cISC4Lot;
template<typename T> class cISC4SimGrid;
class cS3DVector3;

class cISTESurfaceWater : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual float GetWaterDepthAtVertex(int32_t index) const = 0;
	virtual float GetWaterDepthForCell(int32_t x, int32_t z) const = 0;

	virtual bool IsNavigable(int32_t param_1, int32_t param_2, int32_t param_3, cISC4Lot* param_4) const = 0;
	virtual bool IsNavigable(cS3DVector3 param_1, int32_t param_2, cISC4Lot* param_3) const = 0;

	virtual cISC4SimGrid<uint16_t>* GetBodyOfWaterMap() const = 0;
	virtual float AltitudeAtWhichFloodingWillOccur(int32_t x, int32_t z) = 0;
	virtual float GetWaterVelocity(int32_t x, int32_t z) = 0;
	virtual int32_t GetWaterType(int32_t x, int32_t z) = 0;
	virtual bool HasDraftClearance(int32_t x, int32_t z) = 0;
};