#pragma once
#include "cIGZUnknown.h"

class cIGZCursor;
class cIGZWin;

class cISC4ViewInputControl : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual uint32_t GetID() = 0;
	virtual void SetID(uint32_t id) = 0;

	virtual cIGZCursor* GetCursor() = 0;
	virtual void SetCursor(cIGZCursor* cursor) = 0;
	virtual void SetCursor(uint32_t cursor) = 0;

	virtual void SetWindow(cIGZWin* unknown1) = 0;

	virtual bool IsSelfScrollingView() = 0;
	virtual bool ShouldStack() = 0;

	virtual bool OnCharacter(char value) = 0;
	virtual bool OnKeyDown(int32_t vkCode, uint32_t modifiers) = 0;
	virtual bool OnKeyUp(int32_t vkCode, uint32_t modifiers) = 0;
	virtual bool OnMouseDownL(int32_t x, int32_t z, uint32_t modifiers) = 0;
	virtual bool OnMouseDownR(int32_t x, int32_t z, uint32_t modifiers) = 0;
	virtual bool OnMouseUpL(int32_t x, int32_t z, uint32_t modifiers) = 0;
	virtual bool OnMouseUpR(int32_t x, int32_t z, uint32_t modifiers) = 0;
	virtual bool OnMouseMove(int32_t x, int32_t z, uint32_t modifiers) = 0;
	virtual bool OnMouseWheel(int32_t x, int32_t z, uint32_t modifiers, int32_t wheelDelta) = 0;
	virtual bool OnMouseExit() = 0;

	virtual void Activate() = 0;
	virtual void Deactivate() = 0;
	virtual bool AmCapturing() = 0;
};
