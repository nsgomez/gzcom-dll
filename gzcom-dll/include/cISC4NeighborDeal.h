#pragma once
#include "cIGZUnknown.h"

class cIGZDate;
class cISC4RegionalCity;

class cISC4NeighborDeal : public cIGZUnknown
{
public:
	virtual void SetRegionCellOnCitySideOfConnection(int32_t x, int32_t z) = 0;
	virtual void GetRegionCellOnCitySideOfConnection(int32_t& x, int32_t& z) const = 0;
	virtual void SetRegionCellOnOtherSideOfConnection(int32_t x, int32_t z) = 0;
	virtual void GetRegionCellOnOtherSideOfConnection(int32_t& x, int32_t& z) const = 0;

	virtual cISC4RegionalCity* GetCityOnOtherSideOfConnection() const = 0;

	virtual int32_t GetType() const = 0;
	virtual void SetType(int32_t type) = 0;

	virtual int32_t GetAmount() const = 0;
	virtual void SetAmount(int32_t param_1) = 0;
	virtual int32_t GetLastAmount() const = 0;
	virtual void SetLastAmount(int32_t param_1) = 0;
	virtual int32_t GetLastIncAmount() const = 0;
	virtual void SetLastIncAmount(int32_t param_1) = 0;
	virtual int32_t GetIncAmount() const = 0;
	virtual void SetIncAmount(int32_t param_1) = 0;
	virtual int32_t GetIncAmount2() const = 0;
	virtual void SetIncAmount2(int32_t param_1) = 0;
	virtual int32_t GetAmountUsed() const = 0;
	virtual void SetAmountUsed(int32_t param_1) = 0;

	virtual int64_t GetCost() const = 0;
	virtual void UpdateCost() = 0;

	virtual void GetStartDate(cIGZDate& date) const = 0;
	virtual void SetStartDate(cIGZDate const& date) = 0;
	virtual void GetExpirationDate(cIGZDate& date) const = 0;
	virtual void SetExpirationDate(cIGZDate const& date) = 0;
	virtual void GetCurrentDate(cIGZDate& date) = 0;
	virtual void SetCurrentDate(cIGZDate const& date) = 0;
	virtual void GetSuspensionDate(cIGZDate& date) = 0;
	virtual void SetSuspensionDate(cIGZDate const& date) = 0;

	virtual void Copy(cISC4NeighborDeal const& copyFrom) = 0;
	virtual void UpdateState() = 0;
	virtual void Cancel() = 0;
	virtual bool Activate() = 0;

	virtual int32_t GetFlags() const = 0;
	virtual void SetFlags(int32_t flags, bool value) = 0;
	virtual bool CheckFlagsAnd(int32_t flags) const = 0;
	virtual bool CheckFlagsOr(int32_t flags) const = 0;

	virtual bool Clone(cISC4NeighborDeal** outCopy, bool skipDealStatusBroadcasts) const = 0;
};