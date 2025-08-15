#pragma once
#include "cISC4View3DWin.h"
#include "cRZAutoRefCount.h"
#include <cstdint>

class cGZPersistResourceKey;
class cIGZWin;

namespace SC4UI
{
	cIGZWin* CreateWindowFromScript(const cGZPersistResourceKey& key, cIGZWin* parent, uint32_t windowClsid);

	bool CreateWindowFromScript(
		const cGZPersistResourceKey& key,
		cIGZWin* parent,
		uint32_t windowClsid,
		uint32_t riid,
		void** ppvObj);

	cRZAutoRefCount<cISC4View3DWin> GetView3DWin();
}