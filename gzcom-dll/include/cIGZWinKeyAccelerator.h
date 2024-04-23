#pragma once
#include "cIGZUnknown.h"

class cGZMessage;

static const uint32_t kGZCLSID_cGZWinKeyAccelerator = 0x42E967BE;
static const uint32_t kGZIID_cIGZWinKeyAccelerator = 0xE2C1B3C4;

class cIGZWinKeyAccelerator : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool RegisterAccelerator(uint32_t keyCode, uint32_t messageID) = 0;
	virtual bool RegisterAccelerator(uint32_t keyCode, cGZMessage const& param_2) = 0;
	virtual bool UnregisterAccelerator(uint32_t keyCode) = 0;

	virtual bool IsAcceleratorPresent(uint32_t keyCode, bool includeModifiers, bool includeKeyUp) = 0;

	virtual bool TestForAccelerator(cGZMessage const& input, uint32_t& messageID) = 0;
	virtual bool TestForAccelerator(cGZMessage const& input, cGZMessage& messageData) = 0;
	virtual bool TestForAccelerator(uint32_t keyCode, uint32_t modifiers, bool keyDown, uint32_t& messageID) = 0;
	virtual bool TestForAccelerator(uint32_t keyCode, uint32_t modifiers, bool keyDown, cGZMessage& messageData) = 0;

	virtual bool GetKeysForAccelerator(uint32_t keyCode, uint32_t* outKeyArray, uint32_t& outKeyArrayLeength) = 0;

	virtual bool ProcessAccelerator(cGZMessage const& data) = 0;
};
