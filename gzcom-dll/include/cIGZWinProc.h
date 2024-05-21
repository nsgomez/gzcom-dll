#pragma once
#include "cIGZUnknown.h"

class cGZMessage;
class cIGZWin;

static const uint32_t GZIID_cIGZWinProc = 0x22E85D8E;

class cIGZWinProc : public cIGZUnknown
{
public:
	/**
	 * @brief Processes the window procedure message.
	 * @param pWin The window.
	 * @param pMsg The message.
	 * @return True if the message was handled; otherwise, false.
	 */
	virtual bool DoWinProcMessage(cIGZWin* pWin, cGZMessage& pMsg) = 0;

	/**
	 * @brief Processes the window procedure message.
	 * @param pWin The window.
	 * @param dwMessageID The message id.
	 * @param data1 The first message data field.
	 * @param data2 The second message data field.
	 * @param data3 The third message data field.
	 * @return True if the message was handled; otherwise, false.
	 */
	virtual bool DoWinMsg(cIGZWin* pWin, uint32_t dwMessageID, uint32_t data1, uint32_t data2, uint32_t data3) = 0;
};
