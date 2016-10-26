#pragma once
#include "cIGZUnknown.h"

class cISCResExemplar;

class cISCExemplarPropertyHolder : public cIGZUnknown
{
	public:
		virtual bool SetDefaultExemplar(cISCResExemplar* pExemplar) = 0;
		virtual cISCResExemplar* GetDefaultExemplar(void) = 0;
};