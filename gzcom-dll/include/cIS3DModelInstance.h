#pragma once
#include "cIGZUnknown.h"

class cS3DBoundingBox;
class cS3DTransform;
class cIS3DResModel;
class cSC4PickContext;
class SC4DrawAttributes;
class SC4DrawContext;

static const uint32_t GZIID_cIS3DModelInstance = 0x26a68449;

class cIS3DModelInstance : public cIGZUnknown
{
public:
	virtual cIGZUnknown* GetOwner() = 0;
	virtual void SetOwner(cIGZUnknown*) = 0;

	virtual void* GetCustomData() = 0;
	virtual void SetCustomData(void*) = 0;

	virtual void GetBounds(cS3DBoundingBox&) = 0;
	virtual void GetWorldBounds(cS3DBoundingBox&) = 0;

	virtual void GetTransform(cS3DTransform&) = 0;
	virtual void SetTransform(cS3DTransform const&) = 0;

	virtual bool Pick(cSC4PickContext*) = 0;
	virtual bool Draw(SC4DrawContext*, bool) = 0;

	virtual int16_t GetProperties() = 0;
	virtual void SetProperties(int16_t) = 0;

	virtual SC4DrawAttributes* GetDrawAttributes() const = 0;
	virtual void SetDrawAttributes(SC4DrawAttributes&) = 0;

	virtual void GetSortValue(uint32_t&) const = 0;
	virtual cIS3DResModel* GetResModel() const = 0;
};