/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZMessageServer2.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2023 Nicholas Hayes
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

class cIGZMessage2;
class cIGZMessageTarget2;

/**
 * @see cIGZMessageServer
 *
 * A message server for cIGZMessage2 and cIGZMessageTarget2.
 */
class cIGZMessageServer2 : public cIGZUnknown
{
	public:
		virtual bool MessageSend(cIGZMessage2* pMessage) = 0;
		virtual bool MessagePost(cIGZMessage2* pMessage, bool bHighPriority) = 0;

		virtual bool AddNotification(cIGZMessageTarget2* pTarget, uint32_t dwMessageID) = 0;
		virtual bool RemoveNotification(cIGZMessageTarget2* pTarget, uint32_t dwMessageID) = 0;

		virtual bool GeneralMessagePostToTarget(cIGZMessage2* pMessage, cIGZMessageTarget2* pTarget) = 0;
		virtual bool CancelGeneralMessagePostsToTarget(cIGZMessageTarget2* pTarget) = 0;
		
		virtual bool OnTick(uint32_t unknown1) = 0;

		virtual uint32_t GetMessageQueueSize(void) = 0;
		virtual cIGZMessageServer2* SetAlwaysClearQueueOnTick(bool bToggle) = 0;

		virtual uint32_t GetRefCount(void) = 0;
		virtual cIGZMessage2* CreateMessage(uint32_t clsid, uint32_t msgid, void** ppData) = 0;
};