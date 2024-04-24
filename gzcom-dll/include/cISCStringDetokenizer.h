#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;
class cIGZString;

class cISCStringDetokenizer : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void SetTokenReplacementValue(cIGZString const& token, cIGZString const& replacementValue) = 0;

	typedef bool (*TokenReplacementCallback)(cIGZString const& token, cIGZString& outValue, void* pContext);

	virtual void SetTokenReplacementMethod(cIGZString const& token, TokenReplacementCallback pCallback, void* pContext) = 0;
	virtual void AddUnknownTokenReplacementMethod(TokenReplacementCallback pCallback, void* pContext, bool add) = 0;

	virtual bool Detokenize(cIGZString const& tokenizedValue, cIGZString& output) = 0;
	virtual bool Detokenize(cGZPersistResourceKey const& key, cIGZString& output) = 0;

	virtual void SetHTMLCleanMode(bool value) = 0;
	virtual bool GetHTMLCleanMode() = 0;
};