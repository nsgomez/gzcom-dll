#pragma once
#include "cIGZUnknown.h"
#include "cISC4BuildingDevelopmentSimulator.h"

template <typename T> class cISC4SimGrid;

class cISC4CommercialSimulator : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual cISC4SimGrid<uint8_t>* GetProximityMap(cISC4BuildingDevelopmentSimulator::DeveloperType) = 0;
};