#include "cSC4BaseOccupantFilter.h"
#include "cISC4Occupant.h"

bool cSC4BaseOccupantFilter::QueryInterface(uint32_t riid, void** ppvObj)
{
	if (riid == GZIID_cISC4OccupantFilter)
	{
		*ppvObj = static_cast<cISC4OccupantFilter*>(this);
		AddRef();

		return true;
	}

	return cRZBaseUnknown::QueryInterface(riid, ppvObj);
}

uint32_t cSC4BaseOccupantFilter::AddRef()
{
	return cRZBaseUnknown::AddRef();
}

uint32_t cSC4BaseOccupantFilter::Release()
{
	return cRZBaseUnknown::Release();
}

bool cSC4BaseOccupantFilter::IsOccupantIncluded(cISC4Occupant* pOccupant)
{
	return IsOccupantTypeIncluded(pOccupant->GetType());
}

bool cSC4BaseOccupantFilter::IsOccupantTypeIncluded(uint32_t dwType)
{
	return true;
}

bool cSC4BaseOccupantFilter::IsPropertyHolderIncluded(cISCPropertyHolder* pProperties)
{
	return true;
}
