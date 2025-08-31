#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;

static const uint32_t GZIID_cIGZPersistResource = 0x456b8f1d;

class cIGZPersistResource : public cIGZUnknown
{
public:
	virtual void GetKey(cGZPersistResourceKey& key) const = 0;
	virtual bool SetKey(cGZPersistResourceKey const& key) = 0;

	virtual uint32_t GetType() const = 0;
	virtual uint32_t GetGroup() const = 0;
	virtual uint32_t GetInstance() const = 0;

	virtual bool SetType(uint32_t type) = 0;
	virtual bool SetGroup(uint32_t group) = 0;
	virtual bool SetInstance(uint32_t instance) = 0;

	virtual uint32_t GetRefCount() const = 0;
};
