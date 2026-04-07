/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZLuaScriptServer.h
 *
 * Copyright (C) 2026 Nicholas Hayes
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

class cIGZString;
class cIGZLua5;
class cIGZLua5Thread;
template<typename T> class SC4List;
template<typename T> class SC4Vector;

class cIGZLuaScriptServer : public cIGZUnknown
{
public:
	class BreakpointEntry;

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual cIGZLua5* GetLua() = 0;

	/**
	 * @brief Runs the specified script string.
	 * @param script The script string.
	 * @param fileName The file name, used for interacting with the script debugger.
	 * @param arguments The script arguments.
	 * @return The script identifier or 0 on failure.
	 */
	virtual int32_t RunScriptString(cIGZString const& script, cIGZString const& fileName, cIGZString const& arguments) = 0;
	/**
	 * @brief Runs the specified script file.
	 * @param fileName The file name, used for interacting with the script debugger.
	 * @param arguments The script arguments.
	 * @return The script identifier or 0 on failure.
	 */
	virtual int32_t RunScriptFile(cIGZString const& fileName, cIGZString const& arguments) = 0;

	/**
	 * @brief Terminates the specified script.
	 * @param scriptID The script identifier.
	 * @return True if successful; otherwise, false.
	 */
	virtual bool KillScript(int32_t scriptID) = 0;
	/**
	 * @brief Pauses the specified script.
	 * @param scriptID The script identifier or -1 for all scripts.
	 * @return The pause count.
	 */
	virtual int32_t PauseScript(int32_t scriptID) = 0;
	/**
	 * @brief Resumes the specified script.
	 * @param scriptID The script identifier or -1 for all scripts.
	 * @return The pause count.
	 */
	virtual int32_t ResumeScript(int32_t scriptID) = 0;

	virtual bool GetBreakpointExists(int32_t scriptID, cIGZString const& fileName, int32_t lineNumber) = 0;
	virtual bool SetBreakpointExists(int32_t scriptID, cIGZString const& fileName, int32_t lineNumber, bool remove) = 0;
	virtual bool ToggleBreakpointExists(int32_t scriptID, cIGZString const& fileName, int32_t lineNumber) = 0;
	virtual bool GetBreakpointEnabled(int32_t scriptID, cIGZString const& fileName, int32_t lineNumber) = 0;
	virtual bool SetBreakpointEnabled(int32_t scriptID, cIGZString const& fileName, int32_t lineNumber, bool enabled) = 0;
	virtual bool GetBreakpointCondition(int32_t scriptID, cIGZString const& fileName, int32_t lineNumber, cIGZString& condition) = 0;
	virtual bool SetBreakpointCondition(int32_t scriptID, cIGZString const& fileName, int32_t lineNumber, cIGZString const& condition) = 0;
	virtual bool GetBreakpointEntryList(int32_t scriptID, cIGZString const& fileName, SC4List<BreakpointEntry>& list) = 0;

	virtual void EnumerateScriptIDs(SC4Vector<int32_t>& vector) = 0;
	virtual bool GetScriptInfo(int32_t scriptID, cIGZLua5Thread** ppThread, cIGZString* pScriptString, cIGZString* pFileName, int32_t* pPauseCount, int32_t* pResumeCount, bool* unknown7) = 0;
	virtual int32_t GetCurrentRunningScriptID() = 0;

	virtual bool GetScriptAutoYieldEnabled(int32_t scriptID) const = 0;
	virtual bool SetScriptAutoYieldEnabled(int32_t scriptID, bool enabled) = 0;

	virtual int32_t GetLastCreatedScriptID() = 0;
};