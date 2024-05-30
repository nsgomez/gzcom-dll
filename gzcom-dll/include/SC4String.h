#pragma once
#include <cstdint>

class cIGZString;

/**
 * @brief A class that recreates the layout of SC4's internal cRZString class.
 * It is used for structures that have cRZString fields and API methods that return it.
 *
 * Use cRZBaseString if you need a type that implements cIGZString.
 */
class SC4String
{
public:
	cIGZString* AsIGZString()
	{
		return reinterpret_cast<cIGZString*>(this);
	}

	const cIGZString* AsIGZString() const
	{
		return reinterpret_cast<const cIGZString*>(this);
	}

private:
	void* vtable;
	intptr_t stringFields[3];
	uint32_t refCount;
};