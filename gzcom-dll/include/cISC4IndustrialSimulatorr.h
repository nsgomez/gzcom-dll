#pragma once
#include "cIGZUnknown.h"

class cISC4IndustrialSimulator : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;
};