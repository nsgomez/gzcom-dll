#pragma once
#include "cIGZUnknown.h"
#include "cISC4DispatchManager.h"

class cIGZString;

class cISC4PylonOccupant : public cIGZUnknown
{
public:
	typedef uint32_t tUIState;

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void SetUIState(tUIState value) = 0;
	virtual tUIState GetUIState() = 0;

	virtual void SetBitmapInfo(uint32_t textureIID, cIGZString const& mysimBitmapPath) = 0;

	virtual void SetDispatchType(cISC4DispatchManager::tDispatchType value) = 0;
	virtual cISC4DispatchManager::tDispatchType GetDispatchType() = 0;

	virtual void SetDispatchState(cISC4DispatchManager::tDispatchState value) = 0;
	virtual cISC4DispatchManager::tDispatchState GetDispatchState() = 0;

	virtual void SetCallNumber(uint16_t value) = 0;
	virtual uint16_t GetCallNumber() = 0;

	virtual void SetDragState(bool dragState) = 0;
	virtual bool GetDragState() = 0;

	virtual void SetSourceOccupant(cISC4Occupant* pOccupant) = 0;
	virtual cISC4Occupant* GetSourceOccupant() = 0;

	virtual void SetPylonOwner(cIGZUnknown* pOwner) = 0;
	virtual cIGZUnknown* GetPylonOwner() = 0;
};