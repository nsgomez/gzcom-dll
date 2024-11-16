#pragma once
#include "cIGZUnknown.h"

class cIGZCanvas;
class cIGZWinProcFilterW32;

static const uint32_t GZIID_cIGZCanvasW32 = 0xe46397db;

class cIGZCanvasW32 : public cIGZUnknown
{
public:
	virtual cIGZCanvas* AsIGZCanvas() = 0;

	virtual intptr_t Handle() = 0; // The registered mouse wheel message
	virtual intptr_t Class() = 0; // Always returns 0

	virtual bool AddWinProcFilter(cIGZWinProcFilterW32*, bool add) = 0;
};