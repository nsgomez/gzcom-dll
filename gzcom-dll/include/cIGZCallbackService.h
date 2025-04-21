#pragma once
#include "cIGZUnknown.h"
#include "cIGZCallbackManager.h"

static const uint32_t GZSRVID_cIGZCallbackService = 0xa76c78e7;
static const uint32_t GZIID_cIGZCallbackService = 0x276c784b;

class cIGZCallbackService : public cIGZUnknown
{
public:
	virtual cIGZCallbackManager* CallbackManager() = 0;
};