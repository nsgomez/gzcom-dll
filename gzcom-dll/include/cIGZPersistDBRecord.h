#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;

static const uint32_t GZIID_cIGZPersistDBRecord = 0xE56B8F03;

class cIGZPersistDBRecord : public cIGZUnknown
{
public:
	virtual void GetKey(cGZPersistResourceKey& key) const = 0;

	virtual uint16_t GetAccessFlags() const = 0;
	virtual bool Close() = 0;

	virtual bool GetFieldVoid(void*, uint32_t) = 0;
	virtual bool SetFieldVoid(const void*, uint32_t) = 0;

	virtual uint32_t GetSize() = 0;
	virtual bool SetSize(uint32_t) = 0;

	virtual uint32_t GetPosition() = 0;
	virtual uint32_t SeekAbsolute(uint32_t) = 0;
	virtual uint32_t SeekRelative(int32_t) = 0;
};
