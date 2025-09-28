/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4TutorialSystem.h
 *
 * Copyright (C) 2016 Nelson Gomez
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

class cISCLua;
class cISC4TutorialTask;
class cISC4WinCatalogView;

class cISC4TutorialSystem : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool startTutorial(void) = 0;
		virtual bool endTutorial(bool bEndTutorialRegistry) = 0;

		virtual cISCLua* GetScriptingContext(void) = 0;

		virtual bool IsTutorial(void) = 0;
		virtual bool IsEdgeScrollingAllowed(void) = 0;

		virtual cISC4TutorialTask* GetCurrentTask(void) = 0;
		virtual int32_t GetTutorialTaskNumber(void) = 0;
		virtual int32_t GetTutorialGUID(void) = 0;

		virtual bool FilterMessage(uint32_t dwMessageID) = 0;

		virtual cISC4TutorialSystem* ShowUIHintsForUsers(void) = 0;

		virtual bool HandleCatalogMenu(cISC4WinCatalogView* pMenu) = 0;
		virtual bool FilterLeftMouseClick(int32_t& nX, int32_t& nY, int32_t nUnknown) = 0;

		virtual bool ResetTutorialNumAndIndex(int32_t nUnknown1, int32_t nUnknown2) = 0;
};