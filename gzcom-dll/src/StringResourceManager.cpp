/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * StringResourceManager.cpp
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

#include "StringResourceManager.h"
#include "StringResourceKey.h"
#include "cGZPersistResourceKey.h"
#include "cIGZLanguageManager.h"
#include "cIGZPersistResourceManager.h"
#include "cIGZString.h"
#include "GZServPtrs.h"

namespace
{
	bool TryGetResourceString(
		cIGZPersistResourceManager& resourceManager,
		uint32_t groupID,
		uint32_t instanceID,
		cRZAutoRefCount<cIGZString>& outString)
	{
		constexpr uint32_t LTEXTTypeID = 0x2026960B;

		cGZPersistResourceKey key(LTEXTTypeID, groupID, instanceID);

		// GetPrivateResource skips adding the value to the game's resource cache.
		return resourceManager.GetPrivateResource(
			key,
			GZIID_cIGZString,
			outString.AsPPVoid(),
			0,
			nullptr);
	}
}

bool StringResourceManager::GetLocalizedString(const StringResourceKey& key, cRZAutoRefCount<cIGZString>& outString)
{
	cIGZLanguageManagerPtr pLM;
	cIGZPersistResourceManagerPtr pRM;

	return GetLocalizedString(pLM, pRM, key, outString);
}

bool StringResourceManager::GetLocalizedString(
	cIGZLanguageManager* pLM,
	cIGZPersistResourceManager* pRM,
	const StringResourceKey& key,
	cRZAutoRefCount<cIGZString>& outString)
{
	bool result = false;

	if (key.groupID != 0 && key.instanceID != 0 && pLM && pRM)
	{
		// The localized resources use a group ID that is offset from the default language
		// group ID. This system allows a single DAT file to contain string resources for all
		// of the languages that are supported by the game.

		const uint32_t currentLanguage = pLM->GetCurrentLanguage();
		const uint32_t currentLanguageGroupID = key.groupID + currentLanguage;

		// We will search the loaded string resources for a matching value in
		// the game's currently configured language. If one is not found we will use
		// the default string resource.

		result = TryGetResourceString(*pRM, currentLanguageGroupID, key.instanceID, outString);
		if (!result)
		{
			result = TryGetResourceString(*pRM, key.groupID, key.instanceID, outString);
		}
	}

	return result;
}

bool StringResourceManager::GetString(const StringResourceKey& key, cRZAutoRefCount<cIGZString>& outString)
{
	cIGZPersistResourceManagerPtr pRM;

	return GetString(pRM, key, outString);
}

bool StringResourceManager::GetString(
	cIGZPersistResourceManager* pRM,
	const StringResourceKey& key,
	cRZAutoRefCount<cIGZString>& outString)
{
	bool result = false;

	if (key.groupID != 0 && key.instanceID != 0 && pRM)
	{
		result = TryGetResourceString(*pRM, key.groupID, key.instanceID, outString);
	}

	return result;
}
