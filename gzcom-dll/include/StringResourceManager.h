/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * StringResourceManager.h
 *
 * Copyright (C) 2023, 2025 Nicholas Hayes
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
#include "cRZAutoRefCount.h"

class cIGZLanguageManager;
class cIGZPersistResourceManager;
class cIGZString;
struct StringResourceKey;

namespace StringResourceManager
{
	/**
	 * @brief Attempts to get a string in the games current language from the LTEXT files.
	 * @param key A key representing the default string that is used if a localized string is not found.
	 * @param outString The output string.
	 * @return true if successful; otherwise, false.
	 * @remarks The localized LTEXT files have a group ID that is offset based on the in-game language
	 * code. For example, if the default language has a group ID of 0x861C64C0, UK-English would use
	 * 0x861C64C2, German would use 0x861C64C4, etc.
	*/
	bool GetLocalizedString(const StringResourceKey& key, cRZAutoRefCount<cIGZString>& outString);

	/**
	 * @brief Attempts to get a string in the games current language from the LTEXT files.
	 * @param pLM A pointer to the language manager.
	 * @param pRM A pointer to the resource manager.
	 * @param key A key representing the default string that is used if a localized string is not found.
	 * @param outString The output string.
	 * @return true if successful; otherwise, false.
	 * @remarks The localized LTEXT files have a group ID that is offset based on the in-game language
	 * code. For example, if the default language has a group ID of 0x861C64C0, UK-English would use
	 * 0x861C64C2, German would use 0x861C64C4, etc.
	*/
	bool GetLocalizedString(
		cIGZLanguageManager* pLM,
		cIGZPersistResourceManager* pRM,
		const StringResourceKey& key,
		cRZAutoRefCount<cIGZString>& outString);

	/**
	 * @brief Attempts to get a string from the LTEXT files.
	 * @param key A key representing the LTEXT file to load.
	 * @param outString The output string.
	 * @return true if successful; otherwise, false.
	*/
	bool GetString(const StringResourceKey& key, cRZAutoRefCount<cIGZString>& outString);

	/**
	 * @brief Attempts to get a string from the LTEXT files.
	 * @param pRM A pointer to the resource manager.
	 * @param key A key representing the LTEXT file to load.
	 * @param outString The output string.
	 * @return true if successful; otherwise, false.
	*/
	bool GetString(
		cIGZPersistResourceManager* pRM,
		const StringResourceKey& key,
		cRZAutoRefCount<cIGZString>& outString);
}
