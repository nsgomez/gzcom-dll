/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZFontSys.h
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
#include "cIGZFont.h"

class cIGZFontRenderer;
class cIGZString;

class cIGZFontSys : public cIGZUnknown
{
public:
	struct FontInfo
	{
		char name[128];
		cIGZFont::Style style;
		cIGZFont::Type type;

		FontInfo()
			: name{}, style(cIGZFont::Style_Normal), type(cIGZFont::Type::MonoSpaced)
		{
		}
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void SetDefaultCodePage(int32_t codePage) = 0;
	virtual void SetDefaultFontRenderer(cIGZFontRenderer* pRenderer) = 0;
	virtual void SetDefaultFontAntialiasing(cIGZFont::AntialiasingMode mode) = 0;
	virtual void SetDefaultUnantialiasedSizeRange(int32_t min, int32_t max, cIGZString const* fontName) = 0;

	virtual cIGZFont* FontAcquire(int32_t unknown1, uint32_t size, cIGZFont::Style style, uint32_t unknown4, bool addToCache) = 0;
	virtual cIGZFont* FontAcquire(cIGZString const& name, uint32_t size, cIGZFont::Style style, bool addToCache) = 0;
	virtual cIGZFont* FontAcquire(cIGZString const& name, int32_t unknown2, uint32_t size, cIGZFont::Style style, bool addToCache) = 0;
	virtual int32_t FontRelease(cIGZFont* pFont) = 0;

	// MSVC puts every virtual overload of a name at the vtable slot of the first
	// one declared, in REVERSE declaration order. Game slots: 13 AddFont(cIGZFont*),
	// 14 AddFont(cIGZString const&).
	virtual bool AddFont(cIGZString const& path) = 0;
	virtual bool AddFont(cIGZFont* pFont) = 0;
	virtual int32_t AddAllFontsFromDirectory(cIGZString const& directory) = 0;
	virtual bool RemoveFontByFile(cIGZString const& file) = 0; // No-op
	virtual bool RemoveFontByName(cIGZString const& name) = 0;

	virtual uint32_t EnumerateFontInfo(FontInfo* pArray, uint32_t count) = 0;
	virtual uint32_t EnumerateManagedFonts(cIGZFont** pArray, uint32_t count) = 0; // Does not AddRef the font.
	virtual bool AddSubstitution(cIGZString const& actualName, cIGZString const& aliasName) = 0;
	virtual uint32_t EnumerateFontSubstitutions(cIGZString const& fontName, cIGZString** pArray, uint32_t count) = 0;
	virtual bool IsFontAvailable(cIGZString const& name, uint32_t size, cIGZFont::Style style) = 0;
	virtual bool IsSubstitutionAvailable(cIGZString const& actualName, cIGZString const& aliasName) = 0;
};