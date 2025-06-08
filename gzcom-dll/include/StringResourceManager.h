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
