/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZWinCtrlMgr.h
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

class cIGZBuffer;
class cIGZCtrlCreator;
class cIGZFont;
class cIGZString;
class cIGZWinBMP;
class cIGZWinBtn;
class cIGZWinLineInput;
class cIGZWinOptGrp;
class cIGZWinScrollbar;
class cIGZWinSlider;
class cIGZWinSpinner;
class cIGZWinText;
class cRZRect;

class cIGZWinCtrlMgr : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual cIGZFont* SystemFont(int32_t id) = 0;
	virtual void SetSystemFont(int32_t id, cIGZFont* pFont) = 0;
	virtual cIGZBuffer* SystemBMP(int32_t id) = 0;
	virtual void SetSystemBMP(int32_t id, cIGZBuffer* pBuffer) = 0;

	virtual cIGZWinBtn* CreateButton(uint32_t id, cIGZString const& caption, cIGZBuffer* imageBuffer, cRZRect const* imageArea, uint32_t keyEquivalent) = 0;
	virtual cIGZWinBtn* CreateButton(uint32_t style, uint32_t id, cIGZString const& caption, cIGZBuffer* imageBuffer, cRZRect const* imageArea, uint32_t keyEquivalent) = 0;
	virtual cIGZWinBtn* CreateToggleButton(uint32_t id, cIGZString const& caption, cIGZBuffer* imageBuffer, cRZRect const* imageArea, uint32_t keyEquivalent) = 0;
	virtual cIGZWinBtn* CreateRadioCheck(uint32_t id, cIGZString const& caption, cIGZBuffer* imageBuffer, cRZRect const* imageArea, uint32_t keyEquivalent) = 0;
	virtual cIGZWinText* CreateLabel(uint32_t id, cIGZString const& caption) = 0;
	virtual cIGZWinOptGrp* CreateOptGrp(uint32_t id, cIGZString const& caption, cRZRect const* area) = 0;
	virtual cIGZWinBMP* CreateWinBMP(uint32_t id, cIGZBuffer* pBuffer, bool updateSizeToMatchBuffer) = 0;
	virtual cIGZWinSlider* CreateSlider(uint32_t id, int32_t direction, int32_t minValue, int32_t maxValue, int32_t value) = 0;
	virtual cIGZWinScrollbar* CreateScrollbar(uint32_t id, int32_t direction, int32_t minValue, int32_t maxValue, int32_t value) = 0;
	virtual cIGZWinSpinner* CreateSpinner(uint32_t id, int32_t type, int32_t min, int32_t max, int32_t stepSize, int32_t value) = 0;
	virtual cIGZWinLineInput* CreateLineInput(uint32_t id, bool editable) = 0;
	virtual cIGZWinBtn* CreateFixedButton(uint32_t id, cIGZString const& caption, cIGZBuffer* imageBuffer, cRZRect const* imageArea, uint32_t keyEquivalent) = 0;
	virtual cIGZWinBtn* CreateFixedToggleButton(uint32_t id, cIGZString const& caption, cIGZBuffer* imageBuffer, cRZRect const* imageArea, uint32_t keyEquivalent) = 0;
	virtual cIGZWinBtn* CreateCheckBox(uint32_t id, cIGZString const& caption, cIGZBuffer* imageBuffer, cRZRect const* imageArea, uint32_t keyEquivalent) = 0;
	virtual cIGZWinBtn* CreateRadioButton(uint32_t id, cIGZString const& caption, cIGZBuffer* imageBuffer, cRZRect const* imageArea, uint32_t keyEquivalent) = 0;

	virtual bool RegisterCtrlCreator(cIGZCtrlCreator* pCtrlCreator) = 0;
	virtual bool RemoveCtrlCreator(cIGZCtrlCreator* pCtrlCreator) = 0;
	virtual bool CreateCtrl(uint32_t unknown1, uint32_t riid, void** ppvObj) = 0;

	virtual void SetSystemSndVol(int32_t volume) = 0;
	virtual int32_t GetSystemSndVol() = 0;
	virtual uint32_t SystemSndID(int32_t id) = 0;
	virtual void SetSystemSndID(int32_t id, uint32_t value) = 0;

	virtual void DefaultColor(int32_t id, uint8_t& unknown2, uint8_t& unknown3, uint8_t& unknown4) = 0;
	virtual uint32_t DefaultColor(int32_t id) = 0;
	virtual void SetDefaultColor(int32_t id, uint8_t unknown2, uint8_t unknown3, uint8_t unknown4) = 0;
	virtual void SetDefaultColor(int32_t id, uint32_t color) = 0;

	virtual cIGZString* DefaultText(int32_t id) = 0;
	virtual void SetDefaultText(int32_t id, cIGZString* pText) = 0;
	virtual cIGZString* GetFontMapping(int32_t id) = 0;
	virtual int32_t GetFontMappingID(cIGZString* pFontMapping) = 0;
	virtual void SetFontMapping(int32_t id, cIGZString* pFontMapping) = 0;

	virtual uint32_t GetDoubleClickTimeMilliseconds() = 0;
	virtual void SetDoubleClickTimeMilliseconds(uint32_t time) = 0;
	virtual bool CreateDefaultCtrl(uint32_t unknown1, uint32_t riid, void** ppvObj) = 0;
};