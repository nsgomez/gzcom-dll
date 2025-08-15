#pragma once
#include "cIGZUnknown.h"

class cIGZCursor;
class cIGZString;

class cIGZCursorManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool AddCursor(cIGZCursor* cursor, uint32_t id) = 0;
	virtual bool RemoveCursor(uint32_t id) = 0;

	virtual cIGZCursor* GetCursor(uint32_t id) = 0;
	virtual cIGZCursor* GetCursor() = 0;
	virtual bool SetCursor(uint32_t id) = 0;
	virtual bool SetCursor(cIGZCursor* cursor) = 0;

	virtual bool PushAutoCursor(uint32_t id) = 0;
	virtual bool PopAutoCursor() = 0;

	virtual bool AddCursor(cIGZString const& path, uint32_t id) = 0;
	virtual void ShowCursor() = 0;
	virtual void HideCursor() = 0;
};