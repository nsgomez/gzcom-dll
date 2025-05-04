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
