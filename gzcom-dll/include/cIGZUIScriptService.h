#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;
class cIGZScriptableControlSet;
class cIGZUIScriptServiceResourceFactory;
class cIGZScriptTerp;
class cIGZString;
class cIGZWin;

class cIGZUIScriptService : public cIGZUnknown
{
public:
	virtual cIGZWin* CreateWindowFromScript(cGZPersistResourceKey const& key, cIGZWin* parent, uint32_t windowClsid) = 0;
	virtual bool CreateWindowFromScript(cGZPersistResourceKey const& key, cIGZWin* parent, uint32_t windowClsid, uint32_t riid, void** ppvObj) = 0;

	virtual cIGZScriptableControlSet* ExecuteScriptString(cIGZString const& data) = 0;
	virtual cIGZScriptableControlSet* ExecuteScriptFile(cIGZString const& file) = 0;
	virtual cIGZScriptableControlSet* ExecuteScriptResource(const cGZPersistResourceKey& key) = 0;

	virtual cIGZScriptTerp* GetScriptInterpreter() = 0;

	virtual cIGZUIScriptServiceResourceFactory* GetResourceFactory() = 0;
	virtual bool SetResourceFactory(cIGZUIScriptServiceResourceFactory* pFactory) = 0;
};