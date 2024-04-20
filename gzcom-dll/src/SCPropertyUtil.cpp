#include "SCPropertyUtil.h"
#include "cISCPropertyHolder.h"
#include "cISCProperty.h"
#include "cIGZVariant.h"

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint32_t& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				return data->GetValUint32(value);
			}
		}
	}

	value = 0;
	return false;
}

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint8_t& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				return data->GetValUint8(value);
			}
		}
	}

	value = 0;
	return false;
}