/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZWinProc.h
 *
 * Copyright (C) 2024 Nicholas Hayes
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, under
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <https://www.gnu.org/licenses/>.
 */

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
