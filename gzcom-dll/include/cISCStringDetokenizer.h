/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISCStringDetokenizer.h
 *
 * Copyright (C) 2024 Nicholas Hayes
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