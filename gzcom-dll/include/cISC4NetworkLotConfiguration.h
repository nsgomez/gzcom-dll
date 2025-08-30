#pragma once
#include "cIGZUnknown.h"

class cIGZString;
class cSC4LotConfigurationObject;
template <typename T> class SC4Vector;

class cISC4NetworkLotConfiguration : public cIGZUnknown
{
public:
	virtual SC4Vector<cSC4LotConfigurationObject>* GetObjectArray() const = 0;
	virtual uint32_t GetID() const = 0;
	virtual void GetName(cIGZString& name) const = 0;
	virtual uint32_t GetNetworkPieceId() const = 0;
};