#pragma once
#include "cIGZUnknown.h"

class cISCResExemplar;

static const uint32_t GZIID_cISCExemplarPropertyHolder = 0x0ac2b5f7;

class cISCExemplarPropertyHolder : public cIGZUnknown
{
	public:
		virtual bool SetDefaultExemplar(cISCResExemplar* pExemplar) = 0;
		virtual cISCResExemplar* GetDefaultExemplar(void) = 0;
};