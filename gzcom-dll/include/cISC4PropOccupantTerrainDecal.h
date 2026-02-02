#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;

static const uint32_t GZCLSID_cISC4PropOccupantTerrainDecal = 0x2977aa48;
static const uint32_t GZIID_cISC4PropOccupantTerrainDecal = 0x2977aa48;

class cISC4PropOccupantTerrainDecal : public cIGZUnknown
{
public:
	enum class tCompletionAction : uint32_t
	{
		None = 0,
		RemoveOverlay = 1,
		InsertOccupant = 2
	};

	virtual void SetDecalTexture(cGZPersistResourceKey const& textureKey, float scale) = 0;
	virtual void SetOpacity(float param_1) = 0;
	virtual void SetOpacityFade(float time, tCompletionAction action, float minOpacity, float maxOpacity) = 0;
	virtual void SetDecalSize(float scale) = 0;
};