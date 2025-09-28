/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZCmdLine.h
 *
 * Copyright (C) 2024 Nicholas Hayes
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

class cIGZCmdLine : public cIGZUnknown
{
	public:

		virtual uint32_t argc() const = 0;
		virtual const char* const argv(int32_t index) const = 0;
		virtual bool GetCommandLineText(cIGZString& value) const = 0;

		virtual int32_t Find(cIGZString const& value, bool caseSensitive) const = 0;
		virtual int32_t FindSubString(cIGZString const& value, bool caseSensitive) const = 0;

		virtual bool IsSwitchPresent(char argument, cIGZString& value, bool escapeQuotedValues) const = 0;
		virtual int32_t GetIndexOfSwitch(char argument, int32_t startIndex) const = 0;

		virtual bool IsSwitchPresent(cIGZString const& argument) const = 0;
		virtual bool IsSwitchPresent(cIGZString const& argument, cIGZString& value, bool escapeQuotedValues) const = 0;
		virtual int32_t GetIndexOfSwitch(cIGZString const& argument, int32_t startIndex) const = 0;

		virtual bool InsertArgument(cIGZString const& argument, int32_t index) = 0;
		virtual bool EraseArgument(int32_t index) = 0;
};
