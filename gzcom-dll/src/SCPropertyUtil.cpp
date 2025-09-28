/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SCPropertyUtil.cpp
 *
 * Copyright (C) 2024, 2025 Nicholas Hayes
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, under
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <https://www.gnu.org/licenses/>.
 */

#include "SCPropertyUtil.h"
#include "cISCPropertyHolder.h"
#include "cISCProperty.h"
#include "cIGZVariant.h"
#include "StringResourceKey.h"

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, bool& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				return data->GetValBool(value);
			}
		}
	}

	value = false;
	return false;
}

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int8_t& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				return data->GetValSint8(value);
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

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int16_t& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				return data->GetValSint16(value);
			}
		}
	}

	value = 0;
	return false;
}

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint16_t& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				return data->GetValUint16(value);
			}
		}
	}

	value = 0;
	return false;
}

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int32_t& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				return data->GetValSint32(value);
			}
		}
	}

	value = 0;
	return false;
}

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

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, int64_t& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				return data->GetValSint64(value);
			}
		}
	}

	value = 0;
	return false;
}

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, uint64_t& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				return data->GetValUint64(value);
			}
		}
	}

	value = 0;
	return false;
}

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, float& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				return data->GetValFloat32(value);
			}
		}
	}

	value = 0;
	return false;
}

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, double& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				return data->GetValFloat64(value);
			}
		}
	}

	value = 0;
	return false;
}

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, cIGZString& value)
{
	if (propertyHolder)
	{
		const cISCProperty* property = propertyHolder->GetProperty(id);

		if (property)
		{
			const cIGZVariant* data = property->GetPropertyValue();

			if (data)
			{
				data->GetValString(value);
				return true;
			}
		}
	}

	return false;
}

bool SCPropertyUtil::GetPropertyValue(const cISCPropertyHolder* propertyHolder, uint32_t id, StringResourceKey& value)
{
	const cISCProperty* pProperty = propertyHolder->GetProperty(id);

	if (pProperty)
	{
		const cIGZVariant* pVariant = pProperty->GetPropertyValue();

		if (pVariant)
		{
			if (pVariant->GetType() == cIGZVariant::Uint32Array)
			{
				if (pVariant->GetCount() == 3)
				{
					const uint32_t kStringResourceType = 0x2026960B;

					const uint32_t* pData = pVariant->RefUint32();

					if (pData[0] == kStringResourceType)
					{
						value.groupID = pData[1];
						value.instanceID = pData[2];
						return true;
					}
				}
			}
		}
	}

	value.groupID = 0;
	value.instanceID = 0;
	return false;
}
