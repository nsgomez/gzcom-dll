#pragma once
#include "cIGZUnknown.h"

class SC4Percentage;

class cISC4Demand : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;
	virtual bool SimulationBegin() = 0;

	virtual uint32_t GetId() const = 0;
	virtual bool SetId(uint32_t id) = 0;

	virtual float QuerySupplyValue() const = 0;
	virtual float QueryDemandValue() const = 0;
	virtual float QueryNewSupply() const = 0;
	virtual float QueryNewDemand() const = 0;
	virtual float QueryActiveDemandValue() const = 0;
	virtual float QueryEconomyModifier() const = 0;
	virtual float QueryActiveDemandMax() const = 0;
	virtual float QueryActiveDemandMin() const = 0;

	virtual bool AddToSupplyValue(float value) = 0;
	virtual bool AddToDemandValue(float value) = 0;

	virtual bool SetSupplyValue(float value) = 0;
	virtual bool SetDemandValue(float value) = 0;

	virtual bool SetActiveDemandMax(float value) = 0;
	virtual bool SetActiveDemandMin(float value) = 0;

	virtual float GetEconomyModifier() const = 0;
	virtual bool SetEconomyModifier(float value) = 0;

	virtual float GetTaxModifier() const = 0;
	virtual bool SetTaxModifier(float value) = 0;

	virtual SC4Percentage* GetDemandCap() const = 0;
	virtual bool SetDemandCap(const SC4Percentage& demandCap) = 0;

	virtual uint32_t GetRegionUse() = 0;
	virtual bool SetRegionUse(uint32_t param_1) = 0;

	virtual float EndOfCycle() = 0;

	virtual void DebugLockValue(float value) = 0; // no-op
	virtual void DebugUnlockValue() = 0; // no-op
	virtual bool DebugIsValueLocked() = 0; // returns false
};
