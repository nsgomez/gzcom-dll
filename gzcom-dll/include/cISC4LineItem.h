#pragma once
#include "cIGZUnknown.h"

class cISC4LineItem : public cIGZUnknown
{
public:
	enum class DisplayFlag : uint32_t
	{
		ShowLineItem = 1,
		ShowSecondaryInfoField = 2,
		Unknown = 4 // No visible effect.
	};

	enum class Type : uint32_t
	{
		Expense = 0,
		Income = 1
	};

	virtual uint32_t GetID() const = 0;

	virtual Type GetType() const = 0;
	virtual bool SetType(Type value) = 0;

	// The name parameter uses the game's internal cRZString type.
	// Trying to assign it to a cIGZString will crash due to the
	// different object layouts.
	virtual bool GetName(intptr_t& name) = 0;
	/**
	 * @brief Sets the name of the line item.
	 * @param groupID The group ID of the LTEXT entry, can be 0
	 * to get the name of the building represented by instanceID.
	 * @param instanceID The instance ID.
	 * @return True on success; otherwise, false.
	*/
	virtual bool SetName(uint32_t groupID, uint32_t instanceID) = 0;

	virtual int64_t GetSecondaryInfoField() const = 0;
	virtual bool SetSecondaryInfoField(int64_t value) = 0;

	virtual int64_t GetFullExpenses() const = 0;
	virtual int64_t GetCurrentExpenses() const = 0;

	virtual bool SetFullExpenses(int64_t value) = 0;
	virtual bool AddToFullExpenses(int64_t value) = 0;

	virtual int64_t GetIncome() const = 0;
	virtual bool SetIncome(int64_t value) = 0;
	virtual bool AddToIncome(int64_t value) = 0;

	virtual DisplayFlag GetDisplayFlags() = 0;
	virtual bool SetDisplayFlag(DisplayFlag flag, bool value) = 0;

	virtual bool IsLocalFundingItem() const = 0;
};
