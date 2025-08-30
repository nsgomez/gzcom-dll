#pragma once
#include "cIGZUnknown.h"

class cISC4NetworkOccupant;
class cSC4LotConfigurationObject;
template <typename T> class SC4Vector;

class cISC4NetworkLot : public cIGZUnknown
{
public:
	virtual cISC4NetworkOccupant* GetNetworkOccupant() const = 0;
	virtual uint32_t GetLotConfigurationObjectCount() = 0;
	virtual SC4Vector<cSC4LotConfigurationObject>* GetLotConfigurationObjectArray() = 0;
};