#pragma once
#include "cIGZUnknown.h"
#include "cISC4MySim.h"

template <typename T> class SC4Vector;

class cISC4MySimAgentSimulator : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool GetActiveMySims(SC4Vector<cISC4MySim*>& sims) = 0;
	virtual void MoveIn(cIGZString& personalName, bool isMale, cISC4MySim::ZodiacSign sign, SC4String& bio, uint32_t bitmapID, SC4String& bitmapImagePath, uint8_t slot) = 0;

	virtual void TrackLocation(cISC4MySim* pSim) = 0;
	virtual void HideLocation() = 0;

	virtual cISC4MySim* MySimLivesHere(cISC4BuildingOccupant* pBuilding) = 0;
	virtual void CancelMoveIn() = 0;

	virtual void SetActiveUIPanelSim(int32_t slot) = 0;
	virtual bool GetActiveUIPanelSim(int32_t& slot) = 0;
};