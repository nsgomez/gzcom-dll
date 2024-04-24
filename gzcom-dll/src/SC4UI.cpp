#include "SC4UI.h"
#include "cIGZUIScriptService.h"
#include "GZServPtrs.h"

cIGZWin* SC4UI::CreateWindowFromScript(const cGZPersistResourceKey& key, cIGZWin* parent, uint32_t windowClsid)
{
	cIGZUIScriptServicePtr pUIScriptService;

	if (pUIScriptService)
	{
		return pUIScriptService->CreateWindowFromScript(key, parent, windowClsid);
	}

	return nullptr;
}

bool SC4UI::CreateWindowFromScript(
	const cGZPersistResourceKey& key,
	cIGZWin* parent,
	uint32_t windowClsid,
	uint32_t riid,
	void** ppvObj)
{
	cIGZUIScriptServicePtr pUIScriptService;

	if (pUIScriptService)
	{
		return pUIScriptService->CreateWindowFromScript(key, parent, windowClsid, riid, ppvObj);
	}

	return false;
}