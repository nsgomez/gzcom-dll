#include "StringResourceManager.h"
#include "StringResourceKey.h"
#include "cGZPersistResourceKey.h"
#include "cIGZLanguageManager.h"
#include "cIGZPersistResourceManager.h"
#include "cIGZString.h"
#include "GZServPtrs.h"

namespace
{
	bool TryGetResourceString(uint32_t groupID, uint32_t instanceID, cIGZString** outString)
	{
		bool result = false;

		if (outString)
		{
			if (*outString)
			{
				(*outString)->Release();
				*outString = nullptr;
			}

			constexpr uint32_t LTEXTTypeID = 0x2026960B;

			cGZPersistResourceKey key(LTEXTTypeID, groupID, instanceID);

			cIGZPersistResourceManagerPtr resourceManager;
			if (resourceManager)
			{
				// GetPrivateResource skips adding the value to the game's resource cache.
				result = resourceManager->GetPrivateResource(
					key,
					GZIID_cIGZString,
					reinterpret_cast<void**>(outString),
					0,
					nullptr);
			}
		}

		return result;
	}
}

bool StringResourceManager::GetLocalizedString(const StringResourceKey& key, cIGZString** outString)
{
	bool result = false;

	if (key.groupID != 0 && key.instanceID != 0)
	{
		cIGZLanguageManagerPtr languageManager;
		if (languageManager)
		{
			// The localized resources use a group ID that is offset from the default language
			// group ID. This system allows a single DAT file to contain string resources for all
			// of the languages that are supported by the game.

			const uint32_t currentLanguage = languageManager->GetCurrentLanguage();
			const uint32_t currentLanguageGroupID = key.groupID + currentLanguage;

			// We will search the loaded string resources for a matching value in
			// the game's currently configured language. If one is not found we will use
			// the default string resource.

			result = TryGetResourceString(currentLanguageGroupID, key.instanceID, outString);
			if (!result)
			{
				result = TryGetResourceString(key.groupID, key.instanceID, outString);
			}
		}
	}

	return result;
}

bool StringResourceManager::GetString(const StringResourceKey& key, cIGZString** outString)
{
	bool result = false;

	if (key.groupID != 0 && key.instanceID != 0)
	{
		result = TryGetResourceString(key.groupID, key.instanceID, outString);
	}

	return result;
}
