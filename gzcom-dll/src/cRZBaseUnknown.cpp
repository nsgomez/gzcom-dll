#include "cRZBaseUnknown.h"

cRZBaseUnknown::cRZBaseUnknown()
	: refCount(0)
{
}

cRZBaseUnknown::~cRZBaseUnknown()
{
}

bool cRZBaseUnknown::QueryInterface(uint32_t riid, void** ppvObj)
{
	if (riid == GZIID_cIGZUnknown)
	{
		*ppvObj = static_cast<cIGZUnknown*>(this);
		AddRef();

		return true;
	}

	*ppvObj = nullptr;
	return false;
}

uint32_t cRZBaseUnknown::AddRef()
{
	uint32_t localRefCount = refCount + 1;
	refCount = localRefCount;

	return localRefCount;
}

uint32_t cRZBaseUnknown::Release()
{
	uint32_t localRefCount = 0;

	if (refCount > 0)
	{
		localRefCount = refCount - 1;
		refCount = localRefCount;

		if (localRefCount == 0)
		{
			delete this;
		}
	}

	return localRefCount;
}

