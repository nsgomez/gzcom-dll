/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZDate.h
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

class cIGZString;
class cRZTime;

/**
 * @brief An interface for objects representing a calendar date
 */
class cIGZDate : public cIGZUnknown
{
	public:
		virtual bool Set(uint32_t dwDay, uint32_t dwYear) = 0;
		virtual bool Set(uint32_t dwMonth, uint32_t dwDay, uint32_t dwYear) = 0;
		virtual bool Set(cRZTime const& sTime) = 0;
		virtual bool Set(uint32_t dwDay) = 0;
		virtual bool Set(char const* pszMonthName, uint32_t dwDay, uint32_t dwYear) = 0;

		virtual bool Copy(cIGZDate const& sCopyFrom) = 0;
		virtual bool Clone(cIGZDate** ppCopyTo) = 0;

		virtual bool Between(cIGZDate const& sStart, cIGZDate const& sEnd) = 0;
		virtual int32_t CompareTo(cIGZDate const& sOther) = 0;

		virtual uint32_t WeekDay(void) = 0;
		virtual uint32_t Year(void) = 0;
		virtual uint32_t DayOfYear(void) = 0;
		virtual uint32_t DayOfMonth(void) = 0;
		virtual uint32_t FirstDayOfMonth(void) = 0;
		virtual uint32_t FirstDayOfMonth(uint32_t dwMonth) = 0;

		/**
		 * @return The number of days elapsed
		 */
		virtual uint32_t Hash(void) = 0;

		virtual bool IsValid(void) = 0;
		virtual bool Leap(void) = 0;
		virtual bool MaxDate(cIGZDate const& sOther, cIGZDate& sMaxOut) = 0;
		virtual bool MinDate(cIGZDate const& sOther, cIGZDate& sMinOut) = 0;

		virtual uint32_t Month(void) = 0;
		virtual uint32_t Previous(uint32_t dwDayOfPriorWeek, cIGZDate& sOut) = 0;
		virtual uint32_t YearLastTwoDigits(void) = 0;
		virtual uint32_t DayNumber(void) = 0; // Same as Hash

		virtual bool operator<(cIGZDate const& sOther) = 0;
		virtual bool operator<=(cIGZDate const& sOther) = 0;
		virtual bool operator>(cIGZDate const& sOther) = 0;
		virtual bool operator>=(cIGZDate const& sOther) = 0;
		virtual bool operator==(cIGZDate const& sOther) = 0;
		virtual bool operator!=(cIGZDate const& sOther) = 0;

		virtual cIGZDate& operator-(cIGZDate const& sOther) = 0;
		virtual cIGZDate& operator+(cIGZDate const& sOther) = 0;

		virtual cIGZDate& operator-(int32_t nDays) = 0;
		virtual cIGZDate& operator+(int32_t nDays) = 0;

		virtual cIGZDate& operator++(void) = 0;
		virtual cIGZDate& operator--(void) = 0;

		virtual cIGZDate& operator+=(int32_t nDays) = 0;
		virtual cIGZDate& operator-=(int32_t nDays) = 0;

		virtual bool DateString(cIGZString& sDateOut, uint32_t dwFormatID) = 0;
		virtual bool DayWithinMonth(uint32_t dwMonth, uint32_t dwDay, uint32_t dwYear) = 0;

		virtual uint32_t DaysInYear(uint32_t dwYear) = 0;

		/**
		 * @return Produces an internal integral representation of a datetime
		 */
		virtual uint32_t Jday(uint32_t dwMonth, uint32_t dwDay, uint32_t dwYear) = 0;
		virtual bool LeapYear(uint32_t dwYear) = 0;
};