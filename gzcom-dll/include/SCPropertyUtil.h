#pragma once
#include "cISCPropertyHolder.h"

class cIGZString;

namespace SCPropertyUtil
{
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint32_t& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint8_t& value);
	bool GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, cIGZString& value);
}