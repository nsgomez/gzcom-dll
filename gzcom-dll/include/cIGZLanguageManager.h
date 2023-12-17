#pragma once
#include "cIGZUnknown.h"

class cIGZString;
class cIGZLanguageUtility;

class cIGZLanguageManager : public cIGZUnknown
{
public:

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;
	virtual bool AddAvailableLanguage(uint32_t languageID) = 0;
	virtual bool RemoveAvailableLanguage(uint32_t languageID) {}
	virtual uint32_t GetCurrentLanguage() = 0;
	virtual bool SetCurrentLanguage(uint32_t languageID) = 0;
	virtual bool CanSwitchToLanguage(uint32_t languageID) = 0;
	virtual uint32_t GetCurrentSystemLanguage() = 0;
	virtual uint32_t GetSystemLanguageFromLanguage() = 0;
	virtual uint32_t GetLanguageFromSystemLanguage() = 0;
	virtual bool GetLanguageRuntimeLibraryName(cIGZString& name, uint32_t& languageID) = 0;
	virtual bool GetNextAvailableLanguage(uint32_t& languageID) = 0;
	virtual bool GetLanguageDirectoryName(cIGZString& name, uint32_t languageID) = 0;
	virtual bool GetLanguageEnglishName(cIGZString& name, uint32_t languageID) = 0;
	virtual bool GetLanguageLocalName(cIGZString& name, uint32_t languageID) = 0;
	virtual bool GetLanguageIDFromLanguageEnglishName(cIGZString& name, uint32_t& languageID) = 0;
	virtual bool GetLanguageIDFromLanguageLocalName(cIGZString& name, uint32_t& languageID) = 0;
	virtual bool GetLanguageIDFromEitherEnglishOrLocalName(cIGZString& name, uint32_t& languageID) = 0;
	virtual bool GetLanguageEnglishNameFromLanguageID(cIGZString& name, uint32_t languageID) = 0;
	virtual bool GetLanguageLocalNameFromLanguageID(cIGZString& name, uint32_t languageID) = 0;
	virtual uint32_t GetLanguageIDAlias(uint32_t languageID) = 0;
	virtual bool GetISO639LanguageCodeFromLanguageID(cIGZString& name, uint32_t languageCode) = 0;
	virtual bool GetISO639LanguageIDFromLanguageCode(cIGZString& name, uint32_t& languageID) = 0;
	virtual bool GetISO3166CountryCodeFromCountryID(cIGZString& name, uint32_t countryID) = 0;
	virtual bool GetISO3166CountryIDFromCountryCode(cIGZString& name, uint32_t& countryCode) = 0;
	virtual uint32_t GetCurrentCountry() = 0;
	virtual bool SetCurrentCountry(uint32_t countryID) = 0;
	virtual uint32_t GetPrimaryLanguageForCountry(uint32_t countryID) = 0;
	virtual uint32_t GetDefaultCountryForLanguage(uint32_t countryID) = 0;
	virtual uint32_t GetCurrentSystemCountry() = 0;
	virtual bool CanSwitchToCountry(uint32_t countryID) = 0;
	virtual bool GetCountryEnglishName(cIGZString& name, uint32_t countryID) = 0;
	virtual bool GetCountryLocalName(cIGZString& name, uint32_t countryID) = 0;
	virtual bool GetCountryIDFromCountryEnglishName(cIGZString& name, uint32_t& countryID) = 0;
	virtual bool GetCountryIDFromCountryLocalName(cIGZString& name, uint32_t& countryID) = 0;
	virtual cIGZLanguageUtility* GetLanguageUtility(uint32_t languageID) = 0;
	virtual cIGZLanguageUtility* GetNewLanguageUtility(uint32_t languageID) = 0;
	virtual float GetExchangeRateForLocale(uint32_t locale) = 0;
	virtual bool SetExchangeRateForLocale(float exchangeRate, uint32_t locale) = 0;
	virtual bool ConvertMoneyFromBaseToLocale(int32_t unknown1, int32_t* unknown2, uint32_t unknown3) = 0;
	virtual bool ConvertMoneyFromBaseToLocale(int64_t unknown1, int64_t* unknown2, uint32_t unknown3) = 0;
	virtual bool ConvertMoneyFromLocaleToLocale(uint32_t unknown2, int32_t* unknown3, uint32_t unknown4) = 0;
	virtual bool ConvertMoneyFromLocaleToLocale(int64_t unknown1, uint32_t unknown2, int64_t* unknown3, uint32_t unknown4) = 0;
};
