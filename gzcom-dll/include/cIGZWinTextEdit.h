/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZWinTextEdit.h
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

static const uint32_t GZIID_cIGZWinTextEdit = 0x231a1c57;

class cIGZBuffer;
class cIGZFont;
class cIGZString;
class cIGZWin;
class cRZColor;
class cRZRect;

class cIGZWinTextEdit : public cIGZUnknown
{
public:
	enum class ColorIndex : int32_t
	{
		ColorFontNormal = 0,
		ColorFontNormalBackground = 1,
		ColorFontDisabled = 2,
		ColorFontDisabledBackground = 3,
		ColorFontHighlighted = 4,
		ColorFontHighlightedBackground = 5
	};

	enum TextEditFlags : int32_t
	{
		TextEditFlag_Editable = 0x1,
		TextEditFlag_Wrapped = 0x2,
		TextEditFlag_HScrollbar = 0x4,
		TextEditFlag_VScrollbar = 0x8,
		TextEditFlag_Outline = 0x10,
		TextEditFlag_Opaque = 0x20,
		TextEditFlag_AllowInsert = 0x80,
		TextEditFlag_AllowUndo = 0x100,
		TextEditFlag_SingleLine = 0x200,
		TextEditFlag_NotifyOnReturn = 0x400,
		TextEditFlag_NotifyOnChange = 0x800,
		TextEditFlag_EnableClipboard = 0x1000,
		TextEditFlag_PasswordMode = 0x2000,
		TextEditFlag_NotifyOnFocusLost = 0x8000
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual cIGZWin* AsIGZWin() = 0;

	virtual void SetArea(int32_t left, int32_t top, int32_t right, int32_t bottom) = 0;
	virtual void GetTextArea(cRZRect& area) = 0;
	virtual cIGZFont* GetFont() = 0;
	virtual void SetFont(cIGZFont* font) = 0;
	virtual bool SetFontStyle(uint32_t style) = 0;
	virtual bool GetFontStyle(uint32_t& style) = 0;

	// MSVC puts every virtual overload of a name at the vtable slot of the first
	// one declared, in REVERSE declaration order. So each overload group in this
	// class is declared in the reverse of the game's order.
	// Game slots: 12 SetFontColor(ColorIndex, uint32_t), 13 SetFontColor(uint32_t).
	virtual bool SetFontColor(uint32_t color) = 0;
	virtual bool SetFontColor(ColorIndex index, uint32_t color) = 0;
	virtual bool GetFontColor(ColorIndex index, uint32_t& color) = 0;
	virtual bool SetColor(ColorIndex index, cRZColor color) = 0;
	virtual bool GetColor(ColorIndex index, cRZColor& color) = 0;
	virtual bool ClearFontColor(ColorIndex index) = 0;
	virtual void SetCaretColor(uint32_t color) = 0;
	virtual bool GetCaretColor(uint32_t& param_1) const = 0;
	virtual bool SetFillColor(cRZColor color) = 0;
	virtual void SetFillColor(uint32_t color) = 0;
	virtual uint32_t GetHighlightFillColor() = 0;
	virtual void SetHighlightFillColor(uint32_t color) = 0;
	virtual void GetBackgroundImage(cIGZBuffer*& buffer, bool& param_2) = 0;
	virtual void SetBackgroundImage(cIGZBuffer* buffer, bool param_2) = 0;

	virtual bool ScrollLineUp() = 0;
	virtual bool ScrollLineDown() = 0;
	virtual bool ScrollToStart() = 0;
	virtual bool ScrollToEnd() = 0;
	virtual bool ScrollPageUp() = 0;
	virtual bool ScrollPageDown() = 0;
	virtual uint32_t GetMaximumTextToAllow() = 0;
	virtual void SetMaximumTextToAllow(uint32_t value) = 0;
	virtual uint32_t GetFirstVisibleLine() = 0;
	virtual uint32_t GetLineCount() = 0;
	virtual uint32_t GetLineHeight() = 0;
	virtual void SetOutlineUse(bool enabled, uint32_t color) = 0;
	virtual void GetOutlineUse(bool& enabled, uint32_t& color) const = 0;
	virtual uint32_t GetTextGutterX() = 0;
	virtual void SetTextGutterX(uint32_t value) = 0;
	virtual uint32_t GetTextGutterY() = 0;
	virtual void SetTextGutterY(uint32_t value) = 0;
	virtual bool ResizeWindowForExactLineHeights() = 0;

	// Game slots: 44 GetText(char*, uint32_t*), 45 GetText(cIGZString&), 46 GetText().
	virtual const char* GetText() = 0;
	virtual void GetText(cIGZString& text) = 0;
	virtual void GetText(char* textBuffer, uint32_t* param_2) = 0;
	virtual uint32_t GetTextLength() = 0;
	// Game slots: 48 SetText(cIGZString const&, bool), 49 SetText(char*, uint32_t, bool).
	virtual bool SetText(char* text, uint32_t textLength, bool sendTextChangedMessage) = 0;
	virtual void SetText(cIGZString const& text, bool sendTextChangedMessage) = 0;
	// Game slots: 50 InsertText(text, length, line, column), 51 InsertText(text, length, index).
	virtual void InsertText(char* text, uint32_t textLength, uint32_t index) = 0;
	virtual void InsertText(char* text, uint32_t textLength, uint32_t line, uint32_t column) = 0;
	virtual bool RemoveChar(uint32_t param_1, bool param_2, cIGZString* param_3) = 0;

	// Game slots: 53 RemoveText(fromLine, fromColumn, toLine, toColumn, ...), 54 RemoveText(line, column, length, ...),
	// 55 RemoveText(index, length, ...).
	virtual uint32_t RemoveText(uint32_t index, uint32_t length, cIGZString* removedText) = 0;
	virtual uint32_t RemoveText(uint32_t line, uint32_t column, uint32_t length, cIGZString* removedText) = 0;
	virtual uint32_t RemoveText(uint32_t fromLine, uint32_t fromColumn, uint32_t toLine, uint32_t toColumn, cIGZString* removedText) = 0;
	virtual size_t FindText(const char* text, size_t position, size_t count, bool fromStart) = 0;

	virtual void GetIndexFromPosition(uint32_t& index, int32_t param_2, int32_t param_3) = 0;
	virtual void GetColumnFromPosition(uint32_t param_1, uint32_t& column, int32_t param_3) = 0;
	virtual void GetLineAndColumnFromPosition(uint32_t& line, uint32_t& column, int32_t param_3, int32_t param_4) = 0;
	virtual void GetPositionFromLineAndColumn(uint32_t line, uint32_t column, int32_t& param_3, int32_t& param_4) = 0;
	virtual void GetLineAndColumnFromIndex(uint32_t& line, uint32_t& column, uint32_t index) = 0;
	virtual bool GetIndexFromLineAndColumn(uint32_t line, uint32_t column, uint32_t& index) = 0;

	virtual uint32_t GetCharacterCountOfLine(uint32_t line) = 0;
	virtual bool SetInsertMode(bool value) = 0;
	virtual bool GetInsertMode() = 0;
	virtual bool SetInsertionIndex(uint32_t index) = 0;
	virtual bool GetInsertionIndex(uint32_t& index) = 0;
	virtual bool SetInsertionLineAndColumn(uint32_t line, uint32_t column) = 0;
	virtual bool GetInsertionLineAndColumn(uint32_t& line, uint32_t& column) = 0;
	virtual void IncrementInsertionPosition(int32_t param_1) = 0;
	virtual void IncrementInsertionPositionByWord(int32_t param_1) = 0;
	virtual bool SetCaretPeriod(uint32_t value) = 0;
	virtual bool GetCaretPeriod(uint32_t& value) = 0;
	virtual bool GetSelection(uint32_t& start, uint32_t& end) = 0;
	virtual bool SetSelection(uint32_t start, uint32_t end) = 0;

	virtual void SetFlag(TextEditFlags flags) = 0;
	virtual void SetFlags(TextEditFlags flags) = 0;
	virtual void ClearFlag(TextEditFlags flags) = 0;
	virtual bool IsFlagSet(TextEditFlags flags) = 0;
	virtual TextEditFlags GetFlags() = 0;

	virtual void SetMaxUndoLevelCount(uint32_t value) = 0;
	virtual uint32_t GetMaxUndoLevelCount() const = 0;
	virtual bool Undo() = 0;
	virtual bool Redo() = 0;
	virtual bool GetScrollBarImageVertical(cIGZBuffer*& buffer, cRZRect& imageArea) = 0;
	virtual bool GetScrollBarImageHorizontal(cIGZBuffer*& buffer, cRZRect& imageArea) = 0;
	virtual bool SetScrollBarImageVertical(cIGZBuffer* buffer, cRZRect const& imageArea) = 0;
	virtual bool SetScrollBarImageHorizontal(cIGZBuffer* buffer, cRZRect const& imageArea) = 0;
	virtual bool SetSoundID(int32_t index, int32_t soundID) = 0;
};
