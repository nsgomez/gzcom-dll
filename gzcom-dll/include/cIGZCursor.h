#pragma once
#include "cIGZUnknown.h"

class cIGZBuffer;
class cIGZString;

class cIGZCursor : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void SetCursor(bool set) = 0;
	virtual void ShowCursor(bool show) = 0;

	virtual void GetCursorHotSpot(int32_t& x, int32_t& z) = 0;
	virtual void SetCursorHotSpot(int32_t x, int32_t z) = 0;

	virtual bool LoadCursorA(cIGZString const& path) = 0;
	virtual void SetCursorHandle(void* handle) = 0;
	virtual void SetCursorBuffer(cIGZBuffer* buffer) = 0;
	virtual bool SystemHasCursorSupport() = 0;
	virtual cIGZBuffer* GetCursorBuffer() = 0;
	virtual bool IsLoaded() = 0;
};