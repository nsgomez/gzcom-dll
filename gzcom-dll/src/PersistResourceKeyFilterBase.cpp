#include "PersistResourceKeyFilterBase.h"

PersistResourceKeyFilterBase::PersistResourceKeyFilterBase()
{
}

bool PersistResourceKeyFilterBase::QueryInterface(uint32_t riid, void** ppvObj)
{
	if (riid == GZIID_cIGZPersistResourceKeyFilter)
	{
		*ppvObj = static_cast<cIGZPersistResourceKeyFilter*>(this);
		AddRef();

		return true;
	}

	return cRZBaseUnknown::QueryInterface(riid, ppvObj);
}

uint32_t PersistResourceKeyFilterBase::AddRef()
{
	return cRZBaseUnknown::AddRef();
}

uint32_t PersistResourceKeyFilterBase::Release()
{
	return cRZBaseUnknown::Release();
}
