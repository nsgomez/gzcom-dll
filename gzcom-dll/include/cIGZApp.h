/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZApp.h
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

class cIGZFrameWork;
class cIGZSystemService;

/**
 * @brief An interface for generic Gonzo applications
 * @see cISC4App
 *
 * The Application is essentially a root service for games. The game should
 * extend this interface and provide any provide any additional methods
 * needed via another interface.
 */
class cIGZApp : public cIGZUnknown
{
	public:
		virtual cIGZSystemService* AsIGZSystemService(void) = 0;
		virtual char const* ModuleName(void) = 0;
		virtual cIGZFrameWork* FrameWork(void) = 0;

		virtual bool AddApplicationService(cIGZSystemService* pService) = 0;

		virtual bool PreFrameWorkInit(void) = 0;
		virtual bool PostFrameWorkInit(void) = 0;
		virtual bool PreFrameWorkShutdown(void) = 0;

		/**
		 * In cIGZApp, this is a no-op and always returns false.
		 */
		virtual bool GZRun(void) = 0;

		/**
		 * In cIGZApp, this is a no-op and always returns false.
		 * @see cISC4App::LoadRegistry(void)
		 */
		virtual bool LoadRegistry(void) = 0;

		/**
		 * A hardcoded point for EA/Maxis to load any dynamic libraries used
		 * by the game upon initialization. Not used by our directors.
		 */
		virtual void AddDynamicLibrariesHere(void) = 0;

		/**
		 * A hardcoded point for EA/Maxis to initialize COM directors. Not
		 * used by our directors.
		 *
		 * @see cISC4App::AddCOMDirectorsHere(void)
		 */
		virtual void AddCOMDirectorsHere(void) = 0;

		/**
		 * A hardcoded point for EA/Maxis to initialize application services.
		 * Not used by our directors.
		 */
		virtual void AddApplicationServicesHere(void) = 0;
};