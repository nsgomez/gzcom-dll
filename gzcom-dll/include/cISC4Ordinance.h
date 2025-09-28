/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4Ordinance.h
 *
 * Copyright (C) 2023, 2024 Nicholas Hayes
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
class cISCPropertyHolder;
class SC4Percentage;

static const uint32_t GZIID_cISC4Ordinance = 0xAA5E2247;

class cISC4Ordinance : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual int64_t GetCurrentMonthlyIncome(void) = 0;

		virtual uint32_t GetID(void) const = 0;
		virtual cIGZString* GetName(void) = 0;
		virtual cIGZString* GetDescription(void) = 0;

		virtual uint32_t GetYearFirstAvailable(void) = 0;
		virtual SC4Percentage GetChanceAvailability(void) = 0;

		virtual int64_t GetEnactmentIncome(void) = 0;
		virtual int64_t GetRetracmentIncome(void) = 0;
		virtual int64_t GetMonthlyConstantIncome(void) = 0;
		virtual float GetMonthlyIncomeFactor(void) = 0;

		virtual uint32_t GetAdvisorID(void) = 0;

		virtual cISCPropertyHolder* GetMiscProperties(void) = 0;

		virtual bool IsAvailable(void) = 0;
		virtual bool IsOn(void) = 0;
		virtual bool IsEnabled(void) = 0;

		virtual int64_t GetMonthlyAdjustedIncome(void) = 0;

		virtual bool CheckConditions(void) = 0;

		virtual bool IsIncomeOrdinance(void) = 0;

		virtual bool Simulate(void) = 0;

		virtual bool SetAvailable(bool isAvailable) = 0;
		virtual bool SetOn(bool isOn) = 0;
		virtual bool SetEnabled(bool isEnabled) = 0;

		virtual bool ForceAvailable(bool isAvailable) = 0;
		virtual bool ForceOn(bool isAvailable) = 0;
		virtual bool ForceMonthlyAdjustedIncome(int64_t monthlyAdjustedIncome) = 0;
};