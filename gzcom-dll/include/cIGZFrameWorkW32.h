#pragma once
#include "cIGZUnknown.h"
#include <Windows.h>

class cIGZFrameWork;

static const uint32_t GZIID_cIGZFrameWorkW32 = 0x23ea70a1;

class cIGZFrameWorkW32 : public cIGZUnknown
{
public:

	virtual cIGZFrameWork* AsIGZFrameWork() = 0;

	virtual HINSTANCE GetWindowsInstance() = 0;

	virtual HWND GetMainHWND() = 0;

	virtual bool SetMainHWND(HWND) = 0;
};