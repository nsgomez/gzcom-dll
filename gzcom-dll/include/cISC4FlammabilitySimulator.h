#pragma once
#include "cIGZUnknown.h"

template <typename T> class cISC4SimGrid;

class cISC4FlammabilitySimulator : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual cISC4SimGrid<uint8_t>* GetFlammabilityGrid() = 0;
	virtual bool IsCellFlammable(int x, int z) = 0;
	virtual bool GetFlammabilityHotspot(uint8_t* param_1, int* param_2, int* param_3) = 0;
	virtual uint8_t GetAverageFlammability() = 0;
};