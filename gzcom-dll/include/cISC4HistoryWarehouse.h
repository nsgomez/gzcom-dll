/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4HistoryWarehouse.h
 *
 * Copyright (C) 2016 Nelson Gomez
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

class cIGZDate;

class cISC4HistoryWarehouse : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool GetCount(uint32_t dwHistoryType, cIGZDate const& sStartDate, cIGZDate const& sEndDate, float& fUnknown) = 0;
		virtual bool GetTrend(uint32_t dwHistoryType, cIGZDate const& sStartDate, cIGZDate const& sEndDate, float& fM, float& fB) = 0;
		virtual bool GetMinMaxAverage(uint32_t dwHistoryType, cIGZDate const& sStartDate, cIGZDate const& sEndDate, float& fMin, float& fMax, float& fAvg) = 0;
		virtual bool GetPoint(uint32_t dwHistoryType, cIGZDate const& sDate, float& fValue) = 0;

		virtual bool Coalesce(uint32_t dwHistoryType, cIGZDate const& sDate, int32_t lUnknown) = 0;
		virtual bool Dispose(uint32_t dwHistoryType, cIGZDate const& sStartDate, cIGZDate const& sEndDate) = 0;
		virtual bool Dispose(uint32_t dwHistoryType) = 0;

		virtual bool RecordHistoryData(uint32_t dwHistoryType, int32_t lValue) = 0;
		virtual bool SetHistoryDataQueueLength(uint32_t dwHistoryType, uint32_t dwQueueLength) = 0;
};