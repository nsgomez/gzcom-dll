#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;

static const uint32_t GZCLSID_cIGZPersistResourceKeyList = 0x656B8F2D;
static const uint32_t GZIID_cIGZPersistResourceKeyList = 0x656B8F12;

class cIGZPersistResourceKeyList : public cIGZUnknown
{
	public:
		virtual bool Insert(cGZPersistResourceKey const& key) = 0;
		virtual bool Insert(cIGZPersistResourceKeyList const& list) = 0;

		virtual bool Erase(cGZPersistResourceKey const& key) = 0;
		virtual bool EraseAll() = 0;

		typedef void (*EnumKeysFunctionPtr)(cGZPersistResourceKey const& key, void* pContext);

		virtual void EnumKeys(EnumKeysFunctionPtr pCallback, void* pContext) const = 0;

		virtual bool IsPresent(cGZPersistResourceKey const& key) const = 0;
		virtual uint32_t Size() const = 0;
		virtual const cGZPersistResourceKey& GetKey(uint32_t index) const = 0;
};
