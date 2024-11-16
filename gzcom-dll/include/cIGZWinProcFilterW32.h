#pragma once
#include "cIGZUnknown.h"
#include <Windows.h>

class cIGZWinProcFilterW32 : public cIGZUnknown
{
public:
	virtual LRESULT FilterMessage(HWND hWnd, UINT uMsg, WPARAM wParram, LPARAM lParam, bool& handled) = 0;
};