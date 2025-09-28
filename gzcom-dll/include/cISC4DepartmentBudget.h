/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4DepartmentBudget.h
 *
 * Copyright (C) 2025 Nicholas Hayes
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, under
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include "cIGZUnknown.h"

class cIGZString;
class cISC4LineItem;
class cISCPropertyHolder;
class SC4Percentage;

template <typename T> class SC4List;
template <typename T> class SC4Vector;

class cISC4DepartmentBudget : public cIGZUnknown
{
public:
	virtual uint32_t GetDepartmentID() const = 0;
	virtual bool GetDepartmentName(cIGZString& name) = 0;
	virtual bool SetDepartmentName(uint32_t ltextGroupID, uint32_t ltextInstanceID) = 0;

	virtual uint32_t GetBudgetGroup() const = 0;
	virtual bool SetBudgetGroup(uint32_t budgetGroup) = 0;

	virtual bool GetIsFixedFunding() const = 0;
	virtual bool SetFixedFunding(bool value) = 0;

	virtual SC4Percentage* GetFundingPercentage() const = 0;
	virtual bool SetFundingPercentage(SC4Percentage const& percentange, uint32_t lineItem) = 0;
	virtual SC4Percentage* GetMaxAllowedFundingPercentage() const = 0;
	virtual bool SetMaxAllowedFundingPercentage(SC4Percentage const& percentange) = 0;
	virtual int64_t GetIdealMonthlyFunding() const = 0;

	virtual int64_t GetTotalExpenses() const = 0;
	virtual int64_t GetTotalIncome() const = 0;

	virtual cISC4LineItem* CreateLineItem(uint32_t lineNumber, bool isLocallyFunded) = 0;
	virtual cISC4LineItem* CreateLineItemForBuildingType(uint32_t buildingIID, bool isLocallyFunded) = 0;
	virtual bool RemoveLineItem(uint32_t lineNumber) = 0;
	virtual cISC4LineItem* GetLineItem(uint32_t lineNumber) = 0;
	virtual bool GetAllLineItems(SC4Vector<cISC4LineItem*>& destination) = 0;

	virtual bool AddLocallyFundedObject(cISCPropertyHolder* pPropertyHolder, uint32_t purposeID) = 0;
	virtual bool RemoveLocallyFundedObject(cISCPropertyHolder* pPropertyHolder, uint32_t purposeID) = 0;
	virtual bool SetLocalFundingPercent(cISCPropertyHolder* pPropertyHolder, SC4Percentage* unknown2, uint32_t unknown3) = 0;
	virtual bool SetLocalFullFunding(cISCPropertyHolder* pPropertyHolder, int64_t unknown2, uint32_t unknown3) = 0;
	virtual float GetLocalFundingPercent(cISCPropertyHolder* pPropertyHolder, uint32_t unknown2) = 0;
	virtual int64_t GetLocalFullFunding(cISCPropertyHolder * pPropertyHolder, uint32_t unknown2) = 0;
	virtual bool IsLocallyFundedObjectInDepartment(cISCPropertyHolder* pPropertyHolder, uint32_t unknown2) = 0;

	virtual bool RecalculateAllLineItemCurrentExpenses() = 0;

	virtual int64_t GetTotalSpending() const = 0;
	virtual bool SetTotalSpending(int64_t value) = 0;

	virtual bool GetLocallyFundedItemsByPurpose(uint32_t purpose, SC4List<cISCPropertyHolder*>& list) = 0;
	virtual bool HasLocallyFundedItemsByPurpose(uint32_t purpose) = 0;
};
