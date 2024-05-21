#pragma once
#include "cIGZUnknown.h"

class cGZMessage;
class cIGZWin;

static const uint32_t GZIID_cIGZWinMessageTarget = 0xC6AE7085;

class cIGZWinMessageTarget : public cIGZUnknown
{
public:
	virtual bool DoMessage(cIGZWin* pWin, cGZMessage& message) = 0;
};
