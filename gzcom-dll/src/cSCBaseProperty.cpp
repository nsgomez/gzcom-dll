#include "cSCBaseProperty.h"
#include "cIGZIStream.h"
#include "cIGZOStream.h"
#include "cISC4DBSegmentIStream.h"
#include "cISC4DBSegmentOStream.h"

static const uint32_t GZIID_cSCBaseProperty = 0x151ab0f8;

cSCBaseProperty::cSCBaseProperty()
	: propertyID(0), propertyValue(), refCount(0)
{
}

cSCBaseProperty::cSCBaseProperty(uint32_t propertyID)
	: propertyID(propertyID), propertyValue(), refCount(0)
{
}

cSCBaseProperty::cSCBaseProperty(uint32_t propertyID, uint32_t value)
	: propertyID(propertyID), propertyValue(value), refCount(0)
{
}

cSCBaseProperty::cSCBaseProperty(uint32_t propertyID, int32_t value)
	: propertyID(propertyID), propertyValue(value), refCount(0)
{
}

cSCBaseProperty::cSCBaseProperty(uint32_t propertyID, float value)
	: propertyID(propertyID), propertyValue(value), refCount(0)
{
}

cSCBaseProperty::cSCBaseProperty(uint32_t propertyID, cIGZVariant const& propertyValue)
	: propertyID(propertyID), propertyValue(propertyValue), refCount(0)
{
}

cSCBaseProperty::cSCBaseProperty(uint32_t propertyID, cIGZVariant const* propertyValue)
	: propertyID(propertyID), propertyValue(propertyValue), refCount(0)
{
}

cSCBaseProperty::cSCBaseProperty(cISCProperty const& value)
	: propertyID(value.GetPropertyID()),
	  propertyValue(value.GetPropertyValue()),
	  refCount(0)
{
}

cSCBaseProperty::cSCBaseProperty(cSCBaseProperty const& value)
	: propertyID(value.propertyID),
	  propertyValue(value.propertyValue),
	  refCount(0)
{
}

cSCBaseProperty& cSCBaseProperty::operator=(const cSCBaseProperty& other)
{
	if (this == &other)
	{
		return *this;
	}

	propertyID = other.propertyID;
	propertyValue = other.propertyValue;

	return *this;
}

cSCBaseProperty& cSCBaseProperty::operator=(cSCBaseProperty&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	propertyID = other.propertyID;
	propertyValue = std::move(other.propertyValue);

	return *this;
}

bool cSCBaseProperty::QueryInterface(uint32_t riid, void** ppvObj)
{
	if (riid == GZIID_cSCBaseProperty)
	{
		AddRef();
		*ppvObj = this;

		return true;
	}
	else if (riid == GZIID_cISCProperty)
	{
		AddRef();
		*ppvObj = static_cast<cISCProperty*>(this);

		return true;
	}
	else if (riid == GZIID_cIGZUnknown)
	{
		AddRef();
		*ppvObj = static_cast<cIGZUnknown*>(this);

		return true;
	}

	return propertyValue.QueryInterface(riid, ppvObj);
}

uint32_t cSCBaseProperty::AddRef()
{
	return ++refCount;
}

uint32_t cSCBaseProperty::Release()
{
	if (refCount > 0)
	{
		--refCount;
	}

	return refCount;
}

uint32_t cSCBaseProperty::GetPropertyID() const
{
	return propertyID;
}

void cSCBaseProperty::SetPropertyID(uint32_t value)
{
	propertyID = value;
}

cIGZVariant* cSCBaseProperty::GetPropertyValue()
{
	return &propertyValue;
}

const cIGZVariant* cSCBaseProperty::GetPropertyValue() const
{
	return &propertyValue;
}

bool cSCBaseProperty::SetPropertyValue(const cIGZVariant& value)
{
	return propertyValue.CopyFrom(value);
}

bool cSCBaseProperty::Write(cIGZOStream& stream) const
{
	bool result = false;

	cISC4DBSegmentOStream* dbSegment = nullptr;

	if (stream.QueryInterface(GZIID_cISC4DBSegmentOStream, reinterpret_cast<void**>(&dbSegment)))
	{
		result = dbSegment->SetUint32(propertyID)
			  && dbSegment->WriteVariant(propertyValue);

		dbSegment->Release();
	}

	return result;
}

bool cSCBaseProperty::Read(cIGZIStream& stream)
{
	bool result = false;

	cISC4DBSegmentIStream* dbSegment = nullptr;

	if (stream.QueryInterface(GZIID_cISC4DBSegmentIStream, reinterpret_cast<void**>(&dbSegment)))
	{
		result = dbSegment->GetUint32(propertyID)
			  && dbSegment->ReadVariant(propertyValue);

		dbSegment->Release();
	}

	return result;
}
