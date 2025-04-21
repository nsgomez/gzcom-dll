#pragma once
#include "cIGZUnknown.h"

class cIGZCallbackManager : public cIGZUnknown
{
public:
	typedef void(*CallbackFn)(void* state);

	virtual uint32_t Register(CallbackFn callback, void* state, uint32_t intervalInMilliseconds, bool oneShot, bool unknown) = 0;
	virtual bool Unregister(uint32_t id) = 0;

	virtual bool SetCallbackThreadPriority(int32_t priority) = 0;
	virtual int32_t GetCallbackThreadPriority() = 0;
	virtual uint32_t GetCallbackThreadID() = 0;
};