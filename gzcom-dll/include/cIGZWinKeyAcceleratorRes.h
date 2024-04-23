#pragma once
#include "cIGZUnknown.h"

class cIGZWinKeyAccelerator;

static const uint32_t kGZIID_cIGZWinKeyAcceleratorRes = 0x42E3EA4B;

class cIGZWinKeyAcceleratorRes : public cIGZUnknown
{
public:
	virtual bool RegisterResources(cIGZWinKeyAccelerator* keyAccelerator) = 0;
};