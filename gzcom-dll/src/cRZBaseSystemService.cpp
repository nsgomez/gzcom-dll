#include "cRZBaseSystemService.h"

cRZBaseSystemService::cRZBaseSystemService(uint32_t serviceID, int32_t servicePriority)
	: serviceID(serviceID),
	  servicePriority(servicePriority),
	  serviceTickPriority(servicePriority),
	  serviceRunning(false),
	  refCount(0)
{
}

bool cRZBaseSystemService::QueryInterface(uint32_t riid, void** ppvObj)
{
	if (riid == GZIID_cIGZSystemService)
	{
		*ppvObj = static_cast<cIGZSystemService*>(this);
		AddRef();

		return true;
	}
	else if (riid == GZIID_cIGZUnknown)
	{
		*ppvObj = static_cast<cIGZUnknown*>(this);
		AddRef();

		return true;
	}

	*ppvObj = nullptr;
	return false;
}

uint32_t cRZBaseSystemService::AddRef()
{
	return ++refCount;
}

uint32_t cRZBaseSystemService::Release()
{
	if (refCount > 0)
	{
		--refCount;
	}
	return refCount;
}

uint32_t cRZBaseSystemService::GetServiceID()
{
	return serviceID;
}

cIGZSystemService* cRZBaseSystemService::SetServiceID(uint32_t id)
{
	serviceID = id;
	return this;
}

int32_t cRZBaseSystemService::GetServicePriority()
{
	return servicePriority;
}

bool cRZBaseSystemService::IsServiceRunning()
{
	return serviceRunning;
}

cIGZSystemService* cRZBaseSystemService::SetServiceRunning(bool running)
{
	serviceRunning = running;
	return this;
}

bool cRZBaseSystemService::OnTick(uint32_t unknown1)
{
	return true;
}

bool cRZBaseSystemService::OnIdle(uint32_t unknown1)
{
	return true;
}

int32_t cRZBaseSystemService::GetServiceTickPriority()
{
	return serviceTickPriority;
}
