#pragma once

#include "cISCProperty.h"
#include "cRZBaseVariant.h"

class cSCBaseProperty : public cISCProperty
{
public:

	cSCBaseProperty();
	cSCBaseProperty(uint32_t propertyID);
	cSCBaseProperty(uint32_t propertyID, uint32_t value);
	cSCBaseProperty(uint32_t propertyID, int32_t value);
	cSCBaseProperty(uint32_t propertyID, float value);
	cSCBaseProperty(uint32_t propertyID, cIGZVariant const& propertyValue);
	cSCBaseProperty(uint32_t propertyID, cIGZVariant const* propertyValue);

	cSCBaseProperty(cISCProperty const& value);
	cSCBaseProperty(cSCBaseProperty const& value);

	cSCBaseProperty& operator=(const cSCBaseProperty& other);
	cSCBaseProperty& operator=(cSCBaseProperty&& other) noexcept;

	bool QueryInterface(uint32_t riid, void** ppvObj);
	uint32_t AddRef();
	uint32_t Release();

	uint32_t GetPropertyID() const;
	void SetPropertyID(uint32_t value);

	cIGZVariant* GetPropertyValue();
	const cIGZVariant* GetPropertyValue() const;

	bool SetPropertyValue(const cIGZVariant& value);
	bool Write(cIGZOStream& stream) const;
	bool Read(cIGZIStream& stream);

private:

	uint32_t propertyID;
	cRZBaseVariant propertyValue;
	uint32_t refCount;
};