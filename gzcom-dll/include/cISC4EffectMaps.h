#pragma once
#include "cIGZUnknown.h"

template <typename T> class SC4Rect;

class cISC4EffectMaps : public cIGZUnknown
{
public:
	virtual uint32_t MapCount() = 0;
	virtual uint32_t MapVertsX() = 0;
	virtual uint32_t MapVertsZ() = 0;

	virtual float MapLerpedHeight(uint32_t unknown1, float unknown2, float unknown3) = 0;
	virtual float MapVertexHeight(uint32_t unknown1, uint32_t unknown2, uint32_t unknown3) = 0;
	virtual uint32_t MapLerpedNormal(float unknown2, float unknown3) = 0;

	virtual void AddRectToMap(uint32_t unknown1, SC4Rect<int32_t> const& unknown2, float unknown3, uint32_t unknown4) = 0;
};