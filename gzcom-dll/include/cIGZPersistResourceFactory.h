#pragma once
#include "cIGZUnknown.h"

class cIGZPersistDBRecord;
class cIGZPersistResource;

static const uint32_t GZIID_cIGZPersistResourceFactory = 0xA56B8F17;

class cIGZPersistResourceFactory : public cIGZUnknown
{
public:
	virtual bool CreateInstance(uint32_t type, uint32_t riid, void** ppvObj, uint32_t unknown1, cIGZUnknown* unknown2) = 0;
	virtual bool CreateInstance(cIGZPersistDBRecord& record, uint32_t riid, void** ppvObj, uint32_t unknown1, cIGZUnknown* unknown2) = 0;

	virtual bool Read(cIGZPersistResource& resource, cIGZPersistDBRecord& record) = 0;
	virtual bool Write(cIGZPersistResource const& resource, cIGZPersistDBRecord& record) = 0;
};