#pragma once
#include <cstdint>

class cIS3DTextureBindingFactory;

class cS3DTextureBinding
{
	uint32_t unknown1;
	void* unknown2;
	cIS3DTextureBindingFactory* pFactory;
	uint32_t refCount;
};
