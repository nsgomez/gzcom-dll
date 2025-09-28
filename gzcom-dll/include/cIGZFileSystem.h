/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZFileSystem.h
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

class cIGZFileSystem : public cIGZUnknown
{
public:
	virtual const char* AppDrive() = 0;
	virtual const char* AppDirectory() = 0;
	virtual const char* AppName() = 0;
	virtual const char* AppExtension() = 0;
	virtual const char* DataDirectory() = 0;
	virtual const char* PlugInDirectory() = 0;
	virtual const char* CDAppDrive() = 0;
	virtual const char* CDAppDirectory() = 0;
	virtual const char* CDDataDirectory() = 0;
	virtual const char* CDPlugInDirectory() = 0;

	virtual bool FindCDDrive() = 0;
	virtual void UseCDIniFile(bool) = 0;
	virtual void AllowRecursiveCDSearch(bool) = 0;

	virtual void SetExpectedCDName(cIGZString const&) = 0;
	virtual void SetExpectedCDAppPath(cIGZString const&) = 0;

	virtual bool SetDataDirectory(cIGZString const&) = 0;
	virtual bool SetPluginDirectory(cIGZString const&) = 0;

	virtual void GetPluginDirectoryName(cIGZString&) = 0;
	virtual void SetPluginDirectoryName(cIGZString const&) = 0;
};
