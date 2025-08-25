#pragma once
#include "cIGZUnknown.h"

class cIGZString;
class cISC4EffectMaps;
class cISC4VisualEffect;

class cISC4EffectsManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool HasVisualEffect(char const* name) = 0;
	virtual bool CreateVisualEffect(char const* name, cISC4VisualEffect** ppEffect) = 0;
	virtual bool CreateVisualEffect(uint32_t unknown1, uint32_t unknown2, cISC4VisualEffect** ppEffect) = 0;

	virtual void GetStatsString(cIGZString& stats) = 0;
	virtual cISC4EffectMaps* GetEffectMaps() = 0;
	virtual float GetTallestBuildingAltitude() = 0;
};
