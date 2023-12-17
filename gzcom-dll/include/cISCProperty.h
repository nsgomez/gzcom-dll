#pragma once
#include "cIGZUnknown.h"

class cIGZVariant;
class cIGZOStream;
class cIGZIStream;

static const uint32_t GZIID_cISCProperty = 0x452160ec;

class cISCProperty : public cIGZUnknown
{
public:

	virtual uint32_t GetPropertyID() const = 0;
	virtual void SetPropertyID(uint32_t value) = 0;

	virtual cIGZVariant* GetPropertyValue() = 0;
	virtual const cIGZVariant* GetPropertyValue() const = 0;

	virtual bool SetPropertyValue(const cIGZVariant& value) = 0;
	virtual bool Write(cIGZOStream& stream) const = 0;
	virtual bool Read(cIGZIStream& stream) = 0;
};