#pragma once
#include "cISCPropertyHolder.h"

class cIGZString;
struct StringResourceKey;

namespace SCPropertyUtil
{
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int8_t& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint8_t& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int16_t& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint16_t& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int32_t& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint32_t& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int64_t& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint64_t& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, float& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, double& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, cIGZString& value);

	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, StringResourceKey& value);
}