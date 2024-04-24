#pragma once
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
}