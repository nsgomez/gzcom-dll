#pragma once
#include "cIGZUnknown.h"

class cIGZBuffer;
class cIGZFont;
class cIGZString;
class cIGZWin;
class cRZColor;
class cRZRect;

static const uint32_t GZIID_cIGZWinBtn = 0x8810;

class cIGZWinBtn : public cIGZUnknown
{
public:
	virtual cIGZWin* AsIGZWin() = 0;

	virtual bool GetBtnFlag(int32_t flag) const = 0;
	virtual bool SetBtnFlag(int32_t flag, bool value) = 0;

	virtual bool ToggleOn() = 0;
	virtual bool ToggleOff() = 0;
	virtual bool IsOn() const = 0;

	virtual bool SetChecked(bool unknown1) = 0;
	virtual bool IsChecked() const = 0;

	virtual uint32_t GetStyle() = 0;
	virtual bool SetStyle(int32_t unknown1, cIGZBuffer* unknown2, cRZRect const* unknown3) = 0;
	virtual bool SetButtonStyle(int32_t unknown1) = 0;

	virtual int32_t GetImageW() const = 0;
	virtual int32_t GetImageH() const = 0;
	virtual bool GetImageArea(cRZRect& unknown1) const = 0;

	virtual bool SetBuffer(cIGZBuffer* unknown1) = 0;
	virtual bool GetBuffer(cIGZBuffer*& unknown1) const = 0;

	virtual bool SetFont(cIGZFont* font) = 0;
	virtual bool SetFontStyle(uint32_t style) = 0;
	virtual bool GetFontStyle(uint32_t& style) = 0;

	virtual bool SetFontColor(int32_t unknown1, uint32_t unknown2) = 0;
	virtual bool GetFontColor(int32_t unknown1, uint32_t& unknown2) const = 0;
	virtual bool SetFontColor(int32_t unknown1, cRZColor& unknown2) = 0;
	virtual bool GetFontColor(int32_t unknown1, cRZColor& unknown2) const = 0;
	virtual bool ClearFontColor(int32_t unknown1) = 0;

	virtual bool SetCaptionStyle(int32_t style) = 0;
	virtual bool GetCaptionStyle(int32_t& style) const = 0;

	virtual bool SetGutters(uint8_t unknown1, uint8_t unknown2) = 0;
	virtual bool GetGutters(int32_t& unknown1, int32_t& unknown2) const = 0;
	virtual bool SetGutters(uint8_t unknown1, uint8_t unknown2, uint8_t unknown3, uint8_t unknown4) = 0;
	virtual bool GetGutters(int32_t& unknown1, int32_t& unknown2, int32_t& unknown3, int32_t& unknown4) const = 0;

	virtual bool FitSizeToContent() = 0;
	virtual bool GetMinMaxInfo(cRZRect& info) const = 0;

	virtual bool SetTipText(const cIGZString& tipText) = 0;
	virtual bool GetTipText(cIGZString& tipText) const = 0;
	virtual bool ClearTipText() = 0;

	virtual bool SetTipPlacementType(int32_t unknown1) = 0;
	virtual bool GetTipPlacementType(int32_t& unknown1) const = 0;

	virtual bool SetTipPlacementOffsets(int32_t unknown1, int32_t unknown2) = 0;
	virtual bool GetTipPlacementOffsets(int32_t& unknown1, int32_t& unknown2) const = 0;

	virtual bool SetTipColor(int32_t unknown1, uint8_t unknown2, uint8_t unknown3, uint8_t unknown4) = 0;
	virtual bool GetTipColor(int32_t unknown1, uint8_t& unknown2, uint8_t& unknown3, uint8_t& unknown4) const = 0;

	virtual void Flash(uint32_t unknown1, uint32_t unknown2) = 0;
	virtual bool SetSoundID(int32_t unknown1, uint32_t unknown2) = 0;
	virtual uint32_t GetSoundID(int32_t unknown1) const = 0;

	virtual bool SetID(uint32_t unknown1) = 0;
	virtual uint32_t GetID() const = 0;

	virtual bool SetCaption(const cIGZString& caption) = 0;
	virtual cIGZString* GetCaption() = 0;
};
